//
//  main.cpp
//  2개이하로다른비트
//
//  Created by 홍진석 on 2021/09/15.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

string makeBit(long long num){
    string s;
 
    while(num >= 1){
        s = to_string(num%2) + s;
        num /= 2;
    }

    return s;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    FOR(i, numbers.size()){
        string s = makeBit(numbers[i]);

        for(int i=int(s.size()); i>=0; i--){
            if(s[i] == '0'){
                s[i] = '1';
                for(int j = i+1; j<=(int)s.size(); j++) {
                    if(s[j] == '1') {
                        s[j] = '0';
                        break;
                    }
                }
                break;
            }
            if(i == 0){
                s[i] = '0';
                s = '1' + s;
            }
        }
        long long num = 0;
        for(int i=(int)s.size()-1; i>=0; i--){
            num += (s[i]-'0') * pow(2,(int)s.size()-i-1);
        }
        answer.push_back(num);
    }
    
    return answer;
}

int main() {
    vector<long long> numbers = {7};
    solution(numbers);
    return 0;
}

// 양의 정수 x
// f(x) = x보다 크고 x와 비트가 1~2개 다른 수들 중 제일 작은수

//[1001,337,0,1,333,673,343,221,898,997,121,1015,665,779,891,421,222,256,512,128,100]
//[1002, 338, 1, 2, 334, 674, 347, 222, 899, 998, 122, 1019, 666, 781, 893, 422, 223, 257, 513, 129, 101]
