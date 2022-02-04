#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <fstream>

using namespace std;

vector<int> dk(int s, const vector<vector<pair<int, int>>>& g) {
    const int INF = 100000;

    vector<int> d(g.size(), INF);
    d[s] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        long  len = q.top().first;
        int v = q.top().second;
        q.pop();
        if (len > d[v])  continue;

        for (auto i : g[v]) {
            int to = i.second;
            long length = i.first;
            if (d[to] > d[v] + length) {
                d[to] = d[v] + length;
                q.push(make_pair(d[to], to));
            }
        }
    }
    return d;
}

int main()
{
    int n, k, Leon, Matilda, milk, min;
    min = -1;
    ifstream read("D:/Prog/Task1_for_milk_A/test.txt");
    if (read.is_open()) {
        read >> n >> k >> Leon >> Matilda >> milk;

        vector<vector<pair<int, int>>> g(n);

        for (int i = 0; i < k; ++i)
        {
            int f, s, weight;
            read >> f >> s >> weight;
            g[f].push_back(make_pair(weight, s));
            g[s].push_back(make_pair(weight, f));
        }

        read.close();

        vector<int> first = dk(Matilda, g);
        vector<int> second = dk(Leon, g);
        vector<int> third = dk(milk, g);

        for (int i = 0; i < g.size(); ++i)
            if (first[i] + second[i] + third[i] < min || min == -1)
                min = first[i] + second[i] + third[i];
        cout << min;
    }
    return 0;
}
