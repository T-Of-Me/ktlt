// Viết chương trình thêm một phần tử trong danh sách liên kết đã có thứ tự sao cho ta
// vẫn có một danh sách có thứ tự (với danh sách liên kết đơn)
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

Node *createNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}
void insertAtBeginning(List *DS, int x)
{
    Node *newNode = createNode(x);
    newNode->next = *DS;
    *DS = newNode;
}
void insertAtEnd(List *DS, int x) // chuyền tham chiếu
{
    Node *newNode = createNode(x);
    if (*DS == nullptr)
    {
        *DS = newNode;
    }
    else
    {
        Node *temp = *DS;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertAtPos(List *DS, int x, int pos)
{
    Node *newNode = createNode(x);
    if (pos == 1)
    {
        insertAtBeginning(DS, x);
    }
    else
    {
        Node *current = *DS, *pre;
        int POS = 1;
        while (current->next != NULL)
        {
            pre = current;
            current = current->next;
            POS++;
            if (POS == pos)
            {
                break;
            }
        }
        if (current->next != NULL)
        {
            pre->next = newNode;
            newNode->next = current;
        }
        else
        {
            cout << "nam ngoai khoang co the chen " << endl;
        }
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
    List DS = nullptr; // khởi tạo danh sách
    ifstream inputFile("sapxep.inp");
    int value;
    while (inputFile >> value)
    {
        insertAtEnd(&DS, value); // chèn vào đuôi
    }

    inputFile.close();
    //================================    //================================
    cout << "nhap gia tri chen ";
    int data;
    cin >> data;
    cout << "nhap vi tri de chen ";
    int pos;
    cin >> pos;
    insertAtPos(&DS, data, pos);
    //================================    //================================

    //================================    //================================
    // viết vào file out
    ofstream outputFile("sapxep.out");
    outputFile << "Danh sach lien ket: ";
    printList(DS, outputFile);
    outputFile.close();

    return 0;
}