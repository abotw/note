# scanf

## scant() 的返回值

当使用 `scanf()` 函数读取输入时，可以根据其返回值判断读取操作的结果。

| 返回值 | 含义                                             |
| ------ | ------------------------------------------------ |
| 正整数 | 成功读取的变量数量                               |
| 0      | 无法匹配输入项或输入项不是有效的格式             |
| `EOF`  | 到达了输入流的末尾（可以使用 *键盘输入结束符* ） |

``` c linenums="1" title="Error Handling Example: Reading Integers Using scanf() 使用 scanf() 函数读取整数的错误处理示例"
#include <stdio.h>

int main()
{
    int num;
    
    printf("Enter an integer: ");
    int result = scanf("%d", &num);
    
    if (result == 1)
        printf("Successfully read an integer: %d\n", num);
    else if (result == 0)
        printf("Invalid input. Not an integer.\n");
    else if (result = EOF)
        printf("Reached the end of input.\n");
        
    return 0;
}
```

*[键盘输入结束符]: 通常是 Ctrl+D，可以用来模拟到达输入流的末尾。