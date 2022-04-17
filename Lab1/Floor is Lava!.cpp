#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<pii> furs(n);
    for(int i=0; i<n; i++) cin >> furs[i].first >> furs[i].second;

    double l = 0, r = 1e9;
    for(int i=0; i<200; i++){
        ll sum = 0;
        double mid = (l+r)/2;
        for(int j=0; j<n; j++) sum += max(ll(furs[j].first/mid) - furs[j].second, ll(0));
        
        if(sum >= k) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(10) << (l+r)/2 << endl;

    return 0;
}