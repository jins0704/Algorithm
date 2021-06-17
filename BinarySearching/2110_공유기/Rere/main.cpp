#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int arr[200001];

int main() {
    
    cin >> N >> C;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    int low = 1; //최소거리
    int high = arr[N-1] - arr[0]; //최대거리
    int ans =0;
    while(low <= high){
        int cnt = 1;
        
        int mid = (low+high)/2;
        int loc = arr[0];
        
        for(int i=0; i< N; i++){
            int d = arr[i] - loc;
            cout << endl;
            //cout << "mid : " << mid << endl;
            //cout << "i : " << i << " , arr[i] : " << arr[i] << " d : " << d << endl;
            if(mid <= d){
                cnt ++;
                loc = arr[i];
            }
            //cout << "cnt : " << cnt << endl;
        }
        if(cnt >= C){
            ans = mid;
            low = mid+1;
            //cout <<"if" << endl;
        }
        else{
            high = mid -1;
            //cout <<"else" << endl;
        }
    }
    
    cout << ans;
    return 0;
}
