//
//  main.cpp
//  멀쩡한사각형
//
//  Created by 홍진석 on 2021/08/02.
//

#include <iostream>

using namespace std;
bool checkLast = false;
long lastValue = 0;
long gcd(long a, long b) { return (a % b == 0 ? b : gcd(b, a % b)); }

long long sol2(long long startW, long long startH, long long endW, long long endH){
    if((startW+endW)%2 == 0 && (startH+endH)%2 == 0){
        long long midW = (startW+endW+1)/2;
        long long midH = (startH+endH+1)/2;
        return sol2(startW,startH,midW,midH) + sol2(midW, midH, endW, endH) + 2*(endW-midW)*(endH-midH);
    }
    else{
        if(!checkLast){
            long w = endW-startW;
            long h = endH-startH;
            checkLast = true;
            lastValue = (w*h) - (w+h - gcd(w, h));
        }
        return lastValue;
    }
}
long long solution(int w,int h) {
    long long answer = 1;
    
    answer = sol2(0,0,w,h);
 
    return answer;
}

int main() {
    return 0;
}
