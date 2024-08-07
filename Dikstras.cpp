vector<int> dikstras(int src , unordered_map<int,vector<pair<int,int>>>&adj , vector<int>&dist , int n , int m){

    vecotr<int> dist;
    for(int i=0;i<n+1;i++){
        dist[i]  = INT_MAX;
    }
    set<pair<int,int> >st;
    dist[src] = 0 ;

    st.insert({0,1}) ; // distance , source

    while(!st.empty()){
        auto top = *(st.begin());
        int nodedis = top.first ;
        int node = top.second ;
        st.erase(st.begin());
        
        for(auto nei : adj[node]){
            if(nodedis + nei.second < dis[nei.first]){
                auto rec = st.find(dist[nei.first], nei.first);
                if(rec!=st.end()){
                    st.erase(rec);
                }
                dist[nei.first] = nodedis + nei.second;
                st.insert({dist[nei.first],nei.first});
            }
        }
    }
    return dist;

}
