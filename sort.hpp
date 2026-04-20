#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void bubble(std::vector<int>& nums)
{
    int n = nums.size();

    for (int i{}; i < n - 1; ++i)
    {
        bool sw = false;
        for (int j{}; j < n - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                sw = true;
            }
        }
        if (!sw)
            break;
    }
}

void bubble_it(std::vector<int>& nums)
{
    auto endIter = nums.end() - 1;
    while (endIter != nums.begin())
    {
        bool isSwapped = false;

        for (auto beginIter = nums.begin(); beginIter != endIter; ++beginIter)
        {
            if (*beginIter > *(beginIter + 1))
            {
                std::swap(*beginIter, *(beginIter + 1));
                isSwapped = true;
            }
        }

        if (!isSwapped)
            break;
        --endIter;
    }
}

void selection(std::vector<int>& nums)
{
    int n = nums.size();

    for (int i{}; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[j] < nums[min])
            {
                min = j;
            }
        }
        if (min != i)
            std::swap(nums[min], nums[i]);
    }
}

void selection_it(std::vector<int>& nums)
{
    auto currIter = nums.begin();
    while (currIter != nums.end() - 1)
    {
        auto min = currIter;
        for (auto nextIter = currIter + 1; nextIter != nums.end(); ++nextIter) {
            if (*nextIter < *min) {
                min = nextIter;
            }
        }

        if (min != currIter) std::swap(*currIter, *min);
        ++currIter;
    }
}

void selection_it_other(std::vector<int>& nums)
{
    for (auto currIter = nums.begin(); currIter != nums.end() - 1; ++currIter) {
        auto nextIter = std::min_element(currIter, nums.end());
        std::swap(*nextIter, *currIter);
    }
}

std::vector<int> CountingSort(std::vector<int>& nums) {
    int max = nums.front();
    int min = nums.front();

    for (int i = 1; i < nums.size(); ++i) {
        max = std::max(max, nums[i]);
        min = std::min(min, nums[i]);
    } 

    size_t range = max - min + 1;
    std::vector<int> freqMap(range, 0);
    int shift = -min;

    for (int i{}; i < nums.size(); ++i) {
        ++freqMap[nums[i] + shift];
    } 

    nums.clear();
    
    for (int i{}; i < range; ++i) {
        while (freqMap[i]--) 
        {
                nums.push_back(i - shift);
        }
    }

    return nums;
}

void CountingSortStable(std::vector<int>& nums) {
    int max = nums.front();
    int min = nums.front();

    for (int i = 1; i < nums.size(); ++i) {
        max = std::max(max, nums[i]);
        min = std::min(min, nums[i]);
    } 

    size_t range = max - min + 1;
    std::vector<int> freqMap(range, 0);

    for (int i{}; i < nums.size(); ++i) {
        ++freqMap[nums[i] - min];
    } 

    std::vector<int> res(nums.size(), 0);

    for (int i{1}; i < freqMap.size(); ++i) {
        freqMap[i] += freqMap[i - 1];
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
       res[--freqMap[nums[i] - min]] = nums[i];
    }
   
    nums = std::move(res);
}

void CountingSortStable(std::vector<int>& nums, int exp) {
    std::vector<int> freqMap(10, 0);

    for (int i{}; i < nums.size(); ++i) {
        ++freqMap[(nums[i] / exp) % 10];
    } 

    std::vector<int> res(nums.size(), 0);

    for (int i{1}; i < freqMap.size(); ++i) {
        freqMap[i] += freqMap[i - 1];
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
       res[--freqMap[(nums[i] / exp) % 10]] = nums[i];
    }
   
    nums = std::move(res);
}

void CountingSortStableBit(std::vector<int>& nums, int sh) {
    std::vector<int> freqMap(256, 0);

    for (int i{}; i < nums.size(); ++i) {
        ++freqMap[(nums[i] >> sh) & 255];
    } 

    std::vector<int> res(nums.size(), 0);

    for (int i{1}; i < freqMap.size(); ++i) {
        freqMap[i] += freqMap[i - 1];
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
       res[--freqMap[(nums[i] >> sh) & 255]] = nums[i];
    }
   
    nums = std::move(res);
}

void radixSort(std::vector<int>& nums) {
    int min = nums.front();

    for (int i{1}; i < nums.size(); ++i) { 
        min = std::min(min, nums[i]);
    }
    
    if (min < 0) {
        for (int i{}; i < nums.size(); ++i) {
            nums[i] += std::abs(min);
        }
    }

    int max = nums.front();

    for (int i{1}; i < nums.size(); ++i) { 
        max = std::max(max, nums[i]);
    }

    // for (int exp{1}; (max / exp) > 0; exp *= 10) {
    //     CountingSortStableBit(nums, exp);
    // }
    
    for (int sh{0}; (max >> sh) > 0; sh += 8) {
        CountingSortStableBit(nums, sh);
    }

    if (min < 0) {
        for (int i{}; i < nums.size(); ++i) {
            nums[i] -= std::abs(min);
        }
    }
}

std::vector<int> insertionSort(std::vector<int>& nums) {
    for (int i{1}; i < nums.size(); ++i) {
        int j = i - 1;
        int tmp = nums[i];

        while (j >= 0 && tmp < nums[j]) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = tmp;
    }

    return nums;
}

int partition1(std::vector<int>& nums, int l, int r) {
    int i = l - 1;

    for (int j = l; j <= r; ++j) {
        if (nums[j] <= nums[r]) std::swap(nums[++i], nums[j]);
    }

    return i;
}

int partition2(std::vector<int>& nums, int l, int r) {
    int i = l;

    for (int j = l + 1; j <= r; ++j) {
        if (nums[j] <= nums[l]) std::swap(nums[++i], nums[j]);
    }
    
    std::swap(nums[i], nums[l]);
    return i;
}

int partition3(std::vector<int>& nums, int l, int r) {
    int m = l + (r - l) / 2;  
    int median = l;

    if (nums[l] < nums[r]) {
        if (nums[l] < nums[m]) median = (nums[r] < nums[m] ? r : m);
        else median = l;
    } else {
        if (nums[l] > nums[m]) median = (nums[r] > nums[m] ? r : m);
        else median = l;   
    }
    
    std::swap(nums[median], nums[r]);

    int i = l - 1;

    for (int j = l; j <= r; ++j) {
        if (nums[j] <= nums[r]) std::swap(nums[++i], nums[j]);
    }

    return i;
}

int partition4(std::vector<int>& nums, int l, int r) {
    int random = l + (rand() % (r - l));

    std::swap(nums[random], nums[r]);
    int i = l - 1;

    for (int j = l; j <= r; ++j) {
        if (nums[j] <= nums[r]) std::swap(nums[++i], nums[j]);
    }

    return i;
}

void quickSort(std::vector<int>& nums, int l, int r) {
   if (r <= l) return;

   int pivot = partition4(nums, l, r);
   quickSort(nums, l, pivot - 1);
   quickSort(nums, pivot + 1, r);
}

void quickSort(std::vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    quickSort(nums, l, r);
}

#endif