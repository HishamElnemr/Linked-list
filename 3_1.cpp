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

    vector<Node *> debug_data;

    void debug_add_node(Node *node)
    {
        debug_data.push_back(node);
    }
    void debug_remove_node(Node *node)
    {
        auto it = std::find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }

public:
    LinkedList()
    {
    }
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &another) = delete;

    void debug_print_address()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }

    void debug_print_node(Node *node, bool is_seperate = false)
    {
        if (is_seperate)
            cout << "Sep: ";
        if (node == nullptr)
        {
            cout << "nullptr\n";
            return;
        }
        cout << node->data << " ";
        if (node->next == nullptr)
            cout << "X ";
        else
            cout << node->next->data << " ";

        if (node == head)
            cout << "head\n";
        else if (node == tail)
            cout << "tail\n";
        else
            cout << "\n";
    }
    void debug_print_list(string msg = "")
    {
        if (msg != "")
            cout << msg << "\n";
        for (int i = 0; i < (int)debug_data.size(); ++i)
            debug_print_node(debug_data[i]);
        cout << "************\n"
             << flush;
    }

    string debug_to_string()
    {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node *cur = head; cur; cur = cur->next)
        {
            oss << cur->data;
            if (cur->next)
                oss << " ";
        }
        return oss.str();
    }

    void debug_verify_data_integrity()
    {
        if (length == 0)
        {
            assert(head == nullptr);
            assert(tail == nullptr);
        }
        else
        {
            assert(head != nullptr);
            assert(tail != nullptr);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!tail->next);
        }
        int len = 0;
        Node *prev = nullptr;
        for (Node *cur = head; cur; prev = cur, cur = cur->next, len++)
            assert(len < 10000);
        assert(tail == prev);
        assert(length == len);
        assert(length == (int)debug_data.size());
    }
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
    void delete_node(Node *node)
    {
        debug_remove_node(node);
        --length;
        delete node;
    }

    void add_node(Node *node)
    {
        debug_add_node(node);
        ++length;
    }

    void insert_end(int value)
    {
        Node *item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else
            tail->next = item, tail = item;
    }
    void delete_first()
    {
        if (head)
        {
            Node *cur = head;
            head = head->next;

            delete_node(cur);

            if (!head)
                tail = nullptr;
        }
        debug_verify_data_integrity();
    }
    void delete_next_node(Node *node)
    {
        Node *to_delete = node->next;
        bool is_tail = to_delete == tail;
        node->next = node->next->next;
        delete_node(to_delete);
        if (is_tail)
            tail = node;
    }
    Node *get_previous(Node *n)
    {
        for (Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
        {
            if (cur == n)
                return prv;
        }
        return nullptr;
    }
    void swap_head_tail()
    {
        Node *prv = get_previous(tail);
        tail->next = head->next;
        prv->next = head;
        head->next = nullptr;
        swap(tail, head);
        debug_verify_data_integrity();
    }
};
int main()
{
    LinkedList list;
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(6);
    list.swap_head_tail();
    list.print();
}