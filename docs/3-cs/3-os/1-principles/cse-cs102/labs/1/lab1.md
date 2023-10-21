# Lab 1. 数据的表示

## 1. 位运算

-   [x] 进制转换
-   [x] 转换工具
-   [ ] 位运算
-   [ ] 位向量
-   [ ] 位掩码
-   [ ] 其他

### 进制转换

**练习**：参考第一个示例，练习十六进制到二进制。这些值是 32 位无符号整数。

| 十六进制   | 二进制                                              |
| ---------- | --------------------------------------------------- |
| `0x1`      | `00000000 00000000 00000000 00000001`               |
| `0x1ff`    | `00000000 00000000 00000001 11111111`               |
| `0x800000` | `0x00800000`, `00000000 10000000 00000000 00000000` |
| `0xa017`   | `0x0000a017`, `00000000 00000000 10100000 00010111` |

**练习**：练习二进制到十六进制。这些值是 32 位无符号整数。

| 二进制                                | 十六进制     |
| ------------------------------------- | ------------ |
| `11111111 11111111 11111111 11111111` | `0xffffffff` |
| `00000010 00000000 10000000 00000000` | `0x02008000` |
| `00000000 00000000 00011111 11100000` | `0x00001fe0` |
| `11111000 01111111 00000000 00000000` | `0xf87f0000` |

没有必要记住整个 ASCII 表，但了解几个关键字符的位置将会很有用。使用 `man ascii` 学习三个字符“0”，“A”，“a”的代码，并使用它们进行以下转换。

**练习**：练习 ASCII 到十六进制。这些值是字符类型。

| ASCII | 十六进制                                                     |
| ----- | ------------------------------------------------------------ |
| `'I'` | `0x49`<br />'A': 65, A, B, C, D, E, F, G, H, I = 'A' + 8 = 73 = 64 + 8 + 1 = 2^6 + 2^3 + 2^0<br />01001001 |
| `'5'` | `0x35`<br />'0' : 48, 48 + 5 = 53, 53 = 32 + 16 + 4 + 1 = 2^5 + 2^4 + 2^2  + 2^0<br />00110101 |
| `'d'` | `0x64`<br />'a': 97, 'd': a, b, c, d = 'a' + 3 = 100<br />100 = 64 + 32 + 4 = 2^6 + 2^5 + 2^2, 01100100 |

你还应该了解各种独特的无符号和有符号值的位模式。

**练习**：每个常量的位模式是什么？

| 值         | 二进制                             |
| ---------- | ---------------------------------- |
| `-1`       | `11111111111111111111111111111111` |
| `INT_MAX`  | `0111111111111111111111111111111`  |
| `INT_MIN`  | `10000000000000000000000000000000` |
| `UINT_MAX` | `11111111111111111111111111111111` |

### GDB 工具

```sh
$ gdb
(gdb) p 68
$1 = 68
(gdb) p/x 68
$2 = 44
(gdb) p/c 68
$3 = 'D'
(gdb) p/t 68
$4 = 1000100
(gdb) p 45 << 1
$5 = 90
```

### LLDB 工具

-   The LLDB Debugger, <https://lldb.llvm.org/>

### 位运算

你应该了解 C 语言中所有六个**位运算符**的行为：`& | ~ ^ << >>`。

**练习**：通过评估以下表达式来测试你对位运算的理解。为了简便，这里仅使用 `char` 来演示，对于 `int` 等其他类型，位运算的逻辑是一致的。

| 表达式                              | 值                  |
| ----------------------------------- | ------------------- |
| `unsigned char this, that, result;` |                     |
| `this = 0xf0`                       | `11110000`          |
| `that = 0x55`                       | `01010101`          |
| `result = this & that`              | `01010000` = `0x50` |
| `result = this `|` that`            | `11110101` = `0xf5` |
| `result = this ^ that`              | `10100101` = `0xa5` |
| `result = ~this`                    | `00001111` = `0x0f` |
| `result = this >> 2`                | `00111100` = `0x3c` |
| `result = that << 1`                | `10101010` = `0xaa` |

### 位向量

