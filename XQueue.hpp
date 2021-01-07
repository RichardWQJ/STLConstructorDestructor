#ifndef _VIEW_ACTUATOR_QUEUE_HPP_
#define _VIEW_ACTUATOR_QUEUE_HPP_

#include <iostream>
#include <queue>
#include <mutex>

template <typename T>
class XQueue
{
public:
    XQueue() {}
    virtual ~XQueue() {}
    bool IsEmpty();    //队列的判空
    int Size();        //队列的大小
    void Push(T node); //入队列
    void Pop();        //出队列
    T Front();         //队首元素

private:
    std::mutex m_mtx;
    std::queue<T> m_queue;
};

template <typename T>
bool XQueue<T>::IsEmpty()
{
    std::lock_guard<std::mutex> lockGuard(m_mtx);
    return m_queue.empty();
}

template <typename T>
int XQueue<T>::Size()
{
    std::lock_guard<std::mutex> lockGuard(m_mtx);
    return m_queue.size();
}

template <typename T>
void XQueue<T>::Push(T node)
{
    std::lock_guard<std::mutex> lockGuard(m_mtx);
    m_queue.push(node);
}

template <typename T>
void XQueue<T>::Pop()
{
    std::lock_guard<std::mutex> lockGuard(m_mtx);
    m_queue.pop();
}

template <typename T>
T XQueue<T>::Front()
{
    std::lock_guard<std::mutex> lockGuard(m_mtx);
    return m_queue.front();
}

#endif //!_VIEW_ACTUATOR_QUEUE_HPP_