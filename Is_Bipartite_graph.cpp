class Solution {
public:
    bool dfs(int node ,unordered_map<int,vector<int>>&adj , vector<int>&color, int curr_color){
            color[node] = curr_color ;
            for(auto &v : adj[node]){
                if(color[v] == color[node]){
                    return false;
                }
                if(color[v]==-1){
                    if(!dfs(v , adj,color,1-curr_color)){
                        return false;
                    }
                }
                
            }
            return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ; 
        unordered_map<int,vector<int>>adj ; 
        for(int i =0 ; i<graph.size(); i++){
            for(auto v : graph[i]){
                adj[i].push_back(v);
                adj[v].push_back(i) ;
            }
        }
        vector<int>color(n,-1);
        // RED = 0 ; GREEN = 1 // for easy representation
        bool lol = 0 ;
        for(int i=0;i<n;i++){ 
            if(color[i]==-1){
                if(!dfs(i,adj,color,0)){
                    return false;
                } // 1st current node will be RED ; 
            }
        }
        return true; 
    }
};
