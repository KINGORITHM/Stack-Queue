//
// Created by 양시연 on 2019/10/17.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue <int> q;
    for(int i = 0; i < progresses.size(); i++){
        q.push(progresses[i]);
    }

    double time, temp;
    int index = 0;
    int count = 0;

    time = (100.0 - q.front()) / speeds[index];
    if(time - int(time/1) > 0) time = int(time/1) + 1;

    while(index < progresses.size()){

        temp = (100.0 - q.front()) / speeds[index];

        if(temp <= time) {
            count++;
            q.pop();
        } else{
            if(time < temp) {
                time = temp;

                if(time - int(time/1) > 0) time = int(time/1) + 1;
            }

            answer.push_back(count);
            count = 1;
        }
        index++;
    }
    answer.push_back(count);

    return answer;
}

int main(){


    vector <int> progresses = {90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
    vector <int> speeds = {10,9,8,7,6,5,4,3,2,1};

    vector <int> answer;

    answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}