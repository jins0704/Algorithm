//
//  main.cpp
//  최소공배수,최대공약수
//
//  Created by 홍진석 on 2021/09/07.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int lcm(int a, int b){
    return (a*b) / gcd(a, b);
}

int main() {
    
    cout << gcd(15, 10) << endl;
    cout << lcm(5, 3);
    return 0;
}
