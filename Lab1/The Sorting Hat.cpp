#include <bits/stdc++.h>

using namespace std;

typedef pair<string,vector<int>> student;

bool cmp(student &a, student &b){
    for(int i=0; i<4; i++){
        if(a.second[i] != b.second[i]) return a.second[i] > b.second[i];
    }
    return a.first < b.first; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    string str;
    map<char,int> mp;
    mp['G'] = 0;
    mp['H'] = 1;
    mp['R'] = 2;
    mp['S'] = 3;

    int permutation[4][4];
    for(int i=0; i<4; i++){
        cin >> str;
        for(int j=0; j<4; j++) permutation[i][j]=mp[str[j]];
    }

    string name;
    vector<int> tmp(4);
    vector<int> score(4);    
    vector<vector<student>> students(4);
    for(int i=0; i<n; i++){
        cin >> name >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];

        int mx = 0, idx;
        for(int j=0; j<4; j++){
            if(tmp[j] > mx){
                mx = tmp[j];
                idx = j;
            }
        }
        
        for(int j=0; j<4; j++) score[j]=tmp[permutation[idx][j]];

        students[idx].push_back({name,score});
    }
    
    
    for(int i=0; i<4; i++) sort(students[i].begin(), students[i].end(), cmp);

    string school_name[] = {"GRYFFINDOR", "HUFFLEPUFF", "RAVENCLAW", "SLYTHERIN"};
    for(int i=0; i<4; i++){
        cout << school_name[i] << ": " << (students[i].size() ? "" : "NO NEW STUDENTS") << "\n";
        for(auto it: students[i]) cout << it.first << "\n";
    }

    return 0;
}