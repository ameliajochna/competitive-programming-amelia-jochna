#include <deque>
#include <iostream>
using namespace std;

deque<pair<int, int> > k_max;  // val, ind
deque<pair<int, int> > k_min;
deque<int> seq;
int t, n, m[3000001];

void input() {
  cin >> t;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> m[i];
}

void max_deq_calc(int cur_num, int ind) {
  while (!k_max.empty() && k_max.back().first < cur_num) k_max.pop_back();
  k_max.push_back({cur_num, ind});
}

void min_deq_calc(int cur_num, int ind) {
  while (!k_min.empty() && k_min.back().first > cur_num) k_min.pop_back();
  k_min.push_back({cur_num, ind});
}

int longest_subseq() {
  int max_length = 0, cur_size = 0;
  for (int i = 1; i <= n; i++) {
    max_deq_calc(m[i], i);
    min_deq_calc(m[i], i);
    seq.push_back(m[i]);
    cur_size++;
    while (!(k_min.empty() || k_max.empty()) &&
           k_max.front().first - k_min.front().first > t) {
      if (k_min.front().second < k_max.front().second) {
        while (seq.front() != k_min.front().first) {
          seq.pop_front();
          cur_size--;
        }
        seq.pop_front();
        cur_size--;
        k_min.pop_front();
      } else {
        while (seq.front() != k_max.front().first) {
          seq.pop_front();
          cur_size--;
        }
        seq.pop_front();
        cur_size--;
        k_max.pop_front();
      }
    }
    if (cur_size > max_length) max_length = cur_size;
  }

  if (n == 1)
    return 1;
  else
    return max_length;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  cout << longest_subseq();
  return 0;
}
