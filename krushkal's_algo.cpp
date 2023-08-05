#include<algorithm>
bool cmp(vector<int> &a, vector<int> &b) {
  return a[2] < b[2];
}
int findParant(int node, vector<int> &parant) {
  if (parant[node] == node) {
  return node;
  }
  return parant[node]=findParant(parant[node],parant);
}
void unionSet(int u  , int v , vector<int>&parant , vector<int>&rank){
  int p1 = findParant(u, parant);
  int p2 = findParant(v, parant);
  if (rank[p1] < rank[p2]) {
    parant[p1] = p2;

  } else if (rank[p1] > rank[p2]) {
       parant[p2]=p1;
  }
  else{
    parant[p2] = p1;
    rank[p1]++;
  }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
 vector<int>rank(n,0);
 vector<int>parant(n);
 for(int i = 0 ; i < n ;i++){
   parant[i]=i;
 }
 int ans = 0;
 sort(edges.begin() , edges.end(),cmp);
 for (int i = 0; i < edges.size(); i++) {
 int u = edges[i][0];
 int v = edges[i][1];
 int w = edges[i][2];
 int p1 = findParant(u,parant);
 int p2 = findParant(v,parant);
 if (p1 != p2) {
    ans += w;
    unionSet(p1, p2, parant, rank);
 }

 }
 return ans;
}
