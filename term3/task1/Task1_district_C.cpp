#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
//какие рёбра соединяющие компоненты сильной связности прямая пересекает 
using namespace std;

struct Point {
    int x;
    int y;
    Point(int _x, int _y) : x{ _x }, y{ _y }{};
};

vector<int> components(const vector<vector<int>>& g, function<int(int)> vorder = [](int i) {return i; })
{
    vector<int> c(g.size(), -1);
    int ci = 0;
    function<void(int)> dfs = [&](int v)
    {
        c[v] = ci;
        for (int u : g[v])
            if (c[u] == -1)
                dfs(u);
    };
    
    for (int i = 0; i < g.size(); ++i)
    {
        int v = vorder(i);
        if (c[v] == -1)
            dfs(v), ++ci;
    }

    return c;

}



void topological_sort_dfs(const vector<vector<int>>& g, vector<int>& res, vector<bool>& visited, int v)
{
    visited[v] = true;
    for (int u : g[v])
        if (!visited[u])
            topological_sort_dfs(g, res, visited, u);
    res.push_back(v);
}


vector<int> topological_sort(const vector<vector<int>>& g)
{
    vector<int> res(g.size());
    vector<bool> visited(g.size());
    for (int v = 0; v < g.size(); ++v)
        if (!visited[v])
            topological_sort_dfs(g, res, visited, v);
    reverse(res.begin(), res.end());
    return res;
}


vector<vector<int>> invert(const vector<vector<int>>& g)
{
    vector<vector<int>> inverted(g.size());
    for (int v = 0; v < g.size(); ++v)
        for (int u : g[v])
            inverted[u].push_back(v);
    return inverted;
}

vector<int> kosar(const vector<vector<int>>& g)
{
    vector<int> out = topological_sort(invert(g));
    return components(g, [&](int i) {return out[i]; });
}


int main()
{
    int n, m, x, y, from, to, k, b;
    cin >> n >> m;
    vector<Point> p;
    p.reserve(n);
    vector<vector<int>> vert(n);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        p.emplace_back(x,y);
    }
    for (int i = 0; i < m; ++i) {
        cin >> from >> to;
        if (from >= n || to >= n) {
            cout << "you havent so many point or your count of point < 0";
            return 0;
        }
        vert[from].push_back(to);
    }
    vector<int> comp = kosar(vert);
    cin >> k >> b;
    for (int i = 0; i < n; ++i) {
        for (auto j : vert[i])
            if (comp[j] != comp[i])
                if ((p[i].y - k * p[i].x - b) * (p[j].y - k * p[j].x - b) < 0)
                    cout << "point 1: " << p[i].x << p[i].y << " point 2: " << p[j].x << p[j].y <<  endl;
    }
    return 0;
}
