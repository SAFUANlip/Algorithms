#include<iostream>
using namespace std;
int main()
{
    int n = 0, m = 0, first, last, mid = 0;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];

    for(int i = 0; i < m; ++i)
    {
        if(a[n-1] < b[i]) cout<<n<<" ";
        else if(a[0] >= b[i]) cout<<0<<" ";
        else{
            first = 0; last = n;
            while(first < last)
            {
                mid = (first + last) / 2;
                if(b[i] <= a[mid]) last = mid;
                else first = mid + 1;
            }
            cout<<first<<" ";
        }
    }
    return 0;
}
