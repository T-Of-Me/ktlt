// 11.Cài đặt các thao tác với stack. (sử dụng danh sách liên kết đơn)
// Minh họa thông qua dữ liệu nhập từ file.

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
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
    Stack s;
    Init(&s);
    int data;
    ifstream file("input.txt");
    ofstream fileOut("output.txt");
    while (file >> data)
    {
        Push(&s, data);
    }
    while (IsEmpty(s) == 0)
    {
        if (Pop(&s, &data) == 0)
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