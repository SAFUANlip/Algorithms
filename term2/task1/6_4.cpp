//Heap
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
template<typename T>
class myheap {
	typedef function <bool(T, T)> C;
public:
	myheap(std::initializer_list<T> L, C c) : vec(L), c(c) { heapify(); }
	myheap(std::vector<T> L, C c) : vec(L), c(c) { heapify(); }
	myheap(const myheap& M) : vec(M.vec), c(M.c) {}

	myheap& operator = (const myheap& M)
	{
		vec = M.vec;
		c = M.c;
	}

	myheap(C c = less<T>()) :c(c) {}

	const T& top() const
	{
		return vec[0];
	}
	bool empty() const
	{
		return vec.empty();
	}
	void push(const T& val)
	{
		vec.push_back(val);
		sift_up(vec.size() - 1);
	}
	void pop()
	{
		swap(vec.front(), vec.back());
		vec.pop_back();
		sift_down(0);
	}

private:
	vector<T> vec;
	C c;
	void heapify() //делает из массива кучу
	{
		for (int i = vec.size() / 2 - 1; i >= 0; --i)
			sift_down(i);
	}
	void sift_down(int i)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int m = i;
		if (r < vec.size() && c(vec[m], vec[r]))
			m = r;
		if (l < vec.size() && c(vec[m], vec[l]))
			m = l;
		if (m != i)
		{
			swap(vec[i], vec[m]);
			sift_down(m);
		}
	}
	void sift_up(int i)
	{
		//for(int p = (i-1)/2;vec[p]<vec[i]; i = p, p = (i-1)/2)
			//swap(vec[i], vec[p]);
		while (i > 0)
		{
			int p = (i - 1) / 2;
			if (!c(vec[p], vec[i]))
				return;
			swap(vec[i], vec[p]);
			i = p;
		}
	}
};



int main()
{
	int N, k;
	cin >> N;
	vector<int> M(N);
	for (int i = 0; i < N; ++i)
		cin >> M[i];
	cin >> k;
	
	myheap<pair<int, int>> heap([](pair<int, int> p1, pair<int, int> p2) {return p1.first < p2.first; });
	for (int i = 0; i < k; ++i)
		heap.push({ M[i], i });
	cout << heap.top().first << endl;
	for (int i = 1; i < N - k + 1; ++i)
	{
		heap.push({ M[i + k - 1], i + k - 1 });
		while (heap.top().second < i) //в куче удаляем элементы, которые может и максимальные, но по индексу выходят за пределы,
			                          //и так, пока не индекс нововго максимума не окажется в пределах сдвигающегося k
			heap.pop();
		cout << heap.top().first << endl;
	}
	return 0;
}
