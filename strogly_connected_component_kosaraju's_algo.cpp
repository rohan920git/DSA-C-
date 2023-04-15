#include<list>
#include<unordered_map>
#include<stack>
void dfs(unordered_map<int , list<int>> &adj, unordered_map<int,bool> &visited , stack<int>&s , int node){
	visited[node]=true;
	for(auto i : adj[node]){
          if (!visited[i]) {
           dfs(adj,visited, s , i);
		  }
        }
		s.push(node);
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int , list<int>> adj;
	for(int i = 0 ; i< edges.size() ;i++){
     int u = edges[i][0];
	 int v = edges[i][1];
	 
     adj[u].push_back(v);
	}
	stack<int>s;
	unordered_map<int,bool> visited;
	for(int i = 0  ; i < v ; i++){
		if(visited[i] != true){
			dfs(adj, visited ,s , i);
		}
	}
        unordered_map<int, list<int>> transposed;
		for(int i = 0 ; i < v; i++){
			visited[i]=false;
			for(auto j : adj[i]){
				transposed[j].push_back(i);
			}
		}

	int cnt = 0 ;
	stack<int>temp;
    while(!s.empty()){
		int front = s.top();
		s.pop();
		if(!visited[front]){
			cnt++;
			dfs(transposed,visited,temp ,front);
		}
	}
	return cnt;
}
