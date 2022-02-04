#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
//сделать только топологической сортировкой 
using namespace std;

//bool components(const vector<vector<int>>& g, function<int(int)> vorder = [](int i) {return i; })
//{
//    vector<int> c(g.size(), -1);
//    int ci = 0;
//    function<void(int)> dfs = [&](int v)
//    {
//        c[v] = ci;
//        for (int u : g[v])
//            if (c[u] == -1)
//                dfs(u);
//    };
//    for (int i = 0; i < g.size(); ++i)
//    {
//        int v = vorder(i);
//        if (c[v] == -1)
//            dfs(v), ++ci;
//    }
//    vector<vector<int>> comp(ci);
//    for (int v = 0; v < c.size(); ++v) {
//        if (comp[c[v]].size() != 0)
//            return false;
//        else
//            comp[c[v]].push_back(v);
//    }
//    return true;
//}

enum color
{
    white, gray, black
};

bool find_cycle_directed(const vector<vector<int>>& g)
{
    vector<color> colors(g.size(), white);
    function<bool(int)> dfs = [&](int v) {
        colors[v] = gray;
        for (int u : g[v]) {
            if (colors[u] == gray || (colors[u] == white && dfs(u)))
                return true;
        }
        colors[v] = black;
        return false;
    };
    for (int v = 0; v < g.size(); ++v)
        if (colors[v] == white && dfs(v))
            return true;
    return false;
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
    vector<int> res;
    vector<bool> visited(g.size());
    for (int v = 0; v < g.size(); ++v)
        if (!visited[v])
            topological_sort_dfs(g, res, visited, v);
    reverse(res.begin(), res.end());
    return res;
}


//vector<vector<int>> invert(const vector<vector<int>>& g)
//{
//    vector<vector<int>> inverted(g.size());
//    for (int v = 0; v < g.size(); ++v)
//        for (int u : g[v])
//            inverted[u].push_back(v);
//    return inverted;
//}

//bool kosar(const vector<vector<int>>& g)
//{
//    vector<int> out = topological_sort(invert(g));
//    return components(g, [&](int i) {return out[i]; });
//}


int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        if (first == second) {
            cout << "NO";
            return 0;
        }
        g[first].push_back(second);
    }
 
    if (!find_cycle_directed(g)) {
        cout << "YES"<<endl;
        vector<int> go = topological_sort(g);
        for (auto i : go)
            cout << i << " ";
    }
    else
        cout << "NO";
    return 0;
}
