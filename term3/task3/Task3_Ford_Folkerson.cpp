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

int dfs(const vector<vector<int>>& graph, vector<Edge>& edge, vector<bool> &visited, const int v, const int t, int f) { //f - flow
	if (visited[v]) 
		return 0;
	visited[v] = true;
	if (v == t)
		return f;
	for (int i = 0; i < graph[v].size(); ++i) {
		int num_e = graph[v][i]; //номер ребра
		int u = edge[num_e].to; //куда ведёт ребро
		if (edge[num_e].cap > edge[num_e].flow) {
			int add_flow = dfs(graph, edge, visited, u, t, min(f, edge[num_e].cap - edge[num_e].flow));
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
	}
	return 0;
}

int Ford_Folkerson(const vector<vector<int>>& graph, vector<Edge>& edge, const int s, const int t) {
	int flow = 0;
	while (true) {
		int add;
		vector<bool> visited(graph.size());
		add = dfs(graph, edge, visited, s, t, INF);
		if (add)
			flow += add;
		else
			break;
	}
	return flow;
}

void dfs_path(const vector<vector<int>>& graph, const vector<Edge>& edge, vector<int>& path, vector<bool>& visited_ed, const int v, const int t)
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
		cout << v + 1 << " ";
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

	

	int max_flow = Ford_Folkerson(graph, edge, s - 1, t - 1);
	//cout << max_flow<<endl;
	if (max_flow < 2)
		cout << "NO";
	else {
		vector<bool> visited_ed(edge.size()); //было ли посещено ребро
		cout << "YES" << endl;
		path(graph, edge, visited_ed, s - 1, t - 1);
		path(graph, edge, visited_ed, s - 1, t - 1);
	}
	return 0;
}