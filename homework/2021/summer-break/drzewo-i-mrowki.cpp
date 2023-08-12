#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

const int con = 800;

std::unordered_map<char, std::string> createTable() {
  std::unordered_map<char, std::string> table;
  for (char ch = '0'; ch <= '9'; ch++) {
    int val = ch - '0';
    std::string binary = "";
    for (int i = 0; i < 4; i++) {
      binary += (char)('0' + ((val >> (3 - i)) & 1));
    }
    table[ch] = binary;
  }
  for (char ch = 'a'; ch <= 'f'; ch++) {
    int val = ch - 'a' + 10;
    std::string binary = "";
    for (int i = 0; i < 4; i++) {
      binary += (char)('0' + ((val >> (3 - i)) & 1));
    }
    table[ch] = binary;
  }
  return table;
}

std::unordered_map<char, std::string> table = createTable();

std::pair<long long, long long> checkforst(long long cnt0, long long cnt1,
                                           long long n, char cur) {
  long long a, k, b, e;
  a = cnt0 + cnt1;
  k = cnt1 - cnt0;
  if (cur == '0')
    b = -1;
  else
    b = 1;
  n *= con, a *= con, k *= con;
  e = (6 * n - 9 * a - k) / (9 + b);
  if (0 <= e && e < con) return {a + e, k + b * e};
  return {-1, -1};
}

std::pair<long long, long long> checkfornd(long long cnt0, long long cnt1,
                                           long long n, long long a1,
                                           long long k1, char cur) {
  long long a, k, b, e;
  a = cnt0 + cnt1;
  k = cnt1 - cnt0;
  if (cur == '0')
    b = -1;
  else
    b = 1;
  n *= con, a *= con, k *= con;
  e = (12 * n - 9 * (a - a1) + k - k1) / (9 - b);
  if (0 <= e && e < con) return {a + e, k + b * e};
  return {-1, -1};
}

long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }

void solve() {
  long long n;
  std::cin >> n;
  bool fst = false, fnd = false;
  std::pair<long long, long long> metst, metnd;
  long long cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n / 2; i++) {
    char ch;
    std::cin >> ch;
    std::string s = table[ch];
    for (int j = 0; j < 4; j++) {
      if (!fst) {
        std::pair<long long, long long> tmp = checkforst(cnt0, cnt1, n, s[j]);
        if (tmp.first != -1) {
          fst = true;
          metst = tmp;
        }
      }
      if (fst && !fnd) {
        std::pair<long long, long long> tmp =
            checkfornd(cnt0, cnt1, n, metst.first, metst.second, s[j]);
        if (tmp.first != -1) {
          fnd = true;
          metnd = tmp;
        }
      }
      if (s[j] == '0')
        cnt0++;
      else
        cnt1++;
    }
  }
  long long t =
      (3 * metst.first + 3 * metnd.first + metst.second + metnd.second);
  long long div = 4 * con;
  long long gcd_val = gcd(t, div);
  std::cout << t / gcd_val << "/" << div / gcd_val << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
