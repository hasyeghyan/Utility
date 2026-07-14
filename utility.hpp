#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <limits>
#include <string>

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

//Frog Jump {1,2}
//first
// std::vector<int> dp;

// int foo(int n, std::vector<int>& cost) {
//     if (n == 0) return 0;
//     if (dp[n] != -1) return dp[n];

//     int one_step = foo(n - 1, cost) + std::abs(cost[n - 1] - cost[n]);
//     int two_step = std::numeric_limits<int>::max();
//     if (n > 1) two_step = foo(n - 2, cost) + std::abs(cost[n - 2] - cost[n]);

//     return dp[n] = std::min(one_step, two_step);
// }

// int frogJump(std::vector<int>& cost) {
//     int n = cost.size();
//     dp.assign(n, -1);
    
//     return foo(n - 1, cost);
// }

// //second
// int frogJump(std::vector<int>& cost) {
//     int n = cost.size();
//     std::vector<int> dp(n);

//     for (int i{1}; i < n; ++i) {
//         int one_step = dp[i - 1] + std::abs(cost[i - 1] - cost[i]);
//         int two_step = std::numeric_limits<int>::max();
//         if (i > 1) two_step = dp[i - 2] + std::abs(cost[i - 2] - cost[i]);
        
//         dp[i] = std::min(one_step, two_step);
//     }
//     return dp[n - 1];
// }

// //third
// int frogJump(std::vector<int>& cost) {
//     int a = 0;
//     int b = 0;

//     for (int i{1}; i < cost.size(); ++i) {
//         int curr = a + std::abs(cost[i - 1] - cost[i]);
//         if (i > 1) curr = std::min(curr, b + std::abs(cost[i - 2] - cost[i]));
        
//         b = a;
//         a = curr;
//     }
//     return a;
// }

// //Frog Jump {1,2,3}
// //first
// std::vector<int> dp;

// int foo(int n, std::vector<int>& cost) {
//     if (n == 0) return 0;
//     if (dp[n] != -1) return dp[n];

//     int one_step = foo(n - 1, cost) + std::abs(cost[n - 1] - cost[n]);
//     int two_step = std::numeric_limits<int>::max();
//     int three_step = std::numeric_limits<int>::max();

//     if (n > 1) two_step = foo(n - 2, cost) + std::abs(cost[n - 2] - cost[n]);
//     if (n > 2) three_step = foo(n - 3, cost) + std::abs(cost[n - 3] - cost[n]);

//     return dp[n] = std::min({one_step, two_step, three_step});
// }

// int frogJump(std::vector<int>& cost) {
//     int n = cost.size();
//     dp.assign(n, -1);
    
//     return foo(n - 1, cost);
// }

// //second
// int frogJump(std::vector<int>& cost) {
//     int n = cost.size();
//     std::vector<int> dp(n);

//     for (int i{1}; i < n; ++i) {
//         int one_step = dp[i - 1] + std::abs(cost[i - 1] - cost[i]);
//         int two_step = std::numeric_limits<int>::max();
//         int three_step = std::numeric_limits<int>::max();

//         if (i > 1) two_step = dp[i - 2] + std::abs(cost[i - 2] - cost[i]);
//         if (i > 2) three_step = dp[i - 3] + std::abs(cost[i - 3] - cost[i]);
        
//         dp[i] = std::min({one_step, two_step, three_step});
//     }
//     return dp[n - 1];
// }

// //third
// int frogJump(std::vector<int>& cost) {
//     int a = 0;
//     int b = 0;
//     int c = 0;

//     for (int i{1}; i < cost.size(); ++i) {
//         int curr = a + std::abs(cost[i - 1] - cost[i]);
//         if (i > 1) curr = std::min(curr, b + std::abs(cost[i - 2] - cost[i]));
//         if (i > 2) curr = std::min(curr, c + std::abs(cost[i - 3] - cost[i]));
        
//         c = b;
//         b = a;
//         a = curr;
//     }
//     return a;
// }

// //Frog Jump {1,2,.... k}
// //first
// std::vector<int> dp;

// int foo(int n, std::vector<int>& cost, int k) {
//     if (n == 0) return 0;
//     if (dp[n] != -1) return dp[n];
    
//     int ans = std::numeric_limits<int>::max();
//     for (int step{1}; step <= std::min(n, k) ; ++step) {
//         ans = std::min(ans, foo(n - step, cost, k) + std::abs(cost[n - step] - cost[n]));
//     }

