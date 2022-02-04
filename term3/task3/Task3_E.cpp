//Algorithm Dinica
//https://neerc.ifmo.ru/wiki/index.php?title=Файл:Слоистая_сеть.png
//+СМ лекции Pavel Mavrin
//лучше писать это в классе, слишком много аргументов передаётся в функции
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 100000000;

struct Edge {
	int from, to, cap, flow;
};

int dfs(const vector<vector<int>>& graph, vector<Edge>& edge, const vector<int>& dis, vector<int>& NDE, const int v, const int t, int f) { //f - flow
	if (v == t || f == 0) //поток равен 0, значит больше мы ничего не пртолкнём
		return f;
	for (NDE[v]; NDE[v] < graph[v].size(); ) {
		int num_e = graph[v][NDE[v]]; //номер ребра
		int u = edge[num_e].to; //куда ведёт ребро
		if (dis[u] == dis[v] + 1) { //Можем идти только по слоистой сети
			int add_flow = dfs(graph, edge, dis, NDE, u, t, min(f, edge[num_e].cap - edge[num_e].flow));
			if (add_flow) {
				
				if (!(num_e % 2)) {//если это ихсодное ребро
					edge[num_e].flow += add_flow; //увеличение потока
					edge[num_e + 1].flow -= add_flow;
				}
				else {//если это обратное ребро
					edge[num_e].flow += add_flow; //увеличение потока по обратному ребру
					edge[num_e - 1].flow -= add_flow;
				}
				return add_flow;
			}
		}
		++NDE[v]; //Если по ребру вершины v нельзя пустить ещё потока (т.е попадём в тупик), то мы сдвигаем указатель, и в следующий раз будем идти по другому ребру 
	}
	return 0;
}

bool bfs(const vector<vector<int>>& graph, const vector<Edge>& edge, vector<int> &dis, const int s, const int t) {
	//Здесь строится слоистая сеть, это вектор dis (как в лекции), число рёбер от s до других
	dis.assign(graph.size(), INF);
	queue<int> q; //для bfs
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto i : graph[v]) {
			int u = edge[i].to; //конец ребра vu
			//Если вершина ещё не посещена и текущая пропускная способность
			//позволяет пустить ещё потока, то мы добавляем вершину в слоистую сеть
			if (dis[u] == INF && edge[i].flow < edge[i].cap) {
				dis[u] = dis[v] + 1;
				q.push(u);
			}
		}
	}

	return dis[t] != INF; //Если до конечной не дошли, то это уже максимальный поток
}

int Dinic(const vector<vector<int>>& graph, vector<Edge>& edge, const int s, const int t) {
	int max_flow = 0;
	vector<int> dis(graph.size(), INF);
	while (bfs(graph, edge, dis, s, t)) { //Пока есть путь от s до t будем увеличивать поток по слоистой сети
		vector<int> NDE(edge.size(), 0); //Not deleted edges, в процессе dfs будут появляться рёбра, которые будут заполнены, их нужно будет удалять,
		//для этого будем сдвигать указатель на начало списка инцидентных вершине рёбер
		int flow = dfs(graph, edge, dis, NDE, s, t, INF);
		while (flow) {
			max_flow += flow; //Пока поток, который мы пускаем больше нуля, мы будем пытаться запустить всё больше
			flow = dfs(graph, edge, dis, NDE, s, t, INF);
		}
	}
	return max_flow;
}

void dfs_path(const vector<vector<int>>& graph, const vector<Edge>& edge, vector<int> &path, vector<bool> &visited_ed, const int v, const int t)
{
	path.push_back(v);
	if (v == t)
		return;
	for (auto i : graph[v]) {
		int u = edge[i].to;
		if (!visited_ed[i] && edge[i].flow == 1) {
			visited_ed[i] = true;
			dfs_path(graph, edge, path, visited_ed, u, t);
			break; //после одного прохода больше идти не нужно
		}
	}
}
void path(const vector<vector<int>>& graph, const vector<Edge>& edge, vector<bool>& visited_ed, const int s, const int t) {
	vector<int> path;
	dfs_path(graph, edge, path, visited_ed, s, t);
	for (auto v : path)
		cout << v + 1<<" ";
	cout << endl;
}


int main() {
	int vert_count, edge_count, s, t;
	cin >> vert_count >> edge_count >> s >> t;
	vector<vector<int>> graph(vert_count);
	vector<Edge> edge;
	for (int i = 0, si, ti; i < edge_count; ++i) {
		cin >> si >> ti;
		--si;
		--ti;
		//Когда записывается количество рёбер, мы
		//получаем индекс ребра инцидентного вершине, поэтому
		//в графе будут номера рёбер в вектрое рёбер, а не само ребро
		graph[si].push_back(edge.size());
		edge.push_back({ si, ti, 1, 0 });
		graph[ti].push_back(edge.size());
		edge.push_back({ ti, si, 0, 0 }); //Пока обратного ребра как бы нет, поэтому 0, 0
	}

	int max_flow = Dinic(graph, edge, s - 1, t - 1);
	//cout << max_flow<<endl;
	if (max_flow < 2)
		cout << "NO";
	else {
		vector<bool> visited_ed(edge.size()); //было ли посещено ребро
		cout << "YES" << endl;
		path(graph, edge, visited_ed, s-1, t-1);
		path(graph, edge, visited_ed, s-1, t-1);
	}
	return 0;
}