class FrequencyTracker {
   unordered_map<int ,int > mp;
    unordered_map<int,int> mp1;
public:
    FrequencyTracker() {
    mp.clear();
    mp1.clear();
    }
    
    void add(int number) {
      if(mp1.find(mp[number]) != mp1.end()){
          mp1[mp[number]]--;
          if(mp1[mp[number]] == 0){
              mp1.erase(mp[number]);
          }
      }
      mp[number]++;
        mp1[mp[number]]++;
    }
    
    void deleteOne(int number) {
       if(mp.find(number) != mp.end()){
           if(mp1.find(mp[number]) != mp1.end()){
               mp1[mp[number]]--;
               if(mp1[mp[number]] == 0){
                   mp1.erase(mp[number]);
               }
           }
           mp[number]--;
           if(mp[number] == 0){
               mp.erase(number);
           }
           else{
           mp1[mp[number]]++;
           }
       }
    }
    
    bool hasFrequency(int frequency) {
        if(mp1[frequency] >0){
            return true;
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
