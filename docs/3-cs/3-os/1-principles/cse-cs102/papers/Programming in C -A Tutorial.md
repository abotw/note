# Programming in C: A Tutorial

-   Brian W. Kernighan

-   Bell Laboratories, Murray Hill, N. J.

-   Online: [HTML](https://www.lysator.liu.se/c/bwk-tutor.html), [PDF](https://www.bell-labs.com/usr/dmr/www/ctut.pdf)

---

### 5. ` `Simple I/O -- getchar, putchar, printf

>   Basically, `printf` uses its first argument as formatting information, and any successive arguments as variables to be output.

``` c
printf("formatting information", variable_to_be_output_1, variable_to_be_output_2);
```

### 7. ` `While Statement; Assignment within an Expression; Null Statement

>   An assignment statement has a value, just as any other expression does. Its value is the value of the right hand side. 

``` c
int x;
printf("`x = 10` = %d", x = 10); // `x = 10` = 10
```

### 8. ` `Arithmetic

-   **integer division**
-   reminder operator, mod operator: `%`
-   **a lower case ascii character**

>   Corresponding ascii letters are a fixed distance apart.

``` c
printf("A fixed distance from 'a' to 'A': %d", 'a' - 'A'); // A fixed distance from 'a' to 'A': 32
printf("A fixed distance from 'A' to 'a': %d", 'A' - 'a'); // A fixed distance from 'A' to 'a': -32
```

``` c title="case_conversion.c"
#include <stdio.h>

int main()
{
    char c; // Declare a variable to store the input character.

    // Read characters from standard input until the null character ('\0') is encountered.
    while ((c = getchar()) != '\0')
    {
        // Check if the current character is an uppercase letter ('A' to 'Z').
        if ('A' <= c && c <= 'Z')
        {
            // If it is uppercase, convert it to lowercase and print it.
            putchar(c + 'a' - 'A');
        }
        else
        {
            // If it is not an uppercase letter, print it as it is.
            putchar(c);
        }
    }

    return 0; // Exit the program.
}

```

### 10.  Increment and Decrement Operators

>   The value of `++k` is the value of `k` *after* it has been incremented. 
>
>   The value of `k++ `is `k` *before* it is incremented.

### 13. For Statement

>   If the expression is left out, it is taken to be always true, so `for( ; ; ) ...` and `while( 1 ) ...` are both infinite loops.

-   **Infinite loops**
    -   `for ( ; ; ) ...`
    -   `while( 1 ) ... `

### 14. Functions; Comments

>   The return statement simply says to go back to the calling routine. ` `In fact, we could have omitted it, since a return is implied at the end of a function.

### 15. ` `Local and External Variables

>   External variables can be initialized; they are set to zero if not explicitly initialized.

``` c title="external_variable_print.c"
#include <stdio.h>

int n;      // Declare an integer variable 'n'.
char c;     // Declare a character variable 'c'.

int main()
{
    printf("n: %d\nc: %c", n, c); // Print the values of 'n' and 'c'.

    return 0; // Exit the program with a status code of 0.
}

```

``` title="output"
n: 0
c:
```

### 16. Pointers

>   A pointer in C is the address of something.

>   In fact, in the implementation of an array, the array name represents the address of the zeroth element of the array, so you can't use it on the left side of an expression. ` `(You can't change the address of something by assigning to it.)

``` c title="pointer_and_array.c"
#include <stdio.h>

int main()
{
    int a, *b, c;
    
    // Declare integer variables 'a', 'b', and 'c'.
    // 'b' will be a pointer to 'a'.
    b = &a; // Assign the address of 'a' to 'b'.
    c = *b; // Assign the value pointed to by 'b' (which is 'a') to 'c'.
    
    // Print the values of 'a', 'b' (as a pointer), and 'c'.
    printf("a: %d\n*b: %p\nc: %d\n", a, b, c);
    
    char *y;
    char x[100] = {'1', '2', '3', '4', '5'};
    
    // Declare a character pointer 'y'.
    // Assign the address of the first element of array 'x' to 'y'.
    printf("`y = &x[0];`: %p\n`y = x;`: %p\n", y = &x[0], y = x);
    
    // Print explanations for pointer arithmetic.
    printf("`*(y+1)` gives `x[1]`\n");
    
    // Print the value at 'y+1' (which is equivalent to 'x[1]') and 'x[1]'.
    printf("`*(y+1)`: %c\n`x[1]`: %c", *(y+1), x[1]);
    
    return 0; // Exit the program.
}

```

``` title="output"
c: 0
`y = &x[0];`: 0x7ffd7a8be560
`y = x;`: 0x7ffd7a8be560
`*(y+1)` gives `x[1]`
`*(y+1)`: 2
`x[1]`: 2
```

-   null-terminated string
-   null terminator

=== "string_length_array.c"

    ``` c title="string_length_array.c" linenums="1"
    #include <stdio.h>
    
    // Function to calculate the length of a null-terminated string.
    int length(char s[]) {
        int i = 0;
    
        // Iterate through the string until the null terminator is found.
        while (s[i] != '\0') {
            i++;
        }
    
        return i;
    }
    
    int main() {
        // Test the 'length' function with a string and print the result.
        printf("String Length: %d\n", length("hello, world!"));
    
        return 0; // Exit the program.
    }
    ```

=== "string_length_pointer.c"

    ``` c title="string_length_pointer.c" linenums="1"
    #include <stdio.h>
    
    // Function to calculate the length of a null-terminated string using pointers.
    int length(const char *s) {
        int len = 0;
    
        // Iterate through the string using a pointer until the null terminator is found.
        while (*s != '\0') {
            len++;
            s++; // Move the pointer to the next character.
        }
    
        return len;
    }
    
    int main() {
        const char *str = "hello, world!";
    
        // Test the 'length' function with a string and print the result.
        int len = length(str);
        printf("String Length: %d\n", len);
    
        return 0; // Exit the program.
    }
    ```

=== "string_length_for_loop.c" 

    ``` c title="string_length_for_loop.c" linenums="1" hl_lines="8"
    #include <stdio.h>
    
    // Function to calculate the length of a null-terminated string using a pointer.
    int length(const char *s) {
        int n;
    
        // Use a for loop to iterate through the string until the null terminator is found.
        for (n = 0; *s++ != '\0'; n++) ;
    
        return n;
    }
    
    int main() {
        const char *str = "hello, world!";
    
        // Test the 'length' function with a string and print the result.
        int len = length(str);
        printf("String Length: %d\n", len);
    
        return 0; // Exit the program.
    }
    
    ```

>   For arguments to a function, and there only, the declarations 
>
>   ``` c
>   char s[ ];
>   char *s;
>   ```
>
>   are equivalent -- a pointer to a type, or an array of unspecified size of that type, are the same thing.

#### TODO

``` c
strcopy(s,t)
  	char *s, *t; {
    	while(*t++ = *s++);
  	}
```

### 19. The Switch Statement; Break; Continue

>   Testing a value against a series of constants, the switch statement is often clearer and usually gives better code.

### 23. #define, #include

-   macro facility
