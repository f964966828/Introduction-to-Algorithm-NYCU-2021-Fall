#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int value[7] = {1000, 500, 100, 50, 10, 5, 1};
        vector<ll> change(n);
        vector<ll> coin_number(7);
        ll sum, pay, num;
        for(int i=0; i<n; i++){
            cin >> sum;
            pay = 0;
            for(int j=0; j<7; j++){
                cin >> num;
                pay += num * value[j];
                coin_number[j] += num;
            }
            change[i] = pay-sum;
        }

        bool flag = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<7; j++){
                if(change[i]){
                    num = min(change[i]/value[j], coin_number[j]);
                    change[i] -= num * value[j];
                    coin_number[j] -= num;
                }
            }
            if(change[i]) flag = false;
        }

        cout << (flag ? "Yes" : "No") << endl;
    }
}