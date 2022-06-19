#pragma once

#include <cstddef>

using ValueType = double;

//QueueContainer

enum class QueueContainer{
    Vector = 0,
    List,
    
};

class queueimpl;

class Queue{
public:
    Queue(QueueContainer container = QueueContainer::Vector);
    Queue(const ValueType* valueArray, const size_t arraySize,
          QueueContainer container = QueueContainer::Vector);

    ~Queue();

    explicit Queue(const Queue& queueref);
    Queue& operator=(const Queue& queueref);

    Queue(Queue&& moveStack) noexcept;
    Queue& operator=(Queue&& moveStack) noexcept;

    void push(const ValueType& value);
    void pop();
    const ValueType& front() const;
    bool isEmpty() const;
    size_t size() const;

private:

    queueimpl* _pimpl = nullptr;
    QueueContainer _containerType;

    void setImplementation(QueueContainer container);
    void setImplementation(const Queue& queue);
};