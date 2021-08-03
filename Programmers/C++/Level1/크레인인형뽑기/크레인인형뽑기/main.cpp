//
//  main.cpp
//  크레인인형뽑기
//
//  Created by 홍진석 on 2021/05/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int i=0; i<moves.size(); i++){//크레인 작동 순서
        
        int loc = moves[i]-1; //작동시킬 위치
        int doll = 101;
        
        for(int j=0; j< board.size(); j++){//깊이 내려가기
            if(board[j][loc] != 0){//제일 상위 인형꺼내기
                doll = board[j][loc];
                board[j][loc] = 0;
                break;}
        }
        
        if(doll != 101){//꺼내졌으면
            if(!s.empty()){
                if(s.top() == doll){
                    s.pop();
                    answer += 2;}
                else{s.push(doll);}
            }
            else{s.push(doll);}
        }
    }
    
    return answer;
}
int main() {
    return 0;
}
