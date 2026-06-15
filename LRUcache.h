#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <unordered_map>
#include "Node.h"

using namespace std;

class LRUCache
{
private:

    int capacity;

    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

public:

    LRUCache(int cap);

    void insert(Node* node);

    void remove(Node* node);

    int get(int key);

    void put(int key, int value);

    void displayCache();
};

#endif