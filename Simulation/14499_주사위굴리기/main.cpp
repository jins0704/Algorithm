//
//  main.cpp
//  14499_주사위굴리기
//
//  Created by 홍진석 on 2021/09/27.
//

#include <iostream>
#include <vector>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

vector<int> dice(7,0); //바닥은 항상 6
vector<int> answer;
int N,M,x,y,K;
int a,b;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void moveDice(int command){
    if(command == 1){//동
        int temp = dice[1];
        dice[1] = dice[4]; // 1->4
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }
    else if(command == 2){//서
        int temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }
    else if(command == 3){//북
        int temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }
    else{//남
        int temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }

}
int main() {
    cin >> N >> M >> x >> y >> K;
    vector<vector<int>> map(N);

    FOR(i, N){
        FOR(j, M){
            cin >> a;
            map[i].push_back(a);
        }
    }

    FOR(i, K){
        cin >> b;
        if(x+dx[b-1] >= 0 && y+dy[b-1] >= 0){
            if(x+dx[b-1] < N && y+dy[b-1] < M){
                x += dx[b-1];
                y += dy[b-1];
                
                moveDice(b);
                if(map[x][y] == 0){//칸 = 0 -> 주사위 바닥면 수가 복사
                    map[x][y] = dice[6];
                }
                else{//칸 != 0 -> 칸에 쓰여있는수가 바닥면으로 복사, 칸은 0
                    dice[6] = map[x][y];
                    map[x][y] = 0;
                }
                cout << dice[1] << endl;
            }
        }
    }
    
    return 0;
}

