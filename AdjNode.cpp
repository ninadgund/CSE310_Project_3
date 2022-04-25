
#include "AdjNode.h"

Module::AdjNode::AdjNode(int pIndex)
{
    index = pIndex;
    next = nullptr;
}

Module::AdjNode::AdjNode(int pIndex, AdjNode* pNext)
{
    index = pIndex;
    next = pNext;
}

// Should delete the whole list when deleting the top
Module::AdjNode::~AdjNode()
{
    if (next != nullptr)
    {
        delete next;
    }
}

// Add in the list at sorted location
bool Module::AdjNode::addSorted(int pIndex)
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

// Add in the list after current eliment
void Module::AdjNode::addAfter(int pIndex)
{
    AdjNode * temp = next;
    next = new AdjNode(pIndex, temp);
}
