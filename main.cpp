#include <iostream>
#include "LRUcache.h"

using namespace std;

int main()
{
    int capacity;

    cout << "========== LRU Cache Simulator ==========\n";
    cout << "Enter Cache Capacity: ";
    cin >> capacity;

    LRUCache cache(capacity);

    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Put Data\n";
        cout << "2. Get Data\n";
        cout << "3. Display Cache\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int key, value;

            cout << "Enter Key: ";
            cin >> key;

            cout << "Enter Value: ";
            cin >> value;

            cache.put(key, value);

            cout << "Data inserted successfully.\n";
            break;
        }

        case 2:
        {
            int key;

            cout << "Enter Key: ";
            cin >> key;

            int value = cache.get(key);

            if (value == -1)
                cout << "Key not found in cache.\n";
            else
                cout << "Value = " << value << endl;

            break;
        }

        case 3:
        {
            cache.displayCache();
            break;
        }

        case 4:
        {
            cout << "\nExiting LRU Cache Simulator...\n";
            break;
        }

        default:
        {
            cout << "Invalid Choice! Please try again.\n";
        }
        }

    } while (choice != 4);

    return 0;
}