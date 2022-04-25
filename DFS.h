
#pragma once

#include "Graph.h"
#include "Stack.h"

namespace Module
{
    class DFS
    {
    public:
        DFS() = delete;
        ~DFS();

        static void fillOrder(Graph* pGraph, int v, bool* pVis, Stack* pStack);

        static void getSCC(Graph * pGraph);
        static int SCCCount(Graph* pGraph, int v, bool* pVis);

    };
}
