#include <iostream>
#include <algorithm>
#define IMX INT_MAX

using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;
};
bool connection(int mnozhestvoV[8])
{
    int firstEl = mnozhestvoV[0];
    for (int i = 1; i < 8; i++)
    {
        if (mnozhestvoV[i] != firstEl)
        {
            return false;
        }
    }
    return true;
}


void algoritmPrima(int graphMatrix[8][8], int start)
{
    int x = start - 1;
    int y = 0;
    int visited[8];
    int currentEdge = 0;


    for (int i = 0; i < 8; i++)
    {
        visited[i] = false;
    }

    visited[x] = true;

    cout << "алгоритм прима:\n";
    int primEdges[7][2];

    while (currentEdge < 7)
    {
        x = 0;
        y = 0;
        int min = IMX;

        for (int i = 0; i < 8; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < 8; j++)
                {
                    if (!visited[j])
                    {
                        if (min > graphMatrix[i][j])
                        {
                            min = graphMatrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        visited[y] = true;

        primEdges[currentEdge][0] = x + 1;
        primEdges[currentEdge][1] = y + 1;
        currentEdge++;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << "вершина " << primEdges[i][0] << " - " << "вершина " << primEdges[i][1] << "; вес: " << graphMatrix[primEdges[i][0] - 1][primEdges[i][1] - 1] << endl;
    }
}

void algoritmKraskala(Edge edgeList[], int n)
{
    int mnozhestvoV[8];

    for (int i = 0; i < 8; i++)
    {
        mnozhestvoV[i] = i;
    }

    sort(edgeList, edgeList + n, [](Edge& a, Edge& b) { return a.weight < b.weight; });

    cout << "алгоритм краскала:\n";
    int kruskalEdges[7][2];
    int edgeCount = 0;
    for (int i = 0; i < n; i++)
    {
        Edge ed = edgeList[i];

        if (mnozhestvoV[ed.start] != mnozhestvoV[ed.end])
        {
            kruskalEdges[edgeCount][0] = ed.start + 1;
            kruskalEdges[edgeCount][1] = ed.end + 1;
            edgeCount++;

            int oldMnozh = mnozhestvoV[ed.start];
            int newMnozh = mnozhestvoV[ed.end];

            for (int j = 0; j < 8; j++)
            {
                if (mnozhestvoV[j] == oldMnozh)
                {
                    mnozhestvoV[j] = newMnozh;
                }
            }
        }
    }


    for (int i = 0; i < edgeCount; i++) 
    {
        int start = kruskalEdges[i][0];
        int end = kruskalEdges[i][1];
        int weight = 0;

        for (int j = 0; j < n; j++) 
        {
            if ((edgeList[j].start == start - 1 && edgeList[j].end == end - 1) || (edgeList[j].start == end - 1 && edgeList[j].end == start - 1))
            {
                weight = edgeList[j].weight;
                break;
            }
        }
        cout << "вершина " << start << " - " << "вершина " << end << "; вес: " << weight << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    Edge edgeList[] =
    {
        {0, 1, 2}, {0, 3, 8}, {6, 4, 4}, {0, 4, 2},
        {1, 2, 3}, {1, 4, 5}, {1, 3, 10}, {2, 4, 12},
        {2, 7, 7}, {3, 4, 14}, {3, 5, 3}, {3, 6, 1},
        {4, 7, 8}, {5, 6, 6}, {6, 7, 9}, {5, 6, 11}
    };

    int graphMatrix[8][8] =
    {
        /*    1  2   3   4   5   6   7  8  */
        /*1*/ {IMX, 2, IMX,  8,  2,  IMX,  IMX, IMX},
        /*2*/ {2, IMX, 3, 10,  5,  IMX,  IMX, IMX},
        /*3*/ {IMX, 3, IMX,  IMX,  12,  IMX, IMX, 7},
        /*4*/ {8, 10, IMX, IMX,  14, 3,  1, IMX},
        /*5*/ {2, 5, 12, 14, IMX,  11, 4, 8},
        /*6*/ {IMX, IMX, IMX, 3,   11,  IMX, 6, IMX},
        /*7*/ {IMX, IMX, IMX, 1,   4,   6, IMX, 9},
        /*8*/ {IMX, IMX, 7, IMX,   8,   IMX, 9, IMX}
    };

    int start;
    cout << "начальная вершина для прима (от 1 до 8): ";
    cin >> start;

    algoritmPrima(graphMatrix, start);
    algoritmKraskala(edgeList, sizeof(edgeList) / sizeof(edgeList[0]));

    return 0;
}
