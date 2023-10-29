# 作业 1. 有趣的位

## 🔗 快速链接

-   <https://cs102.stickmind.com/reader/topic_1/assign_1.html>
-   <https://web.stanford.edu/class/archive/cs/cs107/cs107.1206/assign1/>

## 1.

-   two's-complement addition

Your task is to implement the functions below to support saturating addition for the `sat` program.

```
long signed_min(int bitwidth);
long signed_max(int bitwidth);
long sat_add(long operand1, long operand2, int bitwidth);
```

```c
#include <errno.h>
#include <error.h> // Include error.h for error
#include <limits.h>
#include <stdio.h> // Include standard I/O library for printf
#include <stdlib.h> // Include standard library for strtol and errno
#include "samples/prototypes.h"

// 给定一个位的宽度，返回在这个位的宽度下，最大的有符号整数的二进制表示形式是什么样子的
long signed_max(int bitwidth) {
    // TODO: Delete this comment and the next few lines, then implement this function
    (void)bitwidth;
    return 0;
}

long signed_min(int bitwidth) {
    // TODO: Delete this comment and the next few lines, then implement this function
    (void)bitwidth;
    return 0;
}

long sat_add(long operand1, long operand2, int bitwidth) {
    // TODO: Delete this comment and the next few lines, then implement this function
    (void)operand1;
    (void)operand2;
    (void)bitwidth;
    return 0;
}

// ------- DO NOT EDIT ANY CODE BELOW THIS LINE (but do add comments!)  -------

long convert_arg(const char* str, long low, long high, const char* argname) {
    char* end = NULL; // Pointer to track the end of the parsed number
    long n = strtol(str, &end, 0); // Convert the string to a long integer
    // Check if there are characters remaining in the string after conversion
    if (*end != '\0') {
        error(1, 0, "Invalid number '%s'", str);
        // Call the `error` function with arguments:
        // 1: Exit with a non-zero status code => exit(1)
        // 0: Use the default error message for the error code
        // "Invalid number '%s'": Custom error message with the invalid number
    }
    // Check if the number is outside the specified range or if an error occured
    if (n < low || n > high || errno == ERANGE) {
        error(1, 0, "Illegal value %s. %s must be in range [%ld, %ld]", str, argname, low, high);
        // Call the `error` function with arguments:
        // 1: Exit with a non-zero status code => exit(1)
        // 0: Use the default error message for the error code
        // "Illegal value %s. %s must be in range [%ld, %ld]": Custom error message
        // %s, %s, %ld, %ld are placeholders for the values of str, argname, low, and high respectively
    }
    return n; // Return the valid long integer
}

int main(int argc, char* argv[]) {
    // Check if there are fewer than 2 command-line arguments
    if (argc < 2) {
        // error(status, errnum, error_message)
        error(1, 0, "Missing argument. Please specify the bitwidth.");
        // Call the `error` function with arguments:
    		// 1: Exit with a non-zero status code => exit(1)
    		// 0: Use the default error message for this error code
    		// "Missing argument. Please specify the bitwidth.": Custom printf(3)-style error message
    }
  
    // 获取用户输入的 bitwidth
    int bitwidth = convert_arg(argv[1], 4, sizeof(long) * CHAR_BIT, "Bitwidth");
    // 确定在该 bitwidth 下的最大有符号值，和最小无符号值
    long min = signed_min(bitwidth);
    long max = signed_max(bitwidth);

    if (argc < 4) {
        printf("%d-bit signed integer range\n", bitwidth);
        printf("min: %ld   %#018lx\n", min, min);
        printf("max:  %ld   %#018lx\n", max, max);
    } else { // 加法计算
        long sum = convert_arg(argv[2], min, max, "Operand");
        printf("%ld ", sum); // 打印第一个操作数
        for (int i = 3; i < argc; i++) { // 从第 4 个参数开始，持续累加
            long next = convert_arg(argv[i], min, max, "Operand"); // 获取参数
            printf("+ %ld ", next); // 输出参数
            sum = sat_add(sum, next, bitwidth); // 计算累加的结果
        }
        printf("= %ld\n", sum); // 打印最终结果
    }
    return 0;
}
```

There are three important restrictions on the code you write for this problem (these restrictions apply only to this program, and not others):

-   **No relational operators or `math.h` functions**. You are prohibited from making any use of the relational operators. This means no use of `< > <= >=`. You may use `!= ==`. You also should not call any function from the floating point `math.h` library (e.g no `pow`, no `exp2`). These restrictions are intended to guide you to implement the operation via bitwise manipulation. All other operators (arithmetic, logical, bitwise, ...) are fine.
-   **No special cases based on bitwidth.** Whether the value of bitwidth is 4, 64, or something in between, your functions must use one unified code path to handle any/all values of bitwidth without special-case handling. You should not use `if switch ?:` to divide the code into different cases based on the value of bitwidth. This doesn't mean that you can't use conditional logic (such as to separately handle overflow or non-overflow cases), but conditionals that dispatch based on the value of bitwidth or make a special case out of one or more bitwidths are disallowed.
-   **No loops or recursion.** No loops or recursion at all. (In particular, no loop increment by one and stop at max.)

#### `strtol`

-   *参考：<http://cs.uccs.edu/~cchow/pub/rtl/doc/html/susv2/xsh/strtol.html>*

#### `error`

-   *参考：<https://man7.org/linux/man-pages/man3/error.3.html>*

```c
void error(int status, int errnum, const char *format, ...);
```

