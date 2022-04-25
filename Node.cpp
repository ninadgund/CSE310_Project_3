
#include "Node.h"

Module::Node::Node()
{
    mNodeID = -1;
    mYear = -1;
}

Module::Node::Node(int pNodeID, int pYear)
{
    mNodeID = pNodeID;
    mYear = pYear;
}

Module::Node::~Node()
{
}
