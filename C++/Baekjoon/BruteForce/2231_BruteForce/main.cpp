//
//  main.cpp
//  2231_BruteForce
//

#include <iostream>
using namespace std;

int main() {
    int g,ans=0;
     int sum =0;
    cin >> g;
    for(int i=0; i<g; i++){
        int n[6] = {0};
        n[0] = (i%1000000-i%100000)/100000;
        n[1] = (i%100000-i%10000)/10000;
        n[2] = (i%10000-i%1000)/1000;
        n[3] = (i%1000-i%100)/100;
        n[4] = (i%100-i%10)/10;
        n[5] = (i%10-i%1)/1;
        sum = n[0]+n[1]+n[2]+n[3]+n[4]+n[5]+i;
        if(sum==g){
            ans =i;
            break;
        }
    }
    if(ans ==0) cout << 0;
    else cout << ans;
    return 0;
}
