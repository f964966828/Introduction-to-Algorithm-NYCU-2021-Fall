#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, T;
    cin >> N >> T;
    
    vector<int> seq(N);
    for(int i=0; i<N; i++){
        cin >> seq[i];
    }

    sort(seq.begin(), seq.end());
    
    int cnt = 0;
    for(int i=0; i<N-2; i++){
        if(i && seq[i] == seq[i-1]) continue;
        int j = i+1;
        int k = N-1;
        
        while(j<k){
            if(seq[i]+seq[j]+seq[k] == T) cnt++;

            if(seq[i]+seq[j]+seq[k] > T){
                k--;
                while(k && seq[k] == seq[k+1]) k--;
            }else{
                j++;
                while(j<N && seq[j] == seq[j-1]) j++;
            }
        }
    }

    if(cnt) cout << cnt << endl;
    else cout << "FeiDooDoo_Zuo_Wei_Men" << endl;

}