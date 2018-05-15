#include "Graph.h"

using namespace std;

class Graph{
    int v;   // number of verticess
    list<int> *adj;  //array of adjacency list
    int *group = new int[v];

    //constructor
    Graph:: Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }
    //
    void Graph::  addEdge(int x,int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    //cout << v << " ";
   
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]){
            DFSUtil(*i, visited);
           
        }
}
 

void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[this->v];
    
    
    for (int i = 0; i < this->v; i++)
        visited[i] = false;
 
    DFSUtil(v, visited);
}



    void Graph:: isReachableUtil(int x,int y,bool *visited,bool *b){
        visited[y] = true;
        if(y == x){*b=true; return;}

        list<int>::iterator it;
        for(it=this->adj[y].begin();it!=this->adj[y].end();++it){
            if(visited[*it] == false) isReachableUtil(x,*it,visited,b);
        }
    }

    bool Graph:: isReachable(int x,int y){
        bool *visited = new bool[this->v];
        bool reachable = false;
        for(int i=0;i<v;i++)visited[i] = false;
        isReachableUtil(x,y,visited,&reachable);

        return reachable;     

    }

};

