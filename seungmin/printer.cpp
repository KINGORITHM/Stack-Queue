//
// Created by 이승민 on 2019-10-14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_max(vector <pair <int, int>> v){
    int temp = v[0].second;
    for (int j = 1; j < v.size(); ++j) {
        if(v[j].second > temp){
            return 0;
        }
    }

    return 1;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector <pair<int, int>> v;

    for (int i = 0; i < priorities.size(); ++i) {
        v.push_back(make_pair(i, priorities[i]));
    }

   while(1){
        if(check_max(v)){
            if(v[0].first == location){
                return answer;
            }
            else{
                v.erase(v.begin());
                answer += 1;
            }
        }
        else{
            v.push_back(make_pair(v[0].first, v[0].second));
            v.erase(v.begin());
        }
    }
}
int main(){

    vector <int> priorities = {2, 1, 3, 2};
    int location = 2;

    /*vector <int> priorities = {1, 1, 9, 1, 1, 1};
     int location = 0;*/


    cout << solution(priorities, location);

    return 0;
}

