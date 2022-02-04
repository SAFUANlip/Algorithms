#include <vector>
#include <iostream>
using namespace std;

void CurtainWagner(vector<vector<int>> g, vector<int>& min_cut) {
    int min_cut_weight = 10000000;
    vector<bool> merged(g.size());
    vector<vector<int>> v(g.size()); //список вершин, которые были сжаты в i-тую (сначала заполняется i, т.к. в i вершине обязательно будет она сама) 
    for (int i = 0; i < v.size(); ++i)
        v[i].push_back(i);
    for (int i = 0; i < g.size() - 1; ++i) {
        vector<bool> inA(g.size());
        vector<int> w(g.size());
        for (int j = 0, prev; j < g.size() - i; ++j) { // -i потому что на каждом шаге у нас становится на одну вершину меньше(merge)
            int vert = -1;
            for (int k = 0; k < g.size(); ++k)
                if (!merged[k] && !inA[k] && (vert == -1 || w[k] > w[vert])) //если вершина вне множества A, если она не была объеденена с другой, то берём максимальную
                    vert = k;
            if (j != g.size() - 1 - i) {
                inA[vert] = true;
                for (int l = 0; l < g.size(); ++l)
                    if (!inA[l])
                        w[l] += g[vert][l];
                prev = vert;
            }
            else {
                if (w[vert] < min_cut_weight) { //Проверка когда осталась последняя вершина, если разрез между ей и множеством A минимален, то это наш новый минимальный глобальный разрез
                    min_cut_weight = w[vert];
                    min_cut = v[vert]; //Вершины, входящие в одно из множеств при минимальном разрезе
                }
                for (int h = 0; h < g.size(); ++h)
                    g[vert][h] = g[h][vert] += g[prev][h];                      //merge prev and vert
                v[vert].insert(v[vert].end(), v[prev].begin(), v[prev].end());  //merge prev and vert
                merged[prev] = true;
            }
        }
    }
    //cout << min_cut_weight<<endl;
}


int main()
{
    int n;
    cin >> n;
    string s;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j)
            g[i][j] = s[j] - '0';
    }
    vector<int> min_cut; 
    CurtainWagner(g, min_cut);
    vector<bool> cut(g.size());
    for (auto i : min_cut) {
        cout << i+1 << " ";
        cut[i] = true;
    }
    cout << endl;
    for (int i = 0; i < g.size(); ++i)
        if (!cut[i])
            cout << i+1<<" ";
	return 0;
}
