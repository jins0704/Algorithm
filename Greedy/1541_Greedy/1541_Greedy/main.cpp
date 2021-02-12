//
//  main.cpp
//  1541_Greedy
//
//  Created by 홍진석 on 2021/02/11.
//

#include <iostream>
#include <string.h>

using namespace std;
string num;
string str1;
bool minusCheck;
int total;

int main() {
    
    cin >> str1;
    
    for(int i=0; i<str1.size(); i++){
        
        if(str1[i] == '+' || str1[i] == '-'){
           
            //숫자 파싱
            int n = stoi(num);
            num.clear();

            if(minusCheck == true){
                total = total - n;
            }
            else{
                total += n;
            }
            
            //앞으로는 쭉 마이너스
            if(str1[i] == '-'){
                minusCheck = true;
            }
            
        }
        else{
            num.push_back(str1[i]);
            
            //마지막 숫자 추가
            if(i == str1.size()-1){
                //숫자 파싱
                int n = stoi(num);
                
                if(minusCheck == true){
                    total -= n;
                }
                else{
                    total += n;
                }
            }
        }
    }
    
    cout << total;
    
    return 0;
}

//양수, +, -, 괄호
//괄호를 적절히 쳐서 값을 최소로 만든다.
