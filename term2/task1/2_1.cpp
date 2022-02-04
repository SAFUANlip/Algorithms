#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int  n = 0, ma = 0, mb = 0, ma1 = 0;
    cin >> n;
    int *a = new int [n];
    int *b = new int [n];

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    for(int i = 1; i < n; ++i)
    {
        if(a[i] + b[i] > a[ma] + b[mb])
        {
            ma = i; mb = i;
        }
        if(a[ma1] + b[i] > a[ma] + b[mb])
        {
            ma = ma1; mb = i;
        }
        if(a[i] > a[ma1]) ma1 = i;
    }
    cout << ma << " " <<mb<<endl;
    delete []a;
    delete []b;
    return 0;
}
