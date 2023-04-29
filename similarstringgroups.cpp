class Solution {
public:
    
    vector <int> adj[301];
    bool vis[301];
    
    bool similar(string &a, string &b) {
        if(a.length() != b.length()) {
            return false;
        }
        
        vector <int> v1(26, 0);
        vector <int> v2(26, 0);
        
        int c = 0;
        for(int i=0;i<a.length();i++) {
            if(a[i] != b[i]) {
                ++c;
            }
            v1[a[i]-'a']++;
            v2[b[i]-'a']++;
        }
        
        if(v1!=v2) {
            return false;
        }
        
        return c <= 2;
    }
    
    void dfs(int src) {
        vis[src] = true;
        
        for(int child: adj[src]) {
            if(vis[child] == false) {
                dfs(child);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        for(int i=0;i<strs.size();i++) {
            for(int j=i+1;j<strs.size();j++) {
                if(similar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        memset(vis, false, sizeof vis);
        int ans = 0;
                
        for(int i=0;i<strs.size();i++) {
            if(vis[i] == false) {
                ++ans;
                dfs(i);
            }
        }
        
        return ans;
    }
};
