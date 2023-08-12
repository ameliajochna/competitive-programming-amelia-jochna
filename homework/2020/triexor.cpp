#include <iostream>
#include <vector>

const int maxN = 2e5 + 2;
int trie[maxN * 30][2], nextv = 1, cnt[maxN * 30][2];

void insertNumber(int n) {
  int s = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (n >> i) & 1;
    cnt[s][b]++;
    if (!trie[s][b]) trie[s][b] = nextv++;
    s = trie[s][b];
  }
}

int queryXOR(int n) {
  int s = 0;
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (n >> i) & 1;
    if (trie[s][!b] && cnt[s][!b] > 0) {
      s = trie[s][!b];
      ans *= 2;
      ans |= 1;
    } else if (trie[s][b]) {
      s = trie[s][b];
      ans *= 2;
    }
  }
  return ans;
}

void eraseNumber(int n) {
  int s = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (n >> i) & 1;
    cnt[s][b]--;
    s = trie[s][b];
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  insertNumber(0);
  int n;
  std::cin >> n;
  while (n--) {
    char type;
    int a;
    std::cin >> type >> a;
    if (type == '+')
      insertNumber(a);
    else if (type == '-')
      eraseNumber(a);
    else if (type == '?')
      std::cout << queryXOR(a) << '\n';
  }
}
