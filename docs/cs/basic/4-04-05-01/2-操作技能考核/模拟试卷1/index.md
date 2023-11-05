

# 操作技能考核：模拟试卷 1

-   [计算机程序设计员实操操作步骤.mp4](../res/计算机程序设计员实操操作步骤.mp4)
-   [模拟试卷1](../res/模拟试卷1.rar)

-   [1-Practice-Test-Paper](./1-Practice-Test-Paper.pdf)
-   [1-Marking-Scheme](./1-Marking-Scheme.pdf)

## 试题 1. 程序改错题（30分）：矩阵乘法

### 1. 具体要求

1.   在电脑桌面建立考生文件夹，文件夹名称为考生准考证号（如：`20230001`）。在考生文件夹中创建1个 `第1题.docx` 文件；
2.   将接收的 Java_exam 导入到 eclipse 中，在 src 源文件夹中找到 modi 包，打开 modi 包中`Modi.java` 文件。
     1.   `Modi.java` ：该程序用于实现二维数组 `c` 存放二维数组 `a` 和 `b` 的乘积结果，程序中共有10处错误，错误所在行的上方标注有 `//---------found---------`。修改程序中的错误并使得其正确运行。

3.   将程序运行截图添加到 `第1题.docx` 文件中，并保存。

### 2. 分析

1.   Define the 2D arrays `a` and `b` 
     定义二维数组 a 和 b

     ```java
     int[][] a = {
         {
             1,
             2,
             3
         },
         {
             4,
             5,
             6
         },
         {
             7,
             8,
             9
         }
     };
     
     int[][] b = {
         {
             9,
             8,
             7
         },
         {
             6,
             5,
             4
         },
         {
             3,
             2,
             1
         }
     };
     
     ```

     

2.   Create the result matrix `c` 
     创建结果矩阵 `c`

     ```java
     int[][] c = new int[a.length][b[0].length];
     ```

     

3.   Perform matrix multiplication
     矩阵相乘

     ```java
     for (int i = 0; i < a.length; i++) {
         for (int j = 0; j < b[0].length; j++) {
             c[i][j] = 0;
             for (int k = 0; k < a[0].length; k++) {
                 c[i][j] += a[i][k] * b[k][j];
             }
         }
     }
     ```

     

4.   Print the result matrix `c`
     打印结果矩阵 `c`

     ```java
     for (int i = 0; i < c.length; i++) {
         for (int j = 0; j < c[0].length; j++) {
             System.out.print(c[i][j] + " ");
         }
         System.out.println();
     }
     ```

### 3. 题目源码和解答

 ``` java title="src/modi/Modi.java" linenums="1" hl_lines="2-3 4-5 35-36 42-43 53-54 55-56 57-58 61-62 68-69 70-71"
 package modi;
 //-----------------Found-----------------
 public Modi { // 1. `public Modi` -> `public class Modi`
     //-----------------Found-----------------
     public static void main(String[] arges) { // 2. `arges` -> `args`
         /**
          * Define the 2D arrays `a` and `b`
          * 定义二维数组 a 和 b
          */
         int a[][] = new int[2][3];
         int b[][] = {
             {
                 1,
                 5,
                 2,
                 8
             },
             {
                 5,
                 9,
                 10,
                 -3
             },
             {
                 2,
                 7,
                 -5,
                 -18
             }
         };
         /**
          * Create the result matrix c
          * 创建结果矩阵 c
          */
         //-----------------Found-----------------
         int c[][] = new int[2][]; // 3. `int[][] c = new int[a.length][b[0].length];` -> `int[2][4]`
         /**
          * Initialize the 2D arrag `a`
          * 初始化二维数组 `a`
          */
         for (int i = 0; i < 2; i++) {
             //-----------------Found-----------------
             for (int j = 0; j < 3; j + ) { // 4. `j+` -> `j++`
                 a[i][j] = (i + 1) * (j + 2);
             }
         }
         /**
          * Perform matrix multiplication
          * 矩阵相乘
          */
         for (int i = 0; i < 2; i++) {
             for (int j = 0; j < 4; j++) {
                 //-----------------Found-----------------
                 c[i][j] = 1; // 5. `c[i][j] = 1;` -> `c[i][j] = 0;`
                 //-----------------Found----------------- 
                 for (int k; k < 3; k++) { // 6. `int k;` -> `int k = 0;`
                     //-----------------Found-----------------
                     c[i][j] = a[i][k] * b[k][j]; // 7. `c[i][j] = a[i][k] * b[k][j];` -> `c[i][j] += a[i][k] * b[k][j];`
                 }
             }
         //-----------------Found-----------------
         // 8. `` -> `}`
         /**
          * Print the result matrix `c`
          * 打印结果矩阵 `c`
          */
         for (int i = 0; i < 2; i++) {
             //-----------------Found-----------------
             for (int j = 0; j < 3; j++) // 9. `j < 3` -> `j < 4`
                 //-----------------Found-----------------
                 System.out.printf(c[j][i] + " "); // 10. `c[j][i]` -> `c[i][j]`
             System.out.println();
         }
     }
 }
 
 ```

