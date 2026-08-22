class Solution {
public:

    bool dfs(unordered_map<int,vector<int>> &mp,vector<bool>&visited,vector<bool>&inrecursion,int node){
        visited[node] = true;
        inrecursion[node] = true;

        for(auto ele: mp[node]){
            if(visited[ele] && inrecursion[ele]) return true;
            else if(!visited[ele] && dfs(mp,visited,inrecursion,ele)) return true;

        }
        inrecursion[node] = false;
        return false;
    }

    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        unordered_map<int,vector<int>> mp;

        for(int i = 0;i<n;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            mp[u].push_back(v);
        }
        vector<bool>visited(num,false);
        vector<bool>inrecursion(num,false);
        for(int i = 0;i<num;i++){
            if(!visited[i] && dfs(mp,visited,inrecursion,i)) return false;

        }
        return true;
        
    }
};