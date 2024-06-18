// Cài đặt các thao tác với stack. (sử dụng mảng)
// Minh họa thông qua dữ liệu nhập từ file.

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;
struct Stack
{
    int top;
    int node[100];
};
void InitStack(Stack *s)
{
    s->top = -1;
}

int IsEmpty(Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(Stack s)
{
    if (s.top == 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(Stack *s, int data)
{
    if (IsFull(*s) == 1)
    {
        return 0;
    }
    else
    {
        s->top++;
        s->node[s->top] = data;
        return 1;
    }
}

int pop(Stack *s, int *data)
{
    if (IsEmpty(*s) == 1)
    {
        return 0;
    }
    else
    {
        *data = s->node[s->top];
        s->top--;
        return 1;
    }
}

int main()
{
    Stack s;
    InitStack(&s);
    int data;
    ifstream file("input.txt");
    ofstream fileOut("output.txt");
    while (file >> data)
    {
        push(&s, data);
    }
    while (IsEmpty(s) == 0)
    {
        if (pop(&s, &data) == 0)
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