```java title="Optimized code" linenums="1"
package modi;

/**
 * The Modi class performs matrix multiplication of two 2D arrays, a and b, and stores the result in matrix c.
 * 
 * @author Your Name
 * @version 1.0
 */
public class Modi {

    /**
     * The main method of the program.
     * 
     * @param args The command-line arguments.
     */
    public static void main(String[] args) {
        /**
         * Define the 2D arrays `a` and `b`
         * 定义二维数组 a 和 b
         */
        int a[][] = new int[2][3];
        int b[][] = {
            {1, 5, 2, 8},
            {5, 9, 10, -3},
            {2, 7, -5, -18}
        };
        
        /**
         * Create the result matrix `c`
         * 创建结果矩阵 c
         */
        int c[][] = new int[2][4];
        
        /**
         * Initialize the 2D array `a`
         * 初始化二维数组 `a`
         */
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) { // Fixed: Corrected the loop control statement
                a[i][j] = (i + 1) * (j + 2);
            }
        }
        
        /**
         * Perform matrix multiplication
         * 矩阵相乘
         */
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                c[i][j] = 0; // Fixed: Initialized c[i][j] to 0
                for (int k = 0; k < 3; k++) { // Fixed: Corrected the loop initialization
                    c[i][j] += a[i][k] * b[k][j]; // Fixed: Accumulated the result in c[i][j]
                }
            }
        }
        
        /**
         * Print the result matrix `c`
         * 打印结果矩阵 `c`
         */
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) { // Fixed: Corrected the loop control statement
                System.out.print(c[i][j] + " "); // Fixed: Changed the output format
            }
            System.out.println();
        }
    }
}

```

### 4. 参考答案

程序改错题（程序错误每处3分，10处。共30分）

| 题号 | 答案                           |
| ---- | ------------------------------ |
| 1    | `class`                        |
| 2    | `args`                         |
| 3    | `int[2][4]`                    |
| 4    | `j++`                          |
| 5    | `c[i][j] = 0`                  |
| 6    | `int k = 0`                    |
| 7    | `c[i][j] += a[i][k] * b[k][j]` |
| 8    | `}`                            |
| 9    | `j < 4`                        |
| 10   | `c[i][j]`                      |

### 5. 补充

#### 矩阵乘法

<iframe width="560" height="315" src="https://www.youtube-nocookie.com/embed/5GGiqiQlpaA?si=v3aMVn7klE-awiKL" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

$$
\displaylines{
MatrixA_{m\times p}
\\
MatrixB_{p\times n}
\\
MatrixC=A\times B\implies C_{m\times n}
}
$$

##### 举例

$$
A =
\begin{bmatrix}
a & b & c \\\\
d & e & f
\end{bmatrix}
$$

$$
B =
\begin{bmatrix}
1 & 2 \\
3 & 4 \\
5 & 6
\end{bmatrix}
$$

$$
C = A\times B =
\begin{bmatrix}
a & b & c \\
d & e & f
\end{bmatrix}
\begin{bmatrix}
1 & 2 \\
3 & 4 \\
5 & 6
\end{bmatrix}
=
\begin{bmatrix}
a+3b+5c & 2a+4b+6c \\
d+3e+5f & 2d+4e+6f
\end{bmatrix}
$$

