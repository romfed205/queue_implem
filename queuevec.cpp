#include <stdexcept>

#include "queuevec.h"

VectorQueue::VectorQueue(const ValueType* valueArray, const size_t arraySize){
    vecvec.insert(vecvec.begin(), valueArray, valueArray + arraySize);
}

void VectorQueue::push(const ValueType& value){
    vecvec.push_back(value);
}

const ValueType& VectorQueue::front() const{
    return vecvec[step_one];
}

void VectorQueue::pop(){
    if (isEmpty()) {
        throw std::runtime_error("Can't pop from empty queue");
    }
    step_one++;
}

size_t VectorQueue::size() const{
    return vecvec.size() - step_one;
}

bool VectorQueue::isEmpty() const{
    return size() == 0;
}