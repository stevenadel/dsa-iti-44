#include <iostream>
#include "node.cpp"
using namespace std;

template<class T>
class Queue {
    public:
    int size;
    Node<T> *head;
    Node<T> *tail;

    Queue<T>()
    {
        size = 0;
        head = tail = nullptr;
    }

    Queue<T>(Queue<T> &queue)
    {
        this->size = 0;
        this->head = this->tail = nullptr;

        Node<T> *next_node = queue.head;
        while (next_node != nullptr)
        {
            T data = next_node->data;
            this->enqueue(data);
            next_node = next_node->next_ptr;
        }
    }

    void enqueue(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        if (head == nullptr)
        {
            head = tail = new_node;
        }
        else 
        {
            tail->next_ptr = new_node;
            new_node->prev_ptr = tail;
            tail = new_node;
        }
        size++;
    }

    T dequeue()
    {
        if (head == nullptr)
        {
            return T();
        }

        Node<T> *node_dequeue = head;
        T data =  node_dequeue->data;
        head = node_dequeue->next_ptr;
        
        if (size > 0)
        {
            size--;
        }

        free(node_dequeue);
        return data;
    }

    void display()
    {
        cout << "Queue: ";
        Node<T> *next_node = tail;
        for (int i = 0; i < size; i++)
        {
            cout << next_node->data << " ";
            next_node = next_node->prev_ptr;
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> *queue = new Queue<int>();
    Queue<int> &queue_ref = *queue;
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    // queue->display();
    // queue->dequeue();
    // queue->dequeue();
    // queue->dequeue();
    queue->display();
    Queue<int> queue2(queue_ref);
    queue->enqueue(5);
    queue2.display();
}