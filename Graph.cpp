
#include "Graph.h"

Module::Graph::Graph(int pNodeCount)
{
    mSorted = false;
    mNodeCount = pNodeCount;
    mVertexCount = 0;
    mEdgeCount = 0;
    mAdjList = new AdjNode*[mNodeCount];
    outDegree = new int[mNodeCount];
    for(int i = 0; i < mNodeCount; i++)
    {
        mAdjList[i] = nullptr;
        outDegree[i] = 0;
    }

    mData = new Node[mNodeCount];
}

Module::Graph::~Graph()
{
    for(int i = 0; i < mNodeCount; i++)
    {
        if (mAdjList[i] != nullptr)
        {
            delete mAdjList[i];
        }
    }
    delete[] mAdjList;
    delete[] outDegree;
    delete[] mData;
}

bool Module::Graph::addVertex(int pNodeId, int pNodeYear)
{
    if (mSorted)
    {
        return false;
    }
    Node newNode(pNodeId, pNodeYear);
    for (int i = 0; i < mNodeCount; i++)
    {
        if (mData[i].mNodeID < 0)
        {
            mData[i] = newNode;
            break;
        }
        if (mData[i].mNodeID < newNode.mNodeID)
        {
            continue;
        }
        Node temp = mData[i];
        mData[i] = newNode;
        newNode = temp;
    }
    mVertexCount++;
    return true;
}

void Module::Graph::setAddDone()
{
    mSorted = true;
}

int Module::Graph::getNodeIndex(int pNodeId)
{
    if (!mSorted)
    {
        return -1;
    }
    for (int i = 0; i < mNodeCount; i++)
    {
        if (mData[i].mNodeID < 0)
        {
            return -1;
        }
        if (mData[i].mNodeID == pNodeId)
        {
            return i;
        }
    }
    return -1;
}

bool Module::Graph::isNodePresent(int pNodeId)
{
    if (getNodeIndex(pNodeId) < 0)
    {
        return false;
    }
    return true;
}

bool Module::Graph::addEdge(int pStartNode, int pEndNode)
{
    int lSNI = getNodeIndex(pStartNode);
    int lENI = getNodeIndex(pEndNode);
    if (lSNI < 0 || lSNI >= mNodeCount || 
    lENI < 0 || lENI >= mNodeCount)
    {
        return false;
    }
    if (mAdjList[lSNI] == nullptr)
    {
        mAdjList[lSNI] = new AdjNode(lENI);
    }
    else
    {
        if (!(mAdjList[lSNI]->addSorted(lENI)))
        {
            return false;
        }
    }
    outDegree[lSNI]++;
    mEdgeCount++;
    return true;
}

void Module::Graph::printOutDegreeDist()
{
    int* oDeg = new int[mNodeCount];
    for(int i = 0; i < mNodeCount; i++)
    {
        oDeg[i] = 0;
    }

    for(int i = 0; i < mNodeCount; i++)
    {
        oDeg[outDegree[i]]++;
    }

    for(int i = 0; i < mNodeCount; i++)
    {
        if (oDeg[i] > 0)
        {
            cout << "\t" << i << " : " << oDeg[i] << "\n";
        }
    }
    delete[] oDeg;
}

Module::Graph* Module::Graph::getTranspose()
{
    Graph* lGraph = new Graph(mNodeCount);
    for (int i = 0; i < mNodeCount; i++)
    {
        lGraph->addVertex(mData[i].mNodeID, mData[i].mYear);
    }
    lGraph->setAddDone();

    for (int i = 0; i < mNodeCount; i++)
    {
        AdjNode* temp = mAdjList[i];
        while (temp != nullptr)
        {
            lGraph->addEdge(mData[temp->index].mNodeID , mData[i].mNodeID);
            temp = temp->next;
        }
    }
    return lGraph;
}
