#include <vector>
#include <iostream>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  int tail = m + n - 1, i = m - 1,  j = nums2.size() - 1;

  while(j >= 0 && i >= 0) {
    if(nums1[i] < nums2[j]) 
      nums1[tail] = nums2[j--];
    else
      nums1[tail] = nums1[i--]; 
    tail--;
  }

  while(j >= 0)
    nums1[tail--] = nums2[j--];
}

int main(int argc, char **argv) {
  std::vector<int> nums1{ 1, 2, 3, 0, 0, 0 }, nums2{ 2, 5, 6};
  int m = 3, n = 3;
  // std::vector<int> nums1{ 0 }, nums2{ 1 };
  // int m = 0, n = 1;

  merge(nums1, m, nums2, n);

  std::cout << "[ ";
  for(auto& n : nums1) {
    std::cout << n;
    std::cout << (n == nums1.back() ? "" : ", ");

  }
  std::cout << " ]" << std::endl;
}
