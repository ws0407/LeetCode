// 卡码网
#include <iostream>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        int iold = s.size() - 1;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            }
        }
        s.resize(s.size() + count * 5);
        int inew = s.size() - 1;
        while (iold >= 0) {
            if (s[iold] >= '0' && s[iold] <= '9') {
                s[inew--] = 'r';
                s[inew--] = 'e';
                s[inew--] = 'b';
                s[inew--] = 'm';
                s[inew--] = 'u';
                s[inew--] = 'n';
            } else {
                s[inew--] = s[iold];
            }
            iold--;
        }
        cout << s << endl;       
    }
}