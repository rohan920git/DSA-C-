#include <iostream>
#include<vector>
using namespace std;
bool solve(int i , int j , int index, string &s ,vector<vector<char>>&a){
    int row = a.size();
    int col = a[0].size();
    if( i >= row || j >= col || i< 0 || j <0){
        return false;
    }
    bool up ,down ,left ,right;
    if(s[index] == a[i][j]){
        if(index == s.size()-1){
            return true;
        }
        up = solve(i , j-1 ,index+1,s,a);
        down = solve(i+1 , j , index+1, s ,a);
        left = solve(i-1,j,index+1,s,a);
        right =solve(i+1, j, index+1, s,a);
    }
    else{
        return false;
    }
    return up|| down || left || right;
}
int main() {
	int index = 0;
	string s = "MAGIC";
	vector<vector<char>>a ={
            {'B','B','M','B','B','B'},
            {'C','B','A','B','B','B'},
            {'I','B','G','B','B','B'},
            {'G','B','I','B','B','B'},
            {'A','B','C','B','B','B'},
            {'M','C','I','G','A','M'}
            };
           int ans =0;
    int row = a.size();
    int col = a[0].size();
    for(int i= 0; i< row ; i++){
        for(int j = 0; j < col ; j++){
            char ch = a[i][j];
            if(ch == s[index]){
              if(solve(i,j,index,s,a)){
                  ans++;
              }
            }
        }
    }
    cout<<ans;
	return 0;
}
