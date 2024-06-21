// 13.Viết chương trình đổi số nguyên không âm sang số nhị phân sử dụng Stack
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};
typedef Node *Stack;
void Init(Stack *s)
{
    *s = NULL;
}

int IsEmpty(Stack s)
{
    if (s == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Push(Stack *s, int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    if (s == NULL)
    {
        *s = NewNode;
    }
    else
    {
        NewNode->next = *s;
        *s = NewNode;
    }
    return 1;
}

int Pop(Stack *s, int *data)
{
    if (IsEmpty(*s) == 1)
    {
        return 0;
    }
    else
    {
        Node *temp = *s;
        *data = (*s)->data;
        *s = temp->next;
        delete temp;
        return 1;
    }
}

int main()
{
    cout << "nhap so  :";
    int so;
    cin >> so;
    if (so < 0)
    {
        return 0 ;
    }
    Stack s;
    Init(&s);
    bool check = false;
    while (check == false)
    {
        int r = so % 16;
        Push(&s, r);
        so = so / 16;
        if (so < 16)
        {
            check = true;
        }
    }
    // cout << so << endl;
    Push(&s, so);
    int data;
    while (IsEmpty(s) == 0)
    {
        if (Pop(&s, &data) == 0)
        {
            cout << "nunu" << endl;
        }
        else
        {
            cout << data << " ";
        }
    }
}

// mệt vl