##### Java 实现

 ``` java title="MatrixMultiplication.java" linenums="1"
 /**
  * MatrixMultiplication class provides methods to multiply two matrices.
  */
 public class MatrixMultiplication {
 
     /**
      * This method multiplies two matrices and returns the result.
      *
      * @param matrixA The first matrix (m x p).
      * @param matrixB The second matrix (p x n).
      * @return The resulting matrix (m x n) after multiplication.
      * @throws IllegalArgumentException if the matrices cannot be multiplied.
      */
     public static int[][] multiply(int[][] matrixA, int[][] matrixB) {
         // Check if matrixA and matrixB can be multiplied
         int numRowsA = matrixA.length;
         int numColsA = matrixA[0].length;
         int numRowsB = matrixB.length;
         int numColsB = matrixB[0].length;
 
         if (numColsA != numRowsB) {
             throw new IllegalArgumentException("Matrix dimensions are not compatible for multiplication.");
         }
 
         // Create the resulting matrix
         int[][] result = new int[numRowsA][numColsB];
 
         // Perform matrix multiplication
         for (int i = 0; i < numRowsA; i++) {
             for (int j = 0; j < numColsB; j++) {
                 int sum = 0;
                 for (int k = 0; k < numColsA; k++) {
                     sum += matrixA[i][k] * matrixB[k][j];
                 }
                 result[i][j] = sum;
             }
         }
 
         return result;
     }
 
     /**
      * Main method for testing matrix multiplication.
      */
     public static void main(String[] args) {
         int[][] matrixA = {
             {1, 2, 3},
             {4, 5, 6}
         };
 
         int[][] matrixB = {
             {7, 8},
             {9, 10},
             {11, 12}
         };
 
         try {
             int[][] result = multiply(matrixA, matrixB);
 
             // Print the result matrix
             for (int i = 0; i < result.length; i++) {
                 for (int j = 0; j < result[0].length; j++) {
                     System.out.print(result[i][j] + " ");
                 }
                 System.out.println();
             }
         } catch (IllegalArgumentException e) {
             System.err.println(e.getMessage());
         }
     }
 }
 
 ```

### 6. 参考

-   How to Multiply Matrices, <https://www.mathsisfun.com/algebra/matrix-multiplying.html>

-   <https://github.com/mathjax/MathJax/issues/2312>
-   MathJax数学公式, <http://masikkk.com/article/MathJax/>
-   A quick guide to LATEX, <https://users.dickinson.edu/~richesod/latex/latexcheatsheet.pdf>

## 试题 2. 程序填空题（30分）：矩形和长方体

### 1. 具体要求

1.   在考生文件夹中创建1个 `第2题.docx` 文件；
2.   blank 包中 `Juxing.java` 文件定义一个类 `Juxing`，描述一个矩形，包含有长、宽两种属性和面积计算方法；blank 包中 `ChangFangTi.java` 文件定义一个类 `ChangFangTi`，该类继承自 `Juxing` 类，同时该类描述一个长方体，包含长、宽、高属性，和计算体积的方法；blank 包中`Blank.java` 文件，创建一个长方体对象，定义其长、宽、高，并输出其底面积和体积。
3.   上述 3 个源文件中共有 10 处语句填空（填空处上方一行标注有 `//----------blank---------` ）。在填空处填写上正确的语句并使得其正确运行。
4.   将程序运行截图添加到 `第2题.docx` 文件中，并保存。

### 2. 分析

1.   `Juxing.java` 文件
2.   `ChangFangTi.java` 文件
3.   `Blank.java` 文件
     1.   创建长方体对象
     2.   计算底面积和体积
     3.   输出底面积和体积

### 3. 题目源码和解答

#### `blank.java`

```java title="blank.java" linenums="1"
package blank;
public class Blank {
    public static void main(String[] args) {
        /**
         * 创建长方体对象
         * Create a ChangFangTi object with specified dimensions
         */
        //-----------blank--------------
        ChangFangTi a = new ___(1) _____; // 1. `ChangFangTi()`
        //-----------blank--------------
        a.___(2) ____(12); //(12)为函数的参数值 // 2. `setChang`
        a.setKuan(10);
        a.setGao(5);
        /**
         * 计算并输出底面积和体积
         * Calculate the area and volume, then display the results
         */
        //----------blank---------------
        System.out.println("长方体的底面积是：" + ___(3) _____); // 3. `a.area()`
        System.out.println("长方体的体积是：" + a.tiji());
    }
}

```

```java title="Optimized code" linenums="1"
package blank;

/**
 * The Blank class contains the main method to create a ChangFangTi object, calculate its area and volume,
 * and display the results.
 */
public class Blank {
    public static void main(String[] args) {
        // Create a ChangFangTi object with specified dimensions
        ChangFangTi changFangTi = new ChangFangTi(5.0, 3.0, 2.0);

        // Calculate the area and volume
        double area = changFangTi.calculateArea();
        double volume = changFangTi.calculateVolume();

        // Display the results
        System.out.println("底面积: " + area);
        System.out.println("体积: " + volume);
    }
}

```

