class Solution {
public:
    bool canConstruct(string r, string magazine) {
        unordered_map<char, int> m;
        for(int i=0; i<r.size(); i++)
        {
            m[r[i]]++;
        }
        int cnt=0;
        unordered_map<char, int> n;
        for(int i=0; i<magazine.size(); i++)
        {
            if(m.find(magazine[i])!=m.end())
            {
                n[magazine[i]]++;
            }
        }
        for(int i=0; i<r.size(); i++)
        {
            if(m[r[i]]<=n[r[i]])
            {
                cnt++;
            }
            else
            {
                return false;
            }
        }
        if(cnt==r.size())
        {
            return true;
        }
        return false;

        
    }
};
