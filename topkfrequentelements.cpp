class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, vector<int>, greater<int>> sortedMap;
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
            sortedMap[itr->second].push_back(itr->first);
        }

        for(auto itr=sortedMap.begin(); itr!=sortedMap.end(); itr++) {
            sort(itr->second.begin(), itr->second.end());
            for(int n : itr->second) {
                res.push_back(n);
                k--;
                if(k<=0) break;
            }
            
            if(k<=0) break;
        }
        

        return res;
    }
};
