#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    vector<int> b;
    int n, m, k, x, pair_count;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a.push_back(x);
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        b.push_back(x);
    }
    cin >> k;

    int i, j;
    pair_count = 0;
    i = 0;
    j = m - 1;
    while (i < n && j >= 0)
    {
        if (a[i] + b[j] == k)
        {
            ++pair_count;
            --j;
            ++i;
        }

        else if (a[i] + b[j] > k)
            --j;
        else
            ++i;
    }
    cout << pair_count;
}
