#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> pii;

struct edge{
    int from;
    int to;
    int cost;
};

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj_list(n), rev_list(n);
    vector<edge> edges;
    int from, to, cost;
    for(int i=0; i<m; i++){
        cin >> from >> to >> cost;
        
        from--;
        to--;

        adj_list[from].push_back({to, cost});
        rev_list[to].push_back({from, cost});
        
        edge e;
        e.from = from;
        e.to = to;
        e.cost = cost;
        edges.push_back(e);
    }

    priority_queue<pii> pq;
    pq.push({0, 0});

    vector<int> visited(n), dis(n, 1e15);
    dis[0] = 0;
    while(!pq.empty()){
        from = pq.top().second;
        pq.pop();
        
        if(visited[from]) continue;
        else visited[from] = 1;
        
        for(auto it: adj_list[from]){
            to = it.first;
            cost = it.second;

            dis[to] = min(dis[to], dis[from] + cost);
            pq.push({-dis[to], to});
        }
    }

    pq.push({0, n-1});
    vector<int> rev_visited(n), rev_dis(n, 1e15);
    rev_dis[n-1] = 0;
    while(!pq.empty()){
        from = pq.top().second;
        pq.pop();
        
        if(rev_visited[from]) continue;
        else rev_visited[from] = 1;
        
        for(auto it: rev_list[from]){
            to = it.first;
            cost = it.second;

            rev_dis[to] = min(rev_dis[to], rev_dis[from] + cost);
            pq.push({-rev_dis[to], to});
        }
    }

    for(auto e: edges){
        cost = dis[e.from] + e.cost + rev_dis[e.to];
        cout << (cost - dis[n-1] <= e.cost ? cost - dis[n-1] : -1) << "\n";        
    }

    return 0;
}