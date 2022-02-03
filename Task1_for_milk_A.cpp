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
//7 11 3 1 5
//0 1 20
//0 6 8
//0 5 30
//5 4 40
//4 6 7
//4 3 11
//6 3 10
//6 2 4
//3 2 2
//1 6 1
//1 2 15

//void bfs_way(const vector<vector<int>>& g, int ver, vector<int>& distance)
//{
//    queue<int> q;
//    distance[ver] = 0;
//    q.push(ver);
//    vector<bool> visited(g.size());
//    visited[ver] = true;
//
//    while (!q.empty()) {
//        for (auto v : g[q.front()]) {
//            if (!visited[v]) {
//                q.push(v);
//                visited[v] = true;
//                distance[v] = distance[q.front()] + 1;
//            }
//        }
//        q.pop();
//    }
//}
//
//int main()
//{
//    int n, k, Leon, Matilda, milk, min;
//    min = -1;
//    cin >> n >> k >> Leon >> Matilda >> milk;
//
//    vector<vector<int>> g(n);
//
//    for (int i = 0; i < k; ++i)
//    {
//        int f, s;
//        cin >> f >> s;
//        g[f - 1].push_back(s - 1);
//        g[s - 1].push_back(f - 1);
//    }
//
//    vector<int> first(g.size());
//    vector<int> second(g.size());
//    vector<int> third(g.size());
//
//    bfs_way(g, Leon - 1, first);
//    bfs_way(g, Matilda - 1, second);
//    bfs_way(g, milk - 1, third);
//
//    for (int i = 0; i < g.size(); ++i)
//        if (first[i] + second[i] + third[i] < min || min == -1)
//            min = first[i] + second[i] + third[i];
//    cout << min;
//
//    return 0;
//}
