#include <iostream>
#include <vector>
#include <algorithm>

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
    Set(size_t n) : sets(n), rank(n,1){
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
    int N, R;
    cin >> N >> R;

    //т.к минимальный вес будет от вершины с наименьшим значением, то нам нужно добавить не все рёбра,
    //а только связывающие минимальную верщину со всеми остальными
    int ind_min = 0; //индекс вершины с минимальным весом (числом)
    vector<ull> vert(N); //веса, соответствующие вершинам
    for (int i = 0; i < vert.size(); ++i) {
        cin >> vert[i];
        if (vert[i] < vert[ind_min])
            ind_min = i;
    }

    DirectedListGraph G;
    for (int i = 0; i < vert.size(); ++i)
        if (i != ind_min)
            G.AddEdge(Edge(ind_min, i, vert[ind_min] + vert[i]));

    for (int i = 0; i < R; ++i)
    {
        ull cost;
        Vertex from, to;
        cin >> from >> to >> cost;
        G.AddEdge(Edge(from-1, to-1, cost));
    }


    //Сам алгоритм по нахождению минимального остовного дерева
    ull min_cost = 0;
    G.edge_sort();          // сортируем ребра
    Set my_set(N);   //создаем множества для вершин
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

