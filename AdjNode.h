
#pragma once

namespace Module
{
    // Linked list of string data type
    class AdjNode
    {
    public:
        int index;
        AdjNode * next;

        AdjNode() = delete;
        ~AdjNode();

        AdjNode(int pIndex);
        AdjNode(int pIndex, AdjNode* pNext);

        bool addSorted(int pIndex);
        void addAfter(int pIndex);
    };


}
