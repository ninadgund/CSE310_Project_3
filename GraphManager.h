
#pragma once

#include "util.h"
#include "Graph.h"

namespace Module
{
    class GraphManager
    {
    private:
        /* data */
        string mstrDateFile;
        string mstrEdgeFile;
        int mStartYear;
        int mEndYear;
        Graph* mGraph;
    
    public:
        GraphManager() = delete;
        ~GraphManager();

        GraphManager(string pstrDateFile, string pstrEdgeFile);

        bool generateGraph(int pStartYear, int pEndYear);
        void printCount();
        void printOutDegree();
        void printDiameter();
        void printSCC();

    };
}
