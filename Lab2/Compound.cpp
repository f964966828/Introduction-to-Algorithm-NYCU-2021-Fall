#include <bits/stdc++.h>

using namespace std;

map<string, int> solve(string str){
    map<string, int> ans;
    string ele, num, tmp;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            int cnt = 1;
            while(cnt){
                if(str[++i] == '(') cnt++;
                else if(str[i] == ')') cnt--;
                  
                if(cnt) tmp.push_back(str[i]);
            }
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            ele.push_back(str[i]);
            if(i+1 != str.size() && str[i+1] >= 'a' && str[i+1] <= 'z') ele.push_back(str[++i]);
        }

        while(i+1 != str.size() && (str[i+1] >= '0' && str[i+1] <= '9')) num.push_back(str[++i]);
        num = (num.size() ? num : "1");

        if(ele.size()){
            ans[ele] += stoi(num);
            ele.clear();
        }else if(tmp.size()){
            for(auto it: solve(tmp)) ans[it.first] += it.second * stoi(num);
            tmp.clear();
        }
        num.clear();
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    
    map<string, int> ans = solve(str);
    vector<pair<string, int>> one, two;
    for(auto it: ans){
        if(it.first.size() == 1) one.push_back({it.first, it.second});
        else two.push_back({it.first, it.second});
    }

    cout << one.size() << endl;
    for(auto it: one) cout << it.first << ":" << it.second << endl;
    cout << two.size() << endl;
    for(auto it: two) cout << it.first << ":" << it.second << endl;

    return 0;
}