位向量是一个独立的布尔值集合，用一个无符号值表示。一个特定位表示一个特定成员，如果该位在位向量中打开，则该位向量集合包含该成员。更改特定位的值可以在位向量集合中添加或删除某个成员。对位向量进行操作时，你可以综合应用位掩码和位运算来隔离某些指定的位。

位运算常用于测试、设置和清除指定的位，并执行一些简单的设置操作。这些经典的位运算惯用法值得我们了解并掌握！

**练习**：你知道如何操作位向量吗？用下面的练习测试一下。假设 `mine` 和 `yours` 都是无符号整数。术语“低”和“高”，“最右”和“最左”，是指“较低有效位”和“较高有效位”。

| 任务                                             | C 表达式                                                     |
| ------------------------------------------------ | ------------------------------------------------------------ |
| 测试 `mine` 最低位是否打开（1 表示开，0 表示关） | `(mine & 1) != 0`                                            |
| 将 `yours` 最低位打开或置 1                      | `yours = yours | 1`                                          |
| 将 `yours` 最低位关闭或置 0                      | 错误：`yours & 0`<br />正确：`yours & (UINT_MAX << 1)`<br />正确：`yours & (~1)` |
| 切换 `yours` 最低位                              | `yours = yours ^ 1`                                          |
| 将 `mine` 和 `yours` 作并集                      | `mine = mine | yours`                                        |
| 将 `mine` 和 `yours` 作交集                      | `mine = mine & yours`                                        |
| 将 `mine` 和 `yours` 作差集                      | 错误：`mine ^ yours`<br />正确：`mine = mine & (~yours)`     |

### 位掩码

当访问单个位时，使用掩码来隔离指定的位，例如，`mine & 1` 中的掩码 `1` 用于测试最低有效位。更改掩码可以更改操作的位，例如，`mine & 2` 中的掩码 `2` 用于测试第二个最低有效位。将其他位包含到掩码中可以影响整个位组，例如，`mine ^= 0x7` 可以切换三个最低位。

**练习**：假设 `mine` 是一个无符号整数，用作位向量。对于以下任务，写出 C 语言的表达式。

| 任务                                  | C 表达式                                         |
| ------------------------------------- | ------------------------------------------------ |
| 测试 `mine` 最低 2 个位是否有打开的位 | `(mine & 0x3) != 0`                              |
| 测试 `mine` 最低 2 个位是否全部打开   | `(mine & 0x3) == 0x3`                            |
| 将 `mine` 最低 8 个位打开             | `mine = mine | 0xff`                             |
| 将 `mine` 的所有位关闭                | 错误：`mine = mine | 0x0`<br />正确：`mine &= 0` |

**常量掩码**应始终以十六进制表示，小十进制整数常量（0，1，...）除外，这是为了增加代码的可读性。对于复杂的掩码，则建议通过构造来表达，而不是硬编码一个魔法数字。你应该练习如何构造复杂的掩码，并在合适的位置使用常量定义（`#define <CONSTANT> <VALUE>`）。

**练习**：给出一个 C 表达式来构造以下每个掩码（32 位无符号整数）。位置值从最低有效位（位置 0）开始计数。

| 任务                          | C 表达式                                                     |
| ----------------------------- | ------------------------------------------------------------ |
| 所有位打开                    | `~0` or `-1`                                                 |
| 位置 `n` 打开，其他位关闭     | `| pow(2, n)`<br />正确：`1 << n`                            |
| 最低 `n` 个位打开，其他位关闭 | `| UINT_MAX >> (32 - n)`<br />正确：`(1 << n) - 1`           |
| 最高位打开，其他位关闭        | `| ~1`<br />正确：`(1U << 31)`                               |
| 最高 `n` 个位打开，其他位关闭 | `| UINT_MAX << (32 - n)`<br />正确：`(1U << n) - 1`<br />正确：`(~0 << (32 - n))` |

### 其他

最后介绍一些稍微花哨的位运算。这些表达式可能很难推理，但通过这些练习可以更好地让你理解位运算以及补码等概念。

