#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data){};
};
class SLL
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;

public:
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
    void insert(int value)
    {
        Node *item = new Node(value);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
            length++;
        }
    }
    Node *get_nth(int n)
    {
        int cur = 0;
        for (Node *item = head; item; item = item->next)
        {
            if (++cur == n)
            {
                return item;
            }
        }
    }
    Node *get_nth_back(int n)
    {
        if (length < n)
        {
            return nullptr;
        }
        return get_nth(length - n + 1);
    }
};
int main()
{
    SLL list;

    list.print();
}