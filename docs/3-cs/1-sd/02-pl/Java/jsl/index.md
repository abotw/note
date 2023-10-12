# Java Standard Library

1.  **java.lang**：包含Java语言的核心类，如基本数据类型的包装类、字符串处理类、异常类等。
2.  **java.util**：提供了集合框架，包括列表、集合、映射等，以及日期和时间处理类。
3.  **java.io**：用于文件和流操作，包括输入输出、文件读写、对象序列化等。
4.  **java.net**：包含网络编程的类，用于创建和管理网络连接、套接字通信等。
5.  **java.awt**：抽象窗口工具包（Abstract Window Toolkit），用于创建图形用户界面（GUI）应用程序。
6.  **javax.swing**：Swing库，用于创建现代化的GUI应用程序，提供了更多的GUI组件和样式。
7.  **java.util.concurrent**：用于多线程编程的类，包括线程池、同步工具、原子变量等。
8.  **java.sql**：用于数据库访问的类，包括JDBC（Java数据库连接）的一部分。
9.  **java.math**：提供了高精度的数学运算类，如BigInteger和BigDecimal。
10.  **java.security**：用于安全性和加密的类，包括密钥管理、数字签名等。
11.  **java.text**：用于文本处理的类，包括日期格式化、数字格式化等。
12.  **java.util.regex**：正则表达式类，用于文本模式匹配和处理。
13.  **java.nio**：新的I/O（Non-blocking I/O）库，提供了更强大的I/O操作支持。

---

## `java.lang`

`java.lang` 是Java语言中的一个核心包（package），包含了一些最基本的类，通常不需要显式导入即可使用。这个包中的类提供了Java程序的基本功能和特性。以下是关于`java.lang`包的大纲：

1. **Object类**：
   - `java.lang.Object`是所有类的超类。它定义了一些通用的方法，如`equals()`（用于比较对象是否相等）、`hashCode()`（返回对象的哈希码值）、`toString()`（返回对象的字符串表示）等。
   
2. **基本数据类型包装类**：
   - `java.lang`包中包括了基本数据类型（int、float、boolean等）的包装类，如`Integer`、`Float`、`Boolean`等，用于将基本数据类型转换为对象，以便在集合等数据结构中使用。

3. **String类**：
   - `java.lang.String`用于表示字符串，提供了丰富的字符串操作方法，包括拼接、分割、替换、大小写转换等。

4. **异常类**：
   - `java.lang`包中包含了异常相关的类，如`Throwable`（所有异常类的根类）、`Exception`（通用异常类）、`RuntimeException`（运行时异常的基类）等。这些类用于处理程序中的异常情况。

5. **线程相关类**：
   - `java.lang.Thread`类用于创建和管理线程，它包括线程的生命周期、同步、睡眠等方法。`java.lang.Runnable`接口用于实现线程的运行逻辑。

6. **包装类**：
   - 除了基本数据类型的包装类外，`java.lang`还包含了其他一些包装类，如`Character`（字符包装类）和`Double`（双精度浮点数包装类）等。

7. **数学相关类**：
   - `java.lang.Math`类包含用于执行基本数学运算的方法，如绝对值、幂运算、对数、三角函数等。

8. **枚举类**：
   - `java.lang.Enum`是所有枚举类的超类，它定义了枚举常量的基本行为。

9. **系统类**：
   - `java.lang.System`类提供了与系统交互的方法，如标准输入输出、系统属性、环境变量等。

10. **ClassLoader类**：
    - `java.lang.ClassLoader`用于动态加载类，实现类加载的自定义逻辑。

11. **其他**：
    - `java.lang.Character`（字符操作）、`java.lang.StringBuilder`和`java.lang.StringBuffer`（字符串构建和操作）等其他类和接口。

`java.lang`包中的类和接口提供了Java程序的基础设施，这些类通常无需导入，因为它们自动包含在Java程序中。这些类是所有Java程序的基础，无论是简单的命令行工具还是复杂的企业级应用程序。

### `java.lang.Math`

-   Java Summary: Math Class, <https://www.cs.rutgers.edu/courses/111/classes/fall_2011_tjang/texts/notes-java/summaries/summary-math.html>

### `java.util.Random`

-   Java Summary: Math.random() and java.util.Random, <https://www.cs.rutgers.edu/courses/111/classes/fall_2011_tjang/texts/notes-java/summaries/summary-random.html>

### `java.util.Date`



## `java.text`

### `java.text.DateFormat`

### `java.text.SimpleDateFormat;`