#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//компоратор
bool comp( pair <int, int>  a, pair <int, int> b) {
    return a.second < b.second;
}

int main()
{
    //int n;
    int a, b, count;
    count = 1;
    //cin >> n;
    vector<pair<int, int>> time;
    
    while(cin>>a>>b)
        time.push_back(make_pair(a, b));

    sort(time.begin(), time.end(), comp);

    int k = 0;
    for (int i = 1; i < time.size(); ++i)
    {
        if (time[i].first >= time[k].second) {
            ++count;
            k = i;
        }
    }
    cout << count;
    return 0;
}
