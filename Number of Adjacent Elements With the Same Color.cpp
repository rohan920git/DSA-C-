class Solution {
public:
    
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>color(n,0);
        int ans = 0 ;
        vector<int>finalans;
        for(int i = 0 ; i< queries.size() ; i++){
            int index = queries[i][0];
            int newcolor = queries[i][1];
            int leftans = index - 1 < 0 ? 0 : color[index-1];
            int rightans = index +1 == n ? 0: color[index+1];
            if(color[index] != 0 && leftans == color[index])ans--;
            if(color[index] != 0 && rightans == color[index])ans--;
            
            color[index]=newcolor;
            if(leftans == color[index]) ans++;
            if(rightans == color[index])ans++;
            finalans.push_back(ans);
        }
        return finalans;
    }
};
