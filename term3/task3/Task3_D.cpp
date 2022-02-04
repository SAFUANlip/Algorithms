#include <iostream>
#include <vector>

using namespace std;
//Про левые и правые части тут https://www.youtube.com/watch?v=wwar25AoPhQ 
//Алгоритм Kuna для поиска максимального паросочетания в двудольном графе(возможно не только в двудольном, но это не точно)
//1 двудольность - добивается с помощью разметки поля на шахматноую доску, пусть нечётная клетка это правая группа вершин (чёрная), а чётная - это
//левая группа вершин (белая) из них мы можем ходить только в чёрные (отсюда двудольность), 


int n, m;
vector<int> p; //

bool dfs(int v, const vector<vector<int>> &g, vector<bool> &visited, vector<bool> &free)
{
    if (visited[v]) return false;
    visited[v] = true;
    for (auto to : g[v]) {
        //если p[to] == -1 значит из чёрной вершины нет ребра и она свободна. + проверка дальше по dfs, по сути мы проскакиваем чёрную вершину и dfs по белой
        if (p[to] == -1 || dfs(p[to], g, visited, free)) { 
            p[to] = v; //инвертирование ребра (по алгоритму)
            free[v] = true; //теперь эта вершина несвободная
            return true;
        }
    }
    return false;
}

void Kuna(const vector<vector<int>>& g)
{
    vector<bool> visited(n * m); //вектор посещений для dfs
    vector<bool> free(n * m); //вектор свободных вершин
    p.assign(n * m, -1); //заменит все элементы вектора на -1 
    bool is = true;
    while (is) { //Пока есть путь, начинающийся с вершины, не занятой паросочетанием и заканчивающийся на такой же вершине, то мы продолжаем искать максимальный
        is = false;
        visited.assign(n * m, false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!((i + j) % 2) && !(free[i * m + j]) && dfs((i * m + j), g, visited, free)) is = true;
        //по алгоритму dfs запускаем только от белых свободных вершин
        //(свободные - которые не связаны с ребром, ведущим из чёрных вершин)
    }
}


int main()
{
    char s[102][102]; //Пределы поля из условия
    int a, b, count, em;
    count = 0;
    cin >> n >> m >> a >> b;
    //построчный ввод точек и звёздочек
    for (int i = 0; i < n; i++)
        cin >> s[i];

    //список смежности для рёбер
    vector<vector<int>> g;
    g.resize(n * m);

    em = 0;  //количество пустых клеток

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.') continue;
            em++;
            if ((i + j) % 2) continue;
            int u = i * m + j; //номер вершины графа

            //слева
            if (j && (s[i][j - 1] == '*')) g[u].push_back(u - 1); //если это не левая граница, и слева ничего можно поставить ячейку, то у вершины u есть ребро

            // справа
            if ((j < m - 1) && (s[i][j + 1] == '*')) g[u].push_back(u + 1);

            //сверху
            if (i && (s[i - 1][j] == '*')) g[u].push_back(u - m); //семжная вершина на строку выше, поэтому -m

            //снизу
            if ((i < n - 1) && (s[i + 1][j] == '*')) g[u].push_back(u + m); //семжная вершина на строку ниже, поэтому +m
        }

    //если поставить одну ячейку стоит столько же или меньше чем двойную, то ставим одинарные.
    if (2 * b <= a)
    {
        cout << em * b;
        return 0;
    }

    Kuna(g);
    for (int i = 0; i < n * m; i++)
        if (p[i] != -1) ++count; //сколько паросочетаний

    cout << count * a + (em - 2 * count) * b;
    return 0;
}

