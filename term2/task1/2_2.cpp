#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int  n = 0;
    double s = 0;
    cin >> n;
    int *x = new int [n];
    int *y = new int [n];

    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n - 1; ++i)
    {
        s += x[i]*y[i+1] - x[i+1]*y[i];
    }
    s = s + x[n-1]*y[0] - x[0]*y[n-1];
    s = abs(s)/2;
    cout << s;
    delete []x;
    delete []y;
    return 0;
}
