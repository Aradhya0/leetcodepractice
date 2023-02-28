
struct Proj
{
    int profit;
    int thr;
    Proj(int profit, int thr) : profit(profit), thr(thr) {}
    bool operator<(const Proj &other)
    {
        return thr < other.thr;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();
        vector<Proj> data;
        for(int i=0; i<n; i++)
            data.emplace_back(profits[i], capital[i]);
        sort(data.begin(), data.end());
        priority_queue<int, vector<int>, less<int>> availableProjects;
        int j = 0;
        for(int projI = 0; projI < k; projI++)
        {
            while(j < n && data[j].thr <= w)
                availableProjects.push(data[j++].profit);
            if(availableProjects.empty())
                break;
            w += availableProjects.top();
            availableProjects.pop();
        }
        return w;
    }
};
