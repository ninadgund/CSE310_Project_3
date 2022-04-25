
#include "FloydWarshall.h"

Module::FloydWarshall::~FloydWarshall()
{

}

int Module::FloydWarshall::getDiameter(Graph* pGraph)
{
    int vC = pGraph->mVertexCount;
    int** dist = new int*[vC];
    for (int i = 0; i < vC; i++)
    {
        dist[i] = new int[vC];
    }

    for (int i = 0; i < vC; i++)
    {
        for (int j = 0; j < vC; j++)
        {
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < vC; i++)
    {
        AdjNode * temp = pGraph->mAdjList[i];
        while (temp != nullptr)
        {
            dist[i][temp->index] = 1;
            temp = temp->next;
        }
    }
    for (int i = 0; i < vC; i++)
    {
        dist[i][i] = 0;
    }

    for (int k = 0; k < vC; k++)
    {
        for (int i = 0; i < vC; i++)
        {
            for (int j = 0; j < vC; j++)
            {
                if ((dist[i][k] >= 0) && (dist[k][j] >= 0))
                {
                    if(dist[i][j] > (dist[i][k] + dist[k][j]))
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    if(dist[i][j] < 0)
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    int diam = 0;
    for (int i = 0; i < vC; i++)
    {
        for (int j = 0; j < vC; j++)
        {
//            cout << dist[i][j] << " ";
            if(dist[i][j] > diam)
            {
                diam = dist[i][j];
            }
        }
//        cout << "\n";
    }

    for (int i = 0; i < vC; i++)
    {
        delete[] dist[i];
    }
    delete[] dist;

    return diam;
}
