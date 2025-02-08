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
        LRUCache(int capacity);
        ~LRUCache();
        V get(K key);
        void put(K key,V value);
};

#endif