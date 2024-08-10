# ListLinker Project

## Description
This project implements various types of linked lists in C++, including:

- **Singly Linked List**
- **Doubly Linked List**
- **Circular Linked List**
- **Doubly Circular Linked List**
- **XOR Linked List**

## Supported Operations
- **PushData**: Add a node to the start of the list.
- **AppendData**: Add a node to the end of the list.
- **InsertData**: Insert a node at a specific position.
- **PopData**: Remove the first node from the list.
- **RemoveLast**: Remove the last node from the list.

### Example
To insert a value into the list:
```cpp
InsertData(&start, value, position);
```
To remove the last element:
```cpp
RemoveLast(&start);
```

1. **Singly Linked List**:
   - Nodes contain a single pointer to the next node.
   - Supports basic operations like insertion, deletion, and traversal.

2. **Doubly Linked List**:
   - Nodes contain two pointers, one pointing to the next node and another to the previous node.
   - Supports bidirectional traversal and operations like insertion and deletion at both ends.

3. **Circular Linked List**:
   - The last node points back to the first node, forming a circle.
   - Suitable for scenarios where the list needs to be looped repeatedly.

4. **Doubly Circular Linked List**:
   - Combines the features of both doubly linked lists and circular linked lists.
   - Each node has two pointers (previous and next), and the list forms a circular structure where the last node points back to the first, and the first node points to the last.
   - Ideal for applications that require efficient traversal in both directions within a circular structure.

5. **XOR Linked List**:
   - A memory-efficient version of a doubly linked list where each node stores the XOR of the previous and next node pointers.
   - Demonstrates how to save memory while maintaining bidirectional traversal capabilities.

## Project Structure
```
/ListLinker     # Source code files
/Test           # Test cases and example usage
README.md       # Project documentation
```

## Contributing
Contributions to improve the project are welcome! If you encounter any issues or have suggestions, feel free to open an issue or submit a pull request.
