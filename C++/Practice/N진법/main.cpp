//
//  main.cpp
//  N진법
//
//  Created by 홍진석 on 2021/09/07.
//

#include <iostream>
#include <math.h>
using namespace std;

string changeToN(int num, int N){
    string n;
    
    while(num>=1){
        n = to_string(num%N) + n;
        num /= N;
    }
    
    return n;
}

int changeToDecimal(string num, int N){
    int n = 0;
    int last = int(num.size()-1);
    
    for(int i= last; i>=0; i--){
        n += (num[i]- '0') * pow(N, last-i);
    }
    
    return n;
}
int main() {
    
    return 0;
}
