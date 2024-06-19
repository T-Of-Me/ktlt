

// 16.Viết chương trình con kiểm tra một chuỗi dấu ngoặc có đúng không ?

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
    string chuoi;
    Init(&s);
    char data;
    ifstream file("input.txt");
    ofstream fileOut("output.txt");
    int i = 0;
    while (file >> chuoi[i])
    {
        if (chuoi[i] == '{' || chuoi[i] == '[' || chuoi[i] == '(')
        {
            Push(&s, chuoi[i]);

            i++;
        }
        else if (chuoi[i] == '}')
        {
            if (s->data == '{')
            {

                Pop(&s, &data);
                i++;
            }
            else
            {
                cout << "chuoi sai " << endl;
                return 0;
            }
        }
        else if (chuoi[i] == ']')
        {
            if (s->data == '[')
            {

                Pop(&s, &data);
                i++;
            }
            else
            {
                cout << "chuoi sai " << endl;
                return 0;
            }
        }
        else if (chuoi[i] == ')')
        {
            if (s->data == '(')
            {

                Pop(&s, &data);
                i++;
            }
            else
            {
                cout << "chuoi sai " << endl;
                return 0;
            }
        }
        else
        {
            cout << "chuoi sai " << endl;
            return 0;
        }
    }

    if (IsEmpty(s) == 1)
    {
        cout << "chuoi dung " << endl;
    }
    else
    {
        cout << "chuoi sai " << endl;
    }

    file.close();
    fileOut.close();
}