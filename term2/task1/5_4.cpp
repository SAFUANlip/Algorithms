#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct oper
{
    char a;
    int prior;

    oper(char val)
    {
        if (val == '+' || val == '-')
            prior = 1;
        else if (val == '*' || val == '/')
            prior = 3;
        else if (val == '%')
            prior = 2;
        else
            prior = -1;
        a = val;
    }
};

int main()
{
    stack<int> numbers;
    stack<oper> arg;
    string exp;
    cin >> exp;
   
    for (int i = 0; i < exp.size(); ++i)
    {
        string buf ="";
        if (('0' <= exp[i]) && (exp[i] <= '9')) {
            while (('0' <= exp[i]) && (exp[i] <= '9') && (i < exp.size()))
            {
                buf += exp[i];
                ++i;
            }
            --i;
            numbers.push(stoi(buf));
        }

        else
        {
            oper val = oper(exp[i]);
            if ((arg.empty()) || (arg.top().prior < val.prior) || (val.a == '(') || (val.a =='<') || (val.a=='['))
                arg.push(val);
            else
            {
                while(!(arg.empty()) && (arg.top().prior >= val.prior) && (arg.top().prior != -1)) {
                    int a = numbers.top();
                    numbers.pop();
                    int b = numbers.top();
                    numbers.pop();

                    switch (arg.top().a)
                    {
                    case '+':
                        b += a;
                        break;
                    case'-':
                        b -= a;
                        break;
                    case'*':
                        b *= a;
                        break;
                    case'/':
                        b /= a;
                        break;
                    case'%':
                        b %= a;
                        break;
                    }
                    arg.pop();
                    numbers.push(b);
                }
                if ((!arg.empty()) && (((arg.top().a == '(') && (val.a == ')')) || ((arg.top().a == '[') && (val.a == ']')) || ((arg.top().a == '<') && (val.a == '>'))))
                    arg.pop();
                else
                    arg.push(val);
            }
        } 
    }

    while (!(arg.empty())) {
        int a = numbers.top();
        numbers.pop();
        int b = numbers.top();
        numbers.pop();
        switch (arg.top().a)
        {
        case '+':
            b += a;
            break;
        case'-':
            b -= a;
            break;
        case'*':
            b *= a;
            break;
        case'/':
            b /= a;
            break;
        case'%':
            b %= a;
            break;
        }
        arg.pop();
        numbers.push(b);
    }
    cout << int(numbers.top());
    return 0;
}
