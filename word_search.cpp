class Solution {
public:
    bool solve(int i , int j , int index, string &s ,vector<vector<char>>&a,vector<vector<bool>>&visited){
    int row = a.size();
    int col = a[0].size();
   
        if( i >= row || j >= col || i < 0 || j < 0 ){
        return false;
    }
    
    if(visited[i][j] ){
        return 0;
    }
   
    bool down ,right , left ,up;
    if(s[index] == a[i][j]){
        visited[i][j]=true;
        if(index == s.size()-1){
            return true;
        }
    
        left = solve(i,j-1,index+1,s,a,visited);
        down = solve(i+1 , j , index+1, s ,a,visited);
        right =solve(i, j+1, index+1, s,a,visited);
        up = solve(i-1 , j ,index+1,s,a,visited);
        
        visited[i][j]=false;
        
        
    }
    else{
        return false;
    }
    return down || right || left||up ;
}
    bool exist(vector<vector<char>>& board, string word) {
        int index =0;
        int row = board.size();
        int col =board[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col ,false));
        for(int i = 0; i< row ; i++){
            for(int j = 0 ; j < col ; j++){
                  
                if(word[index] == board[i][j]){
                    if(solve(i,j,index,word,board,visited)){
                        return true;
                    }
                }
            }
        }
    return false;
    }
};
