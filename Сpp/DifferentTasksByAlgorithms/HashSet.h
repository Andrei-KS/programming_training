/*
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet.
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
*/

#include <array>

const int MAXSZIE = 250;
class MyHashSet {
    struct Node {
        int val;
        Node* next;
        Node() :val(-1), next(nullptr) {}
        Node(int val) :val(val), next(nullptr) {}
    };

    std::array<Node*, MAXSZIE> arr;
    int hashFunction(int key) { return (key + 1000007) % MAXSZIE; }

public:
    /** Initialize your data structure here. */
    MyHashSet();
    ~MyHashSet();

    void add(int key);

    void remove(int key);

    /** Returns true if this set contains the specified element */
    bool contains(int key);
};