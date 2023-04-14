#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   //making adj list
    unordered_map<int ,list<pair<int,int>>> adj;
    for(int i = 0 ; i <edges ;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v ,w));
        adj[v].push_back(make_pair(u ,w));

    }
    //created dist array and set of pair of dis and node 
    vector<int> dist(vertices, INT_MAX);
    set<pair<int,int>>s;
    dist[source]=0;
    s.insert(make_pair(0,source));
    while (!s.empty()) {
    auto top = *(s.begin());
    s.erase(s.begin());
    int topnode = top.second;
    int nodedis = top.first;
    for(auto i : adj[topnode]){
        int dis = i.second + nodedis;
        if (dis < dist[i.first]) {
            auto record = s.find(make_pair(dist[i.first],i.first));
            if (record != s.end()) {
           s.erase(record); 
         }
             dist[i.first]=dis;
             s.insert(make_pair(dis , i.first));
        }
    }
    }
    return dist;
}
