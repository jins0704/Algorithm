//
//  main.cpp
//  큰수만들기
//
//  Created by 홍진석 on 2021/09/08.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = -1;
    int makeLen = int(number.size())-k;
    
    while(answer.size() < number.size()-k){
        int shouldMake = makeLen - int(answer.size());

        pair<char, int> maxValue = make_pair('0', -1);
        
        for(int i=idx+1; i<number.size(); i++){
            if( number.size()-i < shouldMake) { break; }
            
            if(maxValue.second == -1){
                maxValue = make_pair(number[i], i);
            }
            else{
                maxValue = (maxValue.first) < number[i] ? make_pair(number[i], i) : maxValue;
            }
        }
        
        answer.push_back(maxValue.first);
        idx = maxValue.second;
        string rest = number.substr(idx+1, -1);
        
        if(answer.size() + rest.size() == makeLen){
            answer += rest;
            break;
        }
    }
    
    return answer;
}

int main() {
    
    string number = "87654321";
    cout << solution(number, 3);
    
    return 0;
}
