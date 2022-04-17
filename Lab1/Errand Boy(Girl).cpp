#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L, k;
    cin >> N >> L >> k;

    int num;
    vector<int> w(N);
    for(int i=0; i<N; i++) cin >> w[i];

    sort(w.begin(), w.end());

    long long cnt = 0;
    int l = 0, r = N-1;
    while(l <= r){
        if(w[l]+w[r] <= L){
            l++;
            r--;
        }else{
            r--;
        }
        cnt++;
    }

    cout << cnt*k*2 << endl;

    return 0;
}