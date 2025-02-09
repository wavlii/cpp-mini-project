#ifndef LRUCACHE_H
#define LRUCACHE_H

#include<unordered_map>

template<typename K,typename V>
class LRUCache
{
    private:
        struct node
        {
            K key;
            V value;
            node* prev;
            node* next;
            node(K,k,V,v):key(k),value(v),prev(nullptr),next(nullptr){}
        };
        using cacheMap = std::unoedered_map<K,node*>;
        cacheMap cache;
        node* head;
        node* tail;
        int capacity;
        int size;
        void moveTohead(node* );
        void removeNode(node* );
        void addTohead(node* );
    pubilc:
        LRUCache(int cap):capacity(cap),size(0)
        {
            head = new node(K(),V());
            tail = new node(K(),V());
            head->next = tail;head->prev = nullptr;
            tail->prev = head;tail->next = nullptr;
        }
        ~LRUCache()
        {
            node* curr = head;
            while(curr)
            {
                node* temp = curr->next;
                delete curr;
                curr = temp;
            }
            delete head;
            head = nullptr;
        }
        V get(K key)
        {
            //review if the cache has this 'key'
            if(!cache.count(key)) return V();
            node* Node = cache[key];
            moveTohead(Node);
            return Node->value;
        }
        void put(K key,V value);
};



#endif