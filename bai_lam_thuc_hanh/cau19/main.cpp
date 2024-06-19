//  19.Cài đặt các thao tác với queue. (sử dụng mảng)
// Minh họa thông qua dữ liệu nhập từ file

#include <iostream>
#include <fstream>
using namespace std;

struct Queues
{
    int head, tail, count;
    int Node[100];
};
void Init(Queues *q)
{
    q->head = 0;
    q->tail = -1;
    q->count = 0;
}

int IsEmpty(Queues q)
{
    if (q.count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(Queues q)
{
    if (q.count == 100)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// đẩy vào đuôi ra đầu
int Put(Queues *q, int data)
{
    if (IsFull(*q) == 1)
    {
        return 0;
    }
    else
    {
        q->tail = (q->tail + 1) % 100;
        q->Node[q->tail] = data;
        q->count++;
        return 1;
    }

    return 1;
}

int Get(Queues *q, int *data)
{
    if (IsEmpty(*q) == 1)
    {
        return 0;
    }
    else
    {
        *data = q->Node[q->head];
        q->head = (q->head + 1) % 100;
        q->count--;
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
    while (IsEmpty(s) == 0)
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