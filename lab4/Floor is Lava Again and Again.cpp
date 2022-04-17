#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, t;
vector<vector<ll>> info, dp;

ll solve(int time, int idx){
    if(time == t-1) return info[t-1][idx];
    else if(dp[time][idx]) return dp[time][idx];

    ll mx = -1e13;
    for(int i=-1; i<=1; i++) if(idx+i >= 0 && idx+i < n) mx = max(mx, solve(time+1, idx+i));

    dp[time][idx] = mx + info[time][idx];
    return dp[time][idx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    info.resize(t); dp.resize(t);
    for(int i=0; i<t; i++) info[i].resize(n), dp[i].resize(n);
    for(int i=0; i<t; i++) for(int j=0; j<n; j++) cin >> info[i][j];
    for(int i=0; i<n; i++) cout << solve(0, i) << " ";
    cout << endl;
}