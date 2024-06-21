// Viết chương trình con loại bỏ các phần tử trùng nhau (giữ lại duy nhất 1 phần tử)
// trong một danh sách liên kết có thứ tự không giảm (với danh sách liên kết đơn)
// Minh họa, tạo danh sách thông qua dữ liệu nhập từ file

#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
typedef Node *List;

void Init(List *DS)
{
    *DS = NULL;
}
void InsertAtEnd(List *DS, int data)
{
    Node *cur = *DS;
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    if (*DS == NULL)
    {
        *DS = NewNode;
    }
    else
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = NewNode;
    }
}
 
void RemoveDuplicate(List *DS)
{

    Node *cur = *DS;
    while (cur != NULL && cur->next != NULL) //====///////
    {
        Node *preCheck = cur;
        Node *check = cur->next;
        while (check != NULL)
        {
            if (check->data == cur->data)
            {
               
                preCheck->next = check->next;
                delete check;
                check = preCheck->next;//====///////
            }
            else
            {
                preCheck = check;
                check = check->next;
            }
        }
        cur = cur->next;
    }
}

void printList(List DS, ofstream &file) // ghi vào file
{
    Node *temp = DS;
    while (temp != nullptr)
    {
        file << temp->data << " ";
        temp = temp->next;
    }
    file << endl;
}
int main()
{
    List DS;
    Init(&DS);
    ifstream file("input.txt");
    int data;
    cout << "danh sach co dang " << endl;
    while (file >> data)
    {
        InsertAtEnd(&DS, data);
        cout << data << " ";
    }

    RemoveDuplicate(&DS);
    ofstream outputFile("output.txt");
    outputFile << "Danh sach lien ket: ";
    printList(DS, outputFile);
}