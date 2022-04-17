#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> seq(n);
    for(int i=0; i<n; i++) cin >> seq[i];

    sort(seq.begin(), seq.end());

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        
        auto lit = lower_bound(seq.begin(), seq.end(), l);
        auto rit = upper_bound(seq.begin(), seq.end(), r);

        //cout << "ans: " << *lit << " " << *rit << "\n";
        cout << rit - lit << "\n";
    }
    
}