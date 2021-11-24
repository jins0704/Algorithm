//
//  main.cpp
//  조이스틱
//
//  Created by 홍진석 on 2021/08/06.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

int moveCnt(char c){ return min(c-'A', 'Z'-c +1); }

pair<int, int> moveIdx(int idx, string &name, bool check[]){
    int upIdx = idx;
    int downIdx = idx;
    int move = 0;
    
    while(move <= 21){
        move++;
        upIdx = upIdx == name.size()-1 ? 0 : upIdx+1;
        downIdx = downIdx == 0 ? int(name.size()-1) : downIdx-1;
        
        if(!check[upIdx]){
            return make_pair(move, upIdx);
        }
           
        if(!check[downIdx]){
            return make_pair(move, downIdx);
        }
    }
    return make_pair(0, 0);
}

int solution(string name) {
    int checkCnt = 0;
    bool check[21];
    FOR(i, name.size()){
        if(name[i] == 'A'){
            checkCnt++;
            check[i] = true;
        }
        else{ check[i] = false; }
    }
    
    int idx = 0;
    int answer = 0;
 
    while(checkCnt < name.size()){
        
        answer += moveCnt(name[idx]); //알파벳 조작
        check[idx] = true;
        if(answer != 0) {checkCnt ++; }
        if(checkCnt == name.size()){ break; }
        
        pair<int, int> info = moveIdx(idx, name, check);
        
        answer += info.first;
        idx = info.second;
    }

    return answer;
}

int main() {

    cout << solution("JAJAAAJ");
    return 0;
}
