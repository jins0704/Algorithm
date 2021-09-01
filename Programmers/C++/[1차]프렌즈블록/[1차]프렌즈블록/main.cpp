//
//  main.cpp
//  [1차]프렌즈블록
//
//  Created by 홍진석 on 2021/08/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

bool findBlock(int i, int j, vector<string> &board, set<pair<int, int>> &s){
    char c = board[i][j];
    
    if(board[i+1][j] == c && board[i][j+1] == c && board[i+1][j+1] == c){
        s.insert(make_pair(i, j));
        s.insert(make_pair(i+1, j));
        s.insert(make_pair(i, j+1));
        s.insert(make_pair(i+1, j+1));
        return true;
    }
    else{ return false; }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int exist = 0;
    set<pair<int,int>> s;
    do{
        exist = 0;
        for(int i=0; i<m-1; i++){
            for (int j=0; j<n-1; j++) {
                if(board[i][j] != '.'){
                    if(findBlock(i,j,board,s)){ exist++; }
                }
            }
        }
        
        for(auto item : s){ board[item.first][item.second] = '.'; }
    
        if(exist > 0){
            //블럭 내리기
            for (int i=0; i<n; i++) {
                queue<int> q;
                for(int j=m-1; j>=0; j--){
                    if(board[j][i] == '.'){
                        q.push(j);
                    }
                    else{
                        if(!q.empty()){
                            board[q.front()][i] = board[j][i];
                            q.pop();
                            board[j][i] = '.';
                            q.push(j);
                        }
                    }
                }
            }
            answer += s.size();
            s.clear();
        }
    }while(exist > 0);
    
    return answer;
}

int main() {
    vector<string> board = {"AAAAA","AUUUA","AUUAA","AAAAA"};
    cout << solution(4, 5, board);
    return 0;
}
//2x2 4개 같으면 사라지면서 점수 획득
//1. 2x2 성립하는 여러개, 성립 가능
//2. 블록이 모두 지워지면 아래로 떨어져 빈 공간 채운다
//지워지는 블록은 모두 몇개인지 판단
