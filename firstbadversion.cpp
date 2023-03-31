class Solution {
public:
    int binarySearch(int n,int l,int r){
     
        if(r>=l){
            int mid=l+(r-l)/2;
            if(isBadVersion(mid-1)==false && isBadVersion(mid)==true){
                return mid;
            }
            if(isBadVersion(mid-1)==true && isBadVersion(mid)==true){
                return binarySearch(n,l,mid-1);
            }
            if(isBadVersion(mid)==false){
                return binarySearch(n,mid+1,r);
            }

        }
        return -1;
    }
    int firstBadVersion(int n) {
       
       int l=1,r=n;
       return binarySearch(n,1,n);
    }
};
