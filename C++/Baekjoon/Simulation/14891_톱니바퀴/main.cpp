//
//  main.cpp
//  14891_톱니바퀴
//
//  Created by 홍진석 on 2021/10/01.
//

#include <iostream>
#include <vector>
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

vector<vector<int>> gears(5);
int s,n,d,K;
int top[5] = {0,0,0,0,0};

void rotateGear(int n, int direction){
    if(direction == 1){
        top[n] = top[n] == 0 ? 7 : top[n]-1;
    }
    else if(direction == -1){
        top[n] = top[n] == 7 ? 0 : top[n]+1;
    }
}
int main() {
    for(int i=1; i<=4; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &s);
            gears[i].push_back(s);
        }
    }
    
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &n, &d);
        
        bool leftFinish = false;
        bool rightFinish = false;
        
        vector<pair<int, int>> v;
        v.push_back(make_pair(n, d));
        //1 2 3 4
        int leftD = d;
        int rightD = d;
        for(int i=1; i<4; i++){
            if(leftFinish && rightFinish) { break; }

            if(!leftFinish && n-i >=1){
                int curRight = top[n-i]+2 < 8 ? top[n-i]+2 : top[n-i]-6;
                int leftIdx = top[n-i+1]+6 < 8 ? top[n-i+1]+6 : top[n-i+1]-2;
                if(gears[n-i][curRight] == gears[n-i+1][leftIdx]){
                    leftFinish = true;
                }
                else{
                    v.push_back(make_pair(n-i, -1*leftD));
                    leftD*=-1;
                }
            }
            if(!rightFinish && n+i <= 4){
                int curLeft = top[n+i]+6 < 8 ? top[n+i]+6 : top[n+i]-2;
                int rightIdx =  top[n+i-1]+2 < 8 ? top[n+i-1]+2 : top[n+i-1]-6;

                if(gears[n+i][curLeft] == gears[n+i-1][rightIdx]){
                    rightFinish = true;
                }
                else{
                    v.push_back(make_pair(n+i, -1*rightD));
                    rightD*=-1;
                }
            }
        }
        
        for(int i=0; i<v.size(); i++){
            rotateGear(v[i].first,v[i].second);
        }
    }
    int sum = gears[1][top[1]] + gears[2][top[2]] * 2 +  gears[3][top[3]] * 4 + gears[4][top[4]] * 8;
    
    printf("%d",sum);
    
    return 0;
}
