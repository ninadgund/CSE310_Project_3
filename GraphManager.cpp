
#include "GraphManager.h"
#include "FloydWarshall.h"
#include "DFS.h"

Module::GraphManager::GraphManager(string pstrDateFile, string pstrEdgeFile)
{
    mstrDateFile = pstrDateFile;
    mstrEdgeFile = pstrEdgeFile;

    ifstream datesFile(mstrDateFile);
    if (!datesFile.is_open())
    {
        throw 1;
    }
    ifstream edgesFile(mstrEdgeFile);
    if (!edgesFile.is_open())
    {
        throw 1;
    }
    datesFile.close();
    edgesFile.close();
}

Module::GraphManager::~GraphManager()
{
}

bool Module::GraphManager::generateGraph(int pStartYear, int pEndYear)
{
    mStartYear = pStartYear;
    mEndYear = pEndYear;

    {
        ifstream datesFile(mstrDateFile);
        if (!datesFile.is_open())
        {
            return false;
        }

        string line;
        int lNodeCount = 0;
        while (getline(datesFile, line))
        {
            if(line.length() <= 1)
            {
                continue;
            }
            istringstream iss(line);
            // Read query input
            try
            {
                string token;
                if(!std::getline(iss, token, '\t'))
                {
                    throw 1;
                }
                int lNodeId = stoi(token);
                if(!std::getline(iss, token, '\n'))
                {
                    throw 1;
                }
                int lNodeYear = stoi(token);
                if (mStartYear <= lNodeYear && lNodeYear <= mEndYear)
                {
                    lNodeCount++;
                }
            }
            catch (...)
            {
                cout << "Data invalid" << '\n';
            }
        }
        mGraph = new Graph(lNodeCount);
        datesFile.close();
    }

    {
        ifstream datesFile(mstrDateFile);
        if (!datesFile.is_open())
        {
            return false;
        }
        string line;
        while (getline(datesFile, line))
        {
            if(line.length() <= 1)
            {
                continue;
            }
            istringstream iss(line);
            // Read query input
            try
            {
                string token;
                if(!std::getline(iss, token, '\t'))
                {
                    throw 1;
                }
                int lNodeId = stoi(token);
                if(!std::getline(iss, token, '\n'))
                {
                    throw 1;
                }
                int lNodeYear = stoi(token);
                if (mStartYear <= lNodeYear && lNodeYear <= mEndYear)
                {
                    mGraph->addVertex(lNodeId, lNodeYear);
                }
            }
            catch (...)
            {
                cout << "Data invalid" << '\n';
            }
        }
        mGraph->setAddDone();

        datesFile.close();
    }

    {
        ifstream edgesFile(mstrEdgeFile);
        if (!edgesFile.is_open())
        {
            return false;
        }
        string line;
        while (getline(edgesFile, line))
        {
            if(line.length() <= 1)
            {
                continue;
            }
            istringstream iss(line);
            // Read query input
            try
            {
                string token;
                if(!std::getline(iss, token, '\t'))
                {
                    throw 1;
                }
                int lStartNode = stoi(token);
                if(!std::getline(iss, token, '\n'))
                {
                    throw 1;
                }
                int lEndNode = stoi(token);

                mGraph->addEdge(lStartNode, lEndNode);
            }
            catch (...)
            {
                cout << "Data invalid" << '\n';
            }
        }
        mGraph->setAddDone();

        edgesFile.close();
    }

    {
        printCount();
    }

    return true;
}

void Module::GraphManager::printCount()
{
    cout << "The graph G for the years " << mStartYear << " " << mEndYear << " has:\n";
    cout << "\t|V| = " << mGraph->mVertexCount << " vertices\n";
    cout << "\t|E| = " << mGraph->mEdgeCount << " edges\n";
    cout << "\n";
}

void Module::GraphManager::printOutDegree()
{
    float avg = (float)mGraph->mEdgeCount/(float)mGraph->mVertexCount;
    avg -= 0.005;
    cout << setprecision(2) << fixed;
    cout << "The graph G has average out-degree " << mGraph->mEdgeCount << "/" << mGraph->mVertexCount << " = " << avg << ".\n";
    cout << "\n";

    cout << "The out-degree distribution is:\n";
    cout << "\tOut-degree : Number of vertices\n";
    mGraph->printOutDegreeDist();
    cout << "\n";
}

void Module::GraphManager::printDiameter()
{
    cout << "The graph G has diameter "<< Module::FloydWarshall::getDiameter(mGraph) << ".\n";
    cout << "\n";
}

void Module::GraphManager::printSCC()
{
    Module::DFS::getSCC(mGraph);
}
