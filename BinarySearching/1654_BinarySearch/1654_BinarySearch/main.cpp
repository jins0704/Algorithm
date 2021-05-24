//
//  main.cpp
//  1654_BinarySearch
//
//  Created by 홍진석 on 2021/05/24.
//

#include <iostream>

using namespace std;

//N개의 랜선
//K개의 랜선 - 길이는 제각각

long long K, N;
long long arr[10000];
long long maxValue;
long long ans;

int main() {

    cin >> K >> N;
    
    for(int i=0; i<K; i++){
        cin >> arr[i];
        if(maxValue < arr[i]){
            maxValue = arr[i];
        }
    }
     
    long long low =1; //자를 수 있는 최솟 길이
    long long high = maxValue; //자를 수 있는 최대 길이
    long long mid = 0;
   
    while(low <= high){
        long long cnt =0;
        mid = (low+high)/2;
        
        for(int i=0; i<K; i++){
            cnt += arr[i]/mid;
        }
    
        if(cnt < N){
            high = mid-1;
            //cout << "더 잘게 자르자 " << endl;
        }
        else{
            ans = mid;
            low = mid+1;
            //cout << "더 길게 자르자 " << endl;
        }
    }
    
    cout << ans;
    return 0;
}
