class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int x=satisfaction.size();
        vector<int> sum(x);
        for(int i=x;i>0;i--){
            for(int j=1;j<=i;j++){
            sum[x-i]=sum[x-i]+j*satisfaction[j-1];
            if(j==i){
               satisfaction.erase(satisfaction.begin());
            }
            }
        }
        int max=sum[0];
          for(int k=0;k<sum.size();k++) {
        if(max < sum[k]) {
            max = sum[k];
        }
    }
    if(max<1){
        return 0;
    }
    else
          return max;
    }
};
