//LCA, двоичный подъём
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//пример
//		up[v][i]
//	   /
//	  /
//	 up[v][i-1]
//	/
// /  
//v

class LCA {
public:
	//Размер берём из количества вершин, а высота подъёма это на сколько в 2^ можно подняться
	LCA(const vector<vector<long long>>& t) : tree{ t }, jump_height{ int(log2(t.size() - 1)) + 1 } {
		in.assign(t.size(), 0); 
		out.assign(t.size(), 0);
		up.assign(t.size() - 1, vector<int>(jump_height + 1));
		
		build_up_dfs(0, 0);
	}

	int find_LCA(int n1, int n2) {
		if (parent(n1, n2))
			return n1;
		if (parent(n2, n1))
			return n2;
		for (int i = jump_height; i >= 0; --i)
			if (!parent(up[n1][i], n2))
				n1 = up[n1][i];

		return up[n1][0];
	}

private:
	int time = 0;
	int jump_height;
	vector<vector<long long>> tree;
	vector<int> in, out; //Время входа и выхода в вершину, нужно для проверки родителя
	vector<vector<int>> up;

	void build_up_dfs(int v, int p) {
		in[v] = time++;
		up[v][0] = p; //Прыжок в 1 ребро это переход в родителя

		for (int i = 1; i <= jump_height; ++i) {
			up[v][i] = up[up[v][i - 1]][i - 1]; //Прыжок из вершины V на 2^i это прыжок из вершины up[v][i-1] на 2^i-1
		}
		
		for (auto to : tree[v]) {
			if (to != p)
				build_up_dfs(to, v); //обход в глубину, чтобы обработать все вершины и узнать времена входа и выхода
		}

		out[v] = time++;
	}

	bool parent (int node1, int node2) {
		return (in[node1] <= in[node2] && out[node1] >= out[node2]);
	}
};



int main()
{
	int n, m, vert;
	long long v, sum;
	v = sum = 0;
	cin >> n >> m;

	vector<int> in(n + 1), out(n + 1);

	vector<vector<long long>> t(n+1);
	for (int i = 1; i < n; ++i) {
		cin >> vert;
		t[vert].push_back(i);
	}

	LCA t_lca(t);

	long long a1, a2, x, y, z;
	cin >> a1 >> a2;
	cin >> x >> y >> z;
	
	for (int i = 0; i < m; i++)
	{
	    v = t_lca.find_LCA((a1 + v) % n, a2);
	    sum += v;
	
	    a1 = (x * a1 + y * a2 + z) % n;
	    a2 = (x * a2 + y * a1 + z) % n;
	}
	cout << sum;

	return 0;
}

