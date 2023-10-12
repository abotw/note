

## 试题 1. 程序改错题（30分）

**具体要求：**

1.   在电脑桌面建立考生文件夹，文件夹名称为考生准考证号（如：20230001）。在考生文件夹中创建1个“第1题.docx“文件；
2.   将接收的 Java_exam 导入到 eclipse 中，在 src 源文件夹中找到 modi 包，打开 modi 包中Modi.java 文件；该程序用于实现二维数组 c 存放二维数组 a 和 b 的乘积结果，程序中共有10处错误，错误所在行的上方标注有`//---------found---------`。修改程序中的错误并使得其正确运行。
3.   将程序运行截图添加到“第1题.docx“文件中，并保存。

 ``` java title="source code"
 package modi;
 //-----------------Found-----------------
 public   Modi 
 {
 //-----------------Found-----------------
     public static void main(String[] arges)
     {    
         int a[][]=new int[2][3];
         int b[][]={{1,5,2,8},{5,9,10,-3},{2,7,-5,-18}};
 //-----------------Found-----------------
         int c[][]=new int[2][];   
         for(int i=0;i<2;i++)
         {
 //-----------------Found-----------------
             for(int j=0;j<3;j+)
             {  
                 a[i][j]=(i+1)*(j+2);
             }
         }
         for(int i=0;i<2;i++)
         {
             for(int j=0;j<4;j++)   
             {
 //-----------------Found-----------------
                  c[i][j]=1;     
 //-----------------Found----------------- 
                  for(int k;k<3;k++)
                  {
 //-----------------Found-----------------
                       c[i][j]=a[i][k]*b[k][j];
                  }
             }
 //-----------------Found-----------------
  
         for(int i=0;i<2;i++)
        {
 //-----------------Found-----------------
             for(int j=0;j<3;j++)
 //-----------------Found-----------------
              System.out.printf(c[j][i]+" ");
              System.out.println();
        }
     }
 }
 
 ```

``` java title="solution"
package modi;
//-----------------Found-----------------
public class Modi // 1. class
{
//-----------------Found-----------------
    public static void main(String[] args) // 2. arges -> args
    {    
        int a[][]=new int[2][3];
        int b[][]={{1,5,2,8},{5,9,10,-3},{2,7,-5,-18}}; // b[3][4]
//-----------------Found-----------------
        int c[][]=new int[2][4]; // 3. new int[2][4]
        // initialize array a   
        for(int i=0;i<2;i++) // control rows, 2 rows
        {
//-----------------Found-----------------
            for(int j=0;j<3;j++) // 4. j++, control columns, 3 columns
            {  
                a[i][j]=(i+1)*(j+2);
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<4;j++)   
            {
//-----------------Found-----------------
                 c[i][j]= 0; // 5. c[i][j] = 0, initialize array c    
//-----------------Found----------------- 
                 for(int k = 0;k<3;k++) // 6. k = 0
                 {
//-----------------Found-----------------
                      c[i][j]+=a[i][k]*b[k][j]; // 7. c[i][j]+=a[i][k]*b[k][j];
                 }
            }
//-----------------Found-----------------
 } // 8. lack }
 // print array c
        for(int i=0;i<2;i++)
       {
//-----------------Found-----------------
            for(int j=0;j<4;j++) // 9. j < 3 -> j < 4
//-----------------Found-----------------
             System.out.printf(c[i][j]+" "); // 10. c[j][i] -> c[i][j]
             System.out.println();
       }
    }
}


```

``` java title="optimized code"
package modi;

/**
 * This class demonstrates matrix multiplication and prints the result.
 */
public class Modi {
    public static void main(String[] args) {
        // Define matrices A, B, and C
        int a[][] = new int[2][3]; // Matrix A: 2 rows, 3 columns
        int b[][] = {{1, 5, 2, 8}, {5, 9, 10, -3}, {2, 7, -5, -18}}; // Matrix B: 3 rows, 4 columns
        int c[][] = new int[2][4]; // Matrix C: Result of multiplication (2 rows, 4 columns)

        // Initialize array A
        for (int i = 0; i < 2; i++) { // Loop through rows of A
            for (int j = 0; j < 3; j++) { // Loop through columns of A
                a[i][j] = (i + 1) * (j + 2);
            }
        }

        // Perform matrix multiplication (C = A * B)
        for (int i = 0; i < 2; i++) { // Loop through rows of A
            for (int j = 0; j < 4; j++) { // Loop through columns of B
                c[i][j] = 0; // Initialize the corresponding element in C

                for (int k = 0; k < 3; k++) { // Loop through columns of A and rows of B
                    c[i][j] += a[i][k] * b[k][j]; // Calculate the element in C
                }
            }
        }

        // Print the result matrix C
        for (int i = 0; i < 2; i++) { // Loop through rows of C
            for (int j = 0; j < 4; j++) { // Loop through columns of C
                System.out.printf(c[i][j] + " "); // Print the element in C
            }
            System.out.println(); // Start a new line for the next row
        }
    }
}

```



