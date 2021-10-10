//
//  main.cpp
//  1764_듣보잡
//
//  Created by 홍진석 on 2021/10/10.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N,M;
    string s;
    vector<string> answer;
    cin >> N >> M;
    set<string> m;
    
    for(int i=0; i<N+M; i++){
        cin >> s;
        if(m.find(s) != m.end()){
            answer.push_back(s);
        }
        else{
            m.insert(s);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << endl;
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    
    return 0;
}
