# Vector

## Constructor call

* **SYNTAX**： `vector<size_type> v(count, value)`
  * ``size_type` is the type used for indexing the vector
  * `count` specifies the size of the vector
  * `value` is the value used to initialize each element of the vector.

``` cpp linenums="1"
#include <iostream>
#include <vector>

int main()
{
    int n = 10;
    std::vector<bool> is_prime(n, true); // (1)
    
    for (int i = 0; i < is_prime.size(); i ++ ) {
        std::cout 
          << "is_prime[" 
          << i 
          << "] = " 
          << std::boolalpha 
          << is_prime[i] 
          << std::endl; // (2)
    }
    
    return 0;
}
```

1. The line `vector<bool> is_prime(n, true);` creates a `vector` named `is_prime` of type `bool` with a size of `n` elements, all initialized to `true`.
2. `std::boolalpha` is used to print `true` or `false` instead of `1` or `0` for readability.