### 矩阵乘法

-   Ref: <https://www.ruanyifeng.com/blog/2015/09/matrix-multiplication.html>

 ``` java
 public class MatrixMultiplication {
     public static void main(String[] args) {
         // Define two different-sized matrices
         int[][] matrix1 = {
             {1, 2},
             {3, 4}
         };
 
         int[][] matrix2 = {
             {5, 6, 7},
             {8, 9, 10}
         };
 
         // Ensure that the matrices can be multiplied, which requires the number of columns in the
         // first matrix to be equal to the number of rows in the second matrix
         int columns1 = matrix1[0].length;
         int rows2 = matrix2.length;
 
         if (columns1 != rows2) {
             System.out.println("These two matrices cannot be multiplied because their dimensions do not match.");
             return;
         }
 
         // Create the result matrix
         int resultRows = matrix1.length;
         int resultColumns = matrix2[0].length;
         int[][] resultMatrix = new int[resultRows][resultColumns];
 
         // Perform matrix multiplication
         for (int i = 0; i < resultRows; i++) {
             for (int j = 0; j < resultColumns; j++) {
                 int sum = 0;
                 for (int k = 0; k < columns1; k++) {
                     // Calculate the element at row i, column j of the result matrix
                     sum += matrix1[i][k] * matrix2[k][j];
                 }
                 resultMatrix[i][j] = sum;
             }
         }
 
         // Print the resulting matrix
         System.out.println("Matrix multiplication result:");
         for (int i = 0; i < resultRows; i++) {
             for (int j = 0; j < resultColumns; j++) {
                 System.out.print(resultMatrix[i][j] + " ");
             }
             System.out.println();
         }
     }
 }
 
 ```

## 试题 2. 程序填空题（30分）

**具体要求：**

1.   在考生文件夹中创建1个“第2题.docx“文件；
2.   blank 包中 Juxing.java 文件定义一个类 Juxing，描述一个矩形，包含有长、宽两种属性和面积计算方法；blank 包中 ChangFangTi.java 文件定义一个类 ChangFangTi，该类继承自 Juxing 类，同时该类描述一个长方体，包含长、宽、高属性，和计算体积的方法；blank 包中Blank.java 文件，创建一个长方体对象，定义其长、宽、高，并输出其底面积和体积。
3.   上述 3 个源文件中共有 10 处语句填空（填空处上方一行标注有 `//----------blank---------` ）。在填空处填写上正确的语句并使得其正确运行。
4.   将程序运行截图添加到“第2题.docx“文件中，并保存。

 ``` java title="juxing.java"
 package blank;
 //-----------blank--------------
 public _(4)____ Juxing {
   private double chang;
   private double kuan;
 //-----------blank--------------
   __(5)____ double getChang() {
       return chang;
   }
 //-----------blank--------------
   public void setChang(__(6)_____ chang) {
       this.chang = chang;
   }
   public double getKuan() {
       return kuan;
   }
   public void setKuan(double kuan) {
       this.kuan = kuan;
   }
 //-----------blank--------------
   public double area(){
       return ___(7)_____;
   }
 }
 ```

``` java title="solution to juxing.java"
package blank;
//-----------blank--------------
public _(4)____ Juxing { // 4. class
  private double chang;
  private double kuan;
//-----------blank--------------
  __(5)____ double getChang() { // 5. public
      return chang;
  }
//-----------blank--------------
  public void setChang(__(6)_____ chang) { // 6. double
      this.chang = chang;
  }
  public double getKuan() {
      return kuan;
  }
  public void setKuan(double kuan) {
      this.kuan = kuan;
  }
//-----------blank--------------
  public double area(){
      return ___(7)_____; // 7. this.getChang() * this.getKuan()
  }
}
```

``` java title="solution to ChangFangTi.java"
package blank;
//-----------blank--------------
public class ChangFangTi __(8)____ Juxing { // 8. extends
  private double gao;
  public double getGao() {
      return gao;
  }
  public void setGao(double gao)
  {
//-----------blank--------------
      __(9)___= gao; // this.gao
  }
//-----------blank--------------
  public double tiji(){
      return ___(10)____; // this.getChang() * this.getKuan() * this.getGao()
  }
}

```

