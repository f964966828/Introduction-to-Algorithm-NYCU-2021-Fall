#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> values(n);
    for(int i=0; i<n; i++) cin >> values[i];

    vector<int> dp(1e5+5, 1e9);
    dp[0] = 0;
    for(int w=0; w<=1e5+5; w++){
        for(int i=0; i<n; i++) if(w >= values[i]) dp[w] = min(dp[w], dp[w-values[i]]+1);
    }

    int q;
    cin >> q;
    while(q--){
        ll price;
        ll coins[n];
        cin >> price;
        for(int i=0; i<n; i++) cin >> coins[i];

        ll total = 0;
        for(int i=0; i<n; i++) total += values[i]*coins[i];

        cout << dp[int(total - price)] << "\n";
    }

}