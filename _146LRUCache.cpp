//
// Created by Fangzhou Zhang on 2020/5/11.
//
class MyNode {
public:
    MyNode *pre;
    MyNode *next;
    int key;
    int value;
    MyNode(int k, int v) {
        key = k;
        value = v;
        pre = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int, MyNode*> map;
    int size;
    MyNode *head;
    MyNode *tail;
    LRUCache(int capacity) {
        size = capacity;
        head = new MyNode(0, 0);
        tail = new MyNode(0, 0);

        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (map.count(key) > 0) {
            MyNode *node = map[key];
            moveToHead(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (map.count(key) > 0) {
            MyNode *node = map[key];
            node->value = value;
            get(key);
        } else {
            MyNode *node = new MyNode(key, value);
            if (map.size() >= size) {
                MyNode *del = popTail();
                map.erase(del->key);
                deleteNode(del);
            }
            append(node);
            map[key] = node;
        }
    }

    void append(MyNode *node) {
        MyNode *first = head->next;


        node->pre = head;
        node->next = first;

        head->next = node;
        first->pre = node;
    }

    void deleteNode(MyNode *node) {
        MyNode *delPre = node->pre;
        MyNode *delNext = node->next;

        delPre->next = delNext;
        delNext->pre = delPre;
    }

    MyNode * popTail() {
        MyNode * del = tail->pre;
        deleteNode(del);
        return del;
    }

    void moveToHead(MyNode *node) {
        deleteNode(node);
        append(node);
    }
};
