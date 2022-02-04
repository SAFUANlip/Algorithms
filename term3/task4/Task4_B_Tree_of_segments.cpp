#include <iostream>
#include <vector>
using namespace std;

class Tree
{
public:
    Tree(vector<int>& vec, bool flag) : tree(vec.size() * 4) {
        build_max(vec, 0, vec.size() - 1, 1);
    }

    int size() {
        return tree.size();
    }

    int max_segment(int l, int r) {
        return max_s(l, r, 0, tree.size() / 4 - 1, 1);
    }


    void update_max(int left, int right, int increase) { //it update on segment
        update_m(left, right, 0, tree.size() / 4 - 1, increase, 1);
    }

private:
    vector<pair<int, int>> tree;

    void build_max(vector<int>& vec, int left, int right, int v) {
        if (left == right)
            tree[v].first = vec[right];
        else {
            int middle = (left + right) / 2;
            build_max(vec, left, middle, v * 2);
            build_max(vec, middle + 1, right, v * 2 + 1);
            tree[v].first = max(tree[v * 2].first, tree[v * 2 + 1].first);
        }
    }


    int max_s(int left, int right, int l_border, int r_border, int v) {
        if (left > right)
            return 0;
        else if (left == l_border && right == r_border)
            return tree[v].first + tree[v].second;
        //int middle = (l_border + r_border) / 2;
        int middle = l_border + (r_border - l_border) / 2;
        return max(max_s(left, min(right, middle), l_border, middle, 2 * v), max_s(max(middle + 1, left), right, middle + 1, r_border, 2 * v + 1)) + tree[v].second;
    }

    void update_m(int left, int right, int l_border, int r_border, int increase, int v) {
        if (left > right)
            return;
        else if (left == l_border && right == r_border) {
            tree[v].second += increase;
            return;
        }
        else {
            //int middle = (l_border + r_border) / 2;
            int middle = l_border + (r_border - l_border) / 2;
            update_m(left, min(right, middle), l_border, middle, increase, v * 2);
            update_m(max(middle + 1, left), right, middle + 1, r_border, increase, v * 2 + 1);
            tree[v].first = max(tree[v * 2].first + tree[v * 2].second, tree[v * 2 + 1].first + tree[v * 2 + 1].second);
        }
    }
};


int main()
{
    int n, max, count, s, t, tic;
    cin >> n;
    vector<int> a(n - 1);
    for (auto& i : a)
        cin >> i;
    cin >> max >> count;
    Tree tr(a, false);
    for (int i = 0; i < count; ++i) {
        cin >> s >> t >> tic;
        if (tr.max_segment(s, t - 1) + tic <= max)
            tr.update_max(s, t - 1, tic);
        else
            cout << i << " ";
    }
    return 0;
}