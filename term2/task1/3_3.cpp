#include<iostream>
using namespace std;
int main()
{
    int n = 0, m = 0, first = 0, last, mid = 0;
    cin >> n >> m;
    int *a = new int[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int *b = new int[m];
    for(int i = 0; i < m; ++i)
        cin >> b[i];

    for(int i = 0; i < m; ++i)
    {
        if((b[i] >= a[0])&&(b[i] <= a[n-1])){
            last = n - 1;
            while(first < last)
            {
                mid = (first + last) / 2;
                if(a[mid]>=b[i]) last = mid;
                else first = mid + 1;
            }
            if(a[first] == b[i]) cout<<b[i]<<" ";
        }
     }
     delete []a;
     delete []b;
    return 0;
}
