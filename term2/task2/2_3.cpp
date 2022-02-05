#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    vector<pair<int, int>> vec;
    int n, left, right, pen, paint;
    pen = 0, paint = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> left >> right;
        vec.push_back(make_pair(left, 0)); // 0 - начало
        vec.push_back(make_pair(right, 1)); // 1 - конец
    }
    sort(vec.begin(), vec.end());
    //for (auto i =0; i<vec.size(); ++i)
    //   cout << vec[i].first << vec[i].second << endl;
    for (auto i = 0; i < vec.size(); ++i)
    {
        if (pen != 0)
            paint += (vec[i].first - vec[i-1].first);
        if (vec[i].second == 0)
            ++pen;
        else
            --pen;
    }
    cout << paint;
}
