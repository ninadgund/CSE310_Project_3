
#pragma once

namespace Module
{
    // Linked list of int data type
    class StackNode
    {
    public:
        int index;
        StackNode * next;

        StackNode() = delete;
        ~StackNode();

        StackNode(int pIndex);
        StackNode(int pIndex, StackNode* pNext);

        bool addSorted(int pIndex);
        void addAfter(int pIndex);
    };


}
