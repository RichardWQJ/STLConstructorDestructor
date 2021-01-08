#ifndef _NODE_INFO_HPP
#define _NODE_INFO_HPP

#include <iostream>
#include <string>

class NodeInfo
{
public:
    NodeInfo() {}
    NodeInfo(int priority, std::string nodeName)
        : m_iPriority(priority), m_nodeName(nodeName) {}

    ~NodeInfo() {}

    bool operator>(const NodeInfo &nodeInfo) const
    {
        std::cout << "operator < ..." << std::endl;
        return this->GetPriority() > nodeInfo.GetPriority();
    }

    int GetPriority() const
    {
        return m_iPriority;
    }

    std::string GetNodeName()
    {
        return m_nodeName;
    }

private:
    int m_iPriority = -1;
    std::string m_nodeName;
};

#endif //!_NODE_INFO_HPP