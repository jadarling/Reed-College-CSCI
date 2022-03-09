#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

template<class FwdIt, class Compare = std::less<>>
void quickSort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    auto const N = std::distance(first, last);
    if (N <= 1) return; 
    auto const pivot = std::next(first, N / 2);
    std::nth_element(first, pivot, last, cmp);
    quickSort(first, pivot, cmp); 
    quickSort(pivot, last, cmp); 
}

int main()
{
  std::vector<int> testdata(1000000);
  std::iota(testdata.begin(), testdata.end(), 1);
  quickSort(testdata.begin(), testdata.end());
  return testdata[0];
}
