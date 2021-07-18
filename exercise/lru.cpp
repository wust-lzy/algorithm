#include<bits/stdc++.h>
using namespace std;



struct node
{
    int key, val;
    node *pre;
    node *next;
    node ():key(0),val(0),pre(nullptr),next(nullptr){}
    node(int _key,int _value):key(_key),val(_value),pre(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, node *> cache;
    node *head;
    node *tail;
    int size;
    int capacity;

public:
    LRUCache(int c) {
        capacity = c;
        size = 0;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if(!cache.count(key))
            return -1;
        else{   //如果存在结点
            node *t = cache[key];//取出来 移到头部
            move_head(t);//移到头部
            return t->val;
        }    
    }
    void put(int key, int value) {
        if(!cache.count(key)){//不存在 添加进来
            node *t = new node(key, value);
            cache[key] = t;//加进哈希表
            add_head(t);
            size++;
            if(size>capacity){
                node *d = remove_tail();
                cache.erase(d->key);
                delete d;
                size--;
            }
        }
        else{
            node *t = cache[key];//已经存在
            t->val = value;
            move_head(t);
        }
    }

    void remove(node*t){//清除结点
        t->pre->next = t->next;
        t->next->pre = t->pre;
    }

    void add_head(node *t){//把t插入头部
        t->pre = head;
        t->next = head->next;
        head->next->pre = t;
        head->next = t;
    }

    void move_head(node*t){ //把一个结点移到头部
        remove(t);
        add_head(t);
    }

    node* remove_tail(){  //扫尾
        node *t = tail->pre;
        remove(t);
        return t;
    }
};