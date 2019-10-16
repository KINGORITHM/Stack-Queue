//
// Created by 이승민 on 2019-10-16.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int size = truck_weights.size();
    int count = 0;
    vector <int> bridge;
    vector <int> time;
    int temp = 0;
    while(1){
        answer += 1;

        if(time.size() != 0){
            if((time[0] + bridge_length) == answer){
                count++;
                temp -= bridge[0];
                bridge.erase(bridge.begin());
                time.erase(time.begin());
            }
        }

        if(truck_weights.size() != 0){
            if((temp + truck_weights[0]) <= weight){
                bridge.push_back(truck_weights[0]);
                time.push_back(answer);
                temp += truck_weights[0];
                truck_weights.erase(truck_weights.begin());
            }

        }

        if(count == size){
            return answer;
        }
    }
}


int main(){

    //int bridge_length = 2; int weight = 10; vector <int> truck_weights = {7,4,5,6};
    //result = 8

    //int bridge_length = 100; int weight = 100; vector <int> truck_weights = {10};
    //result = 101

    int bridge_length = 100; int weight = 100; vector <int> truck_weights = {10,10,10,10,10,10,10,10,10,10};
    //result = 110

    cout << solution(bridge_length, weight, truck_weights);

    return 0;
}