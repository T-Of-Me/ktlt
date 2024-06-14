#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

void BubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
bool Songuyento(int num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num <= 3)
    {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
void Daycondainhat(int a[], int n)
{
    int maxLength = 1;
    int length = 1;
    int maxStartIndex = 0;
    int startIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            length++;
        }
        else
        {
            if (length > maxLength)
            {
                maxLength = length;
                maxStartIndex = startIndex;
            }
            startIndex = i;
            length = 1;
        }
    }
    if (length > maxLength)
    {
        maxLength = length;
        maxStartIndex = startIndex;
    }
    cout << maxStartIndex + 1 << " ";
    cout << maxStartIndex + maxLength;
}
struct Node
{
    int data;
    Node *next;
};
typedef Node *Stack;
void Init(Stack *s)
{
    (*s) = NULL;
}
int IsEmpty(Stack s)
{
    return (s == NULL);
}
int Push(Stack *s, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = *s;
    *s = temp;
    return 1;
    delete temp;
}
int POP(Stack *s, int *data)
{
    if (IsEmpty(*s))
    {
        return 0;
    }
    else
    {
        *data = (*s)->data;
        (*s) = (*s)->next;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char x;
    freopen("Tungphanthanh.inp", "r", stdin);
    freopen("Tungphanthanh.out", "w", stdout);
    // cau a
    int n;
    cin >> x;
    int a[1000];
    if (x == 'a')
    {
        // cau a
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        BubbleSort(a, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else if (x == 'b')
    {
        // cau b
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {

            if (Songuyento(a[i]) == 1)
            {
                count++;
            }
        }
        cout << count;
    }
    else if (x == 'c')
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Daycondainhat(a, n);
    }
    else if (x == 'd')
    {
        // cau d
        Stack s;
        Init(&s);
        cin >> x;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            Push(&s, a[i]);
        }
        int k;
        while (!IsEmpty(s))
        {
            if (POP(&s, &k) != 1)
            {
                cout << " khong the mo";
            }
            else
            {
                cout << k << " ";
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}