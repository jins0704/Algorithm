//
//  main.cpp
//  네트워크
//
//  Created by 홍진석 on 2021/07/01.
//

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
bool check[201];
void bfs(int start, int n, vector<vector<int>> v){
    queue<int> q;
    
    q.push(start);
    
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        
        for(int i=0; i<n; i++){
            if(cx != i && !check[i]){
                if(v[cx][i] == 1){
                    check[i] = true;
                    q.push(i);
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int network[201] = {0, };
    
//     for(int i=0; i<computers.size(); i++){
//         for(int j=0; j<computers[i].size(); j++){
//             cout << computers[i][j] << " ";
//         }cout << endl;
//     }

    for(int i=0; i<n; i++){
        if(check[i] == 0){
            bfs(i,n,computers);
            answer ++;
        }
    }
    return answer;
}
