//
//  main.cpp
//  10845_Queue
//
//  Created by 홍진석 on 2021/02/02.
//

#include <iostream>
#include <queue>

using namespace std;

deque<int> q;
char method[10];
int main() {

    int N,n;
    
    scanf("%d",&N);
    
    while(N--){
        scanf("%s",method);
        
        if(method[0] == 'p'){
            if(method[1] == 'u'){
                scanf("%d\n",&n);
                q.push_back(n);
                
            }
            else{
                if(!q.empty()){
                    printf("%d\n",q.front());
                    q.pop_front();
                }else{
                    printf("-1\n");
                }
            }
        }
        
        else if(method[0] == 's'){
            printf("%lu\n",q.size());
        }
        else if(method[0]== 'e'){
            if(!q.empty()){
                printf("0\n");
            }else{
                printf("1\n");
            }
        }
        else if(method[0]== 'f'){
            if(!q.empty()){
                printf("%d\n",q.front());
            }
            else{
                printf("-1\n");
            }
        }
        else{
            if(!q.empty()){
                printf("%d\n",q.back());
            }
            else{
                printf("-1\n");
            }
        }
        
    }
    return 0;
}
