
#include "StackNode.h"

Module::StackNode::StackNode(int pIndex)
{
    index = pIndex;
    next = nullptr;
}

Module::StackNode::StackNode(int pIndex, StackNode* pNext)
{
    index = pIndex;
    next = pNext;
}

Module::StackNode::~StackNode()
{
}

bool Module::StackNode::addSorted(int pIndex)
{
    if (pIndex < index)
    {
        int lTemp = index;
        index = pIndex;
        addAfter(lTemp);
    }
    if (pIndex == index)
    {
        return false;
    }
    else if (next != nullptr)
    {
        next->addSorted(pIndex);
    }
    else
    {
        addAfter(pIndex);
    }
    return true;
}

void Module::StackNode::addAfter(int pIndex)
{
    StackNode * temp = next;
    next = new StackNode(pIndex, temp);
}
