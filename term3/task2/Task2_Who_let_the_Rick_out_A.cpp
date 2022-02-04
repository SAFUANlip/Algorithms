#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int dk(int s, int y, const vector<vector<int>>& g, function<int(int, int)> weight) {
    const int INF = 100000;

    vector<long> d(g.size(), INF);
    d[s] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        long  len = q.top().first;
        int v = q.top().second;
        q.pop();
        if (len > d[v])  continue;

        for (int i=0; i < g[v].size(); ++i) {
            int to = g[v][i];
            long length = weight(v, i);
            if (d[to] > d[v] + length) {
                d[to] = d[v] + length;
                q.push(make_pair(d[to], to));
            }
            if (v == y)
                return d[y];
        }
    }
    return d[y];
}

//int main()
//{
//    int n, k, x, y, w, s, f;
//    cin >> n >> k >> s >> f;
//    vector<vector<pair<int, int>>> gw(n);
//    vector<vector<int>> g(n);
//    for (int i = 0; i < k; ++i)
//    {
//        cin >> x >> y >> w;
//        gw[x].push_back(make_pair(w, y));
//        g[x].push_back(y);
//    }
//
//    cout << dk(s, f, g, [gw](int v, int i) {return gw[v][i].first; });
//    return 0;
//}

int main()
{
    int a, b, x, y;
    long M;
    cin >> a >> b >> M >> x >> y;
    vector<vector<pair<int, int>>> gw(M);
    vector<vector<int>> g(M);
    for (long long i = 0; i < M; ++i)
    {
        if ((i + 1) % M == (i * i + 1) % M) {
            gw[i].push_back(make_pair(min(a, b), (i + 1) % M));
            g[i].push_back((i + 1) % M);
        }
        else {
            gw[i].push_back(make_pair(a, (i + 1) % M));
            gw[i].push_back(make_pair(b, (i * i + 1) % M));
            g[i].push_back((i + 1) % M);
            g[i].push_back((i * i + 1) % M);
        }
    }
    cout << dk(x, y, g, [gw](int v, int i) {return gw[v][i].first; });
    return 0;
}

//int dk(int s, int y, const vector<vector<pair<int, int>>>& g) {
//    const int INF = 100000;
//
//    vector<long> d(g.size(), INF);
//    d[s] = 0;
//    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//    q.push(make_pair(0, s));
//    while (!q.empty()) {
//        long  len = q.top().first;
//        int v = q.top().second;
//        q.pop();
//        if (len > d[v])  continue;
//
//        for (auto i : g[v]) {
//            int to = i.second;
//            long length = i.first;
//            if (d[to] > d[v] + length) {
//                d[to] = d[v] + length;
//                q.push(make_pair(d[to], to));
//            }
//            if (v == y)
//                return d[y];
//        }
//    }
//    return d[y];
//}