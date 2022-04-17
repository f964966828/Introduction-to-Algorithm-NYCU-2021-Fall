#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll fast_mul(ll a, ll pow){
    ll ans = 1, mul = a;
    while(pow){
        if(pow&1) ans = (ans*mul)%mod;
        mul = (mul*mul)%mod;
        pow >>= 1;
    } 
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    ll a, b, n, i;
    cin >> a >> b >> n;

    while(n--){
        cin >> i;
        ll ans = (b * (fast_mul(a,i-1)-1)) % mod;
        ans = (ans * fast_mul(a-1,mod-2)) % mod;
        ans = (ans + fast_mul(a,i-1) + mod) % mod;
        cout << ans << endl;
    }
    

    return 0;
}