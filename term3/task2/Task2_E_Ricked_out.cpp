#include <vector>
#include <iostream>
using namespace std;

struct Edge_ATM {
	int from;
	int to;
	double commission;
	double course;
	Edge_ATM(int _from, int _to, double _course, double _commission) :
		from{ _from - 1 }, to{ _to - 1 }, commission{ _commission }, course{ _course }{};
};


int main()
{
	int CurrencyCount; //N
	int ATMcount;      //M
	int currency;      //S
	double money;      //of type S
	cin >> CurrencyCount >> ATMcount >> currency >> money;


	vector<double> allmoney(CurrencyCount);
	allmoney[currency - 1] = money;

	int cur1, cur2; //corrency
	double com12, com21, cr12, cr21;

	vector<Edge_ATM> Edge; 
	Edge.reserve(2 * ATMcount);
	for (int i = 0; i < ATMcount; ++i)
	{
		cin >> cur1 >> cur2 >> cr12 >> com12 >> cr21 >> com21;
		Edge.emplace_back(cur1, cur2, cr12, com12); 
		Edge.emplace_back(cur2, cur1, cr21, com21);
	}

	//ford bellman algorithm, find the maximum possible
	//amount of money of each currency
	for (int i = 0; i < CurrencyCount - 1; ++i)
		for (const auto& e : Edge)
		{
			if (allmoney[e.from] > 0)
				allmoney[e.to] = max(allmoney[e.to], (allmoney[e.from] - e.commission) * e.course);
		}

	//checking for cycles that increase the amount of money
	for (const auto& e : Edge)
		if (allmoney[e.from] > 0 && ((allmoney[e.from] - e.commission) * e.course) > allmoney[e.to]) {
			cout << "YES";
			return 0;
		}

	cout << "NO";
	return 0;
}

