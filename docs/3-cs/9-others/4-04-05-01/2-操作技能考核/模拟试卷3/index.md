# 操作技能考核：模拟试卷 3

-   [计算机程序设计员实操操作步骤.mp4](../res/计算机程序设计员实操操作步骤.mp4)
-   [模拟试卷3](../res/模拟试卷3.rar)

-   [3-Practice-Test-Paper](./3-Practice-Test-Paper.pdf)
-   [3-Marking-Scheme](./3-Marking-Scheme.pdf)

## 试题 1. 程序改错题（30分）：一维数组数值统计

### 1. 具体要求

1.   在电脑桌面建立考生文件夹，文件夹名称为考生准考证号（如：`20230001`）。在考生文件夹中创建1个 `第1题.docx` 文件；
2.   将接收的 Java_exam 导入到 eclipse 中，在 src 源文件夹中找到 modi 包，打开 modi 包中 `Modi.java` 文件。
     1.   `Modi.java`： 该程序实现输出⼀维数组的最⼤值，最⼩组和平均值。程序中共有 10 处错误，错误所在行的上方标注有 `//---------found---------`。修改程序中的错误并使得其正确运行。

3.   将程序运行截图添加到 `第1题.docx` 文件中，并保存。

### 2. 分析

### 3. 题目源码和解答

```java title="scr/Modi.java" linenums="1" hl_lines="6 8 24 27 29 32 38 43 46 48"
package modi;
import java.util.Scanner;
public class Modi {
    public static void main(String[] args) {
        //--------------Found--------------------
        Scanner input = new Scanner(); // 1. `System.in`
        //--------------Found--------------------
        double max; //最高分 // 2. `double max = 0.0 `
        double min = 100.0; //最低分
        double mean = 0.0; //平均值
        double sum = 0.0; //求和
        //--------------Found--------------------
        double[] score = { 
            77.1,
            88.1,
            76.1,
            56.1,
            87.1,
            98.1,
            55.1,
            94.1,
            39.1,
            96.1
        } // 3. `;`
        //求和
        //--------------Found--------------------
        for (int i = 1; i <= score.length - 1; i++) { // 4. `for (int i = 0; i <= score.length - 1; i ++ )`
            //--------------Found--------------------
            sum = score[i]; //求数组元素值的和 // 5. `sum += score[i];`
        }
        //--------------Found--------------------
        for (int i = 0; i <= score.length; i++) { // 6. `for (int i = 0; i <= score.length - 1; i ++ )`
            if (score[i] > max) { //此时i下标大于此时的max，i下标的值就是此时的最高分
                max = score[i];
            }
            if (score[i] < min) { //此时i下标小于此时的max，i下标的值就是此时的最低分
                // --------------Found--------------------
                score[i] = min; // 7. `min = score[i];`
            }
        }
        mean = sum / score.length; //计算平均数
        //--------------Found--------------------
        System.out.printf(max); // 8. `System.out.println(max);`
        System.out.println(min);
        //--------------Found--------------------
        System.out.println(sum); // 9. `System.out.println(mean);`
        //--------------Found--------------------
        // 10. `}`
    }
```



### 4. 参考答案

程序改错题（程序错误每处3分，10处。共30分）

| #    | Answer                                      |
| ---- | ------------------------------------------- |
| 1    | `System.in`                                 |
| 2    | `max = 0.0`                                 |
| 3    | `;`                                         |
| 4    | `for (i = 0; i < score.length - 1); i ++ )` |
| 5    | `sum += score[i]`                           |
| 6    | `i < score.length - 1`                      |
| 7    | `min = score[i]`                            |
| 8    | `println`                                   |
| 9    | `mean`                                      |
| 10   | `}`                                         |



### 5. 补充

### 6. 参考

## 试题 2. 程序填空题（30分）：水仙花数

### 1. 具体要求

1.   在考生文件夹中创建1个 `第2题.docx` 文件；
2.   blank 包中 `Blank.java` 文件实现判断三位数是不是⽔仙花数（各位数字⽴⽅和等于该数字本⾝）。程序中共有 6 处语句填空（填空处上方一行标注有 `//----------blank---------` ）。在填空处填写上正确的语句并使得其正确运行。
3.   将程序运行截图添加到 `第2题.docx` 文件中，并保存。

### 2. 分析

### 3. 题目源码和解答

```java title="src/blank/Blank.java" linenums="1" hl_lines="4 7 10 18 21 24"
package blank;
public class Blank {
    // ----------------blank-------------------
    public static __(1) ___ main(String[] args) { // 1. `void`
        //1.遍历所有的三位数
        // ----------------blank-------------------
        for (_____(2) ____) { // 2. `for (int i = 100; i < 1000; i ++ )`
            //----------------blank--------------------
            //2.调用自定义方法判断是不是水仙花数
            if (__(3) ____) { // 3. `isAim(i)`
                //3.如果是水仙花数，就打印
                System.out.println(i);
            }
        }
    }
    //----------------blank--------------------
    //4.自定义判断水仙花数的方法
    public static ___(4) _____ isAim(int a) { // 4. `public static boolean isAim(int a)`
        int x = a / 100;
        //----------------blank--------------------
        int y = ___(5) ____; // 5. `int y = a / 10 % 10` or `int y = a % 100 / 10`
        int z = a % 10;
        //----------------blank--------------------
        if (a == ___(6) _______) { // 6. `if (a == x*x*x + y*y*y + z*z*z)`
            return true;
        }
        return false;
    }
}
```

### 4. 参考答案

