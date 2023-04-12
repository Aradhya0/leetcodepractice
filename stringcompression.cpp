class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,j=0;
        while(j<n&&i<n){
            int count=0;
            char curr=chars[j];
            while(j<n&&curr==chars[j]){
                j++,count++;
            }
            chars[i++]=curr;
            if(count<=9&&count>1){
                chars[i++]='0'+count;
            }else if(count>1){
                int digs=log10(count);
                int powi=pow(10,digs);
                digs++;
                while(digs--){
                    char temp=count/powi+'0';
                    chars[i++]=temp;
                    count%=powi;
                    powi/=10;
                }
            }
        }
        return i;
        
    }
};
