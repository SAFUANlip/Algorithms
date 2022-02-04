#include<iostream>
using namespace std;
int main()
{
    int n = 0, first, last, mid = 0;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];

   
       first = 0; last = n-1;
       while(first < last)
       {
            mid = (first + last) / 2;
            if(a[mid]>a[mid+1]) last = mid;
            else first = mid + 1;
       }
       cout<<first;
   

    return 0;
}
