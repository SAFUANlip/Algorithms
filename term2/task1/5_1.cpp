#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_close(char a)
{
    return (a == ')' || a == '}'  || a == ']');
}

char mirror(char a)
{
    switch (a) {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    }
}
void sk(const string &s)
{
    stack<char> st;
    string rez = s;

    for(size_t i = 0; i < s.size(); ++i)
    {
        if(is_close(s[i])){
            if(st.empty()){
                rez = mirror(s[i]) + rez;
            }
            else if(mirror(s[i]) == st.top())
                st.pop();
            else{
                cout<<"IMPOSSIBLE";
                return;
            }
        }
        else{
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        rez = rez + mirror(st.top());
        st.pop();
    }

    cout << rez;
}

int main()
{
    string s;
    cin >> s;
    sk(s);
    return 0;
}
