//
//  main.cpp
//  3020_BinarySearch
//
//  Created by 홍진석 on 2021/05/19.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, H;
int bot[100001];
int top[100001];
long minValue = 200001;
int maxCnt;

int main() {
    
    cin >> N >> H;
    
    for(int i=0; i<N/2; i++){
        cin >> bot[i] >> top[i];
    }
    
    sort(bot, bot + (N/2));
    sort(top, top + (N/2));
   
    for(int i=1; i<=H; i++){
        //long val = lower_bound(bot, bot+(N/2), i) - bot + upper_bound(top, top+(N/2), H-i) - top;
        //val = N-val;

        long btCnt = N/2-(lower_bound(bot, bot+(N/2), i) - bot);
        long topCnt = N/2- (upper_bound(top, top+(N/2), H-i) - top);
        long val = btCnt + topCnt;
        if(minValue == val){
            maxCnt++;
        }
        else if(minValue > val){
            minValue = val;
            maxCnt = 1;
        }

    }
    
    cout << minValue << " " << maxCnt;
    
    return 0;
    
}
