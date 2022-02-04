#include <iostream>
#include <string>
#include <stack>
using namespace std;


void sk(const string &a, const string &b)
{
    stack<char> st;
    size_t j = 0;

    for(size_t i = 0 ; i < a.size(); ++i)
    {
        st.push(a[i]);
        while( (!st.empty()) && (st.top() == b[j])  )
        {
            st.pop();
            ++j;
        }
    }
    if(st.empty()) cout << "YES";
    else cout << "NO";
}

int main()
{
    string a, b;
    cin >> a >> b;
    sk(a, b);
    return 0;
}
