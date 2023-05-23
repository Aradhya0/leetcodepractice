class KthLargest {
    priority_queue<int>pq;
int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i:nums)
        {
            pq.push(-1*i);
            if(pq.size()>k)pq.pop();

        }
        
    }
    
    int add(int val) {
        pq.push(-1*val);
        if(pq.size()>k)pq.pop();
        return -1*pq.top();

        
    }
};
