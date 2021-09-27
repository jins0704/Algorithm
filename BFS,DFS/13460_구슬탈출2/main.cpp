//
//  main.cpp
//  13460_구슬탈출2
//
//  Created by 홍진석 on 2021/09/27.
//

#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;
vector<vector<char>> board(11);
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct boardStatus {
    pair<int, int> blue;
    pair<int, int> red;
    int command;
};

pair<pair<int, int>, pair<int, int>> move(int command, pair<int, int> blue, pair<int, int> red){
    int blueCompleted = -1;
    int redCompleted = -1;
    bool fail = false;
    bool success = false;
    int ccnt = 1;
    while (blueCompleted == -1 || redCompleted == -1) {
        if(blueCompleted == -1){
            if(board[blue.first + dx[command]][blue.second + dy[command]] == 'O'){
                fail = true;
                blueCompleted = ccnt;
            }
            else if(board[blue.first + dx[command]][blue.second + dy[command]] != '#'){
                blue.first += dx[command];
                blue.second += dy[command];
            }
            else{ blueCompleted = ccnt; }
        }
    
        if(redCompleted == -1){
            if(board[red.first + dx[command]][red.second + dy[command]] == 'O'){
                success = true;
                redCompleted = ccnt;
            }
            
            else if(board[red.first + dx[command]][red.second + dy[command]] != '#'){
                red.first += dx[command];
                red.second += dy[command];
            }
            
            else{ redCompleted = ccnt; }
        }

        ccnt ++;
    }
    if(success || fail){
        if(fail) {
            return make_pair(make_pair(-1, -1), make_pair(-1, -1));
        }
        if(success){
            return make_pair(make_pair(-2, -2), make_pair(-2, -2));
        }
    }
    
    if(blue.first == red.first && blue.second == red.second){
        if(blueCompleted > redCompleted){ // red가 먼저
            blue.first += (dx[command]*-1);
            blue.second += (dy[command]*-1);
        }
        else { // blue가 먼저
            red.first += (dx[command]*-1);
            red.second += (dy[command]*-1);
        }
    }

    return make_pair(make_pair(red.first, red.second), make_pair(blue.first, blue.second));
}

int BFS(pair<int, int> &blue, pair<int, int> &red){
    queue<boardStatus> q;
    int cnt = 0;
    
    FOR(i, 4){
        boardStatus b;
        b.blue = blue;
        b.red = red;
        b.command = i;
        q.push(b);
    }
    
    
    while (cnt < 10) {
        int qsize = int(q.size());
        cnt++;
        FOR(i, qsize){
            boardStatus c_status = q.front();
            q.pop();
            pair<pair<int, int>, pair<int, int>> result = move(c_status.command, c_status.blue, c_status.red);
           
            if(result.first.first == -1){//fail
                continue;
            }
            else if(result.first.first == -2){//success
                return cnt;
            }
            
            FOR(j, 4){
                if(c_status.command == j){ continue; }
                boardStatus bb;
                bb.command = j;
                bb.blue = make_pair(result.second.first, result.second.second);
                bb.red = make_pair(result.first.first, result.first.second);
                q.push(bb);
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    string s;

    pair<int, int> blueLoc = make_pair(0, 0);
    pair<int, int> redLoc = make_pair(0, 0);

    FOR(i, N){
        cin >> s;
        FOR(j, s.size()){
            if(s[j]== 'B') {
                blueLoc.first = i;
                blueLoc.second = j;
                board[i].push_back('.');
            }
            else if(s[j]== 'R') {
                redLoc.first = i;
                redLoc.second = j;
                board[i].push_back('.');
            }
            else{
                board[i].push_back(s[j]);
            }
        }
    }
    cout << BFS(blueLoc, redLoc);
    
    return 0;
}

// 빨간구슬, 파란구슬 하나씩 넣고 빨간 구술 구멍을 통해 빼내는 게임
// 세로 N, 가로 M
// 가장 바깥 행, 열 막혀있고 구멍은 한개
// 파란 구멍이 들어가면 안된다. 동시도 안됨
// 왼쪽 기울이기, 오른쪽 기울이기, 위로 기울이기, 아래쪽으로 기울이기
// 빨간, 파란 구슬 같은 칸 불가능

// 입력
// 세로 가로 = N , M
// N개의 줄에
// '.' = 빈칸 , '#' = 벽 , '0' = 구멍 , 'R' = 빨간구슬, 'B' = 파란구슬
//최소 몇번 만에 구슬을 통해 빼낼 수 있는지 출력
//10번 이하로 불가능하면 -1

//FOR(i, board.size()){
//    FOR(j, board[i].size()){
//        cout << board[i][j] << "";
//    }cout << endl;
//}
