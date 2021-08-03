//
//  main.cpp
//  2020_KAKAO_Intership_2
//
//  Created by 홍진석 on 2021/04/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> arr;
vector<long long> copyNum;
vector<char> copyOper;

long long calculation(long long a, long long b, char c){
    if(c == '+'){
        return a + b;
    }
    else if(c == '-'){
        return a - b;
    }
    else{
        return a * b;
    }
}
long long solution(string expression) {
    
    vector<char> arr;
    vector<char> oper;
    vector<long long> numbers;
    
    numbers.push_back(stoi(expression));
    
    for(int i=0; i<expression.size(); i++){
        if(expression.at(i) == '-' || expression.at(i) == '+' || expression.at(i) == '*'){
            oper.push_back(expression.at(i));
            string b = expression.substr(i+1,expression.size());
            numbers.push_back(stoi(b));
        }
    }
    
    long long answer = 0;
    string a = " ";
    
    arr.push_back('*');
    arr.push_back('+');
    arr.push_back('-');
   
    do{
        copyNum.clear();
        copyNum.assign(numbers.begin(),numbers.end() ); // 전체 복사
        
        copyOper.clear();
        copyOper.assign(oper.begin(), oper.end() ); // 전체 복사
        
        for(int i=0; i<arr.size(); i++){
           
            int n = 0;
            
            while(1){
                
                if(n == copyOper.size()){
                    break;
                }
                if(copyOper.at(n) == arr.at(i)){
                    long long result = calculation(copyNum.at(n), copyNum.at(n+1), copyOper.at(n));
                    
                    copyNum.erase(copyNum.begin()+n);
                    copyNum.erase(copyNum.begin()+n);
                    copyNum.insert(copyNum.begin()+n, result);
                    
                    copyOper.erase(copyOper.begin()+n);
                }
                else{
                    n++;
                }
            }
        }
        if(abs(copyNum.at(0)) > answer){answer = abs(copyNum.at(0));}
   
    }while(next_permutation(arr.begin(), arr.end()));
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    cout << solution("100-200*300-500+20");
    
    return 0;
}
