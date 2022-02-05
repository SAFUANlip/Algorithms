#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Порядковая статистка

int pivot(const int *vec, int left, int right)
{
    //return leftt + rand() % (rightt - leftt); //выбираем опорный элмент
    //return leftt;
    int m = (left + right) / 2;

    if (vec[left] >= vec[m] && vec[m] >= vec[right])
        return m;
    else if (vec[right] >= vec[m] && vec[m] >= vec[left])
        return m;
    else if (vec[right] >= vec[left] && vec[left] >= vec[m])
        return left;
    else if (vec[m] >= vec[left] && vec[left] >= vec[right])
        return left;
    else if (vec[m] >= vec[right] && vec[right] >= vec[left])
        return right;
    else if (vec[left] >= vec[right] && vec[right] >= vec[m])
        return right;
    return m;
}

int par_tition(int* a, int i, int j)
{
    swap(a[j], a[pivot(a, i, j)]);
    for (int k = i; k < j; ++k)
        if (a[k] <= a[j])
            swap(a[i++], a[k]);
    swap(a[i], a[j]);
    return i;
}

int stat(int* a, int na, int k)
{
    for (int i = 0, j = na - 1; i < j;)
    {
        int p = par_tition(a, i, j);
        if (p < k)
            i = p + 1;
        else if (p > k)
            j = p - 1;
        else
            return a[p];
    }
    return a[k];
}

int main()
{
    srand(unsigned(time(0))); //Вот почему то рандом зарешал
    int n,k,a;
    cin >> n >> k;
    vector<int> all;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        all.push_back(a);
    }
    cout << stat(all.data(), all.size(), k);
    //cout << endl;
    //cout << find_position(all, k);
    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //    cout << all[i]<<" ";
    return 0;
}
