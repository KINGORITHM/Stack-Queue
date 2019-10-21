//
// Created by 이승민 on 2019-10-21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int size = prices.size();
    for (int i = 0; i < size; i++)
    {
        int index = size;
        int temp = prices[i];
        for (int j = i + 1; j < size; j++)
        {
            if (prices[j] < temp) {
                index = j;
                break;
            }
        }
        if (index == size) {
            answer.push_back(index - i - 1);
        }
        else {
            answer.push_back(index - i);
        }
    }

    return answer;
}

int main() {

    vector <int> prices = { 1,2,3,2,3 };
    vector <int> result;

    result = solution(prices);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}