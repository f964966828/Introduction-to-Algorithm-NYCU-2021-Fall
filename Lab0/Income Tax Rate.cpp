#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int,double>> rates;

    double value, rate;
    for(int i=0; i<N; i++){
        cin >> value >> rate;
        rates.push_back({value-1,rate});
    }
    rates.push_back({1e9+5, 0});

    int M;
    cin >> M;
    
    int amount;
    for(int i=0; i<M; i++){
        cin >> amount;

        double sum = 0.0;

        for(int j=1; j<rates.size(); j++){
            if(amount < rates[j-1].first) break;
            sum += (min(amount, rates[j].first) - rates[j-1].first) * rates[j-1].second;
        }

        cout << fixed << setprecision(10) << sum << endl;
    }

    return 0;
}