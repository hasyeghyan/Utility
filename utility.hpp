#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

template <typename T>
class Comp {
    public:
        bool operator()(T& a, T& b){
            return a < b ? true : false;
        }
};

template <typename ForwardIt, typename Comp>
ForwardIt my_min_element(ForwardIt first, ForwardIt last, Comp comp) {
    auto smallest = first;
    
    for (; first != last; ++first) {
        if (comp(*first, *smallest)) {
            smallest = first;
        }
    }

    return smallest;
}

int binarySearchIterative(const std::vector<int>& nums, const int& target) {
    int left = 0;
    int right = nums.size() - 1; 

    while (left <= right) {   
        int mid = left + (right - left) / 2;
    
        if (target < nums[mid]) right = mid - 1;
        else if (target > nums[mid]) left = mid + 1;
        else return mid;
    }
    return -1;
} 

int binarySearchRecursive(const std::vector<int>& nums, int left, int right, const int& target) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if (target < nums[mid]) return binarySearchRecursive(nums, left, mid - 1, target);
    if (target > nums[mid]) return binarySearchRecursive(nums, mid + 1, right, target);
    return mid;
     
    return -1;
} 

int lowerBound(const std::vector<int>& nums, const int& target) {
    int left = 0;
    int right = nums.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
       
        if (nums[mid] >= target) right = mid;
        else left = mid + 1;
    }

    return left;
}

int upperBound(const std::vector<int>& nums, const int& target) {
    int left = 0;
    int right = nums.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
       
        if (nums[mid] > target) right = mid;
        else left = mid + 1;
    }

    return left;
}

template <typename It, typename T>
std::pair<It, It> equal_range(It first, It last, const T& target) {
    return std::make_pair(std::lower_bound(first, last, target), std::upper_bound(first, last, target));
}



int partition(std::vector<int>& nums, int l, int r) {
    int i = l - 1;

    for (int j{l}; j <= r; ++j) {
        if (nums[j] <= nums[r]) std::swap(nums[++i], nums[j]);
    }

        return i;
}

void nthElementRecursive(std::vector<int>& nums, int k, int l, int r) {
    if (r <= l) return;

    int pivot = partition(nums, l, r);

    if (pivot == k) return;
    else if (pivot > k) nthElementRecursive(nums, k, l, pivot - 1);
    else nthElementRecursive(nums, k, pivot + 1, r);

}
   
void nthElementIterative(std::vector<int>& nums, int k, int l, int r) {
    while (l < r) {
        int pivot = partition(nums, l, r);

        if (pivot == k) return;
        else if (pivot > k) r = pivot - 1;
        else l = pivot + 1;
    }
}

void nthElement(std::vector<int>& nums, int k) {
    int l = 0;
    int r = nums.size() - 1;
        
    // nthElementRecursive(nums, k, l, r);
    nthElementIterative(nums, k, l, r);

}

std::vector<int>::iterator partition(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    auto pivot = *std::prev(last); 
    auto i = first;

    for (auto j = first; j != std::prev(last); ++j) {
        if (*j < pivot) {
            std::iter_swap(i, j); 
            ++i;
        }
    }
    std::iter_swap(i, std::prev(last));
    return i;
}

void manual_nth_element(std::vector<int>::iterator first, std::vector<int>::iterator nth, std::vector<int>:: iterator last) {
    while (first < last) {
        auto pivotIt = partition(first, last);

        if (pivotIt == nth) {
            return; 
        }
        else if (nth < pivotIt) {
            last = pivotIt; 
        } else {
            first = std::next(pivotIt);
        }
    }
}

int longestSubarraySumK(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> map{{0, -1}};

    int tmp{};
    int max {};

    for (int i{}; i < nums.size(); ++i) {
        tmp += nums[i];
        if (map.contains(tmp - k)) max = std::max(max, i - map[tmp - k]);
        if (!map.contains(tmp)) map[tmp] = i;
    }

    return max;
}

int maxSumSubarrayOfSizeK(std::vector<int>& nums, int k) {
    int curr{};
    for (int i{}; i < k; ++i) curr += nums[i];

    int res = curr;
    for (int i{k}; i < nums.size(); ++i) {
        curr += nums[i] - nums[i - k];
        res = std::max(res, curr);
    }

    return res;
}

int longestSubstringKdistincCharacters(std::string s, int k) {
    std::unordered_map<char, int> map;
        
    int l{};
    int res{};

    for (int r{}; r < s.size(); ++r) {
        ++map[s[r]];
        while (map.size() > k) {
            if (--map[s[l]] == 0) map.erase(s[l]);
            ++l;
        }
        res = std::max(res, r - l + 1);
    }
    return res;
}

#endif