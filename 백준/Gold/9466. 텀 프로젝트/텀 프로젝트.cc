#include <iostream>
#include <vector>
using namespace std;

int t, n, res;
vector<int> vec;
vector<int> checked; // -1: 팀 실패, 0: 아직 확인 안 됨, 1: 팀 성공
vector<bool> visited;

void dfs(int cur_mem);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        cin >> n;

        // 테스트 케이스마다 초기화
        vec.assign(n + 1, 0);
        checked.assign(n + 1, 0);
        visited.assign(n + 1, false);
        res = 0;

        for (int i = 1; i <= n; i++) {
            cin >> vec[i];
        }

        for (int i = 1; i <= n; i++) {
            if (checked[i] == 0) { // 아직 확인되지 않은 경우만 DFS 수행
                dfs(i);
            }
        }

        // 팀에 포함되지 않은 학생 수 계산
        for (int i = 1; i <= n; i++) {
            if (checked[i] == -1) res++;
        }

        cout << res << "\n";
    }

    return 0;
}

void dfs(int cur_mem) {

    visited[cur_mem] = true;
    int nxt_mem = vec[cur_mem];

    if (!visited[nxt_mem]) { // 아직 방문하지 않은 경우
        dfs(nxt_mem);
    }
    else if (checked[nxt_mem] == 0) { // 사이클 발견
        // 사이클에 포함된 모든 노드 처리
        for (int temp = nxt_mem; temp != cur_mem; temp = vec[temp]) {
            checked[temp] = 1;
        }
        checked[cur_mem] = 1;
    }

    if (checked[cur_mem] != 1) { // 사이클에 포함되지 않으면 실패로 처리
        checked[cur_mem] = -1;
    }
}
