class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for (int i= s.size()-1; i>=0; i--){
            if (s[i]=='#'){
                int num= (s[--i]-'0')+ (10*(s[--i]-'0'))-10;
                char ch= num+'j';
                ans= ch+ans;
            }
            else{
                char ch= s[i]-'1'+'a';
                ans= ch+ ans;
            }
        }
        return ans;
        
    }
};
