#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int main()
{
	priority_queue <int, vector<int>, greater<int>> pq;
	size_t n, k;
	int a;
	vector<int> buf;
	cin >> n >> k;
	size_t j = 0;
	for (size_t i = 0; i < k; ++i)
	{
		cin >> a;
		pq.push(a);
	}

	for (size_t i = k; i < n; ++i)
	{

		cin >> a;
		if (j == k) {
			for (size_t m = 0; m < k; ++m)
				cout << buf[m]<<" ";
			buf.clear();
			j = 0;
			//cout << buf.size() << "size" << endl;
		}
		buf.push_back(pq.top());
		++j;
		pq.pop();
		pq.push(a);
	}

	for (size_t i = 0; i < j; ++i)
		cout << buf[i] << " ";

	while (!pq.empty())
	{
		cout << pq.top()<<endl;
		pq.pop();
	}
}
