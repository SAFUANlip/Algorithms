#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//QuickSort_7

template <typename T>
void qsort(vector<T>& vec, int left, int right)
{
	int mid = vec[(right + left) / 2]; // 45 2 1 9 32 87 2 0 1 поэтому middle нужно запомнить, иначе не будет реализована идея, справа большие, слева меньшие
	int i, j;
	i = left;
	j = right;

	while (i < j)
	{
		while (vec[i] < mid)
			++i;
		while (vec[j] > mid)
			--j;
		if (i <= j)
		{
			swap(vec[i], vec[j]);
			++i;
			--j;
		}
	}

	if (j > left)
		qsort(vec, left, j); //было что j=-1
	if (i < right)
		qsort(vec, i, right);
}



int main()
{
	int x;
	vector<int> v;
	//while (cin>>x)
		//v.push_back(x);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (cin >> x)
		v.push_back(x);

	//qsort(v, 0, v.size() - 1);
	sort(v.begin(), v.end());
	for (int i = 9; i < v.size(); i += 10)
		cout << v[i] << ' ';

	/*for (auto i : v)
		cout << i << " ";*/
	return 0;
}
