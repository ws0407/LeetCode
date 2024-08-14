#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int _val) : val(_val), next(nullptr) {}
    };

    MyLinkedList() {
        _dummy = new LinkedNode(0);
        int _size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= _size) return -1;
        LinkedNode* cur = _dummy->next;
        while(index--) cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = _dummy->next;
        _dummy->next = node;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = _dummy;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size) return;
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = _dummy;
        while (index--) cur = cur->next;
        node->next = cur->next;
        cur->next = node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size) return;
        LinkedNode* cur = _dummy;
        while (index--) cur = cur->next;
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }

    void printLinkedList(){
        LinkedNode* cur = _dummy->next;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode* _dummy;
};


int main(){
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList.get(1);              // 返回 2
    myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
    myLinkedList.get(1);              // 返回 3

    myLinkedList.printLinkedList();
    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */