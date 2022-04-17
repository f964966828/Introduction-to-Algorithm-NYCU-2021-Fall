#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<ll> seq(N);
    for(auto &it: seq) cin >> it;
    
    sort(seq.begin(), seq.end());

    ll ans = 1;
    for(int i=0; i<N; i++){
        ll mul = min(N,seq[i])-i;
        ans *= max(0ll,mul);
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}