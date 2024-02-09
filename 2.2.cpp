#include <iostream>
#include <cassert>
#include <climits>
#include <vector>
#include <algorithm>
#include <sstream>
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
    Node *tail{};
    int length = 0;

public:
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void insert_end(int value)
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
        }
    }
    void swap_pairs()
    {
        for (Node *value = head; value; value = value->next)
        {
            if (value->next)
            {
                swap(value->data, value->next->data);
                value = value->next;
            }
        }
    }
};
int main()
{
    LinkedList list;
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(6);
    list.swap_pairs();
    list.print();
}