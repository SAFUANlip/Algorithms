#include <iostream>
#include <vector>
#include <string>

using namespace std;

//если есть цикл, то это тоже путь, т.е m[i][i] тоже может быть 1
void multip(vector<vector<int>>& m) {
    int n = m.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (m[j][i]) //если есть путь из j в i, то мы смотрим куда есть пути из i и добавляем их к путям для v
                for (int v = 0; v < n; ++v)
                    m[j][v] = m[j][v] | m[i][v];
}


int main()
{
    int n;
    string read;
    cin >> n;
    vector<vector<int>> in(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> read;
        for (int j = 0; j < n; ++j) {
            in[i][j] = read[j] - '0';
        }
    }
    cout << endl;
    multip(in);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << in[i][j];
        cout << endl;
    }
    return 0;
}

//made by SAFUANlip