//     return dp[n] = ans;
// }

// int frogJump(std::vector<int>& cost, int k) {
//     int n = cost.size();
//     dp.assign(n, -1);
    
//     return foo(n - 1, cost, k);
// }

// //second
// int frogJump(std::vector<int>& cost, int k) {
//     int n = cost.size();
//     std::vector<int> dp(n, std::numeric_limits<int>::max());
//     dp[0] = 0;

//     for (int i{1}; i < n; ++i) {
//         for (int step{1}; step <= std::min(i, k) ; ++step) {
//             dp[i] = std::min(dp[i], dp[i - step] + std::abs(cost[i - step] - cost[i]));
//         }
//     }
//     return dp[n - 1];
// }

//Ninja's training
// std::vector<std::vector<int>> dp;

// //first(first version)
// int ninja(int i, int last, int n, std::vector<std::vector<int>>& matrix) {
//     if (dp[i][last] != -1) return dp[i][last];
//     if (i == 0) { 
//         int res = std::numeric_limits<int>::min();
//         for (int j{}; j < 3; ++j) {
//             if (j != last) res = std::max(res, matrix[i][j]);
//         }
//         return dp[i][last] = res;
//     }

//     int res = std::numeric_limits<int>::min();
//     for (int j{}; j < 3; ++j) {
//         if (j != last) res = std::max(res, ninja(i - 1, j, n, matrix) + matrix[i][j]);
//     }
//     return dp[i][last] = res;
// }

// int ninja(std::vector<std::vector<int>>& matrix) {
//     int n = matrix.size();
//     dp.assign(n, std::vector<int>(4, -1));
//     return ninja(n - 1, 3, n, matrix);
// }

// //second(first version)
// int ninja(std::vector<std::vector<int>>& matrix) {
//     int n = matrix.size();
//     std::vector<std::vector<int>> dp(n, std::vector<int>(3));

//     for (int i{}; i < 3; ++i) {
//         int res = 0;
//         for (int j{}; j < 3; ++j) {
//             if (j != i) res = std::max(res, matrix[0][j]);
//         }
//         dp[0][i] = res;
//     }
    
//     for (int day{1}; day < n; ++day) {
//         for (int last{}; last < 3; ++last) {
//             int res = 0;
//             for (int task{}; task < 3; ++task) {
//                 if (task != last) res = std::max(res, matrix[day][task] + dp[day - 1][task]);
//             }
//             dp[day][last] = res;
//         }
//     }
//     return *std::max_element(dp[n - 1].begin(), dp[n - 1].end());
// }


// //second(second version)
// int ninja(std::vector<std::vector<int>>& matrix) {
//     int n = matrix.size();
//     std::vector<std::vector<int>> dp(n, std::vector<int>(3));
    
//     for (int i{}; i < 3; ++i) dp[0][i] = matrix[0][i];

//     for (int day{1}; day < n; ++day) {
//         for (int task{}; task < 3; ++task) {
//             int res = 0;
//             for (int prev{}; prev < 3; ++prev) {
//                 if (task != prev) res = std::max(res, dp[day - 1][prev]);
//             }
//             dp[day][task] = res + matrix[day][task];
//         }
//     }
//     return *std::max_element(dp[n - 1].begin(), dp[n - 1].end());
// }

// //third(first version)
// int ninja(std::vector<std::vector<int>>& matrix) {
//     int n = matrix.size();
    // std::vector<int> dp(3);
    
    //  for (int i{}; i < 3; ++i) {
    //     int res = 0;
    //     for (int j{}; j < 3; ++j) {
    //         if (j != i) res = std::max(res, matrix[0][j]);
    //     }
    //     dp[i] = res;
    // }

    // for (int day{1}; day < n; ++day) {
    //     std::vector<int> tmp(3);
    //     for (int task{}; task < 3; ++task) {
    //         int res = 0;
    //         for (int j{}; j < 3; ++j) {
    //             if (j != task) res = std::max(res, dp[j] + matrix[day][j]);
    //         }
    //         tmp[task] = res;
    //     }
    //     dp = std::move(tmp);
    // }
    // return *std::max_element(dp.begin(), dp.end());
// }

// //third(second version)
// int ninja(std::vector<std::vector<int>>& matrix) {
//     int n = matrix.size();
//     std::vector<int> dp(3);
    
//     for (int i{}; i < 3; ++i) dp[i] = matrix[0][i];

