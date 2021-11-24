//
//  main.cpp
//  1339_Greedy
//
//  Created by 홍진석 on 2021/02/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;

struct Alpha{
    int powN; //곱할 값
    char alpha; //알파벳이 뭔지
    int givenNum; //주어지는 숫자가 무엇인지
};

vector<Alpha> v;

bool compare(Alpha a, Alpha b){
    return a.powN > b.powN;
}


int main() {
    string s;
    
    //문제 갯수 N개 들어온다
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> s;
    
        for(unsigned j =0; j<s.size(); j++){
            //같은 값이 있는지 확인
            bool errorcheck = false;
            
            //있으면 합쳐주기
            for(unsigned k=0; k<v.size(); k++){
                if(v[k].alpha == s[j]){
                    v[k].powN += pow(10, (s.size()-j-1));
                    errorcheck = true;
                    break;
                }
            }
            //없으면 새로 넣어주기
            if(errorcheck == false){
                Alpha a;
                a.alpha = s[j];
                a.powN = pow(10, (s.size()-j-1));
                v.push_back(a);
            }
        }
    }
    
    sort(v.begin(),v.end(),compare);
    
    int num = 9;
    int sum = 0;
    
    for(unsigned i=0; i<v.size(); i++){
        v[i].givenNum = num;
        num--;
        
        sum += v[i].givenNum * v[i].powN;
    }
    
    cout << sum;
    
    return 0;
}

