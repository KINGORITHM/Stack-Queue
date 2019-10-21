//
// Created by 이승민 on 2019-10-14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector <int> time;
    for (int i = 0; i < progresses.size(); ++i) {
        int temp;

        if(((100 - progresses[i]) % speeds[i]) == 0){
            temp = (100 - progresses[i]) / speeds[i];
        }
        else{
            temp = (100 - progresses[i]) / speeds[i];
            temp += 1;
        }
        time.push_back(temp);
    }
    for (int i = 0; i < time.size(); ++i) {
        cout << time[i] << " ";
    }

    cout << endl;
    int count;

    for (int i = 0; i < time.size(); ++i) {
        int temp = time[i];
        int count = 1;

        if(i == time.size() - 1){
            answer.push_back(count);
            break;
        }
        for (int j =  i + 1; j < time.size(); ++j) {
            if(time[j] <= temp){
                count++;
                if(j == (time.size() - 1))
                {
                    i = j;
                    answer.push_back(count);
                    break;
                }
            }
            else{
                answer.push_back(count);
                i = j - 1;
                break;
            }
        }
    }

    return answer;
}

int main(){

    /*vector <int> progresses = {93, 30, 55};
    vector <int> speeds = {1,30,5};*/

    vector <int> progresses = {40, 93, 30, 55, 60, 65};
    vector <int> speeds = {60, 1, 30, 5 , 10, 7};

    vector <int> answer;

    answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }


    return 0;
}