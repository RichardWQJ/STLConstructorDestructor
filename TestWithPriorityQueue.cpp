#include <iostream>
#include <memory>
#include <string>
#include "PriorityQueue.hpp"
#include "NodeInfo.hpp"

#if 0
int main()
{
    PriorityQueue<std::shared_ptr<NodeInfo>> nodeQueue;

    std::shared_ptr<NodeInfo> nodeInfo1 = std::make_shared<NodeInfo>(1, "Node1");
    std::shared_ptr<NodeInfo> nodeInfo5 = std::make_shared<NodeInfo>(5, "Node5");
    std::shared_ptr<NodeInfo> nodeInfo2 = std::make_shared<NodeInfo>(2, "Node2");
    std::shared_ptr<NodeInfo> nodeInfo4 = std::make_shared<NodeInfo>(4, "Node4");
    std::shared_ptr<NodeInfo> nodeInfo3 = std::make_shared<NodeInfo>(3, "Node3");
    std::shared_ptr<NodeInfo> nodeInfo6 = std::make_shared<NodeInfo>(6, "Node6");

    nodeQueue.Push(nodeInfo1);
    nodeQueue.Push(nodeInfo5);
    nodeQueue.Push(nodeInfo2);
    nodeQueue.Push(nodeInfo4);
    nodeQueue.Push(nodeInfo3);
    nodeQueue.Push(nodeInfo6);

    int length = nodeQueue.Size();
    for (int index = 0; index < length; index++)
    {
        std::cout << "Name: " << nodeQueue.Top()->GetNodeName().c_str()
                  << ", Priority: " << nodeQueue.Top()->GetPriority() << std::endl;
        nodeQueue.Pop();
    }

    getchar();
    return 0;
}
#endif

#if 1
int main()
{
    PriorityQueue<NodeInfo> nodeQueue;

    NodeInfo nodeInfo1(1, "Node1");
    NodeInfo nodeInfo5(5, "Node5");
    NodeInfo nodeInfo2(2, "Node2");
    NodeInfo nodeInfo4(4, "Node4");
    NodeInfo nodeInfo3(3, "Node3");
    NodeInfo nodeInfo6(6, "Node6");

    nodeQueue.Push(nodeInfo1);
    nodeQueue.Push(nodeInfo5);
    nodeQueue.Push(nodeInfo2);
    nodeQueue.Push(nodeInfo4);
    nodeQueue.Push(nodeInfo3);
    nodeQueue.Push(nodeInfo6);

    int length = nodeQueue.Size();
    for (int index = 0; index < length; index++)
    {
        std::cout << "Name: " << nodeQueue.Top().GetNodeName().c_str()
                  << ", Priority: " << nodeQueue.Top().GetPriority() << std::endl;
        nodeQueue.Pop();
    }

    getchar();
    return 0;
}
#endif