``` java title="blank.java"
package blank;
public class Blank {
    public static void main(String[] args){
        //-----------blank--------------
        ChangFangTi a=new ___(1)_____;
        //-----------blank--------------
        a.___(2)____(12);//(12)为函数的参数值
        a.setKuan(10);
        a.setGao(5);
        //----------blank---------------
        System.out.println("长方体的底面积是："+  ___(3)_____ );
        System.out.println("长方体的体积是："+a.tiji());
    }
}
```

``` java title="solution to blank.java"
package blank;
public class Blank {
    public static void main(String[] args){
        //-----------blank--------------
        ChangFangTi a=new ___(1)_____; // 1. ChangFangTi()
        //-----------blank--------------
        a.___(2)____(12);//(12)为函数的参数值 // 2. setChang
        a.setKuan(10);
        a.setGao(5);
        //----------blank---------------
        System.out.println("长方体的底面积是："+  ___(3)_____ ); // 3. a.tiji() / a.getGao()
        System.out.println("长方体的体积是："+a.tiji());
    }
}
```



## 试题 3. 程序设计题（40分）

**具体要求：**

1.   在考生文件夹中创建1个“第3题.docx“文件；
2.   在 src 源文件夹中找到 prog 包，打开并编写 prog 包中 Prog.java 文件，将程序中标注有 `//--------prog--------` 的两个函数按要求编写完整并使得其正确运行。2个函数功能要求如下：
     1.   编写 `void max(double a, double b)` 成员方法，实现对两个 double 数进行大小的比较，输出打印较大的那个 double 数；
     2.   编写 `main` 函数，实现在控制台依次输入 `int` / `float` / `double` 类型数据，并输出各类型数据的最大值。
3.   将程序运行截图添加到“第3题.docx“文件中，并保存。
4.   将修改后的Java_exam工程导出，保存到考生文件夹中。

``` java title="Prog.java"
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
//--------------------Prog-------------------
//控制台输入int/float/double类型数据，并输出各类型数据的最大值
        public static void main(String[] args) {

                

                 System.out.println("请输入两个整数：");


                 System.out.println("请输入两个 float 型实数：");

              
                 System.out.println("请输入两个 double 型实数：");


        }

}

```

``` java title-"solution to blank.java"
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
        public static void max(double a, double b) {
            double max3 = a >= b ? a : b;
            System.out.println("最大值：" + max3);
        }
//--------------------Prog-------------------
//控制台输入int/float/double类型数据，并输出各类型数据的最大值
        public static void main(String[] args) {

                

                 System.out.println("请输入两个整数：");
                 Scanner scanner = new Scanner(System.in);
                 intA = scanner.nextInt();
                 intB = scanner.nextInt();
                 max(intA, intB);

                 System.out.println("请输入两个 float 型实数：");
                 floatA = scanner.nextFloat();
                 floatB = scanner.nextFloat();
                 max(floatA, floatB)
              
                 System.out.println("请输入两个 double 型实数：");
                 doubleA = scanner.nextDouble();
                 doubleB = scanner.nextDouble();
                 max(doubleA, doubleB)
                 
                 scanner.close()

        }

}

```

``` java title="optimized code" 
package prog;

import java.util.Scanner;

/**
 * This class contains methods for finding the maximum of two numbers
 * of different data types and provides a console interface to input and
 * display the results.
 */
public class Prog {

    // Variables to store the maximum values
    static int max1;
    static float max2;
    static double max3;

    /**
     * Find the maximum of two integers.
     *
     * @param a The first integer.
     * @param b The second integer.
     */
    public static void max(int a, int b) {
        max1 = (a >= b) ? a : b;
        System.out.println("Maximum value: " + max1);
    }

    /**
     * Find the maximum of two float values.
     *
     * @param a The first float value.
     * @param b The second float value.
     */
    public static void max(float a, float b) {
        max2 = (a >= b) ? a : b;
        System.out.println("Maximum value: " + max2);
    }

    /**
     * Find the maximum of two double values.
     *
     * @param a The first double value.
     * @param b The second double value.
     */
    public static void max(double a, double b) {
        max3 = (a >= b) ? a : b;
        System.out.println("Maximum value: " + max3);
    }

    /**
     * Main method to input and display maximum values for different data types.
     *
     * @param args Command-line arguments (not used in this program).
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter two integers:");
        int intA = scanner.nextInt();
        int intB = scanner.nextInt();
        max(intA, intB);

        System.out.println("Enter two float values:");
        float floatA = scanner.nextFloat();
        float floatB = scanner.nextFloat();
        max(floatA, floatB);

        System.out.println("Enter two double values:");
        double doubleA = scanner.nextDouble();
        double doubleB = scanner.nextDouble();
        max(doubleA, doubleB);

        scanner.close();
    }
}

```

