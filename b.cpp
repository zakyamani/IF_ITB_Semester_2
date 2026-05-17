#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        double x = stod(s);
        
        cout << 1.0 / x << endl;
    }
    return 0;
}