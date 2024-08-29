/**输出一个整数，代表从 beginStr 转换到 endStr 需要的最短转换序列中的字符串数量。
 * 如果不存在这样的转换序列，则输出 0。
 * 第一行包含一个整数 N，表示字典 strList 中的字符串数量。 第二行包含两个字符串，
 * 用空格隔开，分别代表 beginStr 和 endStr。 
 * 后续 N 行，每行一个字符串，代表 strList 中的字符串。 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string beginStr, endStr, tmpStr;
    cin >> beginStr >> endStr;
    unordered_set<string> strSet;
    while (n--) {
        cin >> tmpStr;
        strSet.insert(tmpStr);
    }
    unordered_map<string, int> pathMap;
    pathMap.insert(pair<string, int>{beginStr, 1});

    queue<string> que;
    que.push(beginStr);

    while (!que.empty()) {
        string word = que.front();
        que.pop();
        int path = pathMap[word];

        for (int i = 0; i < word.size(); i++) {
            string newWord = word;
            for (int j = 0; j < 26; j++) {
                newWord[i] = j + 'a';
                if (newWord == endStr) {
                    cout << path + 1;
                    return 0;
                }
                if (strSet.find(newWord) != strSet.end() && pathMap.find(newWord) == pathMap.end()) {
                    pathMap[newWord] = path + 1;
                    que.push(newWord);
                }
            }
        }
    }
    cout << 0;
    return 0;
}