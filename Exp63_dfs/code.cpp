#include <iostream>
#include <vector>
using namespace std;

    
    void dfs(vector<bool>&visited,vector<int> &ans,vector<int>adj[],int node){
        
        visited[node]=1;
        ans.push_back(node);
        
        for(auto neighbour: adj[node]){
            
            if(!visited[neighbour]){
                dfs(visited,ans,adj,neighbour);
            }
        }
    }

  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        
        vector<int>ans;
        
        vector<bool>visited(V,0);
        
        dfs(visited,ans,adj,0);
        return ans;
    }


int main() {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans = dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    
    return 0;
}