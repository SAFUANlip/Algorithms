#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool operator < (const string& s1, const string& s2)
{
        for (int i = 0; i < s1.size() && i < s2.size(); ++i)
        {
            if (s1[i] < s2[i])
                return true;
            else if (s1[i] > s2[i])
                return false;
        }
        return (s1.size() < s2.size());
}


int main()
{
    int n;
    string a;
    cin >> n;
    vector<string> vec;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        vec.push_back(a);
    }
    
    sort(vec.begin(), vec.end());
    for (auto i : vec)
        cout << i << endl;
}
