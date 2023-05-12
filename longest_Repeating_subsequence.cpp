//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int  solve(string &t1 , string &t2 ){
	    vector<vector<int>>dp(t1.size() +1 , vector<int>(t2.size()+1 , 0)); 
	    int n = t1.size();
      int m = t2.size();     
      for(int i = n-1 ; i >= 0 ; i--){
             for(int j = m-1 ; j >= 0 ; j--){
                    int ans= 0;
                    if(t1[i] == t2[j] && i!=j){
                        ans = 1 + dp[i+1][j+1];
                    }
                    else{
                        ans = max(dp[i+1][j] , dp[i][j+1]);
                    }
                 dp[i][j]=ans;
             }
         }
        return dp[0][0];
     }
    
    
		int LongestRepeatingSubsequence(string str){
		   string str1 = str;
		  return solve(str ,str1);
 		
		  
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
