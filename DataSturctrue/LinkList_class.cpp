/*
单链表
初始化
头插 尾插 第k个元素后面插入
头删 尾删
更改第k个元素
*/

#include <bits/stdc++.h>

using namespace std;

class LinkList {
    public:
    struct Node {
        int val;
        Node* next = nullptr;
    };
    Node* init() {
        Node* node = new Node;
        return node;
    }
    Node* init(int x) {
        Node* node = new Node;
        node->val = x;
        return node;
    }
    Node* init(Node* &a, int x) {
        a->next = init(x);
        return a;
    }
    void head_insert(Node* &a, int x) { 
        Node* head = new Node;
        head->val = x;
        head->next = a;
        a = head;
    }
    void tail_insert(Node* &a, int x) {
        Node* head = new Node;
        head = a;
        while (a->next != nullptr) {
            a = a->next;
        }
        Node* tmp = new Node;
        tmp->val = x;
        a->next = tmp;
        a = head;
    }
    void k_insert (Node* &a, int k, int x) {
        if (k == 0) head_insert(a, x);
        Node* ret = new Node;
        ret = a;
        for (; a != nullptr && k > 1; k --) {
            a = a->next;
        }   
        if (a == nullptr && k) {
            a = ret;
            return;
        }
        Node* tmp = new Node;
        tmp->val = x;
        tmp->next = a->next;
        a->next = tmp;
        a = ret;
    }
    void head_delete(Node* &a) {
        if (a == nullptr) return;
        a = a->next;
    }
    void tail_delete(Node* &a) {
        if (a->next == nullptr) {
            a = new Node;
            return;
        }
        Node* ret = new Node;
        ret = a;
        while (a->next->next != nullptr) {
            a = a->next;
        }
        a->next = nullptr;
        a = ret;
    }
    void k_change(Node* &a, int k, int x) {
        Node* ret = new Node;
        ret = a;
        for (; a != nullptr && k > 1; k --) {
            a = a->next;
        }
        if (a == nullptr && k) {
            a = ret;
            return;
        }
        a->val = x;
        a = ret;
    }
};

int main () {
    LinkList s;
    LinkList::Node* l = s.init(1);
    s.head_insert(l, 0);
    s.head_insert(l, 12);
    s.tail_insert(l, 5);
    s.tail_insert(l, 5);
    s.tail_insert(l, 5);
    s.k_insert(l, 4, -1);
    s.head_delete(l);
    s.tail_delete(l);
    s.k_change(l, 6, 9);
    while (l != nullptr) {
        cout << (l->val) << ' ';
        l = l->next;
    }
    return 0;
}
