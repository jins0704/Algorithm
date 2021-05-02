//
//  main.cpp
//  20055_Simulation
//
//  Created by 홍진석 on 2021/05/02.
//

#include <iostream>
#include <queue>

using namespace std;

struct box{
    int maxLimit = 0;
    bool robot = false;
};

box arr[300];
int N,K,l;

int main() {
    
    int limitcnt = 0;
    int step = 0; //몇번째 단계
    cin >> N >> K; //N: 길이 , K: 내구도 0인 칸 제한
    
    int upLoc = 1;
    int downLoc = N;
    
    for(int i=1; i<=2*N; i++){
        cin >> l;
        arr[i].maxLimit = l;
    }
    
    while(limitcnt < K){
        
        step ++;
        
        //1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다. 내리는 위치에 있는 로봇은 내린다.
        
        upLoc = upLoc - 1;
        downLoc = downLoc - 1;
        if(upLoc <= 0){
            upLoc = 2*N;
        }
        if(downLoc <= 0){
            downLoc = 2*N;
        }
        arr[downLoc].robot = false;
        
        
        //2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        
        for(int i=0; i<N-1; i++){
            int moveLoc = downLoc-1 -i;
            
            if(moveLoc <=0){
                moveLoc = moveLoc+2*N;
            }
            
            int nextLoc = moveLoc +1;
            
            if(nextLoc > 2*N){
                nextLoc = nextLoc-2*N;
            }
        
            
            if(arr[nextLoc].maxLimit > 0 && arr[moveLoc].robot && !arr[nextLoc].robot){
                arr[moveLoc].robot = false;
                arr[nextLoc].robot = true;
                arr[nextLoc].maxLimit += -1;
                if(arr[nextLoc].maxLimit == 0){
                    limitcnt += 1;
                }
            }
        }
        
        arr[downLoc].robot = false;
        
        //3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if(arr[upLoc].maxLimit >0){
            arr[upLoc].robot= true;
            arr[upLoc].maxLimit += -1;
            if(arr[upLoc].maxLimit == 0){
                limitcnt += 1;
            }
        }
        
    }
    
    //4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
    cout << step << endl;
    return 0;
}
