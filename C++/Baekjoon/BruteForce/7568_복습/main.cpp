#include <iostream>
#include <queue>

using namespace std;

int N;
int w,h;

struct person{
    int height;
    int weight;
    int grade = 1;
};

int main(){
    //사람들 배열
    person peoeple[51];

    //N명
    cin >> N;
    
    for(int i=0; i<N; i++){
        //몸무게 키 입력
        cin >> w >> h;
        
        peoeple[i].weight = w;
        peoeple[i].height = h;
        
        for(int j=0; j<i; j++){
            //자신보다 큰 사람이 있다면 등수 떨어짐
            if(peoeple[j].weight > peoeple[i].weight && peoeple[j].height > peoeple[i].height){
                peoeple[i].grade++;
            }
            if(peoeple[j].weight < peoeple[i].weight && peoeple[j].height < peoeple[i].height){
                peoeple[j].grade++;
            }
        }
    }
    
    for(int i =0; i<N; i++){
        cout << peoeple[i].grade << " ";
    }
}
