class Solution {
public:
    double average(vector<int>& arr) {
        double n = arr.size();
        double maxi = INT_MIN;
        double mini = INT_MAX;
        double allsum = 0;
        for(double i = 0;i<n;i++){
            if(arr[i]>maxi) maxi = arr[i];
            if(arr[i]<mini) mini = arr[i];
            allsum += arr[i];
        }
        double ans;
        ans = (allsum-maxi-mini)/(n-2);
        return ans;
        
    }
};
