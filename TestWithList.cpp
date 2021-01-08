#include <memory>
#include "List.hpp"
#include "NodeInfo.hpp"

#if 0
int main()
{
    List<std::shared_ptr<NodeInfo>> nodeList;

    std::shared_ptr<NodeInfo> nodeInfo1 = std::make_shared<NodeInfo>(1, "Node1");
    std::shared_ptr<NodeInfo> nodeInfo5 = std::make_shared<NodeInfo>(5, "Node5");
    std::shared_ptr<NodeInfo> nodeInfo2 = std::make_shared<NodeInfo>(2, "Node2");
    std::shared_ptr<NodeInfo> nodeInfo4 = std::make_shared<NodeInfo>(4, "Node4");
    std::shared_ptr<NodeInfo> nodeInfo3 = std::make_shared<NodeInfo>(3, "Node3");
    std::shared_ptr<NodeInfo> nodeInfo6 = std::make_shared<NodeInfo>(6, "Node6");

    nodeList.PushBack(nodeInfo1);
    nodeList.PushBack(nodeInfo5);
    nodeList.PushBack(nodeInfo2);
    nodeList.PushBack(nodeInfo4);
    nodeList.PushBack(nodeInfo3);
    nodeList.PushBack(nodeInfo6);

    int length = nodeList.Size();
    std::cout << "Before Sort:" << std::endl;
    for (int index = 0; index < length; index++)
    {
        std::cout << "Name: " << nodeList.Front()->GetNodeName().c_str()
                  << ", Priority: " << nodeList.Front()->GetPriority() << std::endl;
        nodeList.PopFront();
    }

    nodeList.PushBack(nodeInfo1);
    nodeList.PushBack(nodeInfo5);
    nodeList.PushBack(nodeInfo2);
    nodeList.PushBack(nodeInfo4);
    nodeList.PushBack(nodeInfo3);
    nodeList.PushBack(nodeInfo6);
    nodeList.Sort();

    std::cout << "\nAfter Sort:" << std::endl;
    length = nodeList.Size();
    for (int index = 0; index < length; index++)
    {
        std::cout << "Name: " << nodeList.Front()->GetNodeName().c_str()
                  << ", Priority: " << nodeList.Front()->GetPriority() << std::endl;
        nodeList.PopFront();
    }

    getchar();
    return 0;
}
#endif

#if 1
int main()
{
    List<NodeInfo> nodeList;

    NodeInfo nodeInfo1(1, "Node1");
    NodeInfo nodeInfo5(5, "Node5");
    NodeInfo nodeInfo2(2, "Node2");
    NodeInfo nodeInfo4(4, "Node4");
    NodeInfo nodeInfo3(3, "Node3");
    NodeInfo nodeInfo6(6, "Node6");

    nodeList.PushBack(nodeInfo1);
    nodeList.PushBack(nodeInfo5);
    nodeList.PushBack(nodeInfo2);
    nodeList.PushBack(nodeInfo4);
    nodeList.PushBack(nodeInfo3);
    nodeList.PushBack(nodeInfo6);

    int length = nodeList.Size();
    std::cout << "Before Sort:" << std::endl;
    for (int index = 0; index < length; index++)
    {
        std::cout << "Name: " << nodeList.Front().GetNodeName().c_str()
                  << ", Priority: " << nodeList.Front().GetPriority() << std::endl;
        nodeList.PopFront();
    }

    nodeList.PushBack(nodeInfo1);
    nodeList.PushBack(nodeInfo5);
    nodeList.PushBack(nodeInfo2);
    nodeList.PushBack(nodeInfo4);
    nodeList.PushBack(nodeInfo3);
    nodeList.PushBack(nodeInfo6);
    nodeList.Sort();

    std::cout << "\nAfter Sort:" << std::endl;
    length = nodeList.Size();
    for (int index = 0; index < length; index++)
    {
        std::cout << "Name: " << nodeList.Front().GetNodeName().c_str()
                  << ", Priority: " << nodeList.Front().GetPriority() << std::endl;
        nodeList.PopFront();
    }

    getchar();
    return 0;
}
#endif
