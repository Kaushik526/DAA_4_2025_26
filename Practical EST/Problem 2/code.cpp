class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        

        vector<pair<int,int>> adj[V];
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }
        

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int d = it.first;
            int node = it.second;
            
            if(d > dist[node]) continue;
            
            for(auto &neighbor : adj[node]){
                int adjNode = neighbor.first;
                int weight = neighbor.second;
                
                if(d + weight < dist[adjNode]){
                    dist[adjNode] = d + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};