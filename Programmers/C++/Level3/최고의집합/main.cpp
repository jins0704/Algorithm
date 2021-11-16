//
//  main.cpp
//  최고의집합
//
//  Created by 홍진석 on 2021/11/15.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    answer.assign(n, s/n);
    if(answer[0] == 0) { return {-1}; }
    for(int i=0; i<s%n; i++){
        answer[answer.size()-1-i] ++;
    }
    return answer;
}

int main() {
    vector<int> sol = solution(4,15);
    return 0;
}