//     for (int day{1}; day < n; ++day) {
//         std::vector<int> tmp(3);
//         for (int task{}; task < 3; ++task) {
//             int res = 0;
//             for (int j{}; j < 3; ++j) {
//                 if (j != task) res = std::max(res, dp[j]);
//             }
//             tmp[task] = res + matrix[day][task];
//         }
//         dp = std::move(tmp);
//     }
//     return *std::max_element(dp.begin(), dp.end());
// }

//Subsequence with sum K(dp)
//first
// std::vector<std::vector<int>> dp;

// bool solve(int i, int t, std::vector<int>& nums) {
//     if (t == 0) return true;
//     if (i == 0) return nums[i] == t;
//     if (dp[i][t] != -1) return dp[i][t];

//     return dp[i][t] = solve(i - 1, t, nums) || (t >= nums[i] && solve(i - 1, t - nums[i], nums));
// }

// bool solve(int t, std::vector<int>& nums) {
//     int n = nums.size();
//     dp.assign(n, std::vector<int>(t + 1, -1));
//     return solve(n - 1, t, nums);
// }

// //second
// bool solve(std::vector<int>& nums, int t) {
//     int n = nums.size();
//     std::vector<std::vector<bool>> dp(n, std::vector<bool>(t + 1));

//     for (int i{}; i < n; ++i) dp[i][0] = true;
//     if (t >= nums[0]) dp[0][nums[0]] = true;

//     for (int i{1}; i < n; ++i) {
//         for (int j{1}; j <= t; ++j) {
//             int not_take = dp[i - 1][j];
//             int take = (j >= nums[i]) && (dp[i - 1][j - nums[i]]);

//             dp[i][j] = not_take || take;
//         }
//     }
    
//     return dp[n - 1][t];
// }

// //third
// bool solve(std::vector<int>& nums, int t) {
//     int n = nums.size();
//     std::vector<bool> dp(t + 1);
//     dp[0] = true;

//     for (auto num : nums) {
//         for (int j{t}; j >= num; --j) {
//             dp[j] = dp[j] || dp[j - num];
//         }
//     }
    
//     return dp[t];
// }

//min absoulate difference of partitioning set into two subsets
//first
// std::vector<std::vector<int>> dp;

// int partition(std::vector<int>& nums) {
//     int total = accumulate(nums.begin(), nums.end(), 0);   

//     int n = nums.size();
//     int t = total / 2;
//     dp.assign(n, std::vector<int>(t + 1, -1));

//     for (int i{t}; i >= 0; ++i) {
//         if (subset_sum_k(n - 1, i, nums)) return total - 2 * i;
//     }
//     return 0;
// }

// bool subset_sum_k(int i, int t, std::vector<int>& nums) {
//     if (t == 0) return true;
//     if (i == 0) return nums[i] == t;
//     if (dp[i][t] != -1) return dp[i][t];

//     return dp[i][t] = subset_sum_k(i - 1, t, nums) || (t >= nums[i] && subset_sum_k(i - 1, t - nums[i], nums));
// }

// //second
// int partition(std::vector<int>& nums) {
//     int total = std::accumulate(nums.begin(), nums.end(), 0);   

//     int n = nums.size();
//     int t = total / 2;
//     std::vector<std::vector<bool>> dp(n, std::vector<bool>(t + 1));

//     dp[0][0] = true;
//     if (t >= nums[0]) dp[0][nums[0]] = true;

//     for (int i{1}; i < n; ++i) {
//         for (int j{}; j <= t; ++j) {
//             int not_take = dp[i - 1][j];
//             int take = (j >= nums[i]) && (dp[i - 1][j - nums[i]]);

//             dp[i][j] = not_take || take;
//         }
//     }
    
//     for (int i{t}; i >= 0; --i) {
//         if (dp[n - 1][i]) return total - 2 * i; 
//     }
//     return 0;
// }

// //third
// int partition(std::vector<int>& nums) {
//     int total = std::accumulate(nums.begin(), nums.end(), 0);   

//     int n = nums.size();
//     int t = total / 2;
    
//     std::vector<bool> dp(t + 1);
//     dp[0] = true;

//     for (auto num : nums) {
//         for (int j{t}; j >= num; --j) {
//             dp[j] = dp[j] || dp[j - num];
//         }
//     }

//     for (int i{t}; i >= 0; --i) {
//         if (dp[i]) return total - 2 * i; 
//     }
//     return 0;
// }

