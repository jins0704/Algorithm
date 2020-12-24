//
//  main.cpp
//  2748_DP
//
//  Created by 홍진석 on 2020/08/16.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
long long fibo[91];
void fibonacci(int num){
    fibo[0]=0;
    fibo[1]=1;
    
    for(int i=2; i<=num; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[num] << "\n";
    
    
}
int main() {
    scanf("%d",&n);
    fibonacci(n);
    return 0;
}
