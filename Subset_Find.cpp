#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> vs;

    for (int i = 1; i < (1 << n); i++) {

        string st = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {  
                st += to_string(a[j]);
            }
        }
        vs.push_back(st);
    }
    

    for (auto y : vs) {
        for (int i = 0; i < y.length(); i++) {
            cout << y[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
