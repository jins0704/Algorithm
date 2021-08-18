//
//  main.cpp
//  퍼즐조각채우기
//
//  Created by 홍진석 on 2021/08/17.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

struct puzzleInfo{
    int minX = 0;
    int minY = 0;
    int cnt = 0;
    vector<pair<int, int>> v;
};

puzzleInfo findPuzzle(int i, int j, vector<vector<int>> &table, int findValue, int (*check)[51]){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int cnt = 1;
    int minX = 51, minY = 51;
    
    q.push(make_pair(i, j));
    v.push_back(make_pair(i, j));
    
    while(!q.empty()){
        int cx = q.front().first; int cy = q.front().second;
        q.pop();
        
        minX = min(cx, minX);
        minY = min(cy, minY);
        
        check[cx][cy] = 1;
        
        FOR(i, 4) {
            int nx = cx + dx[i]; int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= table.size() || ny >= table.size()){ continue; }
            if(table[nx][ny] == findValue && check[nx][ny] == 0) {
                cnt ++;
                check[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                v.push_back(make_pair(nx, ny));
                
            }
        }
    }

    FOR(i,v.size()) {
        v[i].first -= minX;
        v[i].second -= minY;
    }
    
    puzzleInfo info{minX, minY, cnt, v};
    
    return info;
    
}

void rotateBoard(vector<vector<int>> &game_board){//90도 회전
    vector<vector<int>> rotateV;
    int gsize = int(game_board.size());

    for(int i=0; i<gsize; i++){
        vector<int> v;
        for(int j= gsize-1; j>=0; j--){ v.push_back(game_board[j][i]); }
        rotateV.push_back(v);
    }
    
    game_board = rotateV;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<vector<pair<int, int>>> tablePuzzles[2500];
    int checkTable[51][51] = {0,};
    int answer =0;
    
    FOR(i, table.size()) {
        FOR(j, table.size()) {
            if(table[i][j] == 1 && !checkTable[i][j]) { // bfs 퍼즐 모양 찾기
                puzzleInfo tablePuzzle = findPuzzle(i,j,table,1,checkTable);
                tablePuzzles[tablePuzzle.cnt].push_back(tablePuzzle.v);
            }
        }
    }
    
    FOR(h, 4){//게임판 90도 씩 돌려보면서 내가 가지고 있는 퍼즐과 맞춰보기
        int checkBoard[51][51] = {0,};
        
        FOR(i, game_board.size()) {
            FOR(j, game_board.size()) {
                if(game_board[i][j] == 0 && !checkBoard[i][j]) {
                    puzzleInfo boardPuzzle = findPuzzle(i,j,game_board,0,checkBoard); //1. bfs로 빈곳 모양 찾기
                    
                    FOR(k, tablePuzzles[boardPuzzle.cnt].size()){
                        if(boardPuzzle.v == tablePuzzles[boardPuzzle.cnt][k]){// 2.내가 가지고 있는 퍼즐과 맞다면
                            FOR(l, boardPuzzle.v.size()){ //3. 안겹치게 퍼즐 지우고 칸 채우기
                                game_board[boardPuzzle.v[l].first + boardPuzzle.minX][boardPuzzle.v[l].second + boardPuzzle.minY] = 1;
                            }
                            answer += boardPuzzle.cnt;
                            
                            tablePuzzles[boardPuzzle.cnt].erase(tablePuzzles[boardPuzzle.cnt].begin() + k);
                            break;
                        }
                    }
                }
            }
        }
        rotateBoard(game_board);
    }

    return answer;
}









int main() {
    vector<vector<int>> game_board =
    {{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
    
    
    //{{1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0}};
    vector<vector<int>> table =
    {{1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1}};
    
    //{{1,0,0,1,1,0},{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0},{0,1,0,0,0,0}};
    solution(game_board, table);
  
    return 0;
}
