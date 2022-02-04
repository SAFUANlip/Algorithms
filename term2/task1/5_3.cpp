#include <iostream>
#include <string>

using namespace std;

struct Rectangle{
    int height;
    int begin;
    int end;
};

class Stack{
public:
    Stack(int n) : top{-1}, Xend{0}, size{n}, Smax{0}
        { buf = new Rectangle[size]; }
    ~Stack() { delete[] buf; }

    void push(int w, int h);
    void search_Smax(int h);

    int get_Smax() { return Smax; }
    int top_height() { return buf[top].height; }

private:
    Rectangle *buf;
    int top;
    int Xend;
   int size;
    int Smax;
};

void Stack::push(int w, int h)
{
    ++top;
    buf[top].height = h;
    if(!top){
        buf[top].begin = 0;
        buf[top].end = Xend + w;
    }
    else{
        buf[top].begin = buf[top - 1].end;
        buf[top].end = buf[top - 1].end + w;
    }

    Xend += w;
}

void Stack::search_Smax(int h)
{
    while(top >= 0 && buf[top].height >= h)
    {
        int s = (Xend - buf[top].begin) * buf[top].height;
        if(s > Smax) Smax = s;
        --top;
    }
}


int main()
{
    int  width, height;
    int n;
    cin >> n;
    Stack rects(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> width >> height;
        if( height <= rects.top_height() )
            rects.search_Smax(height);

        rects.push(width, height);
    }
    rects.search_Smax(0);

    cout << rects.get_Smax();

    return 0;
}