//Count subsets with sum k
//first
// std::vector<std::vector<int>> dp;

// int count(std::vector<int>& nums) {
//     int total = accumulate(nums.begin(), nums.end(), 0);   

//     int n = nums.size();
//     int t = total / 2;
//     dp.assign(n, std::vector<int>(t + 1, -1));

//     return solve(n - 1, t, nums);
// }

// int solve(int i, int t, std::vector<int>& nums) {
//     if (t == 0) return 1;
//     if (i == 0) return nums[i] == t;
//     if (dp[i][t] != -1) return dp[i][t];

//     return dp[i][t] = solve(i - 1, t, nums) + (t >= nums[i] ? solve(i - 1, t - nums[i], nums) : 0);
// }

// //second
// int count(std::vector<int>& nums) {
//     int total = std::accumulate(nums.begin(), nums.end(), 0);   

//     int n = nums.size();
//     int t = total / 2;
//     std::vector<std::vector<int>> dp(n, std::vector<int>(t + 1));

//     dp[0][0] = 1;
//     if (t >= nums[0]) dp[0][nums[0]] = 1;

//     for (int i{1}; i < n; ++i) {
//         for (int j{}; j <= t; ++j) {
//             int not_take = dp[i - 1][j];
//             int take = (j >= nums[i]) ? (dp[i - 1][j - nums[i]]) : 0;

//             dp[i][j] = not_take + take;
//         }
//     }
   
//     return dp[n - 1][t];
// }

// //third
// int partition(std::vector<int>& nums) {
//     int total = std::accumulate(nums.begin(), nums.end(), 0);   

//     int n = nums.size();
//     int t = total / 2;
    
//     std::vector<int> dp(t + 1);
//     dp[0] = 1;

//     for (auto num : nums) {
//         for (int j{t}; j >= num; --j) {
//             dp[j] +=  dp[j - num];
//         }
//     }

//     return dp[t];
// }

//Count partitions with given difference (this is the same as leetcode 494)

//0,1 knapsack
//first

// std::vector<std::vector<int>> dp;

// int knapsack(std::vector<int>& wt, std::vector<int>& val, int cap) {
//     int n = wt.size();
//     dp.assign(n, std::vector<int>(cap + 1 ,-1));

//     return solve(n - 1, cap, wt, val);
// }

// int solve(int i, int c, std::vector<int>& wt, std::vector<int>& val) {
//     if (i == 0) {
//         if (c >= wt[i]) return val[0];
//         return 0;
//     }
//     if (dp[i][c] != -1) return dp[i][c];
//     return dp[i][c] = std::max(solve(i - 1, c, wt, val), (c >= wt[i] ? val[i] + solve(i - 1, c - wt[i], wt, val) : 0));
// }

//second
// int knapsack(std::vector<int>& wt, std::vector<int>& val, int cap) {
//     int n = wt.size();
//     std::vector<std::vector<int>> dp(n, std::vector<int>(cap + 1));
    
//     for (int j{wt[0]}; j <= cap; ++j) dp[0][j] = val[0];

//     for (int i{1}; i < n; ++i) {
//         for (int j{}; j <= cap; ++j) {
//             int not_take = dp[i - 1][j];
//             int take = (j >= wt[i]) ? (val[i] +  dp[i - 1][j - wt[i]]) : 0;

//             dp[i][j] = std::max(not_take, take);
//         }
//     }
   
//     return dp[n - 1][cap];
// }

//third
// int knapsack(std::vector<int>& wt, std::vector<int>& val, int cap) {
//     int n = wt.size();
//     std::vector<int> dp(cap + 1);
    
//     for (int i{}; i < n; ++i) {
//         for (int j{cap}; j >= wt[i]; --j) {
//             int not_take = dp[j];
//             int take = val[i] +  dp[j - wt[i]];

//             dp[j] = std::max(not_take, take);
//         }
//     }
   
//     return dp[cap];
// }

//Unbounded knapsack
//first

// std::vector<std::vector<int>> dp;

// int knapsack(std::vector<int>& wt, std::vector<int>& val, int cap) {
//     int n = wt.size();
//     dp.assign(n, std::vector<int>(cap + 1 ,-1));

//     return solve(n - 1, cap, wt, val);
// }

// int solve(int i, int c, std::vector<int>& wt, std::vector<int>& val) {
//     if (i == 0) {
//         return (c / wt[i]) * val[i];
//     }
//     if (dp[i][c] != -1) return dp[i][c];
//     return dp[i][c] = std::max(solve(i - 1, c, wt, val), (c >= wt[i] ? val[i] + solve(i, c - wt[i], wt, val) : 0));
// }

