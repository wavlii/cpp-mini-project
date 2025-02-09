#include "include\lru\LRUCache.h"

template <typename K, typename V>
LRUCache<K, V>::LRUCache(int cap) : capacity(cap), size(0)
{
    head = new node(K(), V());
    tail = new node(K(), V());
    head->next = tail;
    tail->prev = head;         
}

template <typename K, typename V>
LRUCache<K, V>::~LRUCache() {
    node* curr = head;
    while (curr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }
}