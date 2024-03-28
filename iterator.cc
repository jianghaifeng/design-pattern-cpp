#include <iostream>

using namespace std;

struct ListNode {
    ListNode* next;
    int val;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
public:
    class Iterator {
    private:
        ListNode* current;
    public:
        Iterator(ListNode* node) {
            current = node;
        }

        int& operator*() const {
            return current->val;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    LinkedList() {
        head = new ListNode(0);
        tail = head;
    }
    ~LinkedList() {
        while (head != nullptr) {
            ListNode* p = head;
            head = head->next;
            delete p;
        }
    }

    void push_back(const int& val) {
       if (head == nullptr) head = tail = new ListNode(val);
       else tail->next = new ListNode(val), tail = tail->next;
    }

    Iterator begin() const {
        return Iterator(head->next);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    for (auto iter=list.begin(); iter!=list.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
