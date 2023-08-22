# sort()

``` cpp linenums="1" hl_lines="11" title="Sorting an integer array in ascending order"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {5, 2, 8, 1, 9};
    
    sort(nums.begin(), nums.end()); // Sort the array using the sort function
    
    for (int num: nums)
        cout << num << " ";
    
    return 0;
}
```

``` cpp linenums="1" hl_lines="6 15 17" title="Sorting a string array based on length"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool compareByLength(const std::string& str1, const std::string& str2)
{
    return str1.length() < str2.length();
}

int main()
{
    std::vector<std::string> words = {"apple", "banana", "cat", "dog"};
    
    std::sort(words.begin(), words.end(), compareByLength); // Sort based on length using a custom comparison function
    
    for (const std::string& word : words)
        std::cout << word << " ";
        
    return 0;
}
```

``` cpp linenums="1" hl_lines="10 23 25" title="Sorting a custom structure on a member variable"
#include <iostream>
#include <algorithm>
#include <vector>

struct Person {
    std::string name;
    int age;
};

bool compareByAge(const Person& person1, const Person& person2)
{
    return person1.age < person2.age;
}

int main()
{
    std::vector<Person> people = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20}
    };
    
    std::sort(people.begin(), people.end(), compareByAge);
    
    for (const Person& person : people)
        std::cout << person.name << " (" << person.age << ") "; // Sort based one age using a custom comparison function
    
    return 0;
}
```

