#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

double dk(int s, int f, const vector<vector<pair<double, int>>>& g) {
    const int INF = -1;

    vector<double> d(g.size(), INF);
    d[s] = 1;
    priority_queue < pair<double, int> > q;
    q.push(make_pair(1, s));
    while (!q.empty()) {
        double  len = q.top().first;
        int v = q.top().second;
        q.pop();
        if (len < d[v])  continue;

        for (auto i : g[v]) {
            int to = i.second;
            if (to != v) {
                double length = i.first;
                if (d[to] < d[v] * length && length >= 0) {
                    d[to] = d[v] * length;
                    q.push(make_pair(d[to], to));
                }
            }
        }
    }
    return 1-d[f];
}

int main()
{
    int N, M, s, f, si, fi, we;
    cin >> N >> M >> s >> f;
    vector<vector<pair<double, int>>> g(N);
    for (int i = 0; i < M; ++i)
    {
        cin >> si >> fi >> we;
        g[si-1].push_back(make_pair(double(100 - we)/100, fi-1));
        g[fi-1].push_back(make_pair(double(100 - we)/100, si-1));
    }
    cout<<dk(s - 1, f - 1, g);
}

