
#pragma once

#include "Graph.h"

namespace Module
{
    class FloydWarshall
    {
    public:
        FloydWarshall() = delete;
        ~FloydWarshall();

        static int getDiameter(Graph * pGraph);
    };
}
