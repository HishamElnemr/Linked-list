#include <iostream>
using namespace std;

struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data){};
};

class LinkedList
{
private:
    Node *head{};

public:
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            cout << cur->data << " ";
        }
        cout << "\n";
    }

    void insert(int value)
    {
        Node *item = new Node(value);
        item->next = head;
        head = item;
    }
    Node *get_tail()
    {
        
        if (!head)
        {
            return nullptr;
        }
        Node *cur = head;
        for (; cur->next; cur = cur->next)
            ;
        return cur;
    }
};