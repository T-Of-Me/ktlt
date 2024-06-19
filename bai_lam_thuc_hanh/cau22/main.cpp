// 22. Thực hiện các thao tác trên cây nhị phân tìm kiếm. Chèn, Xóa, Duyệt cây

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
typedef Node *tree;
void Init(tree *t)
{
    *t = NULL;
}

Node *creatNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}
// trái nhỏ phải to   // L N R

void InsertNode(tree *t, int x)
{
    if (*t == NULL)
    {
        *t = creatNode(x);
    }
    else
    {
        Node *p = *t;
        Node *parent = NULL;
        while (p != NULL && p->data != x)
        {
            parent = p;
            if (p->data > x)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (p == NULL) //  vị trí cần chèn
        {
            p = creatNode(x);
            if (parent->data > x)
            {
                parent->left = p;
            }
            else
            {
                parent->right = p;
            }
        }
    }
}
void DeleteNode(tree *t, int x)
{
    if (t != NULL)
    {
        Node *p = *t;
        Node *parent = NULL;
        while (p != NULL && p->data != x)
        {
            parent = p;
            if (x < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (p != NULL) // đã tìm thấy node để xóa
        {
            // trái nhất trên cây con phải
            if (p->left != NULL && p->right != NULL)
            {
                Node *dele = p->right;
                while (dele->left != NULL)
                {
                    parent = dele;
                    dele = dele->left;
                }
                p->data = dele->data; // lấy giá trị của dele
                p = dele;
            }
            // sau đó thực hiện xóa dele

            // nếu là node không lá
            if (p->left == NULL && p->right == NULL)
            {
                if (parent->data > x) // vậy node cần tìm sẽ ở bên trái
                {
                    parent->left = NULL;
                }
                else // không thì sẽ ở bên phải
                {
                    parent->right = NULL;
                }
                delete (p);
            }
            else if (p->left != NULL || p->right != NULL)
            {
                if (p->left != NULL)
                {
                    if (parent->data > p->data) // Node cần xóa ở bên trái
                    {
                        parent->left = p->left;
                    }
                    else
                    {
                        parent->right = p->left;
                    }
                }
                else
                {
                    if (parent->data > p->data)
                    {
                        parent->left = p->right;
                    }
                    else
                    {
                        parent->right = p->left;
                    }
                }
                delete (p);
            }
        }
    }
}
void LNR(tree t)
{
    if (t != NULL)
    {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}
int main()
{
    tree tree;
    Init(&tree);
    ifstream file("input.txt");
    int value;
    while (file >> value)
    {
        InsertNode(&tree, value);
    }
    DeleteNode(&tree, 7);
    LNR(tree);
}
