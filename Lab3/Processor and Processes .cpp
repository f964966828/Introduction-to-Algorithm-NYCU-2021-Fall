#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int main(){
    int n, c, q;
    cin >> n >> c >> q;

    vector<int> seq(q);
    vector<vector<int>> tasks(n+1);
    priority_queue<pii> pq;
    
    for(int i=0; i<q; i++){
        cin >> seq[i];
        tasks[seq[i]].push_back(i);
    }
    for(int i=1; i<=n; i++) tasks[i].push_back(1e9);

    int cnt = 0, idx = 0;
    set<int> s;
    vector<int> flag(n+1);
    while(cnt != c && idx != q){
        if(!flag[seq[idx]]) cnt++;
        flag[seq[idx]]++;
        s.insert(seq[idx]);
        idx++;
    }

    for(int i=1; i<=n; i++){
        if(flag[i]){
            pq.push({tasks[i][flag[i]], i});
            s.insert(i);
        }
    }

    int ans = cnt;
    for(int i=idx; i<q; i++){
        if(s.find(seq[i]) == s.end()){
            ans++;
            s.erase(pq.top().second);
            s.insert(seq[i]);
            pq.pop();
        }

        flag[seq[i]]++;
        pq.push({tasks[seq[i]][flag[seq[i]]], seq[i]});
    }

    cout << ans << endl;
}