#### `Juxing.java`

```java title="Juxing.java" linenums="1"
package blank;
//-----------blank--------------
public _(4) ____ Juxing { // 4. `class`
    private double chang;
    private double kuan;
    //-----------blank--------------
    __(5) ____ double getChang() { // 5. `public`
        return chang;
    }
    //-----------blank--------------
    public void setChang(__(6) _____ chang) { // 6. `double`
        this.chang = chang;
    }
    public double getKuan() {
        return kuan;
    }
    public void setKuan(double kuan) {
        this.kuan = kuan;
    }
    //-----------blank--------------
    public double area() {
        return ___(7) _____; // 7. `chang * kuan`
    }
}

```

```java title="Optimized code" linenums="1"
package blank;

/**
 * The Juxing class represents a rectangle and provides methods to calculate its area.
 */
public class Juxing {
    protected double length;  // The length of the rectangle.
    protected double width;   // The width of the rectangle.

    /**
     * Constructs a new Juxing object with the specified length and width.
     *
     * @param length The length of the rectangle.
     * @param width  The width of the rectangle.
     */
    public Juxing(double length, double width) {
        this.length = length;
        this.width = width;
    }

    /**
     * Calculates and returns the area of the rectangle.
     *
     * @return The area of the rectangle.
     */
    public double calculateArea() {
        return length * width;
    }
}

```

#### `ChangFangTi.java`

```java title="ChangFangTi.java" linenums="1"
package blank;
//-----------blank--------------
public class ChangFangTi __(8) ____ Juxing { // 8. `extends`
    private double gao;
    public double getGao() {
        return gao;
    }
    public void setGao(double gao) {
        //-----------blank--------------
        __(9) ___ = gao; // 9. `this.gao`
    }
    //-----------blank--------------
    public double tiji() {
        return ___(10) ____; // 10. `area() * gao`
    }
}
```

```java title="Optimized code" linenums="1"
package blank;

/**
 * The ChangFangTi class represents a cuboid (a 3D shape) and extends the Juxing class.
 * It provides methods to calculate its volume.
 */
public class ChangFangTi extends Juxing {
    protected double height;  // The height of the cuboid.

    /**
     * Constructs a new ChangFangTi object with the specified length, width, and height.
     *
     * @param length The length of the cuboid.
     * @param width  The width of the cuboid.
     * @param height The height of the cuboid.
     */
    public ChangFangTi(double length, double width, double height) {
        super(length, width);
        this.height = height;
    }

    /**
     * Calculates and returns the volume of the cuboid.
     *
     * @return The volume of the cuboid.
     */
    public double calculateVolume() {
        return length * width * height;
    }
}

```

### 4. 参考答案

程序填空题（程序填空每空3分，10空。共30分）

| 题号 | 答案            |
| ---- | --------------- |
| 1    | `CahngFangTi()` |
| 2    | `setChang`      |
| 3    | `a.area()`      |
| 4    | `class`         |
| 5    | `public`        |
| 6    | `double`        |
| 7    | `chang * kuan`  |
| 8    | `extends`       |
| 9    | `this.gao`      |
| 10   | `area() * gao`  |



## 试题 3. 程序设计题（40分）：大小比较函数重载

### 1. 具体要求

1.   在考生文件夹中创建1个 `第3题.docx` 文件；
2.   在 src 源文件夹中找到 prog 包，打开并编写 prog 包中 `Prog.java` 文件，将程序中标注有 `//--------prog--------` 的两个函数按要求编写完整并使得其正确运行。2个函数功能要求如下：
     1.   编写 `void max(double a, double b)` 成员方法，实现对两个 `double` 数进行大小的比较，输出打印较大的那个 `double` 数；
     2.   编写 `main` 函数，实现在控制台依次输入 `int` / `float` / `double` 类型数据，并输出各类型数据的最大值。
3.   将程序运行截图添加到 `第3题.docx` 文件中，并保存。
4.   将修改后的 Java_exam 工程导出，保存到考生文件夹中。

### 2. 分析

### 3. 题目源码和解答

