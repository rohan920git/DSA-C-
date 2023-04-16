/*
bellman ford algo is used to find shortest path in a graph
dijkstra's algo is also used to find infact we can use it on both directed and undirected graph
but it cannot be applied on graph having negative weight 
bellman ford algo is applied on directed graph and graph should not contain negative cycle
if you want to use it on undirected graph than first we should convert it into directed 
*/
#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
     
    vector<int>dist(n+1, 1e9);
    dist[src]=0;
    for(int i = 1 ; i <= n ;i++){
        for(int j = 0 ; j < m ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + w < dist[v])){
                dist[v] = dist[u]+w;
            }

        }

    }
 
    return dist[dest];
 }
