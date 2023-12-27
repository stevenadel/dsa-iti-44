template <class T>
class Node
{
    public:
    T data;
    Node<T> *next_ptr;
    Node<T> *prev_ptr;

    Node<T>()
    {
        data = T();
        next_ptr = prev_ptr = nullptr;
    }
    
    Node<T>(T d)
    {
        data = d;
        next_ptr = prev_ptr = nullptr;
    }

    ~Node<T>()
    {
        delete next_ptr;
        delete prev_ptr;
    }
};