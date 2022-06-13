#pragma once

#include <cstddef>
using ValueType = double;

class queueimpl {
public:
    virtual void push(const ValueType& value) = 0;
    virtual void pop() = 0;

    virtual const ValueType& front() const = 0;

    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;

    virtual ~queueimpl() = default;

    
};
