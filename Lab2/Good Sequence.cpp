#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll loss(vector<int> &seq, int l, int r){
    if(r == l) return 0;

    vector<int> tmp;
    int idx1 = l, idx2 = (l+r)/2 + 1;
    // merge
    while(idx1 <= (l+r)/2 || idx2 <= r){
        if(seq[idx1] <= seq[idx2] && idx1 <= (l+r)/2 || idx2 > r) tmp.push_back(seq[idx1++]);
        else tmp.push_back(seq[idx2++]);
    }
    for(int i=0; i<=r-l; i++) seq[l+i] = tmp[i];

    ll loss = 0, median = seq[(l+r)/2];
    for(int i=l; i<=r; i++) loss += abs(seq[i]-median);

    return loss;
}

ll solve(vector<int> &seq, int l, int r){
    if(r == l) return 0;
    
    int m = (l+r)/2;
    ll s1 = solve(seq, l, m), s2 = solve(seq, m+1, r);
    ll l1 = loss(seq, l, m), l2 = loss(seq, m+1, r);

    if(r-l < 2) return 0;
    else return min(s1+l2, s2+l1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i=0; i<n; i++) cin >> seq[i];

    cout << solve(seq, 0, n-1) << endl;

    return 0;
}