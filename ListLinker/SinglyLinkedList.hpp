#pragma once

template <typename T>
struct SinglyLinkedListHandler_LinkedList
{
    T data;
    SinglyLinkedListHandler_LinkedList* next_link = nullptr;
};

template <typename T> class SinglyLinkedListHandler
{
private:

    using Node = SinglyLinkedListHandler_LinkedList<T>;
    Node* firstNode = nullptr;

	void deleteLinkedList(Node** start)
	{
		Node* nextNode, * current = *start;
		while (current != nullptr)
		{
			nextNode = current->next_link;
			delete current;
			current = nextNode;
		}
		*start = nullptr;
	}

public:
    void PushData(Node** start, T value)
    {
        Node* newNode;
        newNode = new (Node);
        newNode->data = value;
        newNode->next_link = (*start);
        (*start) = newNode;
        firstNode = *start;
    }
	void AppendData(Node** start, T value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next_link = nullptr;

		if ((*start) == nullptr)
		{
			(*start) = newNode;
			firstNode = *start;
			return;
		}

		Node* tempNode = *start;
		while (tempNode->next_link != nullptr)
		{
			tempNode = tempNode->next_link;
		}
		tempNode->next_link = newNode;
	}
    void InsertData(Node** start, T value, unsigned int position)
    {
		unsigned int counter;
		Node* newNode = nullptr, * tempNode = nullptr, * prevNode = nullptr;

		counter = 0;

		newNode = new (Node);
		newNode->data = value;
		newNode->next_link = nullptr;
		tempNode = (*start);

		while (tempNode != nullptr)
		{
			tempNode = tempNode->next_link;
			counter++;
		}
		if (position == 1)
		{
			if (*start == nullptr)
			{
				*start = newNode;
				(*start)->next_link = nullptr;
			}
			else
			{
				prevNode = (*start);

				*start = newNode;
				(*start)->next_link = prevNode;
			}
		}
		else if (position > 1 && position <= counter)
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
		firstNode = *start;
    }

	void PopData(Node** start)
	{
		if (*start != nullptr) {
			Node* delNode = *start;
			*start = delNode->next_link;
			delete delNode;											// List is empty
		}
		firstNode = *start;
	}
	void RemoveLast(Node** start)
	{
		if (*start == nullptr) {
			return;													// List is empty
		}

		if ((*start)->next_link == nullptr) {
			delete* start;
			*start = nullptr;										// List has only one node
		}
		else {
			Node* tempNode = *start;
			while (tempNode->next_link->next_link != nullptr) {
				tempNode = tempNode->next_link;
			}
			delete tempNode->next_link;
			tempNode->next_link = nullptr;
		}
		firstNode = *start;
	}

	~SinglyLinkedListHandler()
	{
		deleteLinkedList(&firstNode);
	}
};
