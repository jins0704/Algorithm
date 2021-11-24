//
//  main.cpp
//  1759_Backtracking
//
//  Created by 홍진석 on 2021/02/04.
//

#include <iostream>
#include <algorithm>

using namespace std;

// 서로 다른 L개의 알파벳 소문자
// 최소 한 개의 모음 (a,e,i,o,u) 최소 두 개의 자음
// 증가순으로 배열
// 문자의 종류 C
int L, C;
char poss[16];
char posscode[16];
int separ[16];
int check[16];

int mo;
int za;

void makeCode(int cnt){
    if(cnt == L){
        //암호가 만들어졌을때 최소 한개의 모음과 2개의 자음이어야지만 가능한 암호로 출력
        if(mo >=1 && za >=2){
            for(int w = 0; w < cnt; w++){
                printf("%c", posscode[w]);
            }
            printf("\n");
        }
    }
    
    else{
        for(int i=0; i<C; i++){
            if(check[i] == false){
                //증가순이 아니면 넘어가기
                if(cnt >=1){
                    if(int(posscode[cnt-1]) > int(poss[i])){
                        continue;
                    }
                }
                check[i] = true;
                if(poss[i] == 'a' || poss[i] == 'e' || poss[i] == 'i' || poss[i] == 'o' || poss[i] == 'u'){
                    mo++;
                }
                else{
                    za++;
                }
                posscode[cnt] = poss[i];
                makeCode(cnt+1);
                check[i] = false;
               
                if(poss[i] == 'a' || poss[i] == 'e' || poss[i] == 'i' || poss[i] == 'o' || poss[i] == 'u'){
                    mo--;
                }
                else{
                    za--;
                }
            }
        }
    }
}

int main() {
    
    scanf("%d %d", &L, &C);
    
    //가능성 문자 배열
    for(int i=0; i<C; i++){
        cin >> poss[i];
        //separ 배열로 모음은 1, 자음은 0으로 구분
        if(poss[i] == 'a' || poss[i] == 'e' || poss[i] == 'i' || poss[i] == 'o' || poss[i] == 'u'){
            separ[i] = 1;
        }
    }
    
    //알파벳순 정렬
    sort(poss,poss+C);
    
    makeCode(0);
    
    return 0;
}
