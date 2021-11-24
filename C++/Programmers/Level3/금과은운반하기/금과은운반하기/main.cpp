//
//  main.cpp
//  금과은운반하기
//
//  Created by 홍진석 on 2021/09/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 10e14 * 4;
    long long low = 0;
    long long high = 10e14 * 4;

    while(low <= high){
        long long mid = (low + high) / 2;
        long long total_gold = 0;
        long long total_silver = 0;
        long long total_add = 0;
        
        FOR(i, g.size()){
            long long move_cnt = mid / (t[i] * 2);// 전달 횟수
            if (mid % (t[i] * 2) >= t[i]) move_cnt++; //편도 고려
            
            total_gold += (g[i] < move_cnt * w[i]) ? g[i] : move_cnt * w[i]; //최대 옮길 금 고려
            total_silver += (s[i] < move_cnt * w[i]) ? s[i] : move_cnt * w[i]; // 최대 옮길 은 고려
            total_add += (g[i] + s[i] < move_cnt * w[i]) ? g[i] + s[i] : move_cnt * w[i]; // 최대 옮길 광물 고려
        }
        
        if(total_gold >= a && total_silver >=b && total_add >= a+b){
            high = mid -1;
            answer = min(mid, answer);
        }
        else{
            low = mid + 1;
        }
    }
    
    return answer;
}

int main() {
    vector<int> g = {70,70,10};
    vector<int> s = {2,20,500};
    vector<int> w = {100,100,30};
    vector<int> t = {4,8,1};

    
    cout << solution(90, 500, g, s, w, t);
    
    return 0;
}
// w[i] * (1 + (mid / t[i])) / 2
