//
//  main.cpp
//  입국심사
//
//  Created by 홍진석 on 2021/08/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long answer = 1;
    long long low = 1; //최소시간
    long long high = times.back() * (long long)n; //최대시간
    
    while(low <= high){
        long long mid =(low + high) / 2;
        long long num = 0;
        FOR(i, times.size()){
            num += mid / times[i];
        }
        if(num >= n){
            high = mid-1;
            answer = mid;
        }
        else{ low = mid+1; }
    }
    
    return answer;
}

int main() {
    vector<int> v;
    v.push_back(1);
    
    cout << solution(1, v);
    return 0;
}
