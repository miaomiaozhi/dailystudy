#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

class KMP {
public:
    int *ne;
    string mainStr;
    string CompareStr;
    int len = INF;
    KMP () {
        ne = new int(len);
    }
    KMP (string a, string b) {
        len = a.length();
        ne = new int(len);
    }
    void setMainStr(string mainStr) {
        this->mainStr = mainStr;
    }
    void setCompareStr(string CompareStr) {
        this->CompareStr = CompareStr;
    }
    void calcNext() {
        if (len == INF) return;
        for (int i = 1, j = 0; i <= len; i ++) {
            while (j && CompareStr[i] != CompareStr[j + 1]) j = ne[j];
            if (CompareStr[i] == CompareStr[j + 1]) j ++;
            ne[i] = j;
        }
    }
    void displayNext() {
        if (len == INF) return;
        for (int i = 0; i <= len; i ++) {
            cout << ne[i] << ' ';
        }
        cout << endl;
    }
};

int main () {
    string a = "abababa";

    KMP kmp;
    kmp.setCompareStr(a);
    kmp.setMainStr(a);
    kmp.calcNext();
    kmp.displayNext();
    return 0;
}