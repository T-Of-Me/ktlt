//  18.Viết chương trình con kiểm tra một biểu thức được cho dưới dạng hậu tố có chuẩn
// không (thông báo lỗi nếu không chuẩn), giả sử mỗi toán hạng là 1 ký tự

#include <iostream>
#include <string>
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

int Push(Stack *s, char data)
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

int Pop(Stack *s, char *data)
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
    char data;
    ifstream file("input.txt");
    ofstream fileOut("output.txt");
    while (file >> data)
    {
        if (data != '*' && data != '/' && data != '+' && data != '-')
        {
            Push(&s, data);
        }
        else if (data == '*')
        {
            char a = s->data;
            Pop(&s, &data);
            char b = s->data;
            Pop(&s, &data);
            int A = a - 48;
            int B = b - 48;
            int KQ = B * A;
            char kq = KQ + 48;
            Push(&s, kq);
        }
        else if (data == '/')
        {
            char a = s->data;
            Pop(&s, &data);
            char b = s->data;
            Pop(&s, &data);
            int A = a - 48;
            int B = b - 48;
            int KQ = B / A;
            char kq = KQ + 48;
            Push(&s, kq);
        }
        else if (data == '+')
        {
            char a = s->data;
            Pop(&s, &data);
            char b = s->data;
            Pop(&s, &data);
            int A = a - 48;
            int B = b - 48;
            int KQ = B + A;
            char kq = KQ + 48;
            Push(&s, kq);
        }
        else
        {
            char a = s->data;
            Pop(&s, &data);
            char b = s->data;
            Pop(&s, &data);
            int A = a - 48;
            int B = b - 48;
            int KQ = B - A;
            char kq = KQ + 48;
            Push(&s, kq);
        }
    }
    Pop(&s, &data);
    if (IsEmpty(s) == 1)
    {
        cout << "bieu thuc dung " << endl;
    }
    else
    {
        cout << " bieu thuc sai " << endl;
        cout << "ton tai nhieu hon 1 toan tu trong stack ";
    }

    file.close();
    fileOut.close();
}