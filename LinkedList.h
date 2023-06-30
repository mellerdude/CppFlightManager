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
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        clear();
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void remove(const T& value) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->data == value) {
                if (prev != nullptr)
                    prev->next = curr->next;
                else
                    head = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            // Print or do something with curr->data
            curr = curr->next;
        }
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
    }

    T getItemByPos(int pos) const {
        Node* curr = head;
        int memberNumber = 0;
        while (curr != nullptr) {
            if (memberNumber == pos) {
                return curr->data;
            }
            curr = curr->next;
            memberNumber++;
        }
        // Return a default value of type T if the position is out of range
        // or the linked list is empty
        return T();
    }
};

#endif  // LINKEDLIST_H
