#include "utility.hpp"
#include "sort.hpp"

int main() {
  
    std::vector<int> vec1 = {8, 3, 6, 8, 4, 10};
    
    // auto curr1 = std::min_element(vec.begin(), vec.end(), {](a}to& a, auto& b){
    //     return a < b ? true : false;
    // });
    // std::cout << *curr1 << std::endl;
    
    // Comp<int> comp;
    // auto curr2 = std::min_element(vec.begin(), vec.end(), comp);
    // std::cout << *curr2 << std::endl;

    // std::less<int> l;
    // auto curr3 = std::min_element(vec.begin(), vec.end(), l);
    // std::cout << *curr3 << std::endl;

    // std::vector<int> vec1 = {1, 3, 5, 7, 9};
    // std::cout << binarySearchIterative(vec1, 4) << std::endl;
    // std::cout << binarySearchRecursive(vec1, 0, vec1.size() - 1, 3) << std::endl;
    
    // std::vector<int> vec1 = {1, 2, 3, 10, 11, 11};
    // std::cout << upperBound(vec1,10) << std::endl;
    
    // quickSort(vec);
    // nthElement(vec, 4);
    radixSort(vec1);

    for (auto x : vec1) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}