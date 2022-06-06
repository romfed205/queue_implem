#pragma once

#include "queueimp.h"
#include "listimp.h"

class queuelist : public queueimpl {
public:

    queuelist() = default;
    queuelist(const ValueType* valueArray, const size_t arraySize);

    void push(const ValueType& value) override;
    void pop() override;

    const ValueType& front() const override;

    bool isEmpty() const override;
    size_t size() const override;

private:

    List _list;
};
