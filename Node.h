
#pragma once

namespace Module
{
    class Node
    {
    public:
        /* data */
        int mNodeID;
        int mYear;

    public:
        Node();
        ~Node();

        Node(int pNodeID, int pYear);
    };
}
