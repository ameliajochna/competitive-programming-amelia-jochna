#include <algorithm>
#include <iostream>
#include <map>

const long long MOD = 1000000007;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

std::pair<bool, std::pair<long long, long long> > conv(long long a,
                                                       long long b) {
  bool sign = (a * b >= 0);
  a = std::abs(a), b = std::abs(b);
  long long nwd = gcd(a, b);
  a = a / nwd, b = b / nwd;
  return {sign, {a, b}};
}

int main() {
  std::cin.tie(0);
  std::cout.tie(0);

  std::map<std::pair<bool, std::pair<long long, long long> >, long long> cnt;
  long long zerocnt = 0, n;
  std::cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a, b, c;
    std::cin >> a >> b >> c;
    if (b != 0) {
      cnt[conv(a, b)]++;
    } else {
      zerocnt++;
    }
  }

  long long s1 = 0, s2 = 0;
  for (const auto &m : cnt) {
    s1 += m.second;
    s2 += m.second * m.second;
  }
  s1 += zerocnt;
  s2 += zerocnt * zerocnt;

  long long ans = 0;
  for (const auto &m : cnt) {
    long long toadd =
        (1LL * m.second *
         (1LL * (s1 * s1) - s2 - 2 * (m.second) * (s1 - m.second))) %
        MOD;
    ans += toadd;
    ans = ans % MOD;
  }

  long long toadd = (1LL * zerocnt *
                     (1LL * (s1 * s1) - s2 - 2 * (zerocnt) * (s1 - zerocnt))) %
                    MOD;
  ans += toadd;
  long long modinv = 166666668;
  ans = ans % MOD;
  ans = (1LL * ans * modinv) % MOD;
  std::cout << ans << '\n';
  return 0;
}
