class Solution {
public:
    void dfs(int index,vector<int>&path, unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
        if(visited[index]){
            return;
        }
     visited[index] = true;
        path.push_back(index);
        for(auto i : adj[index]){
            if(!visited[i])
             dfs(i,path,visited,adj);
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        int e = edges.size();
            for(int i = 0; i< e ; i++){
              int u = edges[i][0];
              int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
     unordered_map<int,bool>visited;
       int ans = 0;
        for(int i = 0; i<  n ;i++){
            if(!visited[i]){
                int cnt=0;
                vector<int>path;
                dfs(i,path,visited,adj);
                for(int j = 0 ;j <path.size() ; j++){
                    if(adj[path[j]].size() == path.size()-1){
                        cnt++;
                    }
                }
                if(cnt == path.size()){
                    ans++;
                }
                
            }
        
    }
        return ans;
    }
};
