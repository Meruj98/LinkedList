#include <iostream>
#include <string>


template<typename T>
struct node {
    T data;
    node *next;

    node() {}

    node(T data, node *next = nullptr) {
        this->data = data;
    }
};

template<typename T>
class doubly_linked_list {
private:
    node<T> *head;
    node<T> *tail;


public:
    doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(T data) {
        node<T> *tmp = new node<T>();
        tmp->data = data;
        tmp->next = nullptr;
        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void push_front(T data) {
        node<T> *cur = new node<T>;
        cur->next = head;
        cur->data = data;
        head = cur;
    }

    void removeAt(int pos) {

        if (head == nullptr) {
            return;
        }

        node<T> *tmp = head;

        int size = getSize();

        if (pos == 0) {
            head = tmp->next;
            free(tmp);
            return;
        }

        for (int i = 0; tmp != nullptr && i < pos - 1; i++) {
            tmp = tmp->next;
        }

        if (tmp == nullptr || tmp->next == nullptr) {
            return;
        }

        node<T> *next = tmp->next->next;

        free(tmp->next);
        tmp->next = next;
    }

    node<T> *getHead() {
        return head;
    }

    node<T> *getTail() {
        return tail;
    }

    void display() {
        node<T> *n = head;
        while (n != nullptr) {
            std::cout << n->data << std::endl;
            n = n->next;
        }
    }

    int getSize() {
        int size = 0;
        node<T> *n = head;
        while (n != nullptr) {
            size++;
            n = n->next;
        }
        return size;
    }

    void insert(T data, int pos) {

        int size = getSize();

        if (size > 0) {
            if (pos > 0 && pos < size) {
                node<T> *cur = head;
                for (int i = 0; i < pos; ++i) {
                    cur = cur->next;
                }
                node<T> *tmp = new node<T>();
                tmp->data = data;
                tmp->next = cur->next;
                cur->next = tmp;
            }
            if(pos == 0){
                node<T> *cur = new node<T>;
                cur->next = head;
                cur->data = data;
                head = cur;
            }

        }


    }

    T get(int pos) {
        node<T> *cur = head;
        int count = 0;
        while (cur != nullptr) {
            if (count == pos) {
                return cur->data;
            }
            count++;
            cur = cur->next;
        }

    }

    bool isEmpty() {
        return head == nullptr;
    }

};


int main() {
    doubly_linked_list<int> list;
    doubly_linked_list<int> list2;
    for (int i = 1; i < 11; i++) {
        list.push_back(i);
    }
    list.insert(12, 0);
    list.removeAt(1);
    list.push_front(-123);
    list.display();
    int n = 3;
    std::cout << "Element at index " << n << " is " << list.get(2) << std::endl;

    int size = list.getSize();

    doubly_linked_list<std::string> stringList;
    if (stringList.isEmpty()) {
        std::cout << "Empty string list" << std::endl;
    } else {
        std::cout << "Not empty string list" << std::endl;
    }

    std::cout << "Size of list is:" << size;
    return 0;
}