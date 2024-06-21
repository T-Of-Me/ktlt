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
// xoa gia tri

void DeleteFisrt(List *DS)
{
    Node *current = *DS;
    *DS = current->next;
}

void DeletePos(List *DS, int pos)
{

    Node *pre;
    Node *current = *DS;
    int POS = 1;
    if (pos == 1)
    {
        DeleteFisrt(DS);
    }
    else
    {
        // while (current->next != NULL)
        // {
        //     pre = current;
        //     current = current->next;
        //     POS++;
        //     if (POS == pos)
        //     {
        //         break;
        //     }
        // }
        while ( current != NULL && POS < pos)
        {
            POS ++;
            pre = current;
            current = current->next;
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
void DeleteLast(List *DS)
{
    Node *pre;
    Node *cur = *DS;
    while (cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = NULL;
}
int searchNode(List DS, int x)
{
    int i = 0;
    Node *current = DS;
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

void MakeListEmpty(List *DS)
{
    (*DS)->next = NULL;
}
int CheckListEmpty(List DS)
{
    if (DS->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
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
    // cout << "nhap gia tri chen ";
    // int data;
    // cin >> data;
    // cout << "nhap vi tri de chen ";
    // int pos;
    // cin >> pos;
    // insertAtPos(&DS, data, pos);
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

    cout << endl;
    cout << "nhap vi tri can xoa ";
    int y;
    cin >> y;
    DeletePos(&DS, y);
    //================================    //================================
    // viết vào file out
    ofstream outputFile("sapxep.out");
    outputFile << "Danh sach lien ket: ";
    printList(DS, outputFile);
    outputFile.close();

    return 0;
}