```
       error() is a general error-reporting function.  It flushes
       stdout, and then outputs to stderr the program name, a colon and
       a space, the message specified by the printf(3)-style format
       string format, and, if errnum is nonzero, a second colon and a
       space followed by the string given by strerror(errnum).  Any
       arguments required for format should follow format in the
       argument list.  The output is terminated by a newline character.

       The program name printed by error() is the value of the global
       variable program_invocation_name(3).  program_invocation_name
       initially has the same value as main()'s argv[0].  The value of
       this variable can be modified to change the output of error().

       If status has a nonzero value, then error() calls exit(3) to
       terminate the program using the given value as the exit status;
       otherwise it returns after printing the error message.
```

-   `error()` = `exit()` + `strerror()` + `printf()`

##### `exit`

-   *参考：<https://man7.org/linux/man-pages/man3/exit.3.html>*
-   *参考：<https://cplusplus.com/reference/cstdlib/exit/>*

```c
#include <stdlib.h>
[[noreturn]] void exit(int status)
```

`status`

Status code.
If this is `0` or [EXIT_SUCCESS](https://cplusplus.com/EXIT_SUCCESS), it indicates success.
If it is [EXIT_FAILURE](https://cplusplus.com/EXIT_FAILURE), it indicates failure.

##### `strerror()`

-   *参考：<https://man7.org/linux/man-pages/man3/strerror.3.html>*
-   *参考：<https://cplusplus.com/reference/cstring/strerror/?kw=strerror>*

```c
char *strerror(int errnum);
```

##### `errno`

-   *参考：<https://cplusplus.com/reference/cerrno/errno/>*

### `long signed_min(int bitwidth);`

-   The `bitwidth` argument is a number between 4 and 64.

### `long signed_max(int bitwidth);`

### `long sat_add(long operand1, long operand2, int bitwidth);`

## 2.

## 3.

---

# 有符号整型

*参考：<https://notfalse.net/20/signed-number-representations>*

*图片来源：<https://www.quora.com/If-an-unsigned-int-is-given-a-negative-value>*

![img](https://qph.cf2.quoracdn.net/main-qimg-4cabb74764db1c20998fce80917b824a)

![img](https://qph.cf2.quoracdn.net/main-qimg-61d7f4581428aa1987f880ab3a78cb8e-lq)

>   ❓ **如何通过二进制位表示正或负？**
>
>   **概念：**
>
>   -   符号位
>   -   MSB (Most Significant Bit) 最高有效位
>
>   目前的解决方案是通过保留一个**符号位**（最高位）来区分正和负，这个位称为**最高有效位** MSB（most significant bit）。

## 1s 的补码（ones' complement ）

通过将正数的所有二进制位进行反转来表示对应的负数，我们可以得到 1s 的补码表示。

这个命名的由来是基于这样的一个事实，对应的正负数相加可以得到全为 1 的二进制位。例如 -1 和 1 相加的二进制位是 1111。

1s 的补码的缺点是有两个用于表示 0 的不同位模式，造成了不必要的浪费。另外，在进行加法操作时，如果进位超过了总体位数，则需要进行循环进位（end-around carry）。例如，

![图片](https://cs102.stickmind.com/reader/topic_1/assets/end-around-carry.png)

目前，1s 的补码表示在数字信号处理领域依然有大量的应用。

## [2s 的补码（two's complement ）](https://cs102.stickmind.com/reader/topic_1/int_rep_pt2.html#2s-的补码twos-complement-)

如果我们想避免循环进位，可以对反转后的位额外进行一次加 1 操作，那么我们就得到了 2s 的补码表示。

例如，+1 二进制表示为 0001，反转后的结果是 1110，然后再进行加 1 操作得到 1111 用于表示 -1；同样，+2 二进制表示为 0010，反转后的结果是 1101，然后再进行加 1 操作得到 1110 用于表示 -2。

下图通过数字轮盘形象地表示了 2s 的补码表示的有符号整型的二进制表示和十进制数字之间的关系，以及有符号整型能够表示的数字范围：

![图片](https://cs102.stickmind.com/reader/topic_1/assets/signed_int.png)

2s 的补码表示是基数补码（Radix Complement）的一个应用。2s 的补码定义可以表述为一个 N 位表示的值的补码，是该值相对于 2N2� 的补码。

名称中的 2 可以理解为 2N2�，例如 4 个位表示的数字系统，2N=16=100002�=16=10000，那么 +5 的补码就是 -5 ，因为 0101(+5) + 1011(-5) = 10000；这样的结果对于其他互补的值同样成立。

2s 的补码表示除了看起复杂，但却有很多优点。

-   对应的正负数相加的结果依然是 0。

    ```
      0101 (+5)         1111  (-1)
    + 1011 (-5)       + 0001  (+1)
      ======            ======
      0000 (0)          0000  (0)
    ```

-   只有一个位模式用于表示 0，避免了浪费。

-   最高有效位 MSB 依然可以用于表示正负号。

-   加法操作逻辑更简单，可以用于任意的正负数组合，不需要循环进位。

    ```
      0010 (+2)         0100  (+4)           0100  (+4)
    + 1011 (-5)       - 0101  (+5)  -->>   + 1011  (-5)
      ======            ======               ======
      1101 (-3)         ????  (??)           1111  (-1)
    ```

>   **🔔 小技巧** 对于二进制表示的数字，如何快速找到其对应的正/负值？
>
>   从右向左，找到第一个 1，将左侧剩下的位全部反转即可。 例如，+2 的位模式为 0010，那么将第一个 1 左侧所有位反转可以得到 1110，即为 -2。

*[MSB]: Most Significant Bit 最高有效位