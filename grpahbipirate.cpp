class Solution {
private:
    bool bfs(int node , vector<vector<int>>&graph , vector<int>&color ){
        color[node]=0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int currentNode=q.front();
            q.pop();
            for(auto it : graph[currentNode]){
                if(color[it]==color[currentNode]){
                    return false;
                }else if(color[it]==-1){
                    if(color[currentNode]==0){
                        color[it]=1;
                    }else{
                        color[it]=0;
                    }
                    q.push(it);
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0 ; i<n ; i++){
            if(color[i]==-1){
                if(!bfs(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
};
