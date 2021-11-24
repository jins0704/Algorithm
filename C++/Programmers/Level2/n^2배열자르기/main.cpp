//
//  main.cpp
//  n^2배열자르기
//
//  Created by 홍진석 on 2021/11/19.
//

#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right-left+1, 0);
    
    long long x = left/n;
    long long y = left%n;
    int cnt = 0;
    
    while (cnt < right-left+1) {
        answer[cnt] = int(max(x,y) + 1);
        y += 1;
        if(y == n){x+=1; y=0;}
        cnt++;
    }
    return answer;
}

int main() {
    vector<int> v= solution(3, 2, 5);
    
    FOR(i, v.size()) {
        cout << v[i] << " ";
    }
    return 0;
}
