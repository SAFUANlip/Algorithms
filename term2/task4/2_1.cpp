#include <iostream>
#include <vector>
#include <algorithm>
 

int binp(std::vector<std::pair<int, int> >& a, int mass, int l)
{
    int r = a.size();
    while (r - l > 1)
    {
        int m = (r + l) / 2;
        if (a[m].second < mass)
            l = m;
        else
            r = m;
    }
    return (a[l].second >= mass) ? l : r;
}
 
int solve(std::vector<std::pair<int, int> >& a)
{
    int n = a.size();
    std::sort(a.begin(), a.end()); 
    int mass = a[0].first; 
    int ans = 1; 
    int m = 0; 
    while (true)
    {
        m = binp(a, mass, m + 1);
        mass += a[m].first;
        if (m == n) break; 
        ++ans;
    }
    return ans;
}
 
int main()
{
    int x, y;
    std::vector<std::pair<int, int> > a;
    while (std::cin >> x)
    {
        std::cin >> y;
        a.push_back({x,y});
    }
    std::cout << solve(a);
    return 0;
}
