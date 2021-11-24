//
//  main.cpp
//  124나라의숫자
//
//  Created by 홍진석 on 2021/06/30.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int code[3] = {4,1,2};
    
    while(n != 0){
        int rest = n%3;
        
        if(rest == 0){
            answer += to_string(4);
            n= n-1;
        }
        else{
            answer += to_string(code[rest]);
        }
        
        n = n/3;
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
