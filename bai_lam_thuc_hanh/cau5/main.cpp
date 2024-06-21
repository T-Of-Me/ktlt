// 5. Cài đặt các thao tác cơ bản với danh sách liên kết vòng.
// Minh họa, tạo danh sách thông qua dữ liệu nhập từ file.
#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
typedef Node *Link;

struct List
{
    Link fisrt;
    Link Last;
};
void InitCircularLinkedList(List &DS)
{
    DS.fisrt = NULL;
    DS.Last = NULL;
}

void InsertEnd(List &DS, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    if (DS.Last == nullptr)
    {
        newNode->next = newNode;
        DS.Last = newNode;
        DS.fisrt = newNode;
    }
    else
    {
        Node *temp = DS.fisrt;
        while (temp->next != DS.fisrt)
        {
            temp = temp->next;
        }
        // trước temp đến đầu danh sách thì dừng
        temp->next = newNode;
        newNode->next = DS.fisrt;
        DS.Last = newNode;
    }
}
void InsertAtFirst(List &DS, int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    if (DS.fisrt == nullptr)
    {
        NewNode->next = NewNode;
        DS.Last = NewNode;
        DS.fisrt = NewNode;
    }
    else
    {
        Node *temp = DS.fisrt;
        while (temp->next != DS.fisrt)
        {
            temp = temp->next;
        }
        // trước temp đến đầu danh sách thì dừng
        temp->next = NewNode;
        NewNode->next = DS.fisrt;
        DS.fisrt = NewNode;
    }
}
void DeleteLast(List &DS)
{
    Node *temp = DS.fisrt;
    Node *prev;
    while (temp->next != DS.fisrt)
    {
        prev = temp;
        temp = temp->next;
    }
    // trước temp đến đầu danh sách thì dừng
    prev->next = DS.fisrt;
    DS.Last = prev;
}
int main()
{
    List DS;
    InitCircularLinkedList(DS);

    ifstream inputFile("input.txt");
    int value;
    while (inputFile >> value)
    {
        InsertAtFirst(DS, value);
    }
    DeleteLast(DS);
    inputFile.close();

    if (DS.fisrt != nullptr)
    {
        Node *temp = DS.fisrt;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != DS.fisrt);
    }

    return 0;
}
