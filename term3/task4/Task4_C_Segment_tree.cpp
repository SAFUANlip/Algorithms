#include <iostream>
#include <vector>
using namespace std;
//Присвоение на отрезке -> запаздывающее обновление


class Tree
{
public:
    Tree(vector<int>& vec) : tree(vec.size() * 4, make_pair(INF, INF)) {
        build_min(vec, 0, vec.size() - 1, 1);
    }

    int size() {
        return tree.size();
    }

    int min_segment(int l, int r) {
        return min_s(l, r, 0, tree.size() / 4 - 1, 1);
    }


    void update_min(int left, int right, int color) { //it update on segment
        update_m(left, right, 0, tree.size() / 4 - 1, color, 1);
    }

private:
    const int INF = 1000;
    vector<pair<int, int>> tree;

    void build_min(vector<int>& vec, int left, int right, int v) {
        if (left == right)
            tree[v].first = vec[right];
        else {
            int middle = (left + right) / 2;
            build_min(vec, left, middle, v * 2);
            build_min(vec, middle + 1, right, v * 2 + 1);
            tree[v].first = min(tree[v * 2].first, tree[v * 2 + 1].first);
        }
    }


    int min_s(int left, int right, int l_border, int r_border, int v) {
        //Здесь пуш тоже нужен, без него не работает
        push(v); //так же как в обновлении мы спускаемся по дереву, следовательно почему бы и здесь не обновлять узлы

        if (left > right)
            return INF;
        else if (left == l_border && right == r_border)
            return tree[v].first;
        int middle = (l_border + r_border) / 2;
        return min(min_s(left, min(right, middle), l_border, middle, 2 * v), min_s(max(middle + 1, left), right, middle + 1, r_border, 2 * v + 1));
    }

    void update_m(int left, int right, int l_border, int r_border, int color, int v) {
        push(v); //Когда мы спускаемся, то проверяем не нужно ли обновить узел

        if (left > right)
            return;

        else if (left == l_border && right == r_border) {
            //Если это наш отрезок, то обновляем узел и пушим, чтобы передать дочерним новый цвет
            tree[v].second = color;
            push(v);
            return;
        }
        else {
            int middle = (l_border + r_border) / 2;
            update_m(left, min(right, middle), l_border, middle, color, v * 2);
            update_m(max(middle + 1, left), right, middle + 1, r_border, color, v * 2 + 1);
            tree[v].first = min(tree[v * 2].first, tree[v * 2 + 1].first);
        }
    }

    void push(int v) {
        if (tree[v].second != INF) {
            tree[v].first = tree[v].second; //Если была новая краска, то перекрашиваем 

            //Если это не лист, то обновляем новую краску дочерних элементов
            if (v*2 < tree.size() && tree[v*2].first != INF)
                tree[v * 2].second = tree[v].second;
            if (v * 2 + 1 < tree.size() && tree[v * 2 + 1].first != INF)
                tree[v * 2 + 1].second = tree[v].second;

            tree[v].second = INF; //поставим флаг что перекраска прошла, т.е. нового цвета больше нет
        }
    }
};


int main()
{
    int n, r, g, b, k;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> r >> g >> b;
        a.push_back(r + g + b);
    }
    cin >> k;
    Tree tr(a);

    int c, d, e, f;
    for (int i = 0; i < k; ++i) {
        cin >> c >> d >> r >> g >> b >> e >> f;
        tr.update_min(c, d, r + g + b);
        cout << tr.min_segment(e, f) << endl;
    }
    return 0;
}