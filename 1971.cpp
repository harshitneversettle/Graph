class Solution {
public:
   
    bool dfs( unordered_map<int,vector<int>> &adj , int u, int v , vector<bool> &visited){
            if( u == v ) return true ;
            visited[u] = true ;
            for( auto x : adj[u]){
                if( !visited[x] && dfs( adj , x , v , visited ) ) return true ;
            }
            return false ;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n , false ) ;
        unordered_map<int,vector<int>> adj ;
        for( auto harshit : edges ){
            int u = harshit[0] ;
            int v = harshit[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u);
        }
        return dfs( adj , source , destination , visited ) ;
    }
};
