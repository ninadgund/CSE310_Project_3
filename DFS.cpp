
#include "DFS.h"

Module::DFS::~DFS()
{

}

void Module::DFS::fillOrder(Graph* pGraph, int v, bool* pVis, Stack* pStack)
{
    pVis[v] = true;
  
    int vC = pGraph->mVertexCount;
    AdjNode* temp = pGraph->mAdjList[v];

    while (temp != nullptr)
    {
        if(!pVis[temp->index])
        {
            fillOrder(pGraph, temp->index, pVis, pStack);
        }
        temp = temp->next;
    }
  
    pStack->push(v);
}

void Module::DFS::getSCC(Graph* pGraph)
{
    int vC = pGraph->mVertexCount;
    Stack* lStack = new Stack();
    bool* visit = new bool[vC];
    for (int i = 0; i < vC; i++)
    {
        visit[i] = false;
    }

    for(int i = 0; i < vC; i++)
    {
        if(visit[i] == false)
        {
            fillOrder(pGraph, i, visit, lStack);
        }
    }

    Graph* trGraph = pGraph->getTranspose();

    for(int i = 0; i < vC; i++)
    {
        visit[i] = false;
    }

    int* lSCCCount = new int[vC];
    for(int i = 0; i < vC; i++)
    {
        lSCCCount[i] = 0;
    }
    while (!(lStack->empty()))
    {
        int v = lStack->pop();
  
        if (visit[v] == false)
        {
            int liTemp = SCCCount(trGraph, v, visit);
            if (liTemp > 0)
            {
                lSCCCount[liTemp - 1]++;
            }
        }
    }

    int total = 0;
    for(int i = 0; i < vC; i++)
    {
        total += lSCCCount[i];
    }

    cout << "The graph G has " << total << " strongly connected components:\n";
    cout << "\tSize : Number\n";

    for(int i = 0; i < vC; i++)
    {
        if (lSCCCount[i] > 0)
        {
            cout << "\t" << (i + 1) << " : " << lSCCCount[i] << "\n";
        }
    }

    delete[] lSCCCount;
    delete trGraph;
    delete[] visit;
    return;
}

// Actual DFS implementation for count of SCC
int Module::DFS::SCCCount(Graph* pGraph, int v, bool* pVis)
{
    int lCount = 0;
    pVis[v] = true;
    lCount++;

    AdjNode* temp = pGraph->mAdjList[v];

    while (temp != nullptr)
    {
        if (!pVis[temp->index])
        {
            lCount += SCCCount(pGraph, temp->index, pVis);
        }
        temp = temp->next;
    }
    return lCount;
}
