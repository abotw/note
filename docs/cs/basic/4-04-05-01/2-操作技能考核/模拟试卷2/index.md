# 操作技能考核：模拟试卷 2

-   [计算机程序设计员实操操作步骤.mp4](../res/计算机程序设计员实操操作步骤.mp4)
-   [模拟试卷2](../res/模拟试卷2.rar)

-   [2-Practice-Test-Paper](./2-Practice-Test-Paper.pdf)
-   [2-Marking-Scheme](./2-Marking-Scheme.pdf)

## 试题 1. 程序改错题（30分）：奇偶数累加和

### 1. 具体要求

1.   在电脑桌面建立考生文件夹，文件夹名称为考生准考证号（如：`20230001`）。在考生文件夹中创建1个 `第1题.docx` 文件；
2.   将接收的 Java_exam 导入到 eclipse 中，在 src 源文件夹中找到 modi 包，打开 modi 包中 `Modi.java` 文件。
     1.   `Modi.java`： 该程序用于实现输入一个整数 n (1 <= n <= 1000)，如果 n 是奇数，输出 1 + 3 + 5 + ... + n 的值。如果 n 是偶数，则输出 2 + 4 + ... + n。程序中共有 10 处错误，错误所在行的上方标注有 `//---------found---------`。修改程序中的错误并使得其正确运行。

3.   将程序运行截图添加到 `第1题.docx` 文件中，并保存。

### 2. 分析

```
n: [1, 1000]
n is odd:
		1 + 3 + 5 + ... + n
n id even:
		2 + 4 + 6 + ... + n
```

### 3. 题目源码和解答

