#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int count = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int c = i;
        while (c % 5 == 0)
        {
            ++count;
            c /=5;
        }
    }
    cout << count;
}
