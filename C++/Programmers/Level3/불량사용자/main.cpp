//
//  main.cpp
//  불량사용자
//
//  Created by 홍진석 on 2021/11/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

set<set<string>> ss;

int findPair(vector<pair<string, vector<string>>> &v, set<string> &s, int cnt){
    int sol = 0;
    if(cnt == v.size()) {
        if(ss.find(s) == ss.end()){
            ss.insert(s);
            return 1;
        }
    }
    else{
        FOR(i, v[cnt].second.size()){
            if(s.find(v[cnt].second[i]) == s.end()){
                s.insert(v[cnt].second[i]);
                sol += findPair(v, s, cnt+1);
                s.erase(v[cnt].second[i]);
            }
        }
    }
    return sol;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    map<string, vector<string>> info;
    FOR(i, banned_id.size()){
        string name = banned_id[i] + to_string(i);
        info.insert(make_pair(name, vector<string>()));
        int bsize = int(banned_id[i].size());
        FOR(j, user_id.size()){
            if(user_id[j].size() != bsize){ continue; }
            bool check = true;
            FOR(k, user_id[j].size()){
                if(banned_id[i][k] == '*') { continue; }
                if(user_id[j][k] != banned_id[i][k]) { check = false; break; }
            }
            if(check) {
                info[name].push_back(user_id[j]);
            }
        }
    }

    vector<pair<string, vector<string>>> v(info.begin(),info.end());
    
    set<string> s;

    return findPair(v,s,0);
}

int main() {
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"*rodo", "*rodo", "******"};
    cout << solution(user_id, banned_id);
    
    return 0;
}
