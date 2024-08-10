template <typename T> struct XORLinkedListHandler_LinkedList
{
    XORLinkedListHandler_LinkedList* npXOR_list = nullptr;
    T data;
};

template <class T> class XORLinkedListHandler
{
private:
    using Node = XORLinkedListHandler_LinkedList<T>;

    Node* firstNode = nullptr;
    Node* XOR(Node* a, Node* b)
    {
        return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
    }

    void deleteLinkedList(Node** start)
    {
        if (*start == nullptr) return;

        Node *tempNode, *delNode, *prevNode;
        tempNode = *start;
        prevNode = nullptr;

        while (tempNode != nullptr)
        {
            delNode = tempNode;
            tempNode = XOR(prevNode, tempNode->npXOR_list);
            delete delNode;
            prevNode = delNode;
        }
        *start = nullptr;
    }

public:
    void PushData(Node** start, T value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->npXOR_list = XOR(nullptr, (*start));
        if ((*start) != nullptr)
        {
            (*start)->npXOR_list = XOR(newNode, XOR(nullptr, (*start)->npXOR_list));
        }

        firstNode = newNode;
        (*start) = newNode;
    }

    void AppendData(Node** start, T value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->npXOR_list = nullptr;
        if((*start) == nullptr)
            (*start) = newNode;
        else
        {
            Node* nextNode, *currentNode, *prevNode;
            //nextNode = nullptr;
            currentNode = (*start);
            prevNode = nullptr;

            while(true)
            {
                nextNode = XOR(prevNode, currentNode->npXOR_list);
                if(nextNode == nullptr)
                    break;
                
                prevNode = currentNode;
                currentNode = nextNode;
            }

            currentNode->npXOR_list = XOR(prevNode, newNode);
            newNode->npXOR_list = XOR(currentNode, nullptr);
        }

    }

    void InsertData(Node** start, T value, int position)
    {
        if (position < 1) return;

        Node* newNode = new Node;
        newNode->data = value;
        newNode->npXOR_list = nullptr;

        if (*start == nullptr)
        {
            *start = newNode;
            firstNode = newNode;
            return;
        }

        Node* tempNode = *start;
        Node* prevNode = nullptr;
        Node* curNode = nullptr;
        Node* nextNode = nullptr;
        int currentPos = 1; 

        while (currentPos < position && tempNode != nullptr)
        {
            curNode = tempNode;
            tempNode = XOR(prevNode, curNode->npXOR_list);
            prevNode = curNode;
            currentPos++;
        }

        if (position == 1) 
        {
            newNode->npXOR_list = *start;
            (*start)->npXOR_list = XOR(newNode, XOR(nullptr, (*start)->npXOR_list));
            *start = newNode;
            firstNode = newNode;
        }
        else if (tempNode == nullptr && currentPos == position) // Insert at the end
        {
            prevNode->npXOR_list = XOR(newNode, XOR(prevNode->npXOR_list, nullptr));
            newNode->npXOR_list = prevNode;
        }
        else if (currentPos == position) // Insert in the mid
        {
            newNode->npXOR_list = XOR(prevNode, tempNode);
            prevNode->npXOR_list = XOR(XOR(prevNode->npXOR_list, tempNode), newNode);
            tempNode->npXOR_list = XOR(newNode, XOR(prevNode, tempNode->npXOR_list));
        }
        else
        {
            delete newNode;
        }
    }


    void PopData(Node** start)
    {
        if((*start) == nullptr) return;

        Node* delNode,*nextNode;
        delNode = (*start);
        nextNode = XOR(nullptr, (*start)->npXOR_list);

        if(nextNode == nullptr) // next is finished
        {
            (*start) = nullptr;
        }
        else
        {
            Node* nextNextNode;
            nextNextNode = XOR(delNode, nextNode->npXOR_list);
            nextNode->npXOR_list = XOR(nullptr, nextNextNode);
            (*start) = nextNode;
        }
        firstNode = (*start);
        delete delNode;
    }

    void RemoveLast(Node** start)
    {
        Node* delNode;
        if((*start) == nullptr)
            return;
        else if((*start)->npXOR_list == nullptr)
        {
            delNode = (*start);
            (*start) = nullptr;
        }
        else
        {
            Node *prevNode, *tempNode, *currentNode;

            tempNode = nullptr;
            prevNode = nullptr;
            currentNode = (*start);

            while (1)
            {
                tempNode = XOR(prevNode,currentNode->npXOR_list);

                if(tempNode == nullptr)
                    break;

                prevNode = currentNode;
                currentNode = tempNode; 
            }
            prevNode->npXOR_list = XOR(XOR(prevNode->npXOR_list, currentNode), nullptr);
            delNode = currentNode;

        }
        delete delNode;
    }

    ~XORLinkedListHandler()
    {
        deleteLinkedList(&firstNode);
    }
};
