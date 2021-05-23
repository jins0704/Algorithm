//
//  main.cpp
//  1300_BinarySearch
//
//  Created by 홍진석 on 2021/05/23.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, k, ans;
int mid,cnt, newN;
int main() {
    
    cin >> N;
    cin >> k;

    int low = 1;
    int high = k;

    while(low <= high){
        mid = (low+high)/2;
        cnt = 0;
        
        newN = min(N, mid);
        
        for(int i=1; i<=newN; i++){
            cnt += min(mid/i,N);
            
        }
 
        if(cnt < k){
            low = mid+1;
        }
        else{
            high = mid-1;
            ans = mid;
        }
    }
    cout << ans;
    return 0;
}
