#include <iostream>
#include <vector>
#include <algorithm>
//Kruskal
using namespace std;
using Vertex = size_t;
typedef unsigned long long ull;

class Edge {
public:
    Vertex from;
    Vertex to;
    ull cost;
    Edge(Vertex _from, Vertex _to, ull _cost)
        : from{ _from }, to{ _to }, cost{ _cost } {}
};
constexpr bool operator< (const Edge& lft, const Edge& rht) { return lft.cost < rht.cost; } //перегрузка для работы сортировки


//взвешен. граф на основе списка ребер
class DirectedListGraph
{
    std::vector<Edge> edges;
public:
    void AddEdge(const Edge& e)
    {
        edges.push_back(e);
    }

    const vector<Edge> Get_edges() const { return edges; }

    size_t size() const
    {
        return edges.size();
    }

    void edge_sort()
    {
        sort(edges.begin(), edges.end());
    }
};

class Set {
public:
    Set(size_t n) : sets(n), rank(n, 1) {
        for (size_t i = 0; i < n; ++i)
            sets[i] = i;
    }

    bool IsOneSet(size_t x, size_t y) { return Get_Parent(x) == Get_Parent(y); }
    void Union(size_t x, size_t y)
    {
        x = Get_Parent(x);
        y = Get_Parent(y);

        if (rank[x] < rank[y]) swap(x, y); //выбираем множество с меньшим количеством элементов
        sets[y] = x;
        //пересчет количества элеметнов во множестве
        rank[x] += rank[y];
        rank[y] = 0;
    }

private:
    vector<size_t> sets; //множества вершин
    vector<size_t> rank; //кол-во элементов в ioм множестве
    size_t Get_Parent(size_t v)
    {
        if (sets[v] == v) return v; //Если номер вершины не совпадает с её первоначальным множеством, то ищем вершину,
        //чей номер совпадает с номером множества, при этом переномеруем вершины потому что после слияния остались вершины, которые как бы ещё в другом множестве
        else return sets[v] = Get_Parent(sets[v]);
    }
};

int main()
{

	
	int m,n,s,f,w;
	cin >> n >> m;

    DirectedListGraph G;
    for (int i = 0; i < m; ++i)
    {
        ull cost;
        Vertex from, to;
        cin >> from >> to >> cost;
        G.AddEdge(Edge(from - 1, to - 1, cost));
    }

    //Сам алгоритм по нахождению минимального остовного дерева
    ull min_cost = 0;
    G.edge_sort();          // сортируем ребра
    Set my_set(n);   //создаем множества для вершин
    vector<Edge> edges = G.Get_edges();
    for (Edge e : edges)
    {
        if (!my_set.IsOneSet(e.from, e.to))
        {
            min_cost += e.cost;
            my_set.Union(e.from, e.to);
        }
    }

    cout << min_cost;
	return 0;
}

/*
* //Эта реализация в 3 раза медленнее
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int Kruskal(vector<tuple<int, int, int>>& ed, int n) {
    int sum = 0;
    sort(ed.begin(), ed.end());  //Чтобы брать самые лёгкие рёбра
    vector<int> comp(n);         //каждая вершина изначально принадлежит разным компонентам свзяности
    for (int i = 0; i < n; ++i)
        comp[i] = i;
    for (auto e : ed) {
        if (comp[get<1>(e)] != comp[get<2>(e)]) {  //Если вершины в разных компонентах
            sum += get<0>(e);
            int old = comp[get<2>(e)];
            int ne = comp[get<1>(e)];
            for (int i = 0; i < n; ++i) //после добавления вершины привязываем вершины к одной из двух компонент связности
                if (comp[i] == old)
                    comp[i] = ne;
        }
    }

    return sum;
}

int main()
{
    int m,n,s,f,w;
    cin >> n >> m;

    vector<tuple<int, int, int>> ed; // вес - вершина 1 - вершина 2
    for (int i = 0; i < m; ++i) {
        cin >> s >> f >> w;
        ed.push_back(make_tuple(w, s-1, f-1));
    }

    cout << Kruskal(ed, n);
    return 0;
}
*/