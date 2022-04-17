#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, S;
    cin >> N >> M >> S;
    
    vector<int> years(N);
    for(int i=0; i<N; i++) cin >> years[i];
    sort(years.begin(), years.end());

    // strength, count
    int sum = N;
    int s, e, w;
    vector<pii> pandemic;
    for(int i=0; i<M; i++){
        cin >> s >> e >> w;
        auto left = lower_bound(years.begin(), years.end(), s);
        auto right = upper_bound(years.begin(), years.end(), e);
        pandemic.push_back({w, right-left});
        sum -= (right-left);
    }

    vector<int> dp;
    dp.resize(S+1);
    
    for(int i=0; i<M; i++){
        int weight = pandemic[i].first, cost = pandemic[i].second;
        for(int j=S; j-weight >= 0; j--){
            dp[j] = max(dp[j], dp[j-weight] + cost);
        }
    }

    cout << dp[S] + sum << endl;
}