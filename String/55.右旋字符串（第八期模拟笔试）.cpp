// 版本一
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int k;
    string s;
    cin >> k;
    cin >> s;
    int len = s.size(); //获取长度

    reverse(s.begin(), s.end()); // 整体反转
    reverse(s.begin(), s.begin() + k); // 先反转前一段，长度n
    reverse(s.begin() + k, s.end()); // 再反转后一段

    cout << s << endl;
} 