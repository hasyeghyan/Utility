#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

// template <typename T>
// class Comp {
//     public:
//         bool operator()(T& a, T& b){
//             return a < b ? true : false;
//         }
// };

// template <typename ForwardIt, typename Comp>
// ForwardIt my_min_element(ForwardIt first, ForwardIt last, Comp comp) {
//     auto smallest = first;
    
//     for (; first != last; ++first) {
//         if (comp(*first, *smallest)) {
//             smallest = first;
//         }
//     }

//     return smallest;
// }

// int binarySearchIterative(const std::vector<int>& nums, const int& target) {
//     int left = 0;
//     int right = nums.size() - 1; 

//     while (left <= right) {   
//         int mid = left + (right - left) / 2;
    
//         if (target < nums[mid]) right = mid - 1;
//         else if (target > nums[mid]) left = mid + 1;
//         else return mid;
//     }
//     return -1;
// } 

// int binarySearchRecursive(const std::vector<int>& nums, int left, int right, const int& target) {
//     if (left > right) return -1;
    
//     int mid = left + (right - left) / 2;
    
//     if (target < nums[mid]) return binarySearchRecursive(nums, left, mid - 1, target);
//     if (target > nums[mid]) return binarySearchRecursive(nums, mid + 1, right, target);
//     return mid;     
// } 

// int lowerBound(const std::vector<int>& nums, const int& target) {
//     int left = 0;
//     int right = nums.size();
    
//     while (left < right) {
//         int mid = left + (right - left) / 2;
       
//         if (nums[mid] >= target) right = mid;
//         else left = mid + 1;
//     }

//     return left;
// }

// int upperBound(const std::vector<int>& nums, const int& target) {
//     int left = 0;
//     int right = nums.size();
    
//     while (left < right) {
//         int mid = left + (right - left) / 2;
       
//         if (nums[mid] > target) right = mid;
//         else left = mid + 1;
//     }

//     return left;
// }

// template <typename It, typename T>
// std::pair<It, It> equal_range(It first, It last, const T& target) {
//     return std::make_pair(std::lower_bound(first, last, target), std::upper_bound(first, last, target));
// }



// int partition(std::vector<int>& nums, int l, int r) {
//     int i = l - 1;

//     for (int j{l}; j <= r; ++j) {
//         if (nums[j] <= nums[r]) std::swap(nums[++i], nums[j]);
//     }

//         return i;
// }

// void nthElementRecursive(std::vector<int>& nums, int k, int l, int r) {
//     if (r <= l) return;

//     int pivot = partition(nums, l, r);

//     if (pivot == k) return;
//     else if (pivot > k) nthElementRecursive(nums, k, l, pivot - 1);
//     else nthElementRecursive(nums, k, pivot + 1, r);

// }
   
// void nthElementIterative(std::vector<int>& nums, int k, int l, int r) {
//     while (l < r) {
//         int pivot = partition(nums, l, r);

//         if (pivot == k) return;
//         else if (pivot > k) r = pivot - 1;
//         else l = pivot + 1;
//     }
// }

// void nthElement(std::vector<int>& nums, int k) {
//     int l = 0;
//     int r = nums.size() - 1;
        
//     // nthElementRecursive(nums, k, l, r);
//     nthElementIterative(nums, k, l, r);

// }

// std::vector<int>::iterator partition(std::vector<int>::iterator first, std::vector<int>::iterator last) {
//     auto pivot = *std::prev(last); 
//     auto i = first;

//     for (auto j = first; j != std::prev(last); ++j) {
//         if (*j < pivot) {
//             std::iter_swap(i, j); 
//             ++i;
//         }
//     }
//     std::iter_swap(i, std::prev(last));
//     return i;
// }

// void manual_nth_element(std::vector<int>::iterator first, std::vector<int>::iterator nth, std::vector<int>:: iterator last) {
//     while (first < last) {
//         auto pivotIt = partition(first, last);

//         if (pivotIt == nth) {
//             return; 
//         }
//         else if (nth < pivotIt) {
//             last = pivotIt; 
//         } else {
//             first = std::next(pivotIt);
//         }
//     }
// }

// // int longestSubarraySumK(std::vector<int>& nums, int k) {
// //     std::unordered_map<int, int> map{{0, -1}};

// //     int tmp{};
// //     int max {};

// //     for (int i{}; i < nums.size(); ++i) {
// //         tmp += nums[i];
// //         if (map.contains(tmp - k)) max = std::max(max, i - map[tmp - k]);
// //         if (!map.contains(tmp)) map[tmp] = i;
// //     }

// //     return max;
// // }

// int maxSumSubarrayOfSizeK(std::vector<int>& nums, int k) {
//     int curr{};
//     for (int i{}; i < k; ++i) curr += nums[i];

//     int res = curr;
//     for (int i{k}; i < nums.size(); ++i) {
//         curr += nums[i] - nums[i - k];
//         res = std::max(res, curr);
//     }

//     return res;
// }

