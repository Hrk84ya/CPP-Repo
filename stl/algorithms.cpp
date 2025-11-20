#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    std::cout << "Original: ";
    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    // Sorting
    std::vector<int> sorted_nums = numbers;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    std::cout << "Sorted: ";
    std::copy(sorted_nums.begin(), sorted_nums.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    // Finding elements
    auto it = std::find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        std::cout << "Found 8 at position: " << std::distance(numbers.begin(), it) << "\n";
    }
    
    // Count elements
    int count_greater_5 = std::count_if(numbers.begin(), numbers.end(), 
                                       [](int n) { return n > 5; });
    std::cout << "Numbers > 5: " << count_greater_5 << "\n";
    
    // Transform
    std::vector<int> doubled(numbers.size());
    std::transform(numbers.begin(), numbers.end(), doubled.begin(), 
                  [](int n) { return n * 2; });
    std::cout << "Doubled: ";
    std::copy(doubled.begin(), doubled.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    // Accumulate (sum)
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << "\n";
    
    // Min/Max elements
    auto min_it = std::min_element(numbers.begin(), numbers.end());
    auto max_it = std::max_element(numbers.begin(), numbers.end());
    std::cout << "Min: " << *min_it << ", Max: " << *max_it << "\n";
    
    // Partition
    std::vector<int> partitioned = numbers;
    auto partition_point = std::partition(partitioned.begin(), partitioned.end(), 
                                        [](int n) { return n % 2 == 0; });
    std::cout << "Partitioned (even first): ";
    std::copy(partitioned.begin(), partitioned.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    // Binary search (requires sorted container)
    bool found = std::binary_search(sorted_nums.begin(), sorted_nums.end(), 7);
    std::cout << "Binary search for 7: " << (found ? "Found" : "Not found") << "\n";
    
    // Remove duplicates
    std::vector<int> with_duplicates = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    std::sort(with_duplicates.begin(), with_duplicates.end());
    auto unique_end = std::unique(with_duplicates.begin(), with_duplicates.end());
    with_duplicates.erase(unique_end, with_duplicates.end());
    std::cout << "Unique elements: ";
    std::copy(with_duplicates.begin(), with_duplicates.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    return 0;
}