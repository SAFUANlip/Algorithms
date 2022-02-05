#include <functional>
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class bintree
{
    struct Node
    {
        T d;
        Node* l, * r, * p;
    };

public:
    bintree(): root(0) {};

    bintree(initializer_list<T> list){
        for (auto e : list) {
            insert(e);
        }
    }
    bintree(const bintree& m){
        for (auto e : m) {
            insert(e);
        }
    };

    bintree& operator=(const bintree& m) {
        delete_tree(root);

        for (auto e : m) {
            insert(e);
        }
    }

    ~bintree()
    {
        delete_tree(root);
    }

    void clear()
    {
        delete_tree(root);
    }

    bool empty() const //Проверка на пустоту
    {
        return(root == 0);
    }

    void insert(const T& val) //Делаем так чтобы было проще понимать что делает программа (удобство для пользователя)
    {
        insert_tree(root, val, 0);
    }

    void remove(const T& val) //удвление элемента по значению
    {
        delete_from_tree(root, val);
    }

    void bfs() const
    {
        BFS(root);
    }

    void preorder() const
    {
        preorder(root);
    }

    void inorder() const
    {
        inorder(root);
    }

    void postorder() const
    {
        postorder(root);
    }

private:
    Node* root = 0;

    void preorder(Node* n) const{
        if (!n) return;
        cout << n->d << " ";
        preorder(n->l);
        preorder(n->r);
    }

    void inorder(Node* n) const{
        if (!n) return;
        inorder(n->l);
        cout << n->d << " ";
        inorder(n->r);
    }

    void postorder(Node* n) const{
        if (!n) return;
        postorder(n->l);
        postorder(n->r);
        cout << n->d << " ";
    }

    void BFS(Node* root) const {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->d << " ";
            if (node->l)
                q.push(node->l);
            if (node->r)
                q.push(node->r);
        }
    }

    void delete_tree(Node*& node) {
        if (!node) return;
        delete_tree(node->l); delete_tree(node->r);
        delete node;
        node = nullptr;
    }

    void insert_tree(Node*& n, T v, Node* p = 0)
    {
        if (n == 0)
            n = new Node{ v,0,0,p };
        else if (v < n->d)
            insert_tree(n->l, v, n); //если значение меньше родителя, то суём его влево
        else if (n->d < v) //эта проверка, чтобы не было копий
            insert_tree(n->r, v, n); //если значение больше родителя, то суём его вправо
    }

    void delete_from_tree(Node*& n, const T& v)
    {
        if (n == 0)
            return;
        if (v < n->d)
            delete_from_tree(n->l, v);
        else if (v > n->d)
            delete_from_tree(n->r, v);
        else if (n->l == 0 && n->r == 0)
        {
            if (n->p->d > n->d)
                n->p->l = nullptr;
            else
                n->p->r = nullptr;
            delete n;
        }
        else if (n->l == 0 && n->l !=0)
        {
            Node* x = n;
            if (x)
                n->r->p = n->p;
            delete n;
            n = x;
        }
        else if (n->r == 0 && n->l !=0)
        {
            Node* x = n;
            n->l->p = n->p;
            delete n;
            n = x;
        }
        else
        {
            Node* x = n->l;
            while (x->r)
                x = x->r;
            n->d = x->d;

            (x->p->r == x ? x->p->r : x->p->l) = x->l;
            if (x->l)
                x->l->p = x->p;

            Node* p = x->p;

            delete x;
        }
    }
};

int main() {
    bintree<int> tree;
    int n,a;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        tree.insert(a);
    }
    //tree.remove(6);

    tree.postorder();
    return 0;
}
