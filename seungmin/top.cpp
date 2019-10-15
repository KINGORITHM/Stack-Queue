//
// Created by 이승민 on 2019-10-15.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.push_back(0);
    stack <int> s;

    for (int i = heights.size() - 1; i > 0 ; --i) {
        int height = heights[i];
        int count = 0;
        for (int j = i - 1; j >= 0 ; --j) {
            if(height < heights[j]){
                s.push(j + 1);
                break;
            }

            if(j == 0){
                s.push(0);
                break;
            }
        }
    }

    for (int i = 0; i < heights.size() - 1; ++i) {
        answer.push_back(s.top());
        s.pop();
    }
    return answer;
}

int main(){

    //vector <int> heights = {6, 9, 5, 7, 4};
    //vector <int> heights = {3, 9, 9, 3, 5, 7, 2};
    vector <int> heights = {1, 5, 3, 6, 7, 6, 5};

    vector <int> results;
    results = solution(heights);

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << " ";
    }
    return 0;
}