#include <iostream>
#include <stack>
using namespace std;
//очередь с помощью стека


class mqueuestack
{
public:
    mqueuestack() : out(), in() {}

    bool empty()
    {
        return (out.empty() && in.empty());
    }
   
    const int& front()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return (out.top());
    }

    void pop_front()
    {
        if (this->empty())
            return;
        else if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        out.pop();
    }

    void push_back(const int& val)
    {
        if (out.empty() && !in.empty())
        {
            while (!in.empty())
            {
                int a;
                a = in.top();
                out.push(a);
                in.pop();
            }
        }
        in.push(val);
    }

private:
    stack<int> out;
    stack<int> in;
};



int main()
{
    //bool flag = true;
    int n;
    bool flag = true;
    int a, b;
    cin >> n;
    mqueuestack q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (a == 3)
            q.push_back(b);
        else
        {
            if (q.empty())
            {
                if (b != -1)
                    flag = false;
            }
            else if (q.front() == b)
                q.pop_front();
            else
                flag = false;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
