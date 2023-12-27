#include <cstdlib>
#include <iostream>
#include "node.cpp"
using namespace std;

template <class T>
class LinkedList
{
    public:
    int count;
    Node<T> *head;
    Node<T> *tail;

    LinkedList<T>()
    {
        count = 0;
        head = tail = nullptr;
    }

    LinkedList<T>(LinkedList<T> &list)
    {
        this->count = list.count;
        Node<T> *next_node = list->head;
        for (int i = 0; i < count; i++)
        {
            T data = next_node->data;
            this->add(data);
            next_node = next_node->next_ptr;
        }
    }

    void add(T data)
    {
        Node<T> *new_node = new Node<T>(data);

        if (count == 0)
        {
            // New node is the head
            head = new_node;
        }
        else
        {
            // Previous tail now points to new node
            tail->next_ptr = new_node;
        }
        // New node points to last node in list
        new_node->prev_ptr = tail;
        // List's tail is now the new list
        tail = new_node;

        count++;
    }

    void display()
    {
        cout << "Linked List: ";
        Node<T> *next_node = head;
        for (int i = 0; i < count; i++)
        {
            cout << next_node->data << " ";
            next_node = next_node->next_ptr;
        }
        cout << endl;
    }

    void clear_list()
    {
        Node<T> *next_node = head;
        for (int i = 0; i < count; i++)
        {
            next_node = next_node->next_ptr;
            if (i != (count-1))
            {
                free(next_node->prev_ptr);
            }
        }
        free(tail);
        head = tail = nullptr;
        count = 0;
    }

    int search(T data)
    {
        Node<T> *current = head;
        for (int i = 0; i < count; i++)
        {
            if (current->data == data)
            {
                return i;
            }
            current = current->next_ptr;
        }
        return -1;
    }

    bool is_empty()
    {
        return (tail == nullptr) ? true : false;
    }

    int delete_node(T data)
    {
        int index = search(data);
        if (index == -1)
        {
            return index;
        }
        else if (index == 0)
        {
            Node<T> *next = head->next_ptr; 
            free(head);
            head = next;
            next->prev_ptr = nullptr;
        }
        else if (index == (count-1))
        {
            Node<T> *prev = tail->prev_ptr; 
            free(tail);
            tail = prev;
            prev->next_ptr = nullptr;
        }
        else
        {
            Node<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next_ptr;
            }

            Node<T> *next = current->next_ptr; 
            Node<T> *prev = current->prev_ptr;
            next->prev_ptr = prev;
            prev->next_ptr = next;
            free(current);
        }
        count--;
        return index;
    }

    void insert_after(T element, T data)
    {
        int index = search(element);
        if (index == (count-1))
        {
            this->add(data);
        }
        else if (index != -1)
        {
            Node<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next_ptr;
            }
            Node<T> *next = current->next_ptr;

            Node<T> *new_node = new Node<T>(data);
            current->next_ptr = new_node;
            next->prev_ptr = new_node;
            new_node->prev_ptr = current;
            new_node->next_ptr = next;

            count++;
        }
    }

    ~LinkedList<T>()
    {
        this->clear_list();
    }

};

int main()
{
    LinkedList<int> *list = new LinkedList<int>;
    list->add(5);
    list->add(7);
    list->add(5);
    list->add(3);

    list->display();
    // list->clear_list();
    // list->display();
    // cout << list->is_empty() << endl;
    // cout << list->search(3) << endl;
    // cout << list->head << endl;
    // cout << list->tail << endl;
    // list->delete_node(7);
    // list->insert_after(7, 8);
    LinkedList<int> *list2(list);
    list->add(1);
    list2->display();
}

