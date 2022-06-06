#pragma once 

using std::runtime_error;
#include <stdexcept>
#include "queuewithlist.h"


queuelist::queuelist(const ValueType* valueArray, const size_t arraySize) {
    _list.insert(0, valueArray, arraySize);
}

void queuelist::push(const ValueType& value) {
    _list.pushBack(value);
}

void queuelist::pop() {
    if (isEmpty()) {
        throw runtime_error("Chill out Mr");
    }
    _list.popFront();
}

size_t queuelist::size() const {
    return _list.size();
}

const ValueType& queuelist::front() const {
    return _list.front();
}

bool queuelist::isEmpty() const {
    return size() == 0;
}