//second
// int knapsack(std::vector<int>& wt, std::vector<int>& val, int cap) {
//     int n = wt.size();
//     std::vector<std::vector<int>> dp(n, std::vector<int>(cap + 1));
    
//     for (int j{wt[0]}; j <= cap; ++j) dp[0][j] = (j / wt[0]) * val[0];

//     for (int i{1}; i < n; ++i) {
//         for (int j{}; j <= cap; ++j) {
//             int not_take = dp[i - 1][j];
//             int take = (j >= wt[i]) ? (val[i] +  dp[i][j - wt[i]]) : 0;

//             dp[i][j] = std::max(not_take, take);
//         }
//     }
   
//     return dp[n - 1][cap];
// }

///third
// int knapsack(std::vector<int>& wt, std::vector<int>& val, int cap) {
//     int n = wt.size();
//     std::vector<int> dp(cap + 1);
    
//     for (int i{}; i < n; ++i) {
//         for (int j{wt[i]}; j <= cap; ++j) {
//             int not_take = dp[j];
//             int take = val[i] + dp[j - wt[i]];

//             dp[j] = std::max(not_take, take);
//         }
//     }
   
//     return dp[cap];
// }

//LCS(longest common subsequence)
//first

// std::vector<std::vector<int>> dp;

// int solve(std::string& s1, std::string& s2, int i, int j) {
//     if (i < 0 || j < 0) return 0;

//     if (dp[i][j] != -1) return dp[i][j];

//     if (s1[i] == s2[j]) return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1);
//     return dp[i][j] = std::max(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
// }

// int lcs(std::string& s1, std::string& s2) {
//     int n = s1.size();
//     int m = s2.size();
//     dp.assign(n, std::vector<int>(m,-1));

//     return solve(s1, s2, n - 1, m - 1);
// }

//second
// int lcs(std::string& s1, std::string& s2) {
//     int n = s1.size();
//     int m = s2.size();
//     std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    
//     for (int i{1}; i <= n; ++i) {
//         for (int j{1}; j <= m; ++j) {
//             if (s1[i - 1] ==  s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
//             else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
   
//     return dp[n][m];
// }

//third
// int lcs(std::string& s1, std::string& s2) {
//     int n = s1.size();
//     int m = s2.size();
//     std::vector<int> dp(m + 1);
    
//     for (int i{1}; i <= n; ++i) {
//         int prev_diag{};
//         for (int j{1}; j <= m; ++j) {
//             int tmp = dp[j];

//             if (s1[i - 1] ==  s2[j - 1]) dp[j] = 1 + prev_diag;
//             else dp[j] = std::max(dp[j - 1], dp[j]);

//             prev_diag =  tmp;
//         }
//     }
   
//     return dp[m];
// }

//Rod Cutting
//first

// std::vector<std::vector<int>> dp;

// int cut(std::vector<int>& nums) {
//     int n = nums.size();
//     dp.assign(n, std::vector<int>(n + 1,-1));

//     return solve(n - 1, n, nums);
// }

// int solve(int i, int j, std::vector<int>& nums) {
//     if (i == 0) return j * nums[i];
//     if (dp[i][j] != -1) return dp[i][j];
    
//     return dp[i][j] = std::max(solve(i - 1, j, nums), (j >= i + 1 ? nums[i] + solve(i, j - i - 1, nums) : 0));
// }

//second
// int cut(std::vector<int>& nums) {
//     int n = nums.size();
//     std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1));
    
//     for (int j{}; j <= n; ++j) dp[0][j] = j * nums[0];

//     for (int i{1}; i < n; ++i) {
//         for (int j{1}; j <= n; ++j) {
//             int not_cut = dp[i - 1][j];
//             int cut = (j >= i + 1) ? (nums[i] +  dp[i][j - i - 1]) : 0;

//             dp[i][j] = std::max(not_cut, cut);
//         }
//     }
   
//     return dp[n - 1][n];
// }

//third
int cut(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n + 1);
    
    for (int i{}; i < n; ++i) {
        for (int j{i + 1}; j <= n; ++j) {
            int not_cut = dp[j];
            int cut = nums[i] +  dp[j - i - 1];

            dp[j] = std::max(not_cut, cut);
        }
    }
   
    return dp[n];
}

#endif
