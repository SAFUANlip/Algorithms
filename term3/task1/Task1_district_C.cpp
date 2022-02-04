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
/*
7 8
1 5
3 10
5 10
5 6
4 1
3 -5
-1 -4
0 1
1 2
2 3
3 0
4 0
4 5
5 6
6 4
1 1
*/
//int main()
//{
//    int n,m;
//    cin >> n >> m;
//
//    vector<vector<int>> out(n);
//    vector<vector<int>> in(n);
//
//    for (int i = 0; i < m; ++i)
//    {
//        int first, second;
//        cin >> first >> second;
//        if (first != second) {
//            //out[first-1].push_back(second-1);
//            //in[second-1].push_back(first-1);
//
//            out[first].push_back(second);
//            in[second].push_back(first);
//        }
//    }
//
//    int in_c = 0, out_c = 0;
//
//    pair<vector<int>, int> end = kosar(out);
//    vector<int> res = end.first;
//    int count = end.second;
//    
//    vector<vector<int>> comp(count);
//    for (int v = 0; v < res.size(); ++v)
//        comp[res[v]].push_back(v);
//
//    bool have_out = false, have_in = false;
//
//    for (int i = 0; i < comp.size(); ++i) {
//        for (int j = 0; j < comp[i].size(); ++j) {
//            if (comp[i].size() == n) {
//                cout << 0;
//                return 0;
//            }
//            for (int k = 0; k < out[comp[i][j]].size(); ++k)
//                if (i != res[out[comp[i][j]][k]])
//                    have_out = true;
//            for (int k = 0; k < in[comp[i][j]].size(); ++k)
//                if (i != res[in[comp[i][j]][k]])
//                    have_in = true;
//        }
//        if (!have_out) 
//            ++out_c;
//        if (!have_in)
//            ++in_c;
//        have_out = false, have_in = false;
//    }
//
//    cout << max(in_c, out_c);
//
//    return 0;
//}
