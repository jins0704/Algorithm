//
//  main.cpp
//  KAKAO_2022Blind_2
//
//  Created by 홍진석 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

string changeToN(int n, int k){
    string result = "";
    while(n >= 1){
        result = to_string(n%k) + result;
        n /= k;
    }
    return result;
}

vector<long> split(string input, char delimiter){
    vector<long> answer;
    stringstream ss(input);
    string temp;
    temp.clear();
    
    while(getline(ss,temp,delimiter)){
        if(temp.size() > 0 || !temp.empty()){
            answer.push_back(stol(temp));
        }
        temp.clear();
    }
    return answer;
}
bool isPrime(long n) {
    if(n<=1) {
        return false;
    }

    for(int i=2; i<=sqrt(n); i++) {
        if((n%i)==0) {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string changeN = changeToN(n,k);
    vector<long> P = split(changeN, '0');
    
    
    for(int i=0; i<P.size(); i++){
        if(isPrime(P[i])){ answer ++; }
    }
    
    return answer;
}

int main() {
    solution(45, 3);
    return 0;
}

//양의 정수 n
//k진수로 바꿀때 변환된 수 안에 아래 조건에 맞는 소수가 몇개인지 알아본다
    //0P0 : 소수 양쪽에 0이 있는 경우
    //P0 : 소수 왼쪽 아무것도 없고 오른쪽 0인 경우
    //0P : 소수 왼쪽에 0, 오른쪽 아무것도 없는 경우
    //P : 양쪽에 아무것도 없는 경우
    //각 자릿수에 0을 포함하지 않는 소수 -> '101' 안된다

