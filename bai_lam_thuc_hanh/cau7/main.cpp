// Viết chương trình thêm một phần tử trong danh sách liên kết đã có thứ tự sao cho ta
// vẫn có một danh sách có thứ tự (với danh sách liên kết kép)
// Minh họa, tạo danh sách thông qua dữ liệu nhập từ file.

#include <iostream>
#include <fstream>
//  danh sách liên kết kép
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
struct List
{
    Node *head;
    Node *tail;
};

void InitLinkedList(List &DS) // khởi tạo
{
    DS.head = NULL;
    DS.tail = NULL;
}
void InsertAtEnd(List &DS, int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->prev = nullptr;
    NewNode->next = nullptr;

    if (DS.tail == NULL)
    {
        DS.head = NewNode;
        DS.tail = NewNode;
    }
    else
    {
        Node *current = DS.head;
        while (current->next != nullptr)
        {
            current = current->next;
        } // cập nhật lại Node
        current->next = NewNode;
        NewNode->prev = current;
        DS.tail = NewNode; // cập nhật lại tail
    }
}
void InsertFirst(List &DS, int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->prev = nullptr;
    NewNode->next = nullptr;

    if (DS.head == NULL)
    {
        DS.head = NewNode;
        DS.tail = NewNode;
    }
    else
    {
        NewNode->next = DS.head;
        DS.head->prev = NewNode;
        // cập nhật lại head
        DS.head = NewNode;
    }
}

void InsertAtPosition(List &DS, int data, int position) // chuyền vào địa chỉ của con trỏ Node
{
    if (position < 1)
    {
        cout << "Vi tri chen khong hop le." << endl;
        return;
    }

    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->prev = nullptr;
    NewNode->next = nullptr;

    if (position == 1)
    {
        InsertFirst(DS, data);
    }
    else
    {
        Node *current = DS.head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current != nullptr)
        {
            current = current->next;
            currentPosition++;
        }
        if (current == nullptr)
        {
            cout << "Vi tri chen vuot qua kich thuoc danh sach." << endl;
            return;
        }
        NewNode->prev = current;
        NewNode->next = current->next;
        if (current->next != nullptr)
        {
            current->next->prev = NewNode;
        }
        current->next = NewNode;
    }
}
void printToFile(List DS, const string &filename)
{
    ofstream outputFile(filename);
    if (!outputFile)
    {
        cout << "Khong the mo file de ghi." << endl;
        return;
    }

    Node *current = DS.head;
    while (current != nullptr)
    {
        outputFile << current->data << " ";
        current = current->next;
    }

    outputFile.close();
    cout << "Da ghi danh sach vao file " << filename << endl;
}

int main()
{
    List DS;
    InitLinkedList(DS);
    ifstream inputFile("input.txt");
    int value;
    while (inputFile >> value)
    {
        InsertAtEnd(DS, value);
    }
    inputFile.close();
    //==========================================================================//====================
    cout << "nhap vi tri them ";
    int pos;
    cin >> pos;
    cout << "nhap gia tri de them ";
    int data;
    cin >> data;
    InsertAtPosition(DS, data, pos);
    //=================================================================================================

    printToFile(DS, "output.txt");
}