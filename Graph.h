#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include "Queue.h"
using namespace std;
class Graph{
 vector<vector<int>> adj;
public:
 explicit Graph(int n=0):adj(n){}
 void addEdge(int u,int v){if(u<0||v<0||u>=adj.size()||v>=adj.size())return;adj[u].push_back(v);adj[v].push_back(u);}
 void BFS(int s){if(s<0||s>=adj.size())return;vector<bool>vis(adj.size());Queue<int>q;q.enqueue(s);vis[s]=true;cout<<"\nBFS traversal: ";while(!q.empty()){int x=q.dequeue();cout<<x<<" ";for(int y:adj[x])if(!vis[y]){vis[y]=true;q.enqueue(y);}}cout<<"\n";}
};
#endif
