//
//  main.cpp
//  18258_Queue
//
//  Created by 홍진석 on 2021/01/29.
//

#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int N, X;
char method[10];

int main() {
    
    scanf("%d", &N);
    
    while(N--){
        scanf("%s", method);
        
        if(method[0] == 'p'){
            if(method[1] == 'u'){
                scanf("%d",&X);
                q.push(X);
            }else{
                if(q.empty()){
                    printf("-1\n");
                }
                else{
                    printf("%d\n",q.front());
                    q.pop();
                }
            }
        }
        else if(method[0] == 's'){
            printf("%lu\n",q.size());
        }
        else if(method[0] == 'e'){
            if(q.empty()){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else if(method[0] == 'f'){
            if(q.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n",q.front());
            }
        }
        else{
            if(q.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n",q.back());
            }
        }
        
    }
    return 0;
}