```java title="src/modi/Modi.java" linenums="1" hl_lines="4 10 16 18 23 25 29 31 33 36"
package modi;
import java.util.Scanner;
//-----------found---------------
public Modi { // 1. `public class Modi {`
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner r = new Scanner(System.in);
        System.out.println("请输入n的值：");
        //-----------found---------------
        if (r.hasNextInt()) { // 2. `if (!r.hasNextInt())`
            System.out.println("error input");
            return;
        }
        int n = r.nextInt();
        //-----------found---------------
        int sum = 1; // 3. `int sum = 0;`
        //-----------found---------------
        if (n < 1 && n > 1000) { // 4. `if (n < 1 || n > 1000) {`
            System.out.println("error input");
            return;
        }
        //-----------found---------------
        if (n % 2 = 0) // 5. `if (n % 2 == 0)`
            //-----------found---------------
            for (int i = 2; i <= n; i++) // 6. `for (int i = 2; i <= n; i += 2)`
                sum += i;
        else
            //-----------found---------------
            for (int i; i <= n; i += 2) // 7. `for (int i = 1; i <= n; i += 2)`
                //-----------found---------------
                sum = i; // 8. `sum += i;`
        //-----------found---------------
        System.out.printf(sum) // 9. `System.out.print(sum);` or `System.out.println(sum);`
    }
    //-----------found---------------
    // 10. `}`
```

``` java title="Optimized code" linenums="1"
package modi;
import java.util.Scanner;

/**
 * This program calculates the sum of numbers from 1 to n based on user input.
 */
public class Modi {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the value of n:");

        if (!scanner.hasNextInt()) {
            System.out.println("Error: Invalid input. Please enter an integer.");
            return;
        }

        int n = scanner.nextInt();
        int sum = 0;

        if (n < 1 || n > 1000) {
            System.out.println("Error: Input should be between 1 and 1000.");
            return;
        }

        if (n % 2 == 0) {
            // Sum even numbers from 2 to n
            for (int i = 2; i <= n; i += 2) {
                sum += i;
            }
        } else {
            // Sum odd numbers from 1 to n
            for (int i = 1; i <= n; i += 2) {
                sum += i;
            }
        }

        System.out.println("The sum of numbers from 1 to " + n + " is: " + sum);
    }
}

```

### 4. 参考答案

程序改错题（程序错误每处3分，10处。共30分）

| #    | Answer                            |
| ---- | --------------------------------- |
| 1    | `class`                           |
| 2    | `!r.hasNextInt()`                 |
| 3    | `int sum = 0`                     |
| 4    | `if (n < 1 || n > 1000)`          |
| 5    | `if (n % 2 == 0)`                 |
| 6    | `for (int i = 2; i <= n; i += 2)` |
| 7    | `for (int i = 1; i <= n; i += 2)` |
| 8    | `sum = sum + i;` or `sum += i;`   |
| 9    | `System.out.print(sum);`          |
| 10   | `}`                               |

### 5. 补充

#### Windows Command Prompt

-   [x] **Windows Command Prompt in 15 Minutes**, <https://www.cs.princeton.edu/courses/archive/spr05/cos126/cmd-prompt.html>
-   [x] **Windows Command Prompt Cheatsheet**, <https://www.cs.columbia.edu/~sedwards/classes/2015/1102-fall/Command%20Prompt%20Cheatsheet.pdf>
-   [ ] <https://www.cs.princeton.edu/courses/archive/spr17/cos126/precepts/cmdline.html>

#### java.util.Scanner

``` java
import java.util.Scanner;

Scanner scanner = new Scanner(System.in);
int myInt = scanner.nextInt();
String myString = scanner.next();
scanner.close()
```

| Method Type | Return Value | Method Signature              | Description                                                  |
| ----------- | ------------ | ----------------------------- | ------------------------------------------------------------ |
| Constructor | -            | `Scanner(InputStream source)` | Creates(Constructs) a `Scanner` object and associates it with the specified `InputStream`, such as `System.in`, for reading data from the stream. |
| Instance    | `boolean`    | `boolean hasNext()`           | Returns `true` if there is another token in the input.       |
| Instance    | `boolean`    | `boolean hasNextLine()`       | Returns `true` if there is another line in the input.        |
| Instance    | `String`     | `String next()`               | Finds and returns the next complete token from the input.    |
| Instance    | `String`     | `String nextLine()`           | Advances the `Scanner` past the current line and returns the input that was skipped. |
| Instance    | `int`        | `int nextInt()`               | Scans the next token of the input as an integer.             |
| Instance    | `double`     | `double nextDouble()`         | Scans the next token of the input as a double.               |
| Instance    | `boolean`    | `boolean nextBoolean()`       | Scans the next token of the input as a boolean value.        |
| Instance    | -            | `void close()`                | Closes the `Scanner`.                                        |

#### System.in

``` java
import java.util.Scanner;

public class UserInputExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please enter your name: ");
        String name = scanner.nextLine();

        System.out.print("Please enter your age: ");
        int age = scanner.nextInt();

        System.out.println("Hello, " + name + "! You are " + age + " years old.");
    }
}

```

### 6. 参考

## 试题 2. 程序填空题（30分）：冒泡排序

### 1. 具体要求

1.   在考生文件夹中创建1个 `第2题.docx` 文件；
2.   blank 包中 `Blank.java` 文件实现使用冒泡排序法对一维数组排序。程序中共有 6 处语句填空（填空处上方一行标注有 `//----------blank---------` ）。在填空处填写上正确的语句并使得其正确运行。
3.   将程序运行截图添加到 `第2题.docx` 文件中，并保存。

### 2. 分析

### 3. 题目源码和解答

```java title="src/blank/Blank.java" linenums="1" hl_lines="4 16 18 20 23 30"
package blank;
public class Blank {
    //----------------blank---------------
    public static void main(___(1)___) { // 1. `String[] args`
        int[] nums = {
            56,
            89,
            12,
            45,
            88,
            99,
            745,
            7
        }; // 冒泡排序数列
        //----------------blank---------------
        for (int i = 0; i < ___(2)___; i++) { // 2. `nums.length - 1 ` //外循环控制轮数，比较轮数即数列的长度减1；
            //----------------blank---------------
            for (int j = 0; j < ___(3)___; j++) { // 3. `nums.length - 1 - i` // 内循环控制次数，即每一轮比较的次数；
                //----------------blank---------------
                if (___(4)___) { // 4. `nums[j] > nums[j + 1]`
                    nums[j] = nums[j] + nums[j + 1];
                    //----------------blank---------------
                    nums[j + 1] = ___(5)___; // 5. `nums[j] - nums[j + 1]`
                    nums[j] = nums[j] - nums[j + 1];
                }
            }
        }
        System.out.print("冒泡排序法即小到大排列是：");
        //----------------blank---------------
        for (___(6)___) { // 6. `int n : nums`
            System.out.print(n + "\n");
        }
        System.out.println();
    }
}

```

``` java title="Optimized code" linenums="1"
package sorting;

/**
 * This program demonstrates the Bubble Sort algorithm to sort an array of integers in ascending order.
 */
public class BubbleSort {

    /**
     * Sorts an array of integers in ascending order using the Bubble Sort algorithm.
     *
     * @param arr The array to be sorted.
     */
    public static void bubbleSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false; // Flag to optimize by checking if any elements were swapped

            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no two elements were swapped in the inner loop, the array is already sorted
            if (!swapped) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = {56, 89, 12, 45, 88, 99, 745, 7}; // Array to be sorted using Bubble Sort

        // Perform Bubble Sort
        bubbleSort(nums);

        System.out.print("Sorted array in ascending order: ");
        for (int n : nums) {
            System.out.print(n + " ");
        }
        System.out.println();
    }
}

```

### 4. 参考答案

程序填空题（程序填空每空5分，6空。共30分）

| #    | Answer                  |
| ---- | ----------------------- |
| 1    | `String[] args`         |
| 2    | `nums.length - 1`       |
| 3    | `nums.length - 1 - i`   |
| 4    | `nums[j] > nums[j + 1]` |
| 5    | `nums[j] - nums[j + 1]` |
| 6    | `int n : nums`          |

### 5. 补充

#### the `for-each` loop || enhanced for loop

The "for-each" loop is **a syntax structure** in Java used for **iterating over elements** in an array, collection, or other *iterable objects*. It is often referred to as the "enhanced for loop."

``` java
for (elementType variableName : iterableObject) {
    // Perform operations on each element here
}

```

#### Typical array-processing code

![Typical array-processing code](https://introcs.cs.princeton.edu/java/11cheatsheet/images/array-examples.png)

#### Common array methods

| Return Type | Method Signature             | Description                                                  |
| ----------- | ---------------------------- | ------------------------------------------------------------ |
| `int`       | `length`                     | Returns the length (number of elements) of the array.        |
| `int`       | `binarySearch(array, key)`   | Searches for a specified key in the array using binary search. |
| `boolean`   | `equals(array1, array2)`     | Compares two arrays for equality.                            |
| `void`      | `fill(array, value)`         | Fills the array with the specified value.                    |
| `void`      | `sort(array)`                | Sorts the elements in the array in ascending order.          |
| `void`      | `copyOf(original, length)`   | Copies the specified array to a new array of the given length. |
| `String`    | `toString(array)`            | Returns a string representation of the array.                |
| `boolean`   | `deepEquals(array1, array2)` | Compares two arrays for deep equality.                       |

#### Exchange two variables

**方法**

=== "1. Using a Temporary Variable"

    ```java
    public class SwapVariables {
        public static void main(String[] args) {
            int a = 5;
            int b = 10;
    
            System.out.println("Before swapping: a = " + a + ", b = " + b);
    
            // Swap the values using a temporary variable
            int temp = a;
            a = b;
            b = temp;
    
            System.out.println("After swapping: a = " + a + ", b = " + b);
        }
    }
    
    ```

=== "2. Using Arithmetic Operators"

    ```java
    public class SwapVariables {
        public static void main(String[] args) {
            int a = 5;
            int b = 10;
    
            System.out.println("Before swapping: a = " + a + ", b = " + b);
    
            a = a + b; // a = a + b
            b = a - b; // b = (a + b) - b = a
            a = a - b; // a = (a + b) - a = b
    
            System.out.println("After swapping: a = " + a + ", b = " + b);
        }
    }
    
    ```

=== "3. Using XOR Operator"

    ```java
    public class SwapVariables {
        public static void main(String[] args) {
            int a = 5;
            int b = 10;
    
            System.out.println("Before swapping: a = " + a + ", b = " + b);
    
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
    
            System.out.println("After swapping: a = " + a + ", b = " + b);
        }
    }
    
    ```

#### Bubble Sort

=== "C"

    ```c linenums="1"
    #include <stdio.h>
    
    /**
     * Swaps two elements in an integer array.
     *
     * This function swaps the elements at positions 'a' and 'b' in the given array.
     *
     * @param arr The integer array.
     * @param a   The index of the first element to be swapped.
     * @param b   The index of the second element to be swapped.
     */
    void swap(int arr[], int a, int b)
    {
        int temp;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    
    int main(void)
    {
        int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int arrSize = sizeof(arr) / sizeof(arr[0]);
    
        // Perform bubble sort algorithm
        for (int i = arrSize - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                // Compare adjacent elements and swap if necessary
                if (arr[j] > arr[j + 1])
                {
                    swap(arr, j, j + 1);
                }
            }
        }
    
        // Print the sorted array
        for (int i = 0; i < arrSize; i++)
        {
            printf("%-4d", arr[i]);
        }
    
        return 0;
    }
    
    ```

### 6. 参考

-   11.3 冒泡排序，*Hello 算法*，<https://www.hello-algo.com/chapter_sorting/bubble_sort/>

## 试题 3. 程序设计题（40分）：检查密码是否符合规则

### 1. 具体要求

1.   在考生文件夹中创建1个 `第3题.docx` 文件；

2.   在 src 源文件夹中找到 prog 包，打开并编写 prog 包中 `Prog.java` 文件，将程序中标注有 `//--------prog--------` 的两个函数按要求编写完整并使得其正确运行。函数功能是检测字符串是否是一个有效密码。密码具体要求如下:

     1.   密码必须至少 8 位字符

     2.   密码仅包含字母和数字

     3.   密码必须包含至少两个数字

          提示用户输入密码后，如果符合规则显示 `Valid Password`，否则显示 `Invalid Password`。 


3.   将程序运行截图添加到 `第3题.docx` 文件中，并保存。

4.   将修改后的 Java_exam 工程导出，保存到考生文件夹中。

### 2. 分析

| 类   | `Prog`                                                       |
| ---- | ------------------------------------------------------------ |
| 方法 | `public static void main(String[] args)`                     |
|      | 主函数，用于接收用户输入密码并显示结果。                     |
|      | `public static boolean isPasswordValid(String password)`     |
|      | 检查密码是否符合规则的函数。                                 |
|      | `public static boolean isLengthMoreThanEight(String password)` |
|      | 检查密码长度是否至少为8个字符。                              |
|      | `public static boolean isOnlyContainsLetterAndDigit(String password)` |
|      | 检查密码是否仅包含字母和数字。                               |
|      | `private static boolean isDigit(char c)`                     |
|      | 检查字符是否为数字。                                         |
|      | `private static boolean isLetter(char c)`                    |
|      | 检查字符是否为字母。                                         |
|      | `public static boolean isContainsMoreThanTwoDigits(String password)` |
|      | 检查密码是否包含至少两个数字。                               |
|      | `private static int getDigitCount(String password)`          |
|      | 计算密码中包含的数字个数。                                   |

### 3. 题目源码和解答

```java title="src/prog/Prog.java" linenums="1" hl_lines="22-24 58-65"
package prog;
import java.util.Scanner;

public class Prog {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a password:");
        String password = scanner.nextLine();
        if (isPasswordValid(password)) {
            System.out.println("Valid Password");
        } else {
            System.out.println("Invalid Password");
        }
    }

    // --------------------Prog----------------------
    // 判断密码长度、密码组成和密码数字个数是否同时满足，同时满足则为真，否则为假
    // public static boolean isPasswordValid(String password) {
    // }

    public static boolean isPasswordValid(String password) {
        return isLengthMoreThanEight(password) && isOnlyContainsLetterAndDigit(password) && isContainsMoreThanTwoDigits(password);
    }

    public static boolean isLengthMoreThanEight(String password) {
        return password.length() >= 8;
    }

    public static boolean isOnlyContainsLetterAndDigit(String password) {
        for (int i = 0; i < password.length(); i++) {
            char c = password.charAt(i);
            if (!(isLetter(c) || isDigit(c)))
                return false;
            else
                return true;
        }
        return false;
    }

    private static boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    private static boolean isLetter(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    public static boolean isContainsMoreThanTwoDigits(String password) {
        return getDigitCount(password) >= 2;
    }

    // --------------------Prog----------------------
    // 计算密码中包含数字个数
    // private static int getDigitCount(String password) {
    // }

    private static int getDigitCount(String password) {
        int count = 0;
        for (int i = 0; i < password.length(); i++) {
            if (isDigit(password.charAt(i))
                count++;
        }
        return count;
    }

}

```

```java title="Optimized code" linenums="1"
package prog;
import java.util.Scanner;

/**
 * This program checks whether a password meets specific criteria.
 */
public class Prog {

    /**
     * The main method for user input and displaying the result.
     *
     * @param args The command-line arguments (not used).
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a password: ");
        String password = scanner.nextLine();
        if (isPasswordValid(password)) {
            System.out.println("Valid Password");
        } else {
            System.out.println("Invalid Password");
        }
    }

    /**
     * Checks if a password is valid according to specific criteria.
     *
     * @param password The password to be checked.
     * @return True if the password is valid, false otherwise.
     */
    public static boolean isPasswordValid(String password) {
        return isLengthMoreThanEight(password) && isOnlyContainsLetterAndDigit(password) && isContainsMoreThanTwoDigits(password);
    }

    /**
     * Checks if the password length is at least 8 characters.
     *
     * @param password The password to be checked.
     * @return True if the password length is greater than or equal to 8, false otherwise.
     */
    public static boolean isLengthMoreThanEight(String password) {
        return password.length() >= 8;
    }

    /**
     * Checks if the password contains only letters and digits.
     *
     * @param password The password to be checked.
     * @return True if the password consists of only letters and digits, false otherwise.
     */
    public static boolean isOnlyContainsLetterAndDigit(String password) {
        for (int i = 0; i < password.length(); i++) {
            char c = password.charAt(i);
            if (!(isLetter(c) || isDigit(c))) {
                return false;
            }
        }
        return true;
    }

    /**
     * Checks if a character is a digit.
     *
     * @param c The character to be checked.
     * @return True if the character is a digit, false otherwise.
     */
    private static boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    /**
     * Checks if a character is a letter.
     *
     * @param c The character to be checked.
     * @return True if the character is a letter, false otherwise.
     */
    private static boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    /**
     * Checks if the password contains more than two digits.
     *
     * @param password The password to be checked.
     * @return True if the password contains more than or equal to two digits, false otherwise.
     */
    public static boolean isContainsMoreThanTwoDigits(String password) {
        return getDigitCount(password) >= 2;
    }

    /**
     * Counts the number of digits in a given password.
     *
     * @param password The password to count digits in.
     * @return The number of digits in the password.
     */
    private static int getDigitCount(String password) {
        int count = 0;
        for (int i = 0; i < password.length(); i++) {
            if (isDigit(password.charAt(i))) {
                count++;
            }
        }
        return count;
    }
}

```

```java title="逻辑结构优化" linenums="1"
package prog;

import java.util.Scanner;

/**
 * A program to check if a password meets certain requirements.
 * 检查密码是否符合某些特定要求
 */
public class Prog {
    /**
     * The main method for user input and displaying the result.
     * `main` 方法：用户输入和结果显示
     *
     * @param args Command-line arguments (not used). 命令行参数
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a password: ");
        String password = scanner.nextLine();

        if (isValidPassword(password)) {
            System.out.println("Valid Password");
        } else {
            System.out.println("Invalid Password");
        }
    }

    /**
     * Checks if a password meets the specified requirements.
     * 检查密码是否符合特定要求
     *
     * @param password The password to be checked. 需要检查的密码
     * @return True if the password is valid, false otherwise. 若密码有效则返回 `true` ，否则返回 `false`
     */
    public static boolean isValidPassword(String password) {
        // Check if the password length is at least 8 characters.
        // 检查密码程度是否至少 8 个字符
        if (password.length() < 8) {
            return false;
        }

        // Check if the password contains only letters (uppercase and lowercase) and digits.
        // 检查密码是否只包含字母（包括大小写）和数字
        if (!password.matches("^[a-zA-Z0-9]+$")) {
            return false;
        }

        // Check if the password contains at least two digits.
        // 检查密码是否至少包含两位数字
        int digitCount = 0;
        for (char c : password.toCharArray()) {
            if (Character.isDigit(c)) {
                digitCount++;
                if (digitCount >= 2) {
                    break;
                }
            }
        }

        return digitCount >= 2;
    }
}

```

### 4. 参考答案

第一个函数：（共20分）

```java
public static boolean isPasswordValid(String password) {
    boolean condition1 = isLengthMoreThanEight(password);          // 4 points
    boolean condition2 = isOnlyContainsLetterAndDigit(password);   // 3 points
    boolean condition3 = isContainsMoreThanTwoDigits(password);     // 3 points

    if (condition1 && condition2 && condition3) {                   // 5 points
        return true;                                                // 2 points
    } else {                                                        // 1 point
        return false;                                               // 2 points
    }
}

```

第二个函数：（共20分）

```java
private static int getDigitCount(String password) {
    int count = 0;                // 2 points
    for (int i = 0; i < password.length(); i++) {              // 6 points
        char c = password.charAt(i);                           // 6 points
        if (isDigit(c)) {                                      // 3 points
            count++;                                           // 2 points
        }
    }
    return count;                // 1 point
}

```



### 5. 补充

#### Java String API

![Java String API](https://introcs.cs.princeton.edu/java/11cheatsheet/images/string-api.png)

| Return Type | Method Signature         | `public class String()`                           |
| ----------- | ------------------------ | ------------------------------------------------- |
| `int`       | `length()`               | number of characters                              |
| `char`      | `charAt(int i)`          | the character at index i                          |
| `boolean`   | `matches(String regexp)` | is this string matched by the regular expression? |
| `char[]`    | `toCharArray()`          | Converts this string to a new character array.    |

#### Java Character API

| Return Type      | Method Signature   | `public final class Character`                    |
| ---------------- | ------------------ | ------------------------------------------------- |
| `static boolean` | `isDigit(char ch)` | Determines if the specified character is a digit. |

### 6. 参考

-   Java® Platform, Standard Edition & Java Development Kit Version 21 API Specification, <https://docs.oracle.com/en/java/javase/21/docs/api/>
-   3.1 Using Data Types, *Introduction to Programming in Java*, <https://introcs.cs.princeton.edu/java/31datatype/>
