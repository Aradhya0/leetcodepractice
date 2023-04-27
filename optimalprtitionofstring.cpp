class Solution {
public:
    int partitionString(string str) {
        int ans = 1;
        set<char> s;
        for(auto c: str)
        {
            if(s.find(c)!=s.end())
            {
                s.clear();
                ans++;
            }
            s.insert(c);
        }
        return ans;
    }
};
