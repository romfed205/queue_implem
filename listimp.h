#pragma once

#include <ostream>
#include <cstddef>

using ValueType = double;

class List {
public:
    struct Node {
        ValueType value;
        Node* next;
        Node(ValueType value, Node* next = nullptr);
    };

    List();
    ~List();
    List(const ValueType* array, const size_t arraySize);

    List(const List& other);
    List& operator=(const List& other);

    List(List&& other) noexcept;
    List& operator=(List&& other) noexcept;

    const ValueType& front() const;
    const ValueType& back() const;

    void insert(size_t pos, const ValueType& value);
    void insert(size_t pos, const ValueType* array, const size_t arraySize);
    void insert(size_t pos, const List& other);
    void pushBack(const ValueType& value);
    void pushFront(const ValueType& value);

    void erase(size_t pos, size_t count = 1);
    void eraseBetween(size_t beginPos, size_t endPos);
    void popBack();
    void popFront();
    void clear();

    Node* find(const ValueType& value);
    const Node* find(const ValueType& value) const;

    bool isEmpty() const;
    size_t size() const;

    friend std::ostream& operator<<(std::ostream& st, const List& list);

private:
    size_t _size = 0;
    Node* _root;
    Node* _back = nullptr;

    Node* parentNode(size_t pos);
    const Node* parentNode(size_t pos) const;
};
