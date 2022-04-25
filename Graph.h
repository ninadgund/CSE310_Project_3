
#pragma once

#include "util.h"
#include "Node.h"
#include "AdjNode.h"

namespace Module
{
    class Graph
    {
    private:
        /* data */
        int mNodeCount;
        Node* mData;
        int* outDegree;
        bool mSorted;

    public:
        AdjNode** mAdjList;
        int mVertexCount;
        int mEdgeCount;

    public:
        Graph() = delete;
        ~Graph();

        Graph(int pNodeCount);

        bool addVertex(int pNodeId, int pNodeYear);
        void setAddDone();
        int getNodeIndex(int pNodeId);
        bool isNodePresent(int pNodeId);
        bool addEdge(int pStartNode, int pEndNode);
        void printOutDegreeDist();

        Graph* getTranspose();

    };
}
