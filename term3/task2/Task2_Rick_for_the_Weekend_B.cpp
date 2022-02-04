#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int k, s, f, si, fi, pi;
    long N, M;
    cin >> N >> M >> k >> s >> f;
    vector<vector<pair<int, int>>> g(N);
    for (long i = 0; i < M; ++i)
    {
        cin >> si >> fi >> pi;
        //g[si-1].push_back(make_pair(pi, fi-1));
        g[si].push_back(make_pair(pi, fi));
    }
    vector<long> dis(N, 1000000);
    dis[s] = 0;
    vector<long> vis(N, 10000);
    vis[s] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < g.size(); ++j)
            for (auto z : g[j])
                if (dis[z.second] > dis[j] + z.first && vis[j] != i) {
                    dis[z.second] = dis[j] + z.first;
                    vis[z.second] = i;
                }
    }
    if (dis[f] < 1000000)
        cout << dis[f];
    else
        cout << -1;

    return 0;
}