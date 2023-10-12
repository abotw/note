# 实操题

## 试题 1. 程序改错题（30分）

**具体要求：**

1.   在电脑桌面建立考生文件夹，文件夹名称为考生准考证号（如：20230001）。在考生文件夹中创建 1 个“第 1 题.docx“文件；
2.   将接收的 Java_exam 导入到 eclipse 中，在 src 源文件夹中找到 modi 包，打开 modi 包中 Modi.java 文件；该程序用于实现输入一个整数 n (1 <= n <= 1000)，如果 n 是奇数，输出 1 + 3 + 5 + ... + n 的值。如果 n 是偶数，则输出 2 + 4 + ... + n。程序中共有 10 处错误，错误所在行的上方标注有 `//---------found---------`。修改程序中的错误并使得其正确运行。
3.   将程序运行截图添加到“第 1 题.docx“文件中，并保存。

```
n: [1, 1000]
n is odd:		1 + 3 + 5 + ... + n
n id even:	2 + 4 + 6 + ... + n
```

``` java
package modi;
import java.util.Scanner;

/**
 * This program calculates the sum of numbers from 1 to n based on user input.
 */
public class Modi {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please enter the value of n:");

        if (!scanner.hasNextInt()) {
            System.out.println("Error: Invalid input. Please enter an integer.");
            return;
        }

        int n = scanner.nextInt();

        if (n < 1 || n > 1000) {
            System.out.println("Error: n must be between 1 and 1000 (inclusive).");
            return;
        }

        int sum = 0;

        if (n % 2 == 0) {
            // Sum of even numbers from 2 to n
            for (int i = 2; i <= n; i += 2) {
                sum += i;
            }
        } else {
            // Sum of odd numbers from 1 to n
            for (int i = 1; i <= n; i += 2) {
                sum += i;
            }
        }

        System.out.println("The sum of numbers from 1 to " + n + " is: " + sum);
    }
}

```

### java.util.Scanner

``` java
import java.util.Scanner;

Scanner scanner = new Scanner(System.in);
int myInt = scanner.nextInt();
String myString = scanner.next();
scanner.close()
```

| Method                        | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| `Scanner(InputStream source)` | Creates a `Scanner` object and associates it with the specified input stream, such as `System.in`, for reading data from the stream. |
| `boolean hasNext()`           | Checks if there is a next token and returns `true` if one is available, `false` otherwise. |
| `boolean hasNextLine()`       | Checks if there is a next line of input and returns `true` if one is available, `false` otherwise. |
| `String next()`               | Reads and returns the next token as a string.                |
| `String nextLine()`           | Reads and returns the next line of text as a string.         |
| `int nextInt()`               | Reads the next integer value as an integer.                  |
| `double nextDouble()`         | Reads the next floating-point value as a double.             |
| `boolean nextBoolean()`       | Reads the next boolean value as a boolean.                   |
| `void close()`                | Closes the `Scanner`, releasing associated resources.        |

### System.in

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



## 试题 2. 程序填空题（30分）

**具体要求：**

1.   在考生文件夹中创建 1 个“第 2 题.docx“文件;
2.   blank 包中 Blank.java 文件实现使用冒泡排序法对一维数组排序。程序中共有 6 处语句填空(填空处上方一行标注有 `//----------blank---------` )。在填空处填写上正确的语句并使得其正确运行。
3.   将程序运行截图添加到“第 2 题.docx“文件中，并保存。

``` java
package blank;

/**
 * This program demonstrates the Bubble Sort algorithm to sort an array of integers in ascending order.
 */
public class Blank {

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

    /**
     * Sorts an array of integers in ascending order using the Bubble Sort algorithm.
     *
     * @param arr The array to be sorted.
     */
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;

        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no two elements were swapped in inner loop, the array is already sorted
            if (!swapped) {
                break;
            }
        }
    }
}

```

### the `for-each` loop || enhanced for loop

The "for-each" loop is **a syntax structure** in Java used for **iterating over elements** in an array, collection, or other *iterable objects*. It is often referred to as the "enhanced for loop."

``` java
for (elementType variableName : iterableObject) {
    // Perform operations on each element here
}

```

### Common array methods

| Method                                          | Description                                                  |
| ----------------------------------------------- | ------------------------------------------------------------ |
| `length`                                        | Returns the length (number of elements) of the array.        |
| `clone()`                                       | Creates a shallow copy of the array.                         |
| `copyOf(int[] original, int newLength)`         | Copies the specified array into a new array with the specified length. |
| `copyOfRange(int[] original, int from, int to)` | Copies a range of elements from the original array into a new array. |
| `fill(int[] a, int val)`                        | Assigns the specified value to every element in the array.   |
| `equals(Object a, Object b)`                    | Compares two arrays for equality, element by element.        |
| `sort(int[] a)`                                 | Sorts the array in ascending order.                          |
| `binarySearch(int[] a, int key)`                | Searches for a specified value using binary search.          |
| `toString()`                                    | Returns a string representation of the array.                |

## 试题 3. 程序设计题（40分）

 **具体要求：**

1.   在考生文件夹中创建 1 个“第 3 题.docx”文件

2.   在 src 源文件夹中找到 prog 包，打开并编写 prog 包中 Prog.java 文件，将程序中标

注有 “//--------prog--------”的两个函数按要求编写完整并使得其正确运行。函数功能 是检测字符串是否是一个有效密码。密码具体要求如下:

(1)密码必须至少 8 位字符
 (2)密码仅包含字母和数字
 (3)密码必须包含至少两个数字
 提示用户输入密码后，如果符合规则显示 Valid Password，否则显示 Invalid Password。 

3.   将程序运行截图添加到“第 3 题.docx“文件中，并保存。

4.   将修改后的 Java_exam 工程导出，保存到考生文件夹中。

``` java
package prog;
import java.util.Scanner;

/**
 * This program checks the validity of a password based on length, composition, and the number of digits it contains.
 */
public class Prog {

    /**
     * Main method to input and validate a password.
     *
     * @param args The command line arguments (not used in this program).
     */
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

    /**
     * Checks if a password is valid based on length, composition, and the number of digits.
     *
     * @param password The password to validate.
     * @return true if the password is valid, false otherwise.
     */
    public static boolean isPasswordValid(String password) {
        return (isLengthMoreThanEight(password) && isOnlyContainsLetterAndDigit(password) && isContainsMoreThanTwoDigits(password));
    }

    /**
     * Checks if the password length is more than or equal to 8.
     *
     * @param password The password to check.
     * @return true if the password length is more than or equal to 8, false otherwise.
     */
    public static boolean isLengthMoreThanEight(String password) {
        return password.length() >= 8;
    }

    /**
     * Checks if the password contains only letters and digits.
     *
     * @param password The password to check.
     * @return true if the password contains only letters and digits, false otherwise.
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
     * @param c The character to check.
     * @return true if the character is a digit, false otherwise.
     */
    private static boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    /**
     * Checks if a character is a letter.
     *
     * @param c The character to check.
     * @return true if the character is a letter, false otherwise.
     */
    private static boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    /**
     * Checks if the password contains more than or equal to 2 digits.
     *
     * @param password The password to check.
     * @return true if the password contains more than or equal to 2 digits, false otherwise.
     */
    public static boolean isContainsMoreThanTwoDigits(String password) {
        return getDigitCount(password) >= 2;
    }

    /**
     * Counts the number of digits in a password.
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
