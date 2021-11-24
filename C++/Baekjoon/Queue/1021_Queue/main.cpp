//
//  main.cpp
//  1021_Queue
//
//  Created by 홍진석 on 2021/01/28.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int tmp;
int N,M;
int target, loc, sum;

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        dq.push_back(i+1);
    }
    
    while(M--){
        cin >> target;
    
        //t 위치찾기
        for(int i=0; i<dq.size(); i++){
            if(dq[i] == target){
                loc = i;
                break;
            }
        }
        
        if(loc < dq.size()+1 - loc){
            //1번실행
            while(1){
                if(dq.front() == target){
                    dq.pop_front();
                    break;
                }
                //2번실행
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                
                sum++;
            }
        }
        
        else{
            //1번실행
            while(1){
                if(dq.front() == target){
                    
                    dq.pop_front();
                    break;
                }
                //3번실행
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}


