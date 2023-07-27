#include<iostream>
#include<vector>
using namespace std;
void solve(vector<vector<int>>&v , vector<vector<int>>&ans,vector<int>temp,int i , int j ,int n , int m){
    if(i == n-1 && j == m-1){
      temp.push_back(v[i][j]);
      ans.push_back(temp); 
    temp.pop_back();
    return ;}
    if( i > n || j > m){
        return ;
    }
    temp.push_back(v[i][j]);
    if(i+1 < n){
      solve(v,ans,temp,i+1,j,n,m);
    }
    if(j+1 < m){
        solve(v, ans, temp, i , j+1 ,n , m);
    }
    temp.pop_back();
}
int main(){
    int m = 2 , n =2 ;
    vector<vector<int>> v = {{1,3},{4,6}};
    vector<vector<int>>ans;
    vector<int>temp;
    solve(v,ans, temp , 0 , 0 , n ,m );
    for(auto i :ans){
        for(auto j : i){
            cout<<j<<" ";
        }
       cout<<endl;
    }
  return 0;
} 
