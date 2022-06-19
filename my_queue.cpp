#pragma once

#include "my_queue.h"
#include "listimp.h"
#include "queueimp.h"
#include "queuevec.h"
#include "queuewithlist.h"

#include <stdexcept>

Queue::Queue(QueueContainer container){
    setImplementation(container);
}

Queue::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container){
    setImplementation(container);
    for (size_t i = 0; i < arraySize; i++) {
        push(valueArray[i]);
    }
}

Queue::~Queue(){
    delete _pimpl;
}

Queue::Queue(const Queue& queueref) : _containerType(queueref._containerType){setImplementation(queueref);}

Queue& Queue::operator=(const Queue& queueref){
    if (this != &queueref) {
        delete _pimpl;
        setImplementation(queueref);
    }
    return *this;
}

Queue::Queue(Queue&& moveQueue) noexcept{
    _containerType = moveQueue._containerType;
    _pimpl = moveQueue._pimpl;
    moveQueue._pimpl = nullptr;
}

Queue& Queue::operator=(Queue&& moveQueue) noexcept{
    if (this != &moveQueue) {
        delete _pimpl;
        _containerType = moveQueue._containerType;
        _pimpl = moveQueue._pimpl;
        moveQueue._pimpl = nullptr;
    }
    return *this;
}

void Queue::push(const ValueType& value){
    _pimpl->push(value);
}

void Queue::pop(){
    _pimpl->pop();
}

const ValueType& Queue::front() const{
    return _pimpl->front();
}

bool Queue::isEmpty() const{
    return _pimpl->isEmpty();
}

size_t Queue::size() const{
    return _pimpl->size();
}

void Queue::setImplementation(QueueContainer container){
    switch (container)
    {
        case QueueContainer::List:{
            _pimpl = static_cast<queueimpl*>(new queuelist());
            break;
        }
        case QueueContainer::Vector:{
            _pimpl = static_cast<queueimpl*>(new VectorQueue());
            break;
        }
        default:
            throw std::runtime_error("No result bro");
    }
    _containerType = container;
}

void Queue::setImplementation(const Queue& queueref){
    switch (queueref._containerType){
        case QueueContainer::List:{
            _pimpl = static_cast<queueimpl*>(new queuelist(*dynamic_cast<queuelist*>(queueref._pimpl)));
            break;
        }
        case QueueContainer::Vector:{
            _pimpl = static_cast<queueimpl*>(new VectorQueue(*dynamic_cast<VectorQueue*>(queueref._pimpl)));
            break;
        }
        default:
            throw std::runtime_error("No result bro");
    }
    _containerType = queueref._containerType;
}