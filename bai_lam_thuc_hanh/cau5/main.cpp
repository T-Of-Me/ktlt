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
typedef Node *List;


void InitCircularLinkedList(List *DS)
{
    *DS = nullptr;
}

void InsertEnd(List *DS, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    if (*DS == nullptr)
    {
        newNode->next = newNode;  
        *DS = newNode;
    }
    else
    {
        Node *temp = *DS;
        while (temp->next != *DS)
        {
            temp = temp->next;
        }
        // trước temp đến đầu danh sách thì dừng 
        temp->next = newNode;
        newNode->next = *DS;
    }
}

int main()
{
    Node *DS;
    InitCircularLinkedList(&DS);

    ifstream inputFile("input.txt");
    int value;
    while (inputFile >> value)
    {
        InsertEnd(&DS, value);
    }
    inputFile.close();

     
    if (DS != nullptr)
    {
        Node *temp = DS;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != DS);
    }

    return 0;
}
