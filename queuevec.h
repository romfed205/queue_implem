#pragma once

#include "queueimp.h"
#include <vector>


using std::vector;


class VectorQueue : public queueimpl{
public:
    VectorQueue() = default;
    VectorQueue(const ValueType* valueArray, const size_t arraySize);

    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& front() const override;

    bool isEmpty() const override;
    size_t size() const override;

private:
    std::vector<ValueType> vecvec;
    size_t step_one = 0;

};