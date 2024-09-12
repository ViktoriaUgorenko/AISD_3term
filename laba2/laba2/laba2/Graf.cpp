#include<iostream>
#include<queue>
#include<stack>
using namespace std;

const int N = 11;
int graph[N][N] = { 0 }; 
stack<int> stk;
bool used[N]; 

void addEdge(int vertex, int to)
{
	graph[vertex][to] = 1; 
}

void BFS(int start)
{
	queue<int> q;
	bool used[N] = { 0 };
	q.push(start);
	used[start] = true;
	int current;
	while (!q.empty())
	{
		current = q.front();
		q.pop();
		cout << current << " ";
		for (int neighbor = 1; neighbor < N; neighbor++)
		{
			if (graph[current][neighbor] && !used[neighbor])
			{
				q.push(neighbor);
				used[neighbor] = true;
			}
		}
	}
	cout << "\n—ложность BFS: O(V + E), где V Ч количество вершин, E Ч количество рЄбер.\n";
}

void DFS(int start)
{
	stk.push(start);
	fill(begin(used), end(used), false);
	int current;
	while (!stk.empty())
	{
		int currentNode = stk.top();
		stk.pop();

		if (!used[currentNode]) {
			cout << currentNode << " ";
			used[currentNode] = true;

			for (int neighbor = N - 1; neighbor >= 1; --neighbor) 
			{
				if (graph[currentNode][neighbor] && !used[neighbor]) {
					stk.push(neighbor);
				}
			}
		}
	}
	cout << "\n—ложность DFS: O(V + E), где V Ч количество вершин, E Ч количество рЄбер.\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	int start;

	addEdge(1, 2);
	addEdge(1, 5);
	addEdge(2, 7);
	addEdge(2, 8);
	addEdge(2, 1);
	addEdge(3, 8);
	addEdge(4, 6);
	addEdge(4, 9);
	addEdge(5, 1);
	addEdge(5, 6);
	addEdge(6, 5);
	addEdge(6, 4);
	addEdge(6, 9);
	addEdge(7, 2);
	addEdge(7, 8);
	addEdge(8, 7);
	addEdge(8, 2);
	addEdge(8, 3);
	addEdge(9, 4);
	addEdge(9, 6);
	addEdge(9, 10);
	addEdge(10, 9);

	cout << "ведите начальную вершину графа (1-10): ";
	cin >> start;

	if (start < 1 || start >= N) {
		cout << "ошибка: введЄнное число должно быть от 1 до 10." << endl;
		return 1;
	}

	cout << "BFS: ";
	BFS(start);
	cout << endl;

	cout << "DFS: ";
	DFS(start);

	return 0;
}
