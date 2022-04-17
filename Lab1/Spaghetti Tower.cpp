#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, k;
    cin >> N >> k;
    
    vector<int> seq(N);
    for(int i=0; i<N; i++) cin >> seq[i];
    sort(seq.begin(), seq.end());

    int Q;
    cin >> Q;
    while(Q--){
        int x, l;
        cin >> x >> l;
        
        int limit = min(l+1, k*x+1);
        long long ans = 0;
        
        vector<int>::iterator constraint = lower_bound(seq.begin(), seq.end(), limit);
        vector<int>::iterator previous, current;

        //for(auto it: seq) cout << it << " ";
        //cout << endl;

        int target = x;
        int iteration = 0;
        previous = current = lower_bound(seq.begin(), seq.end(), target);
        while(constraint - current > 0){
            target += x;
            current = lower_bound(seq.begin(), seq.end(), target);
            if(constraint - current <= 0) current = constraint;
            ans += (*previous/x) * (current - previous);
            previous = current;
            
            //cout << " " << target << " " << *current << " " << current-seq.begin() << endl;
        }

        cout << ans << endl;
    }
}