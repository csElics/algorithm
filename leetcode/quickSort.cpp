#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>
using namespace std;


void print(vector<int> input) {
    for(int i = 0;i < input.size(); i++) {
    	cout << input.at(i) << endl;
    }
}

// 快排
vector<int> quickSort(vector<int>& input, int start, int end) {
    // 边界
    if (input.size() <= 1 || start >= end) {
        return input;
    }

    int q = input[start];
    int i = start;
    int j = end;
    while (i < j) {
        while (input[i + 1] <= q && i < j) {
            i++;
        }
        while (input[j] > q && i < j) {
            j--;
        }
        if (i < j) {
            swap(input[i + 1], input[j]);
        }
    }
    swap(input[i], input[start]);

    quickSort(input, start, i - 1);
    quickSort(input, i + 1, end);

    return input;
}

int main() {
    vector<int> input;
    cout << "intput numbers: " << endl;
    string i, tmp;
    cin >> i;
    stringstream ss(i);
    while (getline(ss, tmp, ',')) {
        input.push_back(stoi(tmp));
    }

    input = quickSort(input, 0, input.size() - 1);
    cout << "result: " << endl;
    print(input);

    return 0;
}

