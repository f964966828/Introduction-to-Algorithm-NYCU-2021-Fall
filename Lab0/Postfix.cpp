#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    getline(cin, input);
    stringstream ss;
    ss << input;

    string str;
    stack<ll> nums;
    while(ss >> str){
        if(str == "+" || str == "*"){
            ll num1 = nums.top(); nums.pop();
            ll num2 = nums.top(); nums.pop();
            if(str == "+") nums.push((num1+num2)%mod);
            if(str == "*") nums.push((num1*num2)%mod);
        }else{
            nums.push(stoi(str)%mod);
        }
    }

    cout << nums.top() << endl;

    return 0;
}