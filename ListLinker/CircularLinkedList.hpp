#pragma once

template <typename T> struct CircularLinkedListHandler_LinkedList
{
    T data;
    CircularLinkedListHandler_LinkedList* next_link = nullptr;
};

template <typename T> class CircularLinkedListHandler
{
private:
    using Node = CircularLinkedListHandler_LinkedList<T>;

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
        Node* newNode;
        newNode = new (Node);
        newNode->data = value;
        
        if ((*start) == nullptr)
        {
            newNode->next_link = newNode;
            lastNode = newNode;
        }
        else
        {
            newNode->next_link = (*start);
            lastNode->next_link = newNode;


        }
        (*start) = newNode;
        firstNode = *start;
    }

    void AppendData(Node** start, T value)
    {
        Node* newNode;
        newNode = new Node;
        newNode->data = value;

        if ((*start) != nullptr)
        {
            newNode->next_link = lastNode->next_link;
            lastNode->next_link = newNode;
            lastNode = newNode;
        }
        else
        {
            newNode->next_link = newNode;
            lastNode = newNode;
            (*start) = newNode;
        }
        firstNode = *start;
    }

    void InsertData(Node** start, T value, int position)
    {
        unsigned int counter;
        Node* newNode = nullptr, * tempNode = nullptr, * prevNode = nullptr;

        counter = 0;

        newNode = new Node;
        newNode->data = value;
        newNode->next_link = nullptr;
        tempNode = (*start);

        do
        {
            tempNode = tempNode->next_link;
            counter++;
        } while (tempNode != (*start));

        if (position == 1)
        {
            if ((*start) == nullptr)
            {
                *start = newNode;
                lastNode = *start;
            }
            else
            {
                prevNode = (*start);
                *start = newNode;
                (*start)->next_link = prevNode;
            }
            lastNode->next_link = newNode;
        }
        else if (position == counter)
        {
            AppendData(start, value);
        }
        else if (position > 1 && position < counter)
        {
            tempNode = (*start);
            for (int i = 1; i < position; i++)
            {
                prevNode = tempNode;
                tempNode = tempNode->next_link;
            }
            prevNode->next_link = newNode;
            newNode->next_link = tempNode;
        }
        else
        {
            delete newNode;
        }
        firstNode = (*start);


    }

    void PopData(Node** start)
    {
        if (*start == nullptr) return;

        Node* delNode;
        delNode = (*start);
        if ((*start) == (*start)->next_link)
        {
            *start = nullptr;
            lastNode = nullptr;
        }
        else
        {
            *start = (*start)->next_link;
            lastNode->next_link = (*start);
        }
        firstNode = (*start);
        delete delNode;
    }

    void RemoveLast(Node** start)
    {
        if ((*start) == nullptr || lastNode == nullptr) return;

        Node* delNode;
        delNode = lastNode;
        if ((*start) == lastNode)
        {
            *start = nullptr;
            lastNode = nullptr;
        }
        else
        {
            Node* tempNode;
            tempNode = (*start);

            while (tempNode->next_link != lastNode)
            {
                tempNode = tempNode->next_link;
            }
            lastNode = tempNode;
            lastNode->next_link = (*start);
        }
        delete delNode;
    }


    ~CircularLinkedListHandler()
    {
        deleteLinkedList(&firstNode);
    }
};