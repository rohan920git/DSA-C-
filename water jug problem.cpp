class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int j1  = jug1Capacity;
        int j2 =  jug2Capacity;
        int c = targetCapacity;
        vector<int>operations  = {j1, -j1, j2 ,-j2};
        set<int> visited;
        queue<int>q;
        visited.insert(0);
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int operation : operations){
                int total = curr + operation;
                if(total == c ){
                    return true; 
                }
                if(total > j1+j2 || total < 0 ) {
                    continue;
                }
                if(visited.find(total) == visited.end()){
                    visited.insert(total);
                    q.push(total);
                } 
            }
        }
    return false;
    }
};