``` java title="src/prog/Prog.java" linenums="1"
package prog;
import java.util.Scanner;

public class Prog {

    static int a1, b1, max1;
    static float a2, b2, max2;
    static double a3, b3, max3;

    public static void max(int a, int b) {
        if (a >= b)
            max1 = a;
        else
            max1 = b;
        System.out.println("最大值：" + max1);
    }

    public static void max(float a, float b) {
        if (a >= b)
            max2 = a;
        else
            max2 = b;
        System.out.println("最大值：" + max2);
    }

    //--------------------prog-------------------
    //对两个double数进行大小的比较
    public static void max() {

    }

    // public static void max(double a, double b) {
    //     System.out.println("最大值：" + (a > b ? a : b));
    // }

    //--------------------Prog-------------------
    //控制台输入int/float/double类型数据，并输出各类型数据的最大值
    public static void main(String[] args) {
        System.out.println("请输入两个整数：");
        System.out.println("请输入两个 float 型实数：");
        System.out.println("请输入两个 double 型实数：");
    }

    // public static void main(String[] args) {
    //     int ia, ib;
    //     float fa, fb;
    //     double da, db;

    //     Scanner s = new Scanner();
    //     System.out.println("请输入两个整数：");
    //     ia = s.nextInt();
    //     ib = s.nextInt();
    //     max(ia, ib);
    //     System.out.println("请输入两个 float 型实数：");
    //     fa = s.nextFloat();
    //     fb = s.nextFloat();
    //     max(fa, fb);
    //     System.out.println("请输入两个 double 型实数：");
    //     da = s.nextDouble();
    //     db = s.nextDouble();
    //     max(da, db);
    //     s.close();
    // }

}

```

``` java title="Optimized code" linenums="1"
package prog;

import java.util.Scanner;

/**
 * The Prog class contains methods to find the maximum value among two numbers of different data types.
 */
public class Prog {
    static int max1;  // Stores the maximum integer value
    static float max2;  // Stores the maximum float value
    static double max3;  // Stores the maximum double value

    /**
     * This method compares two integer values and prints the larger one.
     *
     * @param a The first integer value
     * @param b The second integer value
     */
    public static void max(int a, int b) {
        max1 = (a >= b) ? a : b;
        System.out.println("The maximum value: " + max1);
    }

    /**
     * This method compares two float values and prints the larger one.
     *
     * @param a The first float value
     * @param b The second float value
     */
    public static void max(float a, float b) {
        max2 = (a >= b) ? a : b;
        System.out.println("The maximum value: " + max2);
    }

    //--------------------prog-------------------
    /**
     * This method compares two double values and prints the larger one.
     *
     * @param a The first double value
     * @param b The second double value
     */
    public static void max(double a, double b) {
        max3 = (a >= b) ? a : b;
        System.out.println("The maximum value: " + max3);
    }

    //--------------------Prog-------------------
    /**
     * The main method of the program.
     * It takes user input for integers, floats, and doubles and finds the maximum value among them.
     *
     * @param args Command line arguments (not used in this program)
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers from the user
        System.out.println("Enter two integers:");
        int int1 = scanner.nextInt();
        int int2 = scanner.nextInt();
        max(int1, int2);

        // Read two float values from the user
        System.out.println("Enter two float values:");
        float float1 = scanner.nextFloat();
        float float2 = scanner.nextFloat();
        max(float1, float2);

        // Read two double values from the user
        System.out.println("Enter two double values:");
        double double1 = scanner.nextDouble();
        double double2 = scanner.nextDouble();
        max(double1, double2);

        scanner.close();
    }
}

```

### 4. 参考答案

程序设计题（程序中每函数20分， 2函数。共40分）

第一个函数：（共20分）

```java
public static void max(double a, double b) { // 8分
    if (a >= b) // 8分
        max3 = a;
    else
        max3 = b;
    System.out.println("最大值：" + max3); // 5分
}

```

第二个函数：（共20分）

```java
Scanner scanner = new Scanner(System.in); // 3分
System.out.println("请输入两个整数：");
a1 = scanner.nextInt(); // 3分
b1 = scanner.nextInt(); // 3分
max(a1, b1); // 3分
System.out.println("请输入两个 float 型实数：");
a2 = scanner.nextFloat(); // 2分
b2 = scanner.nextFloat(); // 1分
max(a2, b2); // 1分
System.out.println("请输入两个 double 型实数：");
a3 = scanner.nextDouble(); // 2分
b3 = scanner.nextDouble(); // 1分
max(a3, b3); // 1分
```

