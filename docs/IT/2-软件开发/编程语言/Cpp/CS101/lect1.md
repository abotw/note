# Lecture 01

>   C++ is a general purpose programming language with a bias towards systems programming that
>
>   -   **is a better C.**
>   -   **supports data abstraction.**
>   -   supports object-oriented programming.[^1]
>   -   supports generic programming
>
>   —— [Bjarne Stroustrup](https://www.stroustrup.com/), inventor of C++

``` cpp title="HelloWorld.cpp"
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

1. Comment:  `/* MAIN PROGRAM */` OR `// MAIN PROGRAM`

``` sh title="CMakeLists.txt"
# Set version (1)
cmake_minimum_required(VERSION 3.20) 

# Set project information (2)
project(
  HelloWorld
  VERSION 1.0
  DESCRIPTION "The Hello World program"
  LANGUAGES CXX)
  
# Add an executable target
add_executable(${PROJECT_NAME})
add_executable(HelloWorld)

# Define Cxx standard
set_target_properties(
	${PROJECT_NAME}
	PROPERTIES CXX_STANDARD 17
						 CXX_STANDARD_REQUIRED ON
						 CXX_EXTENSIONS OFF)
						 
# Add source files
target_sources(${PROJECT_NAME} PRIVATE src/HelloWorld.cpp)→
```

1.   指定 QT 的版本号，不超过 3.24 即可
2.   可选：项目信息

---

*   [Qt Creator](https://www.qt.io/download-qt-installer)
*   ToDesk




[^1]: simula -> c with class