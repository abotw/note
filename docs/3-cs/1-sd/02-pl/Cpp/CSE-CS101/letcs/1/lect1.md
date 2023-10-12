# Lecture 1. Welcome

>   Computer science is no more about computers than astronomy is about tele-scopes, biology is about microscopes or chemistry is about beakers and test tubes. Science is not about tools, it is about how we use them and what we find out when we do.
>
>   —— Michael Fellows and Ian Parberry

---

-   **[CS106A](https://web.stanford.edu/class/cs106a/)**: Programming Methodologies
-   **[CS 106B](https://web.stanford.edu/class/cs106b/)**: Programming Abstractions **编程抽象**
-   **[CS 106L](https://web.stanford.edu/class/cs106l/)**:
-   **CS 107**: Computer Organization and Systems **计算机组成和系统** (**Systems**)
-   **[CS 107E](https://web.stanford.edu/class/cs107e/)**: 
-   **[CS 108](https://web.stanford.edu/class/cs108/)**
-   **CS 111**: Operating Systems Principles **操作系统原理**

**Theory:**

-   **CS 103**: Mathematical Foundations of Computing **离散数学**
-   **CS 109**: Intro to Probability for Computer Scientists **概率学**
-   **CS 161**: Design and Analysis of Algorithms **算法分析**

---

## C++ 语言介绍

![img](https://www.stroustrup.com/Bjarne2018.jpg)

>   C++ is a general purpose programming language with a bias towards systems programming that
>
>   -   **is a better C.**
>   -   **supports data abstraction.**
>   -   supports object-oriented programming.[^1]
>   -   supports generic programming
>
>   —— [Bjarne Stroustrup](https://www.stroustrup.com/), inventor of C++

### `Hello, World` in C++

``` cpp title="HelloWorld.cpp" linenums="1"
/**
 * File: HelloWorld.cpp
 * --------------------
 * This file is adapted from the example
 * on page 1 of Kernighan and Ritchie's
 * book The C Programming Language.
 * (1)
 */ 

#include <iostream>

int main() {
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

1. **Comment**:  `/* MAIN PROGRAM */` OR `// MAIN PROGRAM`

### C++ 标准

### QT Creator

## CMake

``` sh title="CMakeLists.txt" linenums="1"
# Set version (1)
cmake_minimum_required(VERSION 3.20) 

# Set project information (2)
project(
    HelloWorld
    VERSION 1.0
    DESCRIPTION "The Hello World program"
    LANGUAGES CXX)
  
# Add an executable target
add_executable(${PROJECT_NAME}) # add_executable(Hello)

# Define Cxx standard
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES CXX_STANDARD 17
               CXX_STANDARD_REQUIRED ON
               CXX_EXTENSIONS OFF)

# Add source files
target_sources(${PROJECT_NAME}
    PRIVATE src/HelloWorld.cpp)
```

1.   指定 QT 的版本号，不超过 3.24 即可
2.   可选：项目信息


[^1]: simula -> c with class