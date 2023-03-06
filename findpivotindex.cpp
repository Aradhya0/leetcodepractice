class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int sum = 0;
        for(int i =0; i< arr.size(); i++){
            sum += arr[i];
        }
        int lSum = 0;
        int rSum = sum;
        for (int i = 0; i<arr.size(); i++){
            rSum -= arr[i];
            if(rSum ==lSum){
                return i;
            }
            lSum += arr[i];
        }
        return -1;
    }
};
