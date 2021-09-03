//
//  main.cpp
//  소수찾기
//
//  Created by 홍진석 on 2021/09/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string num;
set<int> num_candi;

void makeNum(int cnt, int len, string &numbers, vector<bool> &check){
    if(cnt == len){ num_candi.insert(stoi(num)); }
    else{
        for(int i=0; i< numbers.size(); i++){
            if(!check[i]){
                num.push_back(numbers[i]);
                check[i] = true;
                makeNum(cnt+1, len, numbers, check);
                check[i] = false;
                num.pop_back();
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> check;
    
    for(int i=1; i<=numbers.size(); i++){
        check.assign(numbers.size(), 0);
        makeNum(0, i, numbers, check);
        num.clear();
    }
    
    for(auto n : num_candi){
        if(n <= 1) { continue; }
        
        else if (n == 2) {
            answer ++;
        }
        
        else{
            for(int i=2; i<n; i++){
                if(n%i == 0){ break; }
                if(i == n-1){ answer ++; }
            }
        }
    }
    return answer;
}

int main() {
    solution("17");
    return 0;
}

//한자리 숫자가 적힌 조각
//조각 붙여소수 몇개 만들수있을까
//문자열 numbers
//소수 몇개인지 return
