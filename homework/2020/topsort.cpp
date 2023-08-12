#include <iostream>
#include <queue>
#include <vector>

const int inf = 1073741824;
int n, m;
int before_nr[100001], counter;
std::vector<int> after_v[100001];
std::priority_queue<int> to_do;
std::vector<int> answer;

void making_sequence() {
  for (int i = n; i > 0; i--) {
    if (before_nr[i] == 0) {
      to_do.push(i);
      before_nr[i] = inf;
    }
  }

  while (!to_do.empty()) {
    while (!to_do.empty()) {
      int tmp_front = to_do.top();
      to_do.pop();
      for (int i = 0; i < after_v[tmp_front].size(); i++) {
        before_nr[after_v[tmp_front][i]]--;

        if (before_nr[after_v[tmp_front][i]] == 0) {
          to_do.push(after_v[tmp_front][i]);
          before_nr[after_v[tmp_front][i]] = inf;
        }
      }
      answer.push_back(tmp_front);
    }
    for (int i = n; i > 0; i--) {
      if (before_nr[i] == 0) {
        to_do.push(i);
        before_nr[i] = inf;
      }
    }
  }

  if (answer.size() == n)
    for (int i = 0; i < n; i++) std::cout << answer[i] << " ";
  else
    std::cout << "NIE";
}

void input() {
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int tmp_v1, tmp_v2;
    std::cin >> tmp_v1 >> tmp_v2;
    after_v[tmp_v1].push_back(tmp_v2);
    before_nr[tmp_v2]++;
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  input();
  making_sequence();
}
