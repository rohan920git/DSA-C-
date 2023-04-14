#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creating adj list 
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0 ; i < g.size() ; i++){
        int u = g[i].first.first;
        int v =g[i].first.second;
        int w =g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    // making those tree essential arrays
    vector<int>key(n+1, INT_MAX);
    vector<bool>mst(n+1, false);
    vector<int> parant(n+1 , -1);
    key[1]=0;
    parant[1]=-1;
    
    // ab proccess suru
    for(int i = 1 ; i <= n ;i++){
        int mini = INT_MAX;
        int u ;
        // finding minimum for the key vector
        for(int v = 1 ; v<=n;v++){
            if( mst[v]==false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        mst[u]=true;
        // searching for neighbours of the minimum element
        for(auto j : adj[u]){
            int node = j.first;
            int weight = j.second;
            if(mst[node]==false && weight < key[node]){
                key[node]=weight;
                parant[node]= u;
            
            }
        }
         
    }
    //now making the ans array;
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= n ;i++){
        ans.push_back({{parant[i], i }, key[i]});
    }
    return ans;
}
