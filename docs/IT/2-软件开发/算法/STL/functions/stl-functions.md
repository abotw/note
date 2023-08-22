# STL Functions

## Fill

* `std::fill` is a function from the `<algorithm>` library in C++. 
* It can be used to assign a specific value to a range of elements.

``` cpp linenums="1" hl_lines="10"
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> numbers(5); // Create a vector of size 5
    
    // Fill the entire vector with the value 42
    std::fill(numbers.begin(), numbers.end(), 42);
    
    // Output the elements of the vector
    for (int num : numbers)
        std::cout << num << " ";
    std::cout << std::endl;
    
    return 0;
}
```

