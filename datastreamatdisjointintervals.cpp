class SummaryRanges {
public:
    map<int,int> mp;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        map<int, int> :: iterator it = mp.lower_bound(val);
        if (it == mp.begin()){
            if(it->first == val + 1){
                int last = it->second;
                mp.erase(it);
                mp[val] = last;
            } else if (it->first != val){
                mp[val] = val;
            }
        } else if (it == mp.end()){
            if(mp.empty()) mp[val] = val;
            else {
                if (mp.rbegin()->second == val - 1) mp.rbegin()->second = val;
                else if(mp.rbegin()->second < val) mp[val] = val;
                
            }
        } else {
            if(val + 1 == it-> first && val - 1 == (prev(it))->second){
                prev(it)->second = it->second;
                mp.erase(it);
            } else if(val + 1 == it-> first){
                mp[val] = it->second;
                mp.erase(it);
            } else if (val - 1 == (prev(it))->second){
                prev(it)->second = val;
            } else if (it -> first != val && prev(it)-> second < val){
                mp[val] = val;
            } 
            
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> vec;
        for (map<int, int> :: iterator it = mp.begin();it != mp.end(); it++){
            vec.push_back({it -> first, it -> second});
        }
        return vec;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
