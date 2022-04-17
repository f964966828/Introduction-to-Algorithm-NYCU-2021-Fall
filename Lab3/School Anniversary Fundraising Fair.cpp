#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

bool cmp(pii a, pii b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, p, l, r;
    cin >> n >> p >> l >> r;

    vector<pii> itv(n);
    for(int i=0; i<n; i++) cin >> itv[i].first >> itv[i].second;

    sort(itv.begin(), itv.end(), cmp);

    priority_queue<pii> pq;
    int idx = 0, cnt = 0;
    while(idx != n && itv[idx].first <= l) pq.push({itv[idx].second, itv[idx++].first});
    

    while(l < r){
        if(pq.empty()) break;
        l = pq.top().first; pq.pop();
        while(idx != n && itv[idx].first <= l) pq.push({itv[idx].second, itv[idx++].first});
        cnt++;
    }

    cout << (l<r ? 0 : cnt * p) << endl;
}