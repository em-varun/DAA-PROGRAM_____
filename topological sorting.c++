#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {

int V;

list<int>* adj;

void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
public:

Graph(int V);

void addEdge(int v, int w);

void topologicalSort();
void displayAdjList() {
for(int i = 0; i<V; i++) {
cout << i << "--->";
list<int> :: iterator it;
for(it = adj[i].begin(); it != adj[i].end(); ++it) {
}
cout << *it << " ";
cout << endl;
}
}
};

Graph::Graph(int V)
{

this->V = V;
adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[],stack<int>& Stack)

{



visited[v] = true;

list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i)
if ( !visited[*i])
topologicalSortUtil(*i, visited, Stack);

Stack.push(v);
}

void Graph::topologicalSort()
{
stack<int> Stack;

bool* visited = new bool[V];
for (int i = 0; i < V; i++)
visited[i] = false;

for (int i = 0; i < V; i++)
if (visited[i] == false)
topologicalSortUtil(i, visited, Stack);

while (Stack.empty() == false) {
cout << Stack.top() << " ";
Stack.pop();
}
}

// Driver Code
int main()
{

Graph g(6);
g.addEdge(5, 2);
g.addEdge(5, 0);

g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);
cout << "Following is a Topological Sort of the given"
"graph \n";

g.displayAdjList();
g.topologicalSort();
return 0;
}