// int longestSubstringKdistincCharacters(std::string s, int k) {
//     std::unordered_map<char, int> map;
        
//     int l{};
//     int res{};

//     for (int r{}; r < s.size(); ++r) {
//         ++map[s[r]];
//         while (map.size() > k) {
//             if (--map[s[l]] == 0) map.erase(s[l]);
//             ++l;
//         }
//         res = std::max(res, r - l + 1);
//     }
//     return res;
// }

//BobAlice problem
// std::vector<char> curr{};
// std::vector<bool> used{};

// void foo(std::vector<char>& v, int pos) {
//     if (pos == 3) {
//         for (auto x : curr) std::cout << x << " ";
//         std::cout << std::endl;
//         return; 
//     }

//     for (int i{}; i < 3; ++i) {
//         if (used[i] || (pos == 1 && v[i] == 'A')) continue;
        
//         used[i] = true;
//         curr[pos] = v[i];
        
//         foo(v, pos + 1);
//         used[i] = false;
//     }
// }

// void foo(std::vector<char>& v) {
//     curr.resize(3);
//     used.resize(3, false);
//     foo(v, 0);
// }

// //Towers of Hanoi
// void toh(char A, char B, char C, int n) {
//     if (!n) return;

//     toh(A, C, B, n - 1);
//     std::cout << A << "->" << C << std::endl;
//     toh(B, A, C, n - 1);
// }

// //Knight's tour
// bool ktour(int i, int j, std::vector<std::vector<int>>& matrix, int& n, int& m, std::vector<std::pair<int, int>>& p, int step) {
//     for (auto [x, y] : p) {
//         int ni = i + x;
//         int nj = j + y;

//         if (ni < n && ni >= 0 && nj < m && nj >= 0 && matrix[ni][nj] == -1) {           
//             matrix[ni][nj] = step;
            
//             if (step == n * m - 1) return true; 
//             if (ktour(ni, nj, matrix, n, m, p, step + 1)) return true;
           
//             matrix[ni][nj] = -1;
//         }
//     }
//     return false;
// }

// bool ktour(std::vector<std::vector<int>>& matrix) {
//     int n = matrix.size();
//     int m = matrix.front().size();
//     std::vector<std::pair<int, int>> p {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, -1}, {2, 1}, 
//     {1, -2}, {1, 2}};
    
//     for (int i{}; i < n; ++i) {
//         for (int j{}; j < m; ++j) {
//             int step{1};
//             matrix[i][j] = 0;
//             if (ktour(i, j, matrix, n, m, p, step)) return true;
//             matrix[i][j] = -1;
//         }
//     }
//     return false;
// }

// //subset sum equals k
// std::vector<std::vector<int>> res;
// std::vector<int> tmp;

// //first version
// // bool subsets(int i, std::vector<int>& nums, int k) {
// //     if (!k) return true;
// //     for (; i < nums.size(); ++i) {
// //         if (k >= nums[i]) { 
// //             if (subsets(i + 1, nums, k - nums[i])) return true;
// //         }
// //     }
// //     return false;
// // }

// //second version
// bool subsets(int i, std::vector<int>& nums, int k) {
//     if (!k) return true;
//     if (i == nums.size()) return false;

//     if (k >= nums[i]) { 
//         if (subsets(i + 1, nums, k - nums[i])) return true;
//     }
//     if (subsets(i + 1, nums, k)) return true;

//     return false;
// }

// bool subsets(std::vector<int>& nums, int k) {
//     return subsets(0, nums, k);
// }

//frog jump
//first
std::vector<int> dp;

int foo(int n, std::vector<int>& cost) {
    if (n == 0) return 0;
    if (dp[n]) return dp[n];

    if (n == 1) dp[n] = foo(n - 1, cost) + std::abs(cost[n - 1] - cost[n]);
    else dp[n] = std::min(foo(n - 1, cost) + std::abs(cost[n - 1] - cost[n]), foo(n - 2, cost) + std::abs(cost[n - 2] - cost[n]));

    return dp[n];
}

int frogJump(std::vector<int>& cost) {
    int n = cost.size();
    dp.assign(n, 0);
    
    return foo(n - 1, cost);
}

//second
int frogJump(std::vector<int>& cost) {
    int n = cost.size();
    std::vector<int> dp(n);
    dp[1] = std::abs(cost[0] - cost[1]);

    for (int i{2}; i < n; ++i) {
        dp[i] = std::min(dp[i - 1] + std::abs(cost[i - 1] - cost[i]), dp[i - 2] + std::abs(cost[i - 2] - cost[i]));
    }
    return dp[n - 1];
}

//third
int frogJump(std::vector<int>& cost) {
    int a = 0;
    int b = std::abs(cost[0] - cost[1]);

    for (int i{2}; i < cost.size(); ++i) {
        int c = std::min(b + std::abs(cost[i - 1] - cost[i]), a + std::abs(cost[i - 2] - cost[i]));
        a = b;
        b = c;
    }
    return b;
}

#endif