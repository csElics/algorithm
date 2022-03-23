#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>
using namespace std;

// 快排
vector<int> quickSort(vector<int> input, int start, int end) {
    // 边界
    if (input.size() <= 1 || start >= end) {
        return input;
    }

    int q = input[start];
    int i = start;
    int j = end;
    while (i < j) {
        while (input[i] <= q && i < j) {
            i++;
        }
        while (input[j] > q && j > start) {
            j--;
        }
        if (i < j) {
            swap(input[i], input[j]);
        }
    }
    swap(input[j], input[start]);

    quickSort(input, start, j - 1);
    quickSort(input, j + 1, end);

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
    for(int i = 0;i < input.size(); i++) {
    	cout << input.at(i) << endl;
    }

    return 0;
}

