
template <typename T> struct CircularDoublyLinkedListHandler_LinkedList
{
    CircularDoublyLinkedListHandler_LinkedList* prev_link = nullptr;
    T data;
    CircularDoublyLinkedListHandler_LinkedList* next_link = nullptr;
};

template <class T> class CircularDoublyLinkedListHandler
{
private:
    using Node = CircularDoublyLinkedListHandler_LinkedList<T>;

    Node* firstNode = nullptr;
    Node* lastNode = nullptr;

    void deleteLinkedList(Node** start)
    {
        if (*start == nullptr) return;

        Node* nextNode, * current = *start;
        do 
        {
            nextNode = current->next_link;
            delete current;
            current = nextNode;
        } while (current != *start);
        *start = nullptr;
        firstNode = nullptr;
        lastNode = nullptr;
    }

public:
    void PushData(Node** start, T value)
    {
        Node* newNode = new Node;
        newNode->data = value;

        if(*start == nullptr)
        {
            newNode->prev_link = newNode;
            newNode->next_link = newNode;
            lastNode = newNode;
        }
        else
        {
            newNode->next_link = (*start);
            newNode->prev_link = (*start)->prev_link;
            (*start)->prev_link->next_link = newNode;
            (*start)->prev_link = newNode;
        }

        (*start) = newNode;
        firstNode = (*start);
    }

    void AppendData(Node** start, T value) 
    {
        Node* newNode = new Node;
        newNode->data = value;

        if (*start == nullptr) 
        {
            *start = newNode;
            newNode->next_link = newNode;
            newNode->prev_link = newNode;
            firstNode = *start;
        } 
        else 
        {
            Node* last = (*start)->prev_link;
            newNode->next_link = *start;
            newNode->prev_link = last;
            last->next_link = newNode;
            (*start)->prev_link = newNode;
        }

        firstNode = (*start);
    }
    void InsertData(Node** start, T value, int position)
    {
        if (position < 1) return;

        Node* newNode = new Node;
        newNode->data = value;

        if ((*start) == nullptr) {
            newNode->next_link = newNode;
            newNode->prev_link = newNode;
            *start = newNode;
            firstNode = newNode;
            return;
        }

        Node* tempNode = *start;
        unsigned int counter = 1;

        do {
            tempNode = tempNode->next_link;
            counter++;
        } while (tempNode != (*start));

        if (position == 1) 
        {
            Node* last = (*start)->prev_link;
            newNode->next_link = (*start);
            newNode->prev_link = last;
            last->next_link = newNode;
            (*start)->prev_link = newNode;
            (*start) = newNode;
        }

        else if (position == counter) 
        {
            Node* last = (*start)->prev_link;
            newNode->next_link = *start;
            newNode->prev_link = last;
            last->next_link = newNode;
            (*start)->prev_link = newNode;
            lastNode = newNode;
        } 

        else if (position > 1 && position < counter)
        {
            tempNode = (*start);
            for (int i = 1; i < position; i++)
            {
                tempNode = tempNode->next_link;
            }
            newNode->prev_link = tempNode->prev_link;
            newNode->next_link = tempNode;
            tempNode->prev_link->next_link = newNode;
            tempNode->prev_link = newNode;
        }
        else
        {
            delete newNode;
        }
    }

    void PopData(Node** start)
    {
        if (*start == nullptr) return;

        Node* delNode;
        delNode = (*start);
        if ((*start) == (*start)->next_link)
        {
            (*start) = nullptr;
            lastNode = nullptr;
        }
        else
        {
            (*start)->next_link->prev_link = delNode->prev_link;
            delNode->prev_link->next_link = (*start)->next_link;
            (*start) = delNode->next_link;
        }

        delete delNode;
        firstNode = (*start);
    }

    void RemoveLast(Node** start)
    {
        if (*start == nullptr) return;

        Node* delNode;
        Node* last;
        last = (*start)->prev_link;
        delNode = last;

        if((*start) == (*start)->prev_link)
        {
            *start = nullptr;
            firstNode = nullptr;
        }
        else
        {
            Node* secondlast = last->prev_link;
            secondlast->next_link = (*start);
            (*start)->prev_link = secondlast;
        }
        delete delNode;
    }

    ~CircularDoublyLinkedListHandler()
    {
        deleteLinkedList(&firstNode);
    }
};