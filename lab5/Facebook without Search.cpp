#include <bits/stdc++.h>

using namespace std;

struct query{
    char op;
    int a;
    int b;
};

vector<int> set_idx;

int find(int idx){
    if(idx == set_idx[idx]) return idx;
    return set_idx[idx] = find(set_idx[idx]);
}

void uni(int a, int b){
    int r1 = find(a), r2 = find(b);
    set_idx[r2] = r1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    set<pair<int,int>> rls;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        rls.insert({min(a, b), max(a, b)});
    }

    vector<query> queries(Q);
    for(auto &it: queries){
        cin >> it.op >> it.a >> it.b;
        if(it.op == 'U'){
            rls.erase({min(it.a, it.b), max(it.a, it.b)});
        }
    }

    set_idx.resize(N);
    for(int i=0; i<N; i++) set_idx[i] = i;
    for(auto it: rls) uni(it.first, it.second);
    
    vector<int> ans;
    for(int i=Q-1; i>=0; i--){
        if(queries[i].op == 'U') uni(queries[i].a, queries[i].b);
        else{
            ans.push_back(find(queries[i].a) == find(queries[i].b) ? 1 : 0); 
        }
    }
    
    for(int i=ans.size()-1; i>=0; i--) cout << (ans[i] ? "YES" : "NO") << "\n";
}