| 表达式         | 结果                                                         |
| -------------- | ------------------------------------------------------------ |
| `1 << x`       | $2^X$                                                        |
| `~x + 1`       | $-x$                                                         |
| `x >> 31`      | 判断正负：<br />`res == 1 ` => x 是负数<br />`res == 0` => x 是正数 |
| `x &= (x - 1)` | 将 x 最低的 on 位关闭                                        |
| `(x ^ y) < 0`  | 判断 x 和 y 是否异号（符号相异）                             |

## 2. 圆整

打开 `round.c` 文件，查看函数 `is_power_of_2` 和 `round_up` 的代码。

-   `is_power_of_2` 利用了 2 的幂的位模式的独特属性。还记得该属性是什么吗？该值与其前一个值（`num - 1`）之间的关系（就两个值共有的位而言）是什么？代码如何利用这两个属性来确定给定值是否为 2 的幂？

-   `round_up` 返回第一个参数圆整后的值，圆整算法是向上舍入到第二个参数最近的倍数。首先考虑一般情况，当倍数不是 2 的幂时，如何使用算术运算向上舍入到下一个倍数？现在考虑倍数为 2 的幂的特殊情况，如何利用位运算取代低效的乘法/除法？

    函数 `round_up` 的计算过程类似于 Excel 中的 `CEILING` 函数，参考：[Round a number up to nearest multiple - exceljet.net](https://exceljet.net/formulas/round-a-number-up-to-nearest-multiple#:~:text=To round a number up to the nearest,formula in cell D6 is%3A %3D CEILING (B6%2CC6))。

这些函数表明，数字的表示只是一种位模式，了解不同表示形式的优势，可以更方便地选择算术运算或位运算，以提高计算效率。

***表 - 2 的幂及其完整二进制位模式***

| 幂   | 2 的幂 | 二进制位模式        |
| ---- | ------ | ------------------- |
| 0    | 1      | 0000 0000 0000 0001 |
| 1    | 2      | 0000 0000 0000 0010 |
| 2    | 4      | 0000 0000 0000 0100 |
| 3    | 8      | 0000 0000 0000 1000 |
| 4    | 16     | 0000 0000 0001 0000 |
| 5    | 32     | 0000 0000 0010 0000 |
| 6    | 64     | 0000 0000 0100 0000 |
| 7    | 128    | 0000 0000 1000 0000 |
| 8    | 256    | 0000 0001 0000 0000 |
| 9    | 512    | 0000 0010 0000 0000 |
| 10   | 1024   | 0000 0100 0000 0000 |

***表 - 16、15和按位与操作结果的二进制位模式***

| 十进制数  | 二进制位模式 |
| --------- | ------------ |
| 16        | `0001 0000`  |
| 15        | `0000 1111`  |
| `16 & 15` | `0000 0000`  |

***结论***

表达式 `num & (num - 1) == 0` 可用于检查一个整数 `num` 是否具有二进制表示中仅有一个位为1的特性，如果成立，那么 `num` 是一个2的幂或0。

---

| Decimal Value     | Binary Representation (32 bits)     |
| ----------------- | ----------------------------------- |
| `multiple`        | 1 followed by 0s (e.g., 16, 32, 64) |
| `multiple - 1`    | All 1s except the leftmost bit      |
| `~(multiple - 1)` | All 0s except the leftmost bit      |

| Decimal Value                   | Binary Representation (32 bits)    |
| ------------------------------- | ---------------------------------- |
| 16                              | `00000000000000000000000000010000` |
| 15                              | `00000000000000000000000000001111` |
| ~(15) = -16 (in 2's complement) | `11111111111111111111111111110000` |

```c title="round.c"
/**
 * File: round.c
 * --
 * Code passages to read as part of lab1.
 */

#include <stdbool.h> // for bool
#include <stdio.h>

/**
 * Function: is_power_of_2
 * ------------------------
 * Checks if a given unsigned integer is a power of 2.
 * 
 * num: The unsigned integer to be checked.
 * 
 * Returns: True if num is a power of 2, false otherwise.
 */
bool is_power_of_2(unsigned int num) {
    // The expression `num & (num - 1) == 0` implies that num satisfies one of the following conditions:
    // 1. num is 0.
    // 2. num is a power of 2.
    return num != 0 && (num & (num - 1)) == 0;
}

/**
 * What is special about powers of 2 that allow rounding via bitwise ops
 * in place of the more expensive multiply/divide used for general case?
 */
unsigned int round_up(unsigned int value, unsigned int multiple) {
    if (!is_power_of_2(multiple)) {
        return ((value + multiple - 1) / multiple) * multiple;
    } else {
        return (value + multiple - 1) & ~(multiple - 1);
    }
}

// Function to print the result of rounding up a value to the nearest multiple.
void print_round_up(unsigned int value, unsigned int multiple) {
    // Print the function call with input values.
    printf("round_up(%u, %u) = %u\n", value, multiple, round_up(value, multiple));
}

int main(int argc, char* argv[]) {
    print_round_up(2, 7);
    print_round_up(6, 5);
    print_round_up(100, 32);
    print_round_up(4, 4);
    return 0;
}

```

```c title="version 2"
#include <stdbool.h> // 包含 bool 类型
#include <stdio.h>

// 函数原型
bool is_power_of_2(unsigned int num);
unsigned int round_up(unsigned int value, unsigned int multiple);
void print_round_up(unsigned int value, unsigned int multiple);

int main(int argc, char* argv[]) {
    print_round_up(2, 7);
    print_round_up(6, 5);
    print_round_up(100, 32);
    print_round_up(4, 4);
    return 0;
}

// 检查一个数是否是2的幂
bool is_power_of_2(unsigned int num) {
    return num != 0 && (num & (num - 1)) == 0;
}

// 根据指定倍数将值向上舍入
unsigned int round_up(unsigned int value, unsigned int multiple) {
    if (!is_power_of_2(multiple)) {
        // 对于非2的幂倍数，使用除法和乘法来舍入
        return ((value + multiple - 1) / multiple) * multiple;
    } else {
        // 对于2的幂倍数，使用位运算来舍入
        return (value + multiple - 1) & ~(multiple - 1);
    }
}

// 打印舍入结果
void print_round_up(unsigned int value, unsigned int multiple) {
    printf("round_up(%u, %u) = %u\n", value, multiple, round_up(value, multiple));
}

```

```c title="print_binary.c"
#include <stdio.h> // 包含 printf 函数的头文件

void print_binary(unsigned int num) {
    if (num > 1) {
        print_binary(num >> 1); // 递归调用，右移一位
    }
    printf("%d", num & 1); // 打印最低位的二进制值
}

int main() {
    unsigned int i, j;
    i = 0;
    j = i - 1;

    printf("i (binary): ");
    print_binary(i);
    printf("\n");

    printf("j (binary): ");
    print_binary(j);
    printf("\n");

    return 0;
}

```

Output

```
i (binary): 0
j (binary): 11111111111111111111111111111111
```

| i    | `unsigned int` 0          |
| ---- | ------------------------- |
| j    | `unsigned int` 4294967295 |

## 3. 中点计算

## 4. 工作流练习

-   [ ] GDB and Debugging, <https://web.stanford.edu/class/archive/cs/cs107/cs107.1242/resources/gdb.html>

现在轮到你自己编写一些位运算代码并练习使用 Unix/Linux 开发工具了！

程序 `parity` 输出其命令行参数的奇偶校验。如果值的位模式中存在奇数个 `1`，则该值为奇校验；否则，为偶校验。通过运行 `samples/parity_soln` 程序测试不同的参数，来确认你对奇偶校验的理解。

假设 `parity.c` 中的代码是你的同事编写的，他声称它是“完整的”，但在出门的路上，他们发现了一些未修复的错误。你的任务是使用 `sanitycheck` 和 `gdb` 调试器测试并调试该程序，使其真正的完整。

关于 GDB，[CS107 GDB and Debugging](https://web.stanford.edu/class/archive/cs/cs107/cs107.1206/resources/gdb) 是一个很好的参考。

-   使用 `make` 构建程序并尝试使用不同的值运行 `./parity` 几次。呃哦！似乎它认为每个值都是奇校验！有没有测试出哪些值具有偶校验？
-   在调试器下运行 `gdb parity`。可以使用 `list` 命令打印出 GDB 正在检查的部分代码。使用 `list compute_parity` 打印 `compute_parity` 函数并记下更新循环内结果的行号。
-   接下来，在该行上设置一个断点，以便在 GDB 中运行程序时，可以在执行该行之前暂停并等待进一步的指令。可以通过键入 `break XXX` 来添加断点，其中 `XXX` 是函数名称或行号。
-   在 `gdb` 下运行程序，输入 `run`，然后输入命令行参数（用于检查的数字）。 GDB 将运行程序并在断点处暂停。请注意，断点所在的行并没有执行。当停在断点处时，打印 `result` 的值，可以使用 `p result`（命令 `print` 的缩写）进行打印。咦？`result` 似乎包含了一个垃圾值。它竟然从未初始化过！这合法吗？在 Java 等具有安全意识的语言中，编译器可能会防止这种情况发生。
-   执行 `make clean` 并 `make` 检查下有没有构建警告，此处你应该看不到 `gcc` 的任何提醒。在运行时，该变量将使用其内存中剩余的任何垃圾值。这给了我们一个经验教训——在自由放任的 C 语言世界中，你需要提高自己的警惕性。
-   修复该程序、构建并重新运行。参考作业 0 中 `sanitycheck` 的使用，确保你的代码可以通过所有的默认测试。

既然更正后的程序通过了 `sanitycheck` 检查，那么就可以结束了，对吧？没那么简单~请记住，`sanitycheck` 检查的是否彻底取决于其测试用例。默认的测试用例仅仅是一个开始；你可以使用 `custom_tests` 添加自己的测试，以便更全面地验证该程序。

-   仔细阅读 `sanitycheck` 默认的检查结果。它包括多少个不同的测试用例？这些测试用例是什么？
-   使用 `custom_tests` 中的附加测试进一步检查该程序。可以发现其中一项测试由于超时而失败，但这并不是说该程序效率较低，而是发生了无限循环（死循环）。
-   调试无限循环的最佳方法是在 GDB 下运行程序，一旦停止，使用 `Control-C` 停止程序。 GDB 将显示程序停止时正在执行的位置，可以方便地查看具体发生了什么。
-   一起试一试：在 GDB 中以负参数运行 `parity` 程序并让它停止响应。输入 `Control-C` 中断程序，并使用 `backtrace` 命令查看程序正在执行的位置——此时将显示当前的调用栈，可以查看当前正在执行函数。
-   在循环中步进执行 `step` 并收集信息，以便诊断循环未正确退出的原因。
-   一旦你查出问题的原因，就可以编辑代码来修复它。重新构建并测试，直到所有的错误都被消除为止。

```c title="parity.c"
/**
 * File: parity.c
 * --
 * Read lab1 writeup for more information.
 */

#include <error.h>
#include <stdio.h>
#include <stdlib.h>

int compute_parity(int x) {
    int result;

    while (x != 0) {
        // invert result if lsb is on
        result ^= (x & 1);

        // shift bits down
        x = x >> 1;
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        error(1, 0, "missing argument");
    }
    int val = atoi(argv[1]);

    /**
     * Note for below: a "ternary" operator has the form EXPRESSION ? IF_TRUE : IF_FALSE
     * If the expression is true, it evaluates to the value in IF_TRUE.  Otherwise, it
     * evaluates to the value in IF_FALSE.  For instance, below, if compute_parity(val)
     * is true, the third parameter will evaluate to "odd".  Otherwise, it will be "even".
     */
    printf("%d has %s parity\n", val, compute_parity(val) ? "odd" : "even");
    return 0;
}

```

---

```sh
# help
help
help list

# list
l
list main

# info
info
info breakpoints
info functions

# run
run

# break
b
break
b filename:linenum

# next
n

# clear

# where
where

# step, step into a function
s
step

# finish

# delete
delete breakpointnum

# print
p valname

# up
up

# down
down

# disassemble
disassemble
disas

# T UI mode: control x + control a
tui e
# control l: refresh the screen

# quit
quit
```

