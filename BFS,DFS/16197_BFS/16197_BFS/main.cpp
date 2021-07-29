//
//  main.cpp
//  16197_BFS
//
//  Created by 홍진석 on 2021/07/29.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M;
char c;
char arr[21][21];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<pair<int, int>,pair<int, int>>> q;

int bfs(){
    int cnt = 0;

    while(!q.empty()){
        int size = int(q.size());

        for(int i=0; i<size; i++){
            int firstCX = q.front().first.first;
            int firstCY = q.front().first.second;
            int secondCX = q.front().second.first;
            int secondCY = q.front().second.second;
            
            q.pop();

            for(int j=0; j<4; j++){
                int firstNX = firstCX + dx[j];
                int firstNY = firstCY + dy[j];
                int secondNX = secondCX + dx[j];
                int secondNY = secondCY + dy[j];
                if(arr[firstNX][firstNY] == '#'){
                    firstNX = firstCX;
                    firstNY = firstCY;
                }
                if(arr[secondNX][secondNY] == '#'){
                    secondNX = secondCX;
                    secondNY = secondCY;
                }
                
                int check = 0;
                
                if(firstNX < 0 || firstNX >= N || firstNY < 0 || firstNY >= M){check ++;}
                if(secondNX < 0 || secondNX >= N || secondNY < 0 || secondNY >= M){check ++;}
                
                if(check == 0){
                    q.push(make_pair(make_pair(firstNX, firstNY), make_pair(secondNX, secondNY)));
                }
                else if(check == 1){
                    return cnt+1;
                }
            }
        }
        cnt++;
        if(cnt >= 10){return -1;}
    }
    return -1;
}

int main() {
    
    cin >> N >> M;
    int coinIdx = 1;
    pair<int, int> coinFirst;
    pair<int, int> coinSecond;
    
    //init
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'o'){
                if(coinIdx == 1){
                    coinFirst = make_pair(i, j);
                    coinIdx++;
                }
                else{
                    coinSecond = make_pair(i, j);
                }
            }
        }
    }
    q.push(make_pair(coinFirst, coinSecond));
   
    cout << bfs();

    return 0;
}
