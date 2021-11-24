//
//  main.cpp
//  110옮기기
//
//  Created by 홍진석 on 2021/09/16.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    string first; string second;
    
    FOR(i, s.size()){
        string zzo = "";
        int oneCnt = 0;
        
        FOR(j, s[i].size()){
            if(s[i][j] == '1') {oneCnt ++;}
            else{
                if(oneCnt >= 2){
                    j -= 3;
                    oneCnt -= 2;
                    s[i].erase(j+1,3);
                    zzo += "110";
                }
                else {oneCnt = 0; }
            }
        }
        int loc = -1;
        
        FOR(j, s[i].size()){
            if(s[i][j] == '1') {
                if(j == s[i].size()-1){ loc = j; }
                else{
                    if(s[i][j+1] == '1'){
                        loc = j;
                        break;
                    }
                }
            }
        }

        if(loc < 0){ s[i] += zzo; }
        else{
            first = s[i].substr(0,loc);
            second = s[i].substr(loc,-1);
            s[i] = first + zzo + second;
        }
      
        answer.push_back(s[i]);
    }
    return answer;
}

int main() {
    vector<string> s = {"100111100"};
    solution(s);
    return 0;
}


//0,1 문자열 x
//최대한 사전 순으로 앞에 오도록
//"110" 뽑아서 임의의 위치에 삽입
