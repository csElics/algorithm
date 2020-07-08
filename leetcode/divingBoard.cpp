#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 等差数列问题
vector<int> divingBoard(int shorter, int longer, int k) {
    vector<int> result;

    if (0 == k) {
        return result;
    }

    // 公差
    int d = longer - shorter;

    if (0 == d) {
        result.push_back(shorter * k);
        return result;
    }

    // 用通项公式算每一个和 an = a0 + (n - 1) * d
    int a0 = shorter * k;
    for (int i = 0; i <= k; ++i) {
        result.push_back(a0 + d * i);
    }

    return result;
}

int main() {
    int shorter,longer,k;

    cout << "shorter: " << endl;
    cin >> shorter;
    cout << "longer: " << endl;
    cin >> longer;
    cout << "k: " << endl;
    cin >> k;

    vector<int> numberVector = divingBoard(longer, shorter, k);
    cout << "result: " << endl;
    for(int i = 0;i < numberVector.size(); i++) {
	cout << numberVector.at(i) << endl;
    }

    return 0;
}

