class Solution {
public:

    bool possible(vector<int>& a,int n,int mid,int days)
    {
        int i,s=0;

        for(i=0;i<n;i++)
        {
            s+=a[i];

            if(s>mid)
            {
                days--;
                s=a[i];
            }

            if(days<=0)
            return 0;
        }

        return 1;
    }

    int shipWithinDays(vector<int>& a, int days) {
        int i,n=a.size();
        int l,h,ans=INT_MAX;
        l=h=a[0];

        for(i=1;i<n;i++)
        {
            l=max(l,a[i]);
            h+=a[i];
        }

        while(l<=h)
        {
            int mid=(l+h)/2;

            if(possible(a,n,mid,days))
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else
            l=mid+1;
        }

        return ans;
    }
};
