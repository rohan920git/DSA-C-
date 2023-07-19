class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>q;
        for(int i = 0 ; i < points.size() ; i++){
          int temp = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            q.push({temp, i});
        }
        vector<vector<int>>ans;
        while(k--){
            pair<int,int> a = q.top();
            q.pop();
            int index = a.second;
            ans.push_back({points[index][0],points[index][1]});
        }
    return ans;
    }
};
