#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int Prima(vector<vector<pair<int, int>>>& g) {
    int sum;

    vector<bool> visited(g.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        auto v = q.top();
        q.pop();
        if (visited[v.second])
            continue;
        visited[v.second] = true;
        sum += v.first;
        for (auto j : g[v.second]) {
            if (!visited[j.second])
                q.push(j);
        }
    }
    return sum;
}


int main()
{
    int n, m;
    int s, f, w;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> s >> f >> w;
        g[s-1].push_back(make_pair(w, f-1));
        g[f-1].push_back(make_pair(w, s-1));
        //g[s].push_back(make_pair(w, f));
        //g[f].push_back(make_pair(w, s));
    }
    cout << Prima(g);
    return 0;
}
