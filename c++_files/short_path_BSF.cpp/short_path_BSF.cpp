#include <iostream>
#include <deque>
#define MAX 10

using namespace std;

struct vertex
{
    int distance = -1;
    int predecesor = -1;
};

const int MATRIX[MAX][MAX] = {
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0}};

deque<int> queue;

int visitVertexChildren(struct vertex graph[], int destination, int count);
void iterateVertex(struct vertex *graph, int destination, int count);
deque<int> findShortPath(struct vertex graph[], int start, int end);
void printDeque(deque<int> path);
void printVertex(struct vertex arr[]);

int main()
{
    int destination = 8, origin = 5;
    int count = 0;
    struct vertex arrVertex[MAX];
    iterateVertex(arrVertex, destination, count);
    printDeque(findShortPath(arrVertex, origin, destination));
    return 0;
}

void printVertex(struct vertex arr[])
{
    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i].distance << endl;
    }
}

int visitVertexChildren(struct vertex graph[], int destination, int count)
{
    int childrenVisited = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (MATRIX[destination][i] == 1 && graph[i].distance == -1)
        {
            childrenVisited++;
            graph[i].distance = count;
            graph[i].predecesor = destination;
            queue.push_back(i);
        }
    }
    return childrenVisited;
}
void iterateVertex(struct vertex graph[], int destination, int count)
{
    graph[destination].distance = count;
    int childrenVisited = visitVertexChildren(graph, destination, ++count);
    int nextVisitedChildren = 0;
    for (;childrenVisited >= 0 && !queue.empty(); childrenVisited--)
    {
        if( childrenVisited == 0) {
            childrenVisited = nextVisitedChildren;
            nextVisitedChildren = 0;
            count++;
            nextVisitedChildren += visitVertexChildren(graph, queue.front(), count + 1);
            queue.pop_front();
        } else {
            nextVisitedChildren += visitVertexChildren(graph, queue.front(), count + 1);
            queue.pop_front();
        }
    }
}
void printDeque(deque<int> path)
{
    while (!path.empty())
    {
        cout << path.back() << endl;
        path.pop_back();
    }
}

deque<int> findShortPath(struct vertex graph[], int start, int end)
{
    deque<int> path;
    path.push_front(start);
    while (start != end)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (MATRIX[start][i] == 1)
            {
                if (path.front() == start)
                {
                    path.push_front(i);
                }
                else if (graph[i].distance < graph[path.front()].distance)
                {
                    path.pop_front();
                    path.push_front(i);
                }
            }
        }
        start = path.front();
    }
    return path;
}