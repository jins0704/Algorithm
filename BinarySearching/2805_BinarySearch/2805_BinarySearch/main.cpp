//
//  main.cpp
//  2805_BinarySearch
//
//  Created by 홍진석 on 2021/05/17.
//

#include <iostream>

// 나무 M 미터
// 절단기에 높이 H를 지정 -> 톱날이 땅으로 부터 H 미터 위로
// 한 줄에 연속해 있는 나무를 모두 절단해버린다.
// H보다 큰 나무는 H위의 부분이 잘리며, 낮은 나무는 잘리지 않는다.
// 적어도 M 미터의 나무를 집에 가져가기 위해 설정할 수 있는 높이의 최댓값

using namespace std;

long long N,M;
long long woods[10000001];
long long longest;
long long sol;
void start(long long s, long long l){
    long long copyM = M;
    long long mid =0;

    mid = (s+l)/2;
    if(s >= l){return;}
    //cout << s << " " << mid << " " << l << endl;

    
    for(int i=0; i<N; i++){
        if(mid < woods[i]){
            //cout << woods[i] - mid << endl;
            copyM -= woods[i]-mid;
            
            if(copyM < 0){break;}
        }
    }
    
    if(copyM <= 0){
        //cout << mid << " 에서 자르기 가능 "<< endl;
        if(sol < mid){
            sol = mid;
        }
        start(mid+1, l);
    }
    else{
        start(s,mid);
    }
    
}

int main() {
    
    cin >> N >> M; //나무의 수, 필요한 나무 길이
    
    for(int i=0; i<N; i++){
        cin >> woods[i];
        if(woods[i] > longest){
            longest = woods[i];
        }
    }
    
    start(0,longest);
    
    cout << sol;
    return 0;
}
