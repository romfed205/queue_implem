#include "listimp.h"

List::Node::Node(ValueType value, Node* next) {
    this->value = value;
    this->next = next;
}

List::List() {
    _root = new Node(0);
    _back = _root;
}

List::List(const ValueType* array, const size_t arraySize):
    List()
{
    insert(0, array, arraySize);
}

List::List(const List& other):
    List()
{
    insert(0, other);
}

List::~List() {
    clear();
}

List& List::operator=(const List& other){
    if (this != &other) {
        clear();
        insert(0, other);
    }
    return *this;
}

List::List(List&& other) noexcept: List(){
    _root->next = other._root->next;
    _size = other._size;
    _back = other._back;
    other._root->next = nullptr;
    other._back = other._root;
    other._size = 0;
}

List& List::operator=(List&& other) noexcept {
    if (this != &other) {
        clear();
        _root->next = other._root->next;
        _size = other._size;
        _back = other._back;
        other._root->next = nullptr;
        other._back = other._root;
        other._size = 0;
    }
    return *this;
}

const ValueType& List::front() const {
    return _root->next->value;
}

const ValueType& List::back() const {
    return _back->value;
}

void List::insert(size_t pos, const ValueType& value) {
    insert(pos, &value, 1);
}

void List::pushBack(const ValueType& value) {
    _back->next = new Node(value);
    _back = _back->next;
    _size++;
}

void List::pushFront(const ValueType& value) {
    List::Node* front = _root->next;
    _root->next = new Node(value, front);
    _size++;
}

void List::insert(size_t pos, const ValueType* array, const size_t arraySize) {
    List::Node* current = parentNode(pos);
    List::Node* afterParent = current->next;
    for (size_t i = 0; i < arraySize; i++) {
        current->next = new Node(array[i]);
        current = current->next;
    }
    current->next = afterParent;
    if (afterParent == nullptr) {
        _back = current;
    }
    _size += arraySize;
}

void List::insert(size_t pos, const List& other) {
    List::Node* current = parentNode(pos);
    List::Node* afterParent = current->next;
    List::Node* node = other._root;
    while (node->next != nullptr) {
        node = node->next;
        current->next = new Node(node->value);
        current = current->next;
    }
    current->next = afterParent;
    if (afterParent == nullptr) {
        _back = current;
    }
    _size += other.size();
}

void List::erase(size_t pos, size_t count) {
    List::Node* parent = parentNode(pos);
    List::Node* current = parent->next;
    List::Node* next;
    for (size_t i = 0; i < count && current != nullptr; i++) {
        next = current->next;
        delete current;
        current = next;
    }
    parent->next = current;
    if (current == nullptr) {
        _back = parent;
    }
    _size -= count;
}

void List::eraseBetween(size_t beginPos, size_t endPos) {
    erase(beginPos, endPos - beginPos);
}

void List::popBack() {
    erase(size() - 1);
}

void List::popFront() {
    erase(0);
}

void List::clear() {
    eraseBetween(0, size());
}

List::Node* List::find(const ValueType& value) {
    return const_cast<List::Node*>(const_cast<const List*>(this)->find(value));
}

const List::Node* List::find(const ValueType& value) const {
    const List::Node* current = _root;
    while (current->next != nullptr) {
        current = current->next;
        if (current->value == value) {
            return current;
        }
    }
    return nullptr;
}

bool List::isEmpty() const {
    return size() == 0;
}

size_t List::size() const {
    return _size;
}

List::Node* List::parentNode(size_t pos) {
    return const_cast<List::Node*>(const_cast<const List*>(this)->parentNode(pos));
}

const List::Node* List::parentNode(size_t pos) const {
    size_t current = 0;
    List::Node* node = _root;
    while (node->next != nullptr && current < pos) {
        node = node->next;
        current++;
    }
    return node;
}

std::ostream& operator<<(std::ostream& st, const List& list) {
    List::Node* node = list._root->next;
    while (node != nullptr) {
        st << node->value << ", ";
        node = node->next;
    }
    st << ";";
    return st;
}
