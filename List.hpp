#ifndef _CUSTOMIZED_LIST_HPP_
#define _CUSTOMIZED_LIST_HPP_

#include <iostream>
#include <string>
#include <mutex>
#include <list>

template <typename N>
static inline bool Compare(const N& node1, const N& node2)
{
    return node1 < node2; //由小到大排序
}

template <typename T>
class List
{
public:
    List() {}
    ~List() {}

    void PushBack(const T &node)
    {
        std::lock_guard<std::mutex> lockGuard(m_mtx);
        m_list.push_back(node);
    }

    T Front()
    {
        std::lock_guard<std::mutex> lockGuard(m_mtx);
        return m_list.front();
    }

    void PopFront()
    {
        std::lock_guard<std::mutex> lockGuard(m_mtx);
        m_list.pop_front();
    }

    bool Empty()
    {
        std::lock_guard<std::mutex> lockGuard(m_mtx);
        return m_list.empty();
    }

    void Resize(const size_t &size)
    {
        std::lock_guard<std::mutex> lockGuard(m_mtx);
        m_list.resize(size);
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> lockGuard(m_mtx);
        return m_list.size();
    }

    void Sort()
    {
        std::lock_guard<std::mutex> lockGuard(m_mtx);
        return m_list.sort();
    }

private:
    std::mutex m_mtx;
    std::list<T> m_list;

private:
    List(const List &);
    List &operator=(const List &);
};

#endif //!_CUSTOMIZED_LIST_HPP_