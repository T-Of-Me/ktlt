// 9. Viết chương trình con loại bỏ các phần tử trùng nhau (giữ lại duy nhất 1 phần tử)
// trong một danh sách liên kết có thứ tự không giảm (với danh sách liên kết kép)
// Minh họa, tạo danh sách thông qua dữ liệu nhập từ file.

#include <iostream>
#include <iostream>
#include <fstream>
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

void printList(List &DS, ofstream &file) // ghi vào file
{
    Node *temp = DS.head;
    while (temp != nullptr)
    {
        file << temp->data << " ";
        temp = temp->next;
    }
    file << endl;
}

void RemoveDuplicate(List &DS)
{

    if (DS.head == NULL)
    {
        return;
    }
    else
    {
        Node *cur = DS.head;
        while (cur != NULL && cur->next != NULL)
        {
            Node *check = cur->next;
            while (check != NULL)
            {
                if (check->data == cur->data)
                {
                    check->prev->next = check->next;
                    delete check;
                    // cập nhật lại check 
                    check = check->prev->next;
                }
                else
                {
                    check = check->next;
                }
            }

            cur = cur->next;
        }
    }
}

int main()
{
    List DS;
    InitLinkedList(DS);
    ifstream file("input.txt");
    int data;
    cout << "danh sach co dang " << endl;
    while (file >> data)
    {
        InsertAtEnd(DS, data);
        cout << data << " ";
    }

    RemoveDuplicate(DS);
    cout << "dasdasd";
    ofstream outputFile("output.txt");
    outputFile << "Danh sach lien ket: ";
    printList(DS, outputFile);
}