class Solution {
public:   
    unordered_map<string,bool> mp;
    bool rec(string s1, string s2){
        string s = s1 + "_" + s2;
        if(s1==s2){
            return mp[s]=true;
        }
        if(s1.size()<=1 || s2.size()<=1){
            return mp[s]=false;
        }
        
        if(mp.find(s)!=mp.end()){
            return mp[s];
        }
        
        bool flag = false;
        for(int i=1;i<s1.size();i++){
            bool cond1 = rec(s1.substr(0,i),s2.substr(s2.size()-i)) && rec(s1.substr(i),s2.substr(0,s2.size()-i));
            bool cond2 = rec(s1.substr(0,i),s2.substr(0,i)) && rec(s1.substr(i),s2.substr(i));
            
            if(cond1 || cond2){
                flag=true;
                break;
            }
        }
      return mp[s]=flag;  
    }
    
    bool isScramble(string s1, string s2) {
        vector<int> v(26,0);
        if(s1.size()!=s2.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            v[s1[i]-'a']++;
            v[s2[i]-'a']--;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=0){
                return false;
            }
        }
      return rec(s1,s2);  
    }
};
