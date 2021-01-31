#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>
#include<list>
using namespace std;

/*
 The Graph
 There is a list of nodes and then every node has its own list of vertces/edges.
 
 When you create the graph, you specify the total number of nodes the graph is going to have. Every node has its own list.
 When you call the function add_edge it grabs the node (which is a list) at the index v.
 Then it adds the number w to that list signifying there is a link from node v to node w.
 The same happens again in the next statement except in reverse.
 It grabs the list at index w and adds the number v to the list signifying there is a link from node w to node v.
 
 It is due to this nature we find the comment // Note: the graph is undirected, because it draws a path from both nodes to the other.
 
 
 //Results in 5 lists that look like this
 
 (NODE) |  1, 2, 3
 adj[0] |
 ---------------------------------
 (NODE) |  0, 2
 adj[1] |
 ---------------------------------
 (NODE) |
 adj[2] |  0, 1
 ---------------------------------
 (NODE) |  0, 4
 adj[3] |
 ---------------------------------
 (NODE) |   3
 adj[4] |
 
 ---
 
 0 > 1, 2, 3
 1 > 0, 2
 2 > 0, 1
 3 > 0, 4
 4 > 3
 
 */

//USES ADJACENCY LIST
class Graph
{
private:
  int V;
  list<int> *adj;
  void DFSUtil(int s, bool visited[]);
  
public:
  Graph(int V);
  void addEdge(int v, int w);
  void DFSrecursive();
  void DFS(int s);
  void printDFSiterative();
  void BFS(int index);
  ~Graph();
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V]; //A new array of lists is created for all the vertex's/nodes to store the adjacent vertexes
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w); //Push adjacent into adjacency list
}

Graph::~Graph()
{
  delete [] adj;
}

//DFS Recursive
void Graph::DFSUtil(int s, bool visited[])
{
  visited[s] = true;
  cout << s << " ";
  
  list<int>::iterator i;
  for (i = adj[s].begin(); i != adj[s].end(); ++i)
  {
    if (!visited[*i])
      DFSUtil(*i, visited);
  }
}

void Graph::DFSrecursive()
{
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;
  //DFSUtil(s, visited);
  
  for (int i = 0; i < V; i++)
  {
    if (visited[i] == false)
      DFSUtil(i, visited);
    cout<<"\n";
  }
  delete [] visited;
}

//DFS iterative
void Graph::DFS(int index) // prints all not yet visited vertices reachable from s
{
  vector<bool> visited(V, false);   // Initially mark all verices as not visited
  stack<int> stack;  // Create a stack for DFS
  
  stack.push(index);  // Push the current source node.
  
  while (!stack.empty())
  {
    index = stack.top();     // Pop a vertex from stack and print it
    stack.pop();
    
    // Stack may contain same vertex twice. So we need to print the popped item only if it is not visited.
    if (!visited[index])
    {
      cout << index << " ";
      visited[index] = true;
    }
    
    // Get all adjacent vertices of the popped vertex s. If a adjacent has not been visited, then push it o the stack.
    for (auto i = adj[index].begin(); i != adj[index].end(); ++i)
      if (!visited[*i])
        stack.push(*i);
  }
}

/*
 BFS: Breadth First Search - Queue
 - Uses the idea of exhausting all the adjacent of a particular vertex before moving on to another vertex.
 - Runtime for BFS on GRAPHS - Since the sum of the lengths of all the adjacency lists is Θ(E), the total time spent in scanning adjacency lists is O( E). The overhead for initialization is O( V), and thus the total running time of BFS is O( V + E)."
 
 ALGORITHM:
 - Start at a vertex add it to queue, mark it as visited, go to an adj vertex, add it onto queue and mark as visited
 - Go to all adj vertices of cur, mark as visited and add to queue.
 - After all adj vertices are exhausted, pop off queue and mark that as curr.
 - Since queue is FIFO, the one that was inserted first will be popped out each time and its adj vertices will be added to the end.
 - In the end dequeue
 
 Simplified algo:
 - go to vertex, add to queue, mark as visited.
 - Go to all adj vertex mark as visited and add to queue, when done pop from queue.
 - If queue is empty, BFS done.
 */

void Graph::BFS(int index)
{
  bool *visited = new bool[V]; //Mark all the vertices as not visited
  for(int i = 0; i < V; i++)
    visited[i] = false;
  
  list<int> queue;   // Create a queue for BFS
  
  visited[index] = true; // Mark the current node as visited and enqueue it
  queue.push_back(index);
  
  list<int>::iterator i; // 'i' will be used to get all adjacent vertices of a vertex
  while(!queue.empty())
  {
    index = queue.front();   // Dequeue a vertex from queue and print it
    cout << index << " ";
    queue.pop_front();
    
    for(i = adj[index].begin(); i != adj[index].end(); ++i)//Get all adjacent vertices of the dequeued vertex s. If adjacent has not been visited, then mark it visited and enqueue it
    {
      if(!visited[*i])
      {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

int main(int argc, const char * argv[])
{
  
  Graph g(5); // Total 5 vertices in graph
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 4);
  
  cout << "Following is Depth First Traversal\n";
  g.DFS(0);
  
  //Graph g(4); //creates a graph object with 4 vertices
  
  /*g.addEdge(2,0);
   g.addEdge(0,2);
   g.addEdge(0,1);
   g.addEdge(2,3);
   g.addEdge(3,3);
   g.addEdge(1,2);
   g.DFSrecursive();
   */
  
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  
  cout << "Following is Breadth First Traversal " << "(starting from vertex 2) " << endl; //2 0 3 1
  g.BFS(2);
  
  return 0;
}





