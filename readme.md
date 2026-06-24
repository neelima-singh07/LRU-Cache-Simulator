# LRU Cache Simulator

A high-performance **Least Recently Used (LRU) Cache** implementation in C++ that simulates cache memory behavior with efficient O(1) operations for both get and put operations.

## Overview

This project implements an LRU cache data structure that automatically evicts the least recently used item when the cache reaches its capacity. It's commonly used in CPU caches, web browsers, database management systems, and other applications requiring fast data retrieval with limited memory constraints.

## Features

- **O(1) Time Complexity**: Both `get()` and `put()` operations run in constant time
- **Efficient Memory Management**: Automatic eviction of least recently used items
- **Thread-Safe Operations**: Built for reliable concurrent access patterns
- **Flexible Configuration**: Easily customizable cache capacity
- **Optimized Data Structures**: Uses a doubly-linked list and hash map for optimal performance

## How It Works

The LRU Cache combines two data structures:

1. **Doubly-Linked List**: Maintains the order of items based on their usage recency
   - Most recently used items are at the head
   - Least recently used items are at the tail

2. **Hash Map**: Provides O(1) access to cache nodes
   - Maps cache keys to their corresponding nodes in the linked list

### Operations

- **`get(key)`**: Retrieves a value and marks it as recently used
- **`put(key, value)`**: Inserts or updates a key-value pair; evicts LRU item if cache is full
- **`capacity`**: Maximum number of items the cache can store

## Usage

```cpp
#include "LRUCache.h"

int main() {
    // Create an LRU cache with capacity of 5
    LRUCache cache(5);
    
    // Put items in cache
    cache.put(1, "apple");
    cache.put(2, "banana");
    cache.put(3, "cherry");
    
    // Get items from cache
    auto value = cache.get(1);  // Returns "apple", marks as recently used
    
    // Add more items
    cache.put(4, "date");
    cache.put(5, "elderberry");
    cache.put(6, "fig");        // Evicts least recently used item
    
    return 0;
}
