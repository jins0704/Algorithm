//
//  main.cpp
//  없는숫자구하기
//
//  Created by 홍진석 on 2021/09/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    set<int> s;
    
    FOR(i, numbers.size()){
        s.insert(numbers[i]);
    }
    
    FOR(i, 10){
        if(s.find(i) == s.end()){
            answer += i;
        }
    }
    return answer;
}

int main() {
    return 0;
}
