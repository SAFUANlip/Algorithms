#include <iostream>
#include <vector>
using namespace std;


void find(const vector<int>& arr1, const vector<int>& arr2, int& begin, int& end, int& var)
{
    if (var <= arr1[begin]) {
        cout << begin << " ";
        return;
    }
    else if (var >= arr1[end]) {
        cout << end << " ";
        return;
    }
    int first = begin; 
    int last = end;
    while (last - first > 1)
    {
        int mid = (first + last) / 2;
        if (arr1[mid] >= var) last = mid;
        else first = mid;
    }
    if (abs(var - arr1[first]) <= abs(var - arr1[last])) cout << first << " ";
    else cout << last << " ";
}


int main()
{
    int n, m, x;
    cin >> n;
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        arr1.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        arr2.push_back(x);
    }
    int first = 0, last, mid = 0;
    for (int i = 0; i < m; ++i)
    {
        if (arr2[i] <= arr1[0]) cout << 0 << " ";
        else if (arr2[i] >= arr1[n - 1]) cout << n - 1 << " ";
        else
        {
            int k = 1;
            int begin = 0, end = 1;
            while ((end <= arr1.size()-1) && !(arr2[i] <= arr1[end] && arr2[i] >= arr1[begin]))
            {
                begin = end;
                end = end + 4 * k;
                ++k;
            }
            if (!(end <= arr1.size() - 1))
                end = arr1.size() - 1;
            
            find(arr1, arr2, begin, end, arr2[i]);
        }
    }    
    return 0;
}
