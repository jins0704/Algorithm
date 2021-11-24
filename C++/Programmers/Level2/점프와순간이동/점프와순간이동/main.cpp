//
//  main.cpp
//  점프와순간이동
//
//  Created by 홍진석 on 2021/08/31.
//

#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;

    while(n > 1){
        if(n%2 == 1){
            n -= 1;
            ans ++;
        }
        n /= 2;
    }
    return ans;
}

int main() {
    cout << solution(5);
    return 0;
}

//순간이동 건전지 안씀 -> 현재까지 온 거리 x2
//k칸 점프 -> K만큼 건전지 사용
//N만큼 떨어진 장소 이동
//점프를 최소
//건전지 사용량의 최솟값 구하기
