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
//  các thao tác chèn

void insertAtBeginning(List *head, int x)
{
    Node *newNode = createNode(x);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(List *head, int x) // chuyền tham chiếu
{
    Node *newNode = createNode(x);
    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertAtPos(List *head, int x, int pos)
{
    Node *newNode = createNode(x);
    if (pos == 1)
    {
        insertAtBeginning(head, x);
    }
    else
    {
        Node *current, *pre;
        int POS = 1;
        while (current->next != nullptr && POS < pos)
        {
            pre = current;
            current = current->next;
            POS++;
            if (POS == pos)
            {
                break;
            }
        }
        if (pre->next != NULL)
        {
            pre->next = newNode;
            newNode->next = current;
        }
        else
        {
            cout << "khong hop le " << endl;
        }
    }
}
// xoa gia tri

void DeleteFisrt(List *head)
{
    Node *current = *head;
    *head = current->next;
}

void DeletePos(List *head, int pos)
{

    Node *pre;
    Node *current = *head;
    int POS = 1;
    if (pos == 1)
    {
        DeleteFisrt(head);
    }
    else
    {
        while (current != nullptr)
        {
            pre = current;
            current = current->next;
            POS++;
            if (POS == pos)
            {
                break;
            }
        }
        // tìm thấy vị trí cần xóa
        if (current->next == NULL)
        {
            pre->next = NULL;
        }
        else
        {
            pre->next = current->next;
        }
    }
}

int searchNode(List head, int x)
{
    int i = 0;
    Node *current = head;
    while (current != nullptr)
    {
        i++;
        if (current->data == x)
        {
            return i;
        }
        current = current->next;
    }
    return 0;
}

void MakeListEmpty(List *head)
{
    (*head)->next = NULL;
}
int CheckListEmpty(List head)
{
    if (head->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printList(List head, ofstream &file) // ghi vào file
{
    Node *temp = head;
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
    string s;

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
    // cout << "nhap gia tri can search :";
    // int x;
    // cin >> x;
    // int k;
    // k = searchNode(DS, x);
    // if (k == 0)
    // {
    //     cout << "Node khong ton tai";
    // }
    // else
    // {
    //     cout << "Node o vi tri thu " << k << endl;
    // }
    //================================    //================================
    // MakeListEmpty(&DS);

    //================================    //================================
    // xoa node

    // cout << endl;
    // cout << "nhap vi tri can xoa ";
    // int y;
    // cin >> y;
    // DeletePos(&DS, y);
    //================================    //================================
    // viết vào file out
    ofstream outputFile("sapxep.out");
    outputFile << "Danh sach lien ket: ";
    printList(DS, outputFile);
    outputFile.close();

    return 0;
}