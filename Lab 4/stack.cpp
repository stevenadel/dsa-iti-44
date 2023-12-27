#include <iostream>
#include "node.cpp"
using namespace std;

template<class T>
class Stack {
    public:
    int size;
    Node<T> *head;

    Stack<T>()
    {
        size = 0;
        head = nullptr;
    }

    // Reverse stack
    Stack<T>(Stack<T> &stack)
    {
        this->size = 0;
        this->head = nullptr;

        Node<T> *next_node = stack.head;
        while (next_node != nullptr)
        {
            T data = next_node->data;
            this->push(data);
            next_node = next_node->next_ptr;
        }
    }

    void push(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        if (head == nullptr)
        {
            head = new_node;
        }
        else 
        {
            new_node->next_ptr = head;
            head = new_node;
        }
        size++;
    }

    T pop()
    {
        if (head == nullptr)
        {
            return T();
        }

        Node<T> *node_pop = head; 
        head = node_pop->next_ptr;
        free(node_pop);
        
        if (size > 0)
        {
            size--;
        }
        return node_pop->data;
    }

    void display()
    {
        cout << "Stack: ";
        Node<T> *next_node = head;
        for (int i = 0; i < size; i++)
        {
            cout << next_node->data << " ";
            next_node = next_node->next_ptr;
        }
        cout << endl;
    }

    ~Stack<T>()
    {
        free(head);
    }
};

int main()
{
    Stack<int> *stack = new Stack<int>();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->display();
    stack->pop();
    stack->display();
    stack->pop();
    stack->display();

    // Stack<int> stack2(*stack);
    // stack->push(9);
    // stack2.pop();
    // stack2.display();
}