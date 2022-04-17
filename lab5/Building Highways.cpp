#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef pair<int,int> pii;
vector<int> parent;

struct edge{
    int from;
    int to;
    int cost;
};

bool cmp1(edge a, edge b){
    return a.cost < b.cost;
}

bool cmp2(edge a, edge b){
    return a.cost > b.cost;
}

int find(int idx){
    if(idx == parent[idx]) return idx;
    return parent[idx] = find(parent[idx]);
}

void uni(int a, int b){
    int r1 = find(a), r2 = find(b);
    parent[r2] = r1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m, k, f, s;
        cin >> n >> m >> k >> f >> s;
        
        int from, to;
        char type;
        vector<edge> edges;
        for(int i=0; i<m; i++){
            cin >> from >> to >> type;
            edge e;
            e.from = from;
            e.to = to;
            e.cost = (type == 'F' ? f : s);
            edges.push_back(e);
        }

        bool flag = true;
        vector<edge> mst;

        // minimum
        sort(edges.begin(), edges.end(), cmp1);
        mst.clear();
        parent.clear();
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        for(auto it: edges){
            if(find(it.from) != find(it.to)){
                uni(it.from, it.to);
                mst.push_back(it);
            }
        }
        int mn = 0;
        for(auto it: mst) mn += it.cost;
        if(mst.size() != n-1) flag = false;

        // maximum
        sort(edges.begin(), edges.end(), cmp2);
        mst.clear();
        parent.clear();
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        for(auto it: edges){
            if(find(it.from) != find(it.to)){
                uni(it.from, it.to);
                mst.push_back(it);
            }
        }

        int mx = 0;
        for(auto it: mst) mx += it.cost;
        if(mst.size() != n-1) flag = false;
        
        if(flag && k >= mn && k <= mx){
            flag = false;
            for(int i=0; i<=k; i+=s){
                if((k-i)%f == 0 && (k-i)/f + i/s == n-1) flag = true;
            }
            cout << (flag ? "Yes" : "No") << '\n';
        }else{
            cout << "No" << '\n';
        }
    }
}