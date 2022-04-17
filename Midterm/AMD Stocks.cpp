#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

bool cmp(pii a, pii b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pii> itv(n);
    for(int i=0; i<n; i++) cin >> itv[i].first >> itv[i].second;

    sort(itv.begin(), itv.end(), cmp);

    multiset<int> times;
    for(int i=0; i<k; i++) times.insert(0);
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        //cout << times.top() << " " << itv[i].first << endl;
        auto it = times.lower_bound(itv[i].first);
        if(it == times.begin()) continue;
        times.erase(--it);
        times.insert(itv[i].second);
        cnt++;
    }
    
    cout << cnt << endl;
}