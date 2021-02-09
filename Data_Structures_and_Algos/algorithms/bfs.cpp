

#include <list>
#include <iostream>

//A directed graph using 
//adjacency list representation 
class Graph  { 
    public: 
    Graph(int vertices) { 
        this->V = vertices; 
        adj = new std::list<int>[V]; 
    } 
  
    //add an edge to graph 
    void addEdge(int v, int edge) { 
        adj[v].push_back(edge);  
    } 
    //prints BFS traversal from a given source s 
    void BFS(int s) {
        //var to check if the node was visited
        bool *visited = new bool[V]; 
        for(int i = 0; i < V; i++){ 
            visited[i] = false; 
        }
        //queue for breadth first search
        std::list<int> q; 
        //add current node to queue
        visited[s] = true; 
        q.push_back(s); 
        std::list<int>::iterator i;   
        while(!q.empty()) { 
            s = q.front(); 
            std::cout << s << " "; 
            q.pop_front(); 
            //qet all adjacent vertices of the vertex s
            //If a adjacent has not been visited, add it to the queue
            for (i = adj[s].begin(); i != adj[s].end(); ++i)  { 
                if (!visited[*i]) { 
                    visited[*i] = true; 
                    q.push_back(*i); 
                } 
            } 
        } 
    }

    private:
    //vertices
    int V;  
    //ptr to arr containing adj. lists
    std::list<int> *adj;    
}; 

int main() {
    // Create a graph given in the above diagram 
    Graph graph(4); 
    graph.addEdge(0, 1); 
    graph.addEdge(0, 2); 
    graph.addEdge(1, 2); 
    graph.addEdge(2, 0); 
    graph.addEdge(2, 3); 
    graph.addEdge(3, 3); 
  
    std::cout<<"BFS traversal starting from vertex 1: \n";
    graph.BFS(1); 
    std::cout<<"\n";
  
    return 0; 
}
  

  
