#include <iostream>
#include <queue>
#include <map>
#define PEOPLENUM 50
 
using namespace std;
pair<int,int> people_info[PEOPLENUM];

int main(){
    int people_num=0,height=0,weight=0,rank=1;
    cin>>people_num;

    for(int i=0;i<people_num;i++){
        cin>>height>>weight;
        people_info[i]=make_pair(height,weight);
    }

    for(int i=0;i<people_num;i++){
        int myrank=1;
        for(int j=0;j<people_num;j++){
            if(i==j) continue;
            if(people_info[i].first<people_info[j].first&&people_info[i].second<people_info[j].second){
                myrank++;
            }
        }
        cout<<myrank<<" ";
    }
}