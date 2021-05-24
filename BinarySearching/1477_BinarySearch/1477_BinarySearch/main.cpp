//
//  main.cpp
//  1477_BinarySearch
//
//  Created by 홍진석 on 2021/05/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 현재 고속도로에 휴개소 N개
// 휴게소의 위치는 고속도로의 시작으로 부터 얼마나 떨어져있는지.
// 휴게소 M개를 더 세우려고 한다.
// 모든 휴게소를 방문한다.
// 휴게소 M개를 더 지어서 휴게소가 없는 구간의 길이의 최댓값을 최소로 한다.
// 휴게소의 위치는 중복되지 않는다.

int N, M, L, n;
int ans;

vector<int> v;
int main() {
    cin >> N >> M >> L; //현재 개수, 더 지을 개수, 고속도로 길이
    for(int i=0; i<N; i++){
        cin >> n;
        v.push_back(n);
    }
    
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end());
    
    int low = 1;
    int high = v.back()-1;
    
    while(low <= high){
        int cnt = 0;
        int mid = (low+high)/2;
        
        //cout << low << " " << high << endl;
        //cout << "mid : " << mid << endl;
        
        for(int i=1; i<v.size(); i++){

            int ccnt = (v[i]-v[i-1])/mid;
            
            if((v[i]-v[i-1])%mid == 0){ccnt -= 1;}
            
            cnt += ccnt;
        }
        //cout << "cnt : " << cnt << endl;
        if(cnt <= M){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    
    cout << low;
    return 0;
}
