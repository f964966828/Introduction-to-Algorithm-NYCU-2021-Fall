#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

pii solve(vector<vector<pii>> &dp, vector<ll> &seq, int l, int r){
    if(l == r) return {0,seq[l]};
    if(dp[l][r].first) return dp[l][r];
    
    ll score = -1e9, number = 0;
    for(int i=1; i<r-l; i++){
        for(int j=1; j<r-l; j++){
            if(l+i+j > r || i == 2 || j == 2 || r-l-i-j+1 == 2) continue;

            pii l1 = solve(dp, seq, l, l+i-1);
            pii l2 = solve(dp, seq, l+i, l+i+j-1);
            pii l3 = solve(dp, seq, l+i+j, r);
            ll new_score = l1.second * l3.second - l2.second + l1.first + l2.first + l3.first;
            ll new_number = l1.second + l2.second + l3.second;
            if(new_score > score){
                score = new_score;
                number = new_number;
            }
        }
    }
    
    dp[l][r] = {score, number};
    return dp[l][r];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> seq(n);
    for(int i=0; i<n; i++) cin >> seq[i];

    vector<vector<pii>> dp(n, vector<pii>(n));
    
    cout << solve(dp, seq, 0, n-1).first << endl;
}