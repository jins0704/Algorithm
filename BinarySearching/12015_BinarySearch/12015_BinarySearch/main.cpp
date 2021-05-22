//
//  main.cpp
//  12015_BinarySearch
//
//  Created by 홍진석 on 2021/05/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,n;

vector<int> v;

int main() {
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> n;
        
        if(v.empty()){
            v.push_back(n);
        }
        
        else{
            if(n > v.back()){
                v.push_back(n);
                //cout << n << " 넣기" << endl;
            }
            else{
                long idx = lower_bound(v.begin(), v.end(), n) - v.begin();
                v[idx] = n;
                
            }
        }
    }
    
    cout << v.size() << endl;
    return 0;
}

//int N;
//int arr[1000001];
//int dp[1000001];
//vector<int> vt;
//
//int main() {
    
    //    cin >> N;
    //
    //    for(int i=0; i<N; i++){
    //        cin >> arr[i];
    //    }
    //
    //    int res = 1;
    //
    //    for(int i=0; i<N; i++){
    //
    //        dp[i] = 1;
    //
    //        for(int j=0; j<i; j++){
    //            if(arr[j] < arr[i]){
    //                dp[i] = max(dp[i],dp[j]+1);
    //            }
    //        }
    //        res = max(res,dp[i]);;
    //    }
    //    cout <<res << endl;
    //
//    return 0;
//}
