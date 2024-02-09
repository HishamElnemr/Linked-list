#include <iostream>
#include <cassert>
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
    int lenght = 0;

public:
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
    void insert_front(int value)
    {
        Node *item = new Node(value);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            item->next = head;
            head = item;
            lenght++;
        }
    }
    void delete_front(int value)
    {
        Node *item = head->next;
        delete head;
        head = item;
    }
};
int main()
{
    SLL list;
    list.insert_front(1);
    list.insert_front(2);
    list.insert_front(3);
    list.delete_front(3);
    list.print();
}