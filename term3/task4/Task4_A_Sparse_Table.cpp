#include <iostream>
#include <vector>
#include <cmath>

//https://contest.yandex.ru/contest/20268/problems/

using namespace std;

/* по горизонтали k, по вертикали i
 * [k][i]
 *  -> k
 * i
 */

class Sparse_Table {
public:

    Sparse_Table(const vector<int>& v) : ST(int(log2(v.size())) + 1)
        //составляем таблицу
    {
        for (int i = 0; i < v.size(); ++i)
            ST[0].push_back(make_pair(v[i], i));
        for (int k = 1; k < int(log2(v.size())) + 1; ++k)
            for (int i = 0; i < v.size() - pow(2, k) + 1; ++i)
                ST[k].push_back(min(ST[k - 1][i], ST[k - 1][i + pow(2, k - 1)]));
    }

    int Get_RMQ(int l, int r)
        // находим минимум на отрезке [l;r]
    {
        int k = int(log2(r - l + 1));
        return (min(ST[k][l], ST[k][r - pow(2, k) + 1])).first;
    }

    int Get_index_RMQ(int l, int r)
    {
        int k = int(log2(r - l + 1));
        return (min(ST[k][l], ST[k][r - pow(2, k) + 1])).second;
    }

    int Get_second_RMQ(int l, int r)
        //Ищем индекс минимума, а второй минимум ищем слева и справа от первого
    {
        int ind_min = Get_index_RMQ(l, r);
        if (ind_min == 0 || ind_min == l)
            return Get_RMQ(ind_min + 1, r);
        else if (ind_min == ST[0].size() - 1 || ind_min == r)
            return Get_RMQ(l, ind_min - 1);
        else
            return min(Get_RMQ(l, ind_min - 1), Get_RMQ(ind_min + 1, r));
    }

private:
    vector<vector<pair<int, int>>> ST;

};


int main()
{
    int size, N;
    cin >> size >> N;
    vector<int> a(size);
    for (auto& i : a)
        cin >> i;
    Sparse_Table S(a);
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        cout << S.Get_second_RMQ(l - 1, r - 1) << endl;
    }

    return 0;
}
