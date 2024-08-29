/**A star算法
 * 棋盘大小 1000 x 1000
 */

#include <bits/stdc++.h>
using namespace std;

#define N_MAX 1000

int dir[8][2]={-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2};

vector<int> sorted_dis{0, 5, 2, 4, 10, 18, 20, 1, 9, 8};

struct Knignt 
{
    int x, y, step, dis;    // 到终点的欧氏距离的平方
    bool operator < (const Knignt& k) const {
            // 如果是0，那么是最小的，其次是5，其次是2,4,10,1,9,
            if (dis > 20 && k.dis > 20) return dis > k.dis;
            for (int item: sorted_dis) {
                if (item == dis) return false;
                if (item == k.dis) return true;
            }
        return dis > k.dis;
    }
};

void calc_dis(Knignt& k, int x, int y) {
    k.dis = (k.x - x) * (k.x - x) + (k.y - y) * (k.y - y);
}


int main() {
    int n, x1, y1, x2, y2;
    cin >> n;
    Knignt cur, next;
    bool visited[N_MAX+5][N_MAX+5];
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        priority_queue<Knignt, vector<Knignt>, less<Knignt>> pq; // 优先队列
        memset(visited, false, sizeof(visited));                 // 是否访问过
        
        cur = {x1, y1, 0};
        calc_dis(cur, x2, y2);
        pq.push(cur);
        while (!pq.empty()) {
            cur = pq.top(); pq.pop();
            if (cur.x == x2 && cur.y == y2) {
                cout << cur.step << endl;
                break;
            }
            for (int i = 0; i < 8; i++) {
                int next_x = cur.x + dir[i][0];
                int next_y = cur.y + dir[i][1];
                if (next_x > 0 && next_x <= N_MAX && next_y > 0 && next_y <= N_MAX && !visited[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    next = {next_x, next_y, cur.step + 1};
                    calc_dis(next, x2, y2);
                    pq.push(next);
                }
            }
        }
    }

    return 0;
}