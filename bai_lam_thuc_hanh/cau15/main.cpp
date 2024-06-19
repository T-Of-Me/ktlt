
// 15.Viết chương trình đảo ngược một danh sách sử dụng Stack

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

struct List
{
    int a;
    char b;
};
struct Node
{
    List data;
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

int Push(Stack *s, List data)
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

int Pop(Stack *s, List *data)
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
    List data;
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