#include <bits/stdc++.h>
#define int long long

using namespace std;

int loss(vector<int> &seq, int l, int r){
    int mx = -1e9, sum = 0;
    for(int i=l; i<=r; i++) mx = max(mx, seq[i]);
    for(int i=l; i<=r; i++) sum += mx-seq[i];
    return sum;
}

int solve(vector<int> &seq, int l, int r){
    int mid = (l+r)/2;
    if(r-l < 2) return 0;
    else return min(solve(seq, l, mid) + loss(seq, mid+1, r), loss(seq, l, mid) + solve(seq, mid+1, r));
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i=0; i<n; i++) cin >> seq[i];

    cout << solve(seq, 0, n-1) << endl;
}