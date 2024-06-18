// Cài đặt các thao tác với stack. (sử dụng danh sách liên kết kép)
// Minh họa thông qua dữ liệu nhập từ file.

// 11.Cài đặt các thao tác với stack. (sử dụng danh sách liên kết đơn)
// Minh họa thông qua dữ liệu nhập từ file.

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
struct Stack
{
    Node *head;
    Node *tail;
};

void InitStack(Stack &s)
{
    s.head = NULL;
    s.tail = NULL;
}

int IsEmpty(Stack s)
{
    if (s.head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Push(Stack &S, int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    if (S.head == NULL)
    {
        S.head = NewNode;
    }
    else
    {
        NewNode->next = S.head;
        // (*s)->prev = NewNode;
        S.head = NewNode;
    }
    return 1;
}

int Pop(Stack &s, int *data)
{
    if (IsEmpty(s) == 1)
    {
        return 0;
    }
    else
    {
        *data = s.head->data;
        s.head = s.head->next;
        return 1;
    }
}

int main()
{
    Stack s;
    InitStack(s);
    int data;
    ifstream file("input.txt");
    ofstream fileOut("output.txt");
    while (file >> data)
    {
        Push(s, data);
    }
    while (IsEmpty(s) == 0)
    {
        if (Pop(s, &data) == 0)
        {
            cout << "nunu" << endl;
        }
        else
        {
            fileOut << data << " ";
            cout << data << " ";
        }
    }
    file.close();
    fileOut.close();
}