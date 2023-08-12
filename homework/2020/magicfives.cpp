#include <algorithm>
#include <iostream>
#include <vector>

int select(std::vector<int> &A, int k) {
  if (A.size() <= 5) {
    std::sort(A.begin(), A.end());
    return A[k - 1];
  }

  std::vector<int> marray;
  for (int i = 0; i < A.size(); i += 5) {
    int right = i + 5, left = i;
    if (right > A.size()) right = A.size();
    std::sort(A.begin() + left, A.begin() + right);
    marray.push_back(A[(left + right) / 2]);
  }

  int med = select(marray, marray.size() / 2);
  std::vector<int> smaller, same, bigger;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] < med)
      smaller.push_back(A[i]);
    else if (A[i] == med)
      same.push_back(A[i]);
    else if (A[i] > med)
      bigger.push_back(A[i]);
  }

  if (k <= smaller.size())
    return select(smaller, k);
  else if (k <= (smaller.size() + same.size()))
    return med;
  else
    return select(bigger, k - smaller.size() - same.size());
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int result = select(a, k);
  std::cout << result << std::endl;
  return 0;
}