程序填空题（程序填空每空5分，6空。共30分）

| #    | Answer                              |
| ---- | ----------------------------------- |
| 1    | `void`                              |
| 2    | `i = 100; i < 1000; i ++ `          |
| 3    | `isAim(i)`                          |
| 4    | `boolean`                           |
| 5    | `a % 100 / 10`                      |
| 6    | `x * x * x + y * y * y + z * z * z` |

### 5. 补充

## 试题 3. 程序设计题（40分）：检查密码是否符合规则

### 1. 具体要求

1.   在考生文件夹中创建1个 `第3题.docx` 文件；

2.   在 src 源文件夹中找到 prog 包，打开并编写 prog 包中 `Prog.java` 文件，将程序中标注有 `//--------prog--------` 的两个函数按要求编写完整并使得其正确运行。编写数学⼯具类 `MyMath`，包含以下成员⽅法：
     1.   `int min(int a, int b)`，返回 `a`, `b` 最⼩值。
     2.   `int min(int a, int b, int c)`，返回 `a`, `b`, `c` 最⼩值。
     3.   `int min(int [ ]list)`，返回数组 `list` 最⼩元素。
     4.   `int numOfDiff(int [ ]list)`，返回数组 `list` 的不同元素的个数。 



3.   将程序运行截图添加到 `第3题.docx` 文件中，并保存。

4.   将修改后的 Java_exam 工程导出，保存到考生文件夹中。

### 2. 分析

### 3. 题目源码和解答

```java linenums="1" hl_lines="2-21 48-59"
import java.util.*;
public class Prog {
    //-----------------prog----------------------
    //判断数组长度大于3，符合则输入数组数据，调用min方法和numOfDiff方法分别输出最小值和不同元素个数
    public static void main(String[] args) {
        int count;
        int list[];
        Scanner in = new Scanner(System.in);
        count = in .nextInt();
        if (count <= 3) {
            return;
        }
        list = new int[count];
        for (int i = 0; i < count; i++) {
            list[i] = in .nextInt();
        }
        System.out.println(MyMath.min(list[0], list[1]));
        System.out.println(MyMath.min(list[0], list[1], list[2]));
        System.out.println(MyMath.min(list));
        System.out.println(MyMath.numOfDiff(list));
    }
}
class MyMath {
    static int min(int a, int b) {
        if (a < b)
            return a;
        else
            return b;
    }
    static int min(int a, int b, int c) {
        int min;
        if (a < b)
            min = a;
        else
            min = b;
        if (min < c)
            return min;
        else
            return c;
    }
    static int min(int[] list) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < list.length; i++)
            if (list[i] < min)
                min = list[i];
        return min;
    }
    //-----------------prog----------------------
    //返回数组中元素不相同的个数
    static int numOfDiff(int[] list) {
        Arrays.sort(list);
        int num = 1;
        for (int i = 1; i < list.length; i++) {
            if (list[i] != list[i - 1]) {
                num++;
            }
        }
        return num;
    }
}
```

```java linenums="1" hl_lines="3-20 47-55"
import java.util.*;
public class Prog {
    //-----------------prog----------------------
    //判断数组长度大于3，符合则输入数组数据，调用min方法和numOfDiff方法分别输出最小值和不同元素个数
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int len = in.nextInt();
        if (len <= 3) {
            return;
        } else {
            int[] list = new int[len];
            for (int i = 0; i < len; i ++ ) {
                list[i] = in.nextInt();
            }
            System.out.println(MyMath.min(list[0], list[1]));
            System.out.println(MyMath.min(list[0], list[1], list[2]));
            System.out.println(MyMath.min(list));
            System.out.println(MyMath.numOfDiff(list));
        }
    }
}
class MyMath {
    static int min(int a, int b) {
        if (a < b)
            return a;
        else
            return b;
    }
    static int min(int a, int b, int c) {
        int min;
        if (a < b)
            min = a;
        else
            min = b;
        if (min < c)
            return min;
        else
            return c;
    }
    static int min(int[] list) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < list.length; i++)
            if (list[i] < min)
                min = list[i];
        return min;
    }
    //-----------------prog----------------------
    //返回数组中元素不相同的个数
    static int numOfDiff(int[] list) {
        Set<Integer> set = new HashSet<>();
        for (int n : list) {
            set.add(n);
        }
        return set.size();
    }
}
```

### 4. 参考答案

程序设计题（程序中每函数 20 分， 2 函数。共 40 分）

第一个函数：（共20分）

```java
//-----------------prog----------------------
//判断数组长度大于3，符合则输入数组数据，调用min方法和numOfDiff方法分别输出最小值和不同元素个数
public static void main(String[] args) {
    int count;
    int list[];
    Scanner in = new Scanner(System.in);
    count = in .nextInt();
    if (count <= 3) {
        return;
    }
    list = new int[count];
    for (int i = 0; i < count; i++) {
        list[i] = in .nextInt();
    }
    System.out.println(MyMath.min(list[0], list[1]));
    System.out.println(MyMath.min(list[0], list[1], list[2]));
    System.out.println(MyMath.min(list));
    System.out.println(MyMath.numOfDiff(list));
}
```

第二个函数：（共20分）

```java
    //-----------------prog----------------------
    //返回数组中元素不相同的个数
    static int numOfDiff(int[] list) {
        Arrays.sort(list);
        int num = 1;
        for (int i = 1; i < list.length; i++) {
            if (list[i] != list[i - 1]) {
                num++;
            }
        }
        return num;
    }
```

### 5. 补充

### 6. 参考
