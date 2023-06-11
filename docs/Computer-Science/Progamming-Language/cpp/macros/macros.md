# macros

## 宏 WHAT?

* 宏 / 宏定义 是预处理指令。
* 宏在编译时**进行简单文本替换**。
* 宏可以用来：
    * 定义常量
    * 创建函数宏
    * 进行条件编译
    * ...

### 特性

#### Token Concatenation（标记连接）

* 允许将两个或多个标记（tokens）组合成一个新的标记。
* 标记（tokens）在C语言中是由预处理器处理的最小单位，可以是关键字、标识符、运算符、常量等。

## HOW?

``` cpp title="macros.cpp" linenums="1"
#include <iostream>

// 定义常量宏
#define PI 3.14159

// 创建函数宏
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 带参数的宏
#define SQUARE(x) ((x) * (x))

// 条件编译
#define DEBUG_MODE

// 条件表达式
#define IS_EVEN(x) ((x) % 2 == 0)

int main() {
    // 使用常量宏
    double radius = 5.0;
    double circumference = 2 * PI * radius;
    std::cout << "Circumference: " << circumference << std::endl;

    // 使用函数宏
    int a = 10;
    int b = 20;
    int maxNum = MAX(a, b);
    std::cout << "Max: " << maxNum << std::endl;

    // 使用带参数的宏
    int num = 5;
    int result = SQUARE(num);
    std::cout << "Square: " << result << std::endl;

    // 使用条件编译
#ifdef DEBUG_MODE
    std::cout << "Debug mode is enabled." << std::endl;
#else
    std::cout << "Debug mode is disabled." << std::endl;
#endif

    // 使用条件表达式
    int number = 7;
    if (IS_EVEN(number)) {
        std::cout << number << " is even." << std::endl;
    } else {
        std::cout << number << " is odd." << std::endl;
    }

    return 0;
}

```

``` cpp title="Macro Definitions and Token Concatenation in C Language C语言中的宏定义和标记连接" linenums="1"
#include <stdio.h>

#define CONCAT(x, y) x##y
// 带参数的宏
#define PRINT_INT(x) printf("%d\n", x)

int main() {
    int num1 = 10;
    int num2 = 20;

    int concatenated = CONCAT(num, 1);
    PRINT_INT(concatenated);  // 输出: 10

    concatenated = CONCAT(num, 2);
    PRINT_INT(concatenated);  // 输出: 20

    return 0;
}
```

