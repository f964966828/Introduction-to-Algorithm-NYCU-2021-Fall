#include <bits/stdc++.h>

using namespace std;

void First_DFS(vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &topo_order, int idx){
    visited[idx] = 1;
    for(auto it: adj_list[idx]){
        if(!visited[it]) First_DFS(adj_list, visited, topo_order, it);
    }
    topo_order.push_back(idx);
} 

void Second_DFS(vector<vector<int>> &rev_list, vector<int> &visited, vector<int> &SCC_idx, vector<vector<int>> &SCC_member, int time, int idx){
    visited[idx] = 1;
    SCC_idx[idx] = time;
    SCC_member[time].push_back(idx);
    for(auto it: rev_list[idx]){
        if(!visited[it]) Second_DFS(rev_list, visited, SCC_idx, SCC_member, time, it);
    }
}

int Third_DFS(vector<vector<int>> &new_adj_list, vector<vector<int>> &SCC_member, vector<int> &result, int idx){
    if(result[idx]) return result[idx];
    for(auto it: new_adj_list[idx]){
        result[idx] = max(result[idx], Third_DFS(new_adj_list, SCC_member, result, it));
    }
    result[idx] += SCC_member[idx].size();
    return result[idx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj_list(n), rev_list(n);
    int from, to;
    for(int i=0; i<m; i++){
        cin >> from >> to;
        adj_list[from].push_back(to);
        rev_list[to].push_back(from);
    }

    vector<int> topo_order, visited(n);
    for(int i=0; i<n; i++){
        if(!visited[i]) First_DFS(adj_list, visited, topo_order, i);
    }
    
    reverse(topo_order.begin(), topo_order.end());

    for(int i=0; i<n; i++) visited[i] = 0;
    vector<int> SCC_idx(n);
    vector<vector<int>> SCC_member(n);

    int time = 0;
    for(auto it: topo_order){
        if(!visited[it]) Second_DFS(rev_list, visited, SCC_idx, SCC_member, time++, it);
    }

    vector<int> in_node(n);
    vector<vector<int>> new_adj_list(n);
    for(int i=0; i<n; i++){
        for(auto it: SCC_member[i]){
            for(auto to: adj_list[it]){
                if(i != SCC_idx[to]){
                    new_adj_list[i].push_back(SCC_idx[to]);
                    in_node[SCC_idx[to]]++;
                }
            }
        }
    }

    vector<int> result(n);
    for(int i=0; i<n; i++){
        if(in_node[i] == 0) Third_DFS(new_adj_list, SCC_member, result, i);
    }

    int ans = 0;
    for(auto it: result) ans = max(ans, it);
    cout << ans << "\n";
}