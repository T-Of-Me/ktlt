//  20.Cài đặt các thao tác với queue. (sử dụng danh sách liên kết đơn)
// Minh họa thông qua dữ liệu nhập từ file

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
struct Queues
{
    Node *tail, *head;
};

void Init(Queues *s)
{
    s->head = NULL;
    s->tail = NULL;
}

int IsEmpty(Queues *s)
{
    if (s->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// vào đuôi ra đầu
int Put(Queues *s, int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    if (s->tail == NULL)
    {
        s->head = NewNode;
        s->tail = NewNode;
        return 1;
    }
    else
    {
        s->tail->next = NewNode;
        s->tail = NewNode; // cập nhật lại tail
        return 1;
    }
}

int Get(Queues *q, int *data)
{
    if (IsEmpty(q) == 1)
    {
        return 0;
    }
    else
    {
        *data = q->head->data;
        Node *temp = q->head;
        if (q->head == q->tail)
        {
            q->head = NULL;
            q->tail = NULL;
        }
        else
        {
            q->head = temp->next;
        }
        return 1;
    }
}

int main()
{
    Queues s;
    Init(&s);
    int data;
    ifstream file("input.txt");
    ofstream fileOut("output.txt");
    while (file >> data)
    {
        Put(&s, data);
    }
    while (IsEmpty(&s) == 0)
    {
        if (Get(&s, &data) == 0)
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