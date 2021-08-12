//
//  main.cpp
//  거짓말
//
//  Created by 홍진석 on 2021/08/12.
//

#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

int N, M;
int a, b, c, d;
int arr[51][51];
bool check[51];
vector<int> parties[51];

void bfs(int V){
    queue<int> q;
    q.push(V);
    
    while (!q.empty()) {
        int cx = q.front();
        q.pop();
        
        FOR(i, N+1){
            if(arr[cx][i] == 1 && !check[i]){
                check[i] = true;
                q.push(i);
            }
        }
    }
}
int main() {
    cin >> N >> M; //사람 수, 파티의 수
    cin >> a;
    vector<int> knowPeoeple;
    FOR(i, a){
        cin >> b;
        knowPeoeple.push_back(b); //진실을 알고 있는 사람
        check[b] = true;
    }
    
    FOR(i, M){
        cin >> c;
        FOR(j, c){
            cin >> d;
            parties[i].push_back(d); //파티 저장
        }
    }
    
    FOR(i, M){
        for(int j =0; j<parties[i].size()-1; j++){
            for(int k = j+1; k < parties[i].size(); k++){
                arr[parties[i][j]][parties[i][k]] = 1; arr[parties[i][k]][parties[i][j]] = 1;
            }
        }
    }
    
    
    FOR(i, knowPeoeple.size()){ bfs(knowPeoeple[i]); }

    int cnt = 0;
    FOR(i, M){
        bool poss = true;
        FOR(j, parties[i].size()){
            if(check[parties[i][j]]){
                poss = false;
                break;
            }
        }
        if(poss){ cnt ++; }
    }
    cout << cnt;
    
    return 0;
}
