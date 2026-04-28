#include <iostream>
#include <vector>
using namespace std;

int main() {
vector<int> data;
    int number;
    cin >>number;
    while (number >= 0) {
        auto iter = data.begin();
        while (iter != data.end() && *iter < number) {
            iter++;
            data.insert(iter, number);
            cin >> number;

        }
        for (const auto& e: data) {
            cout << e << endl;
        }
    }
return 0;
}