#include <bits/stdc++.h>

using namespace std;
vector<int> s, inv_in, post;

void solve(int& idx, int pidx, int l, int r, int& cnt){
    idx--;
    if(pidx != -1 && s[post[idx]] > s[post[pidx]]) cnt++;

    pidx = idx;
    if(idx != 0 && inv_in[post[idx-1]] > inv_in[post[pidx]] && inv_in[post[idx-1]] <= r){
        solve(idx, pidx, inv_in[post[pidx]], r, cnt);    
    }
    if(idx != 0 && inv_in[post[idx-1]] < inv_in[post[pidx]] && inv_in[post[idx-1]] >= l){
        solve(idx, pidx, l, inv_in[post[pidx]], cnt);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    s.resize(n);
    inv_in.resize(n);
    post.resize(n);

    int tmp;
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++){
        cin >> tmp;
        inv_in[tmp-1] = i;
    }
    for(int i=0; i<n; i++){
        cin >> tmp;
        post[i] = tmp-1;
    }

    int idx = n, cnt = 0;
    solve(idx, -1, 0, n-1, cnt);
    
    cout << cnt << endl;
}