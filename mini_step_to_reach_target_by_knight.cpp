//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	  vector<vector<int>>visi(N+1,vector<int>(N+1,0));
	  queue<pair<int,int>>q;
	  int x1 = KnightPos[0],x2=KnightPos[1],y1 = TargetPos[0],y2 = TargetPos[1];
	  if(x1 == y1 && x2 == y2){
	      return 0 ;
	  }
	  if(x1 > N || x2 > N || y1 > N || y2 >N ){
	      return -1;
	  }
	  q.push({x1,x2});
	  vector<vector<int>>v = {{-1,-2},{1,2},{-1,2},{1,-2},{-2,-1},{2,1},{-2,1},{2,-1}};
	  while(!q.empty()){
	      auto temp = q.front();
	      q.pop();
	      int i = temp.first;
	      int j = temp.second;
	   
	      if(i == y1 && j == y2){
	          return visi[i][j];
	      }
	      for(auto ad : v){
	         int x = i + ad[0], y = j + ad[1];
	         if(x > 0 && x <= N && y > 0 && y <= N && visi[x][y]==0){
	             q.push({x,y});
	             visi[x][y]=visi[i][j]+1;
	         }
	      }
	  }
	
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
