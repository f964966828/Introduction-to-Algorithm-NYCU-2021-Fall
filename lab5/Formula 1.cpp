#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long
vector<int> parent;
const int mod = 1e9+7;

struct edge{
    int a;
    int b;
    int cost;
};

bool cmp(edge e1, edge e2){
    return e1.cost < e2.cost;
}

int find(int idx){
    if(idx == parent[idx]) return idx;
    return parent[idx] = find(parent[idx]);
}

void uni(int a, int b){
    int r1 = find(a), r2 = find(b);
    parent[r2] = r1;
}

int DFS(vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &child_num, int idx){
    visited[idx] = 1;
    for(auto it: adj_list[idx]){
        if(!visited[it]) child_num[idx] += DFS(adj_list, visited, child_num, it);
    }
    return child_num[idx];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    for(auto &it: edges) cin >> it.a >> it.b >> it.cost;
    
    sort(edges.begin(), edges.end(), cmp);

    vector<edge> mst;
    parent.resize(n+1);
    for(int i=0; i<n; i++) parent[i] = i;
    for(auto it: edges){
        if(find(it.a) != find(it.b)){
            uni(it.a, it.b);
            mst.push_back(it);
        }
    }

    if(mst.size() == n-1){
        int sum = 0;
        for(auto it: mst) sum = (sum + it.cost) % mod;
        cout << sum*2%mod << " ";
        
        vector<int> child_num(n, 1), visited(n);
        vector<vector<int>> adj_list(n);
        for(auto it: mst){
            adj_list[it.a-1].push_back(it.b-1);
            adj_list[it.b-1].push_back(it.a-1);
        }

        DFS(adj_list, visited, child_num, 0);

        sum = 0;
        for(auto it: mst){
            int tmp = min(child_num[it.a-1], child_num[it.b-1]);
            sum = (sum + (tmp*(n-tmp)*it.cost*2)%mod) % mod;
        }

        cout << sum%mod << "\n";

    }else{
        cout << -1 << "\n";
    }

    return 0;
}