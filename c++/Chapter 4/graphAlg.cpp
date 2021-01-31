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
  void DFSiterative(int index, vector<bool> &visited);
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

/*
 DFS iterative
	- Go to a vertex, mark it as visited and push on to stack
	- Choose an adjacent vertex to visit, mark it as visited and push onto stack
	- Go to that adjacent vertex and choose a vertex of the adjacent vertex
	- Go to that vertex, mark that as visited and push onto stack
	- then go to the vertex of the adjacent vertex and do the same
	- Go all the way in the depth and keep doing that till once for a vertex there are
    no more vertices left unvisited
	- When a vertex has no more unvisited vertices then pop it off the stack
	- keep popping till you find a vertex with a adjacent vertex, then mark that one 	  as visited and put that into stack.
 */

void Graph::DFSiterative(int index, vector<bool> &visited)
{
  stack<int> stack;
  stack.push(index); // Push the current source node.
  
  while (!stack.empty())
  {
    index = stack.top();
    
    // Pop a vertex from stack and print it and mark as visited
    stack.pop();
    if (!visited[index]) // Stack may contain same vertex twice. So we need to print the popped item only if it is not visited.
    {
      cout << index << " ";
      visited[index] = true;
    }
    
    //Go through the array of list at that particular vertex therefore vertexes adjacent to that vertex
    for (auto i = adj[index].begin(); i != adj[index].end(); ++i)
      //Get all adjacent vertices of the popped vertex index. If a adjacent has not been visited, then push it to the stack.
      if (!visited[*i])
        stack.push(*i);
  } //end of while
}

void Graph::printDFSiterative()
{
  vector<bool> visited(V, false); // Mark all the vertices as not visited
  
  for (int i = 0; i < V; i++)
    if (!visited[i])
      DFSiterative(i, visited);
}

/*
 BFS: Breadth First Search - Queue
 - Uses the idea of exhausting all the adjacent of a particular vertex before moving on to another vertex.
 - Runtime for BFS on GRAPHS - Since the sum of the lengths of all the adjacency lists is Θ(E), the total time spent in scanning adjacency lists is O( E). The overhead for initialization is O( V), and thus the total running time of BFS is O( V + E)."
 
 ALGORITHM:
 - go to a vertex
 - Stay on vertex and go to an adjacent vertex p
 - put that adjacent vertex on queue
 - Go back to original vertex and go to next adjacent vertex
 - Put that vertex on queue again
 - Keep doing that till all there vertices get over
 - After we are done with the first vertex, go to the next one by popping the first one 	off the queue
 - That first vertex on queue is the next chosen vertex and do the same thing again, go
 its adjacent vertices and keep adding to the queue the vertices that have not already
 been visited
*/

void Graph::BFS(int index)
{
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;
  
  // Create a queue for BFS
  list<int> queue;
  
  visited[index] = true; // Mark the current node as visited and enqueue it
  queue.push_back(index);
  
  list<int>::iterator i; // 'i' will be used to get all adjacent vertices of a vertex
  
  while(!queue.empty())
  {
    index = queue.front();   // Dequeue a vertex from queue and print it
    cout << index << " ";
    queue.pop_front();
    
    // Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it
    for(i = adj[index].begin(); i != adj[index].end(); ++i)
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
  Graph g(4); //creates a graph object with 4 vertices
  
  /*g.addEdge(2,0);
  g.addEdge(0,2);
  g.addEdge(0,1);
  g.addEdge(2,3);
  g.addEdge(3,3);
  g.addEdge(1,2);
  
  //g.DFSrecursive();
  
  Graph g(5);  // Total 5 vertices in graph
  g.addEdge(1, 0);
  g.addEdge(2, 1);
  g.addEdge(3, 4);
  g.addEdge(4, 0);
  
  cout << "Following is Depth First Traversal\n";
  g.DFS(); //0 1 2 3 4
  
  g.printDFSiterative();*/

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  
  cout << "Following is Breadth First Traversal "
  << "(starting from vertex 2) " << endl; //2 0 3 1
  g.BFS(2);
  
  return 0;
}





