// 17.Viết chương trình tính giá trị của một biểu thức hậu tố

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
    string data;
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

int Push(Stack *s, string data)
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

int Pop(Stack *s, string *data)
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
    string data;
    ifstream file("input.txt");
    ofstream fileOut("output.txt");
    while (file >> data)
    {
        if (data != "*" && data != "/" && data != "+" && data != "-")
        {
            Push(&s, data);
        }
        else if (data == "*")
        {
            string a = s->data;
            Pop(&s, &data);
            string b = s->data;
            Pop(&s, &data);
            int A = stoi(a);
            int B = stoi(b);
            int KQ = B * A;
            string kq = to_string(KQ);
            Push(&s, kq);
        }
        else if (data == "/")
        {
            string a = s->data;
            Pop(&s, &data);
            string b = s->data;
            Pop(&s, &data);
            int A = stoi(a);
            int B = stoi(b);
            int KQ = B / A;
            string kq = to_string(KQ);
            Push(&s, kq);
        }
        else if (data == "+")
        {
            string a = s->data;
            Pop(&s, &data);
            string b = s->data;
            Pop(&s, &data);
            int A = stoi(a);
            int B = stoi(b);
            int KQ = B + A;
            string kq = to_string(KQ);
            Push(&s, kq);
        }
        else
        {
            string a = s->data;
            Pop(&s, &data);
            string b = s->data;
            Pop(&s, &data);
            int A = stoi(a);
            int B = stoi(b);
            int KQ = B - A;
            string kq = to_string(KQ);
            Push(&s, kq);
        }
    }
    cout << s->data;
    file.close();
    fileOut.close();
}