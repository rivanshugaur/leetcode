class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj,int u,vector<bool>& visited){
        visited[u] = true;
        for(auto &v: adj[u]){
            if(visited[v]==false){
                dfs(adj,v,visited);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>> adj;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        vector<bool>visited(n,false);
        for(int i = 0;i<n;i++){
            if(visited[i]==false){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
        
    }
};