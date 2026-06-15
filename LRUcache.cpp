#include "LRUcache.h"
#include <iostream>

using namespace std;
LRUCache::LRUCache(int cap)
{
    capacity = cap;

    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
}
void LRUCache::insert(Node* node)
{
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}
void LRUCache::remove(Node* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
int LRUCache::get(int key)
{
    if(cache.find(key) == cache.end())
        return -1;

    Node* node = cache[key];

    remove(node);

    insert(node);

    return node->value;
}
void LRUCache::put(int key, int value)
{
    if(cache.find(key) != cache.end())
    {
        Node* node = cache[key];

        remove(node);

        cache.erase(key);

        delete node;
    }

    if(cache.size() == capacity)
    {
        Node* lru = tail->prev;

        remove(lru);

        cache.erase(lru->key);

        delete lru;
    }

    Node* node = new Node(key, value);

    insert(node);

    cache[key] = node;
}