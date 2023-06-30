#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insert(const T& value);
    void remove(const T& value);
    void print() const;
    void clear();
};

#endif  // LINKEDLIST_H
