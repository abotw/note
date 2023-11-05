# Lab 2

-   Lab 2: C Strings, <https://web.stanford.edu/class/archive/cs/cs107/cs107.1242/lab2/>
-   Lab 2 Extra Problem, <https://web.stanford.edu/class/archive/cs/cs107/cs107.1242/lab2/extra.html>

-   Lab 2 Solutions, <https://web.stanford.edu/class/archive/cs/cs107/cs107.1242/lab2/solutions.html>
-   <string.h> string functions, Guide to C stdlib functions, <https://web.stanford.edu/class/archive/cs/cs107/cs107.1242/guide/stdlib#stringh-string-functions>

```c
error(1, 0, "required argument is number 1 or 2");
```

```c
#include <stdlib.h>

atoi()
```

```c
printf("strlen(uninitializedPtr) = %zu\n", strlen(uninitializedPtr));
```

```c
strncpy()
```

## Lecture Review

## Solutions

### 1) Valgrind

-   [x] Valgrind Memcheck, <https://web.stanford.edu/class/archive/cs/cs107/cs107.1242/resources/valgrind>
-   Valgrind User Manual, <https://valgrind.org/docs/manual/manual.html>

#### Error 1

```sh
$ valgrind ./buggy 1
==199627== Memcheck, a memory error detector
==199627== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==199627== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==199627== Command: ./buggy 1
==199627==
--- Making error 1: strlen called on uninitialized pointer

==199627== Use of uninitialised value of size 8
==199627==    at 0x484ED16: strlen (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==199627==    by 0x10920F: makeError1 (buggy.c:17)
==199627==    by 0x109305: main (buggy.c:39)
==199627==
==199627== Invalid read of size 1
==199627==    at 0x484ED16: strlen (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==199627==    by 0x10920F: makeError1 (buggy.c:17)
==199627==    by 0x109305: main (buggy.c:39)
==199627==  Address 0x100000000 is not stack'd, malloc'd or (recently) free'd
==199627==
==199627==
==199627== Process terminating with default action of signal 11 (SIGSEGV)
==199627==  Access not within mapped region at address 0x100000000
==199627==    at 0x484ED16: strlen (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==199627==    by 0x10920F: makeError1 (buggy.c:17)
==199627==    by 0x109305: main (buggy.c:39)
==199627==  If you believe this happened as a result of a stack
==199627==  overflow in your program's main thread (unlikely but
==199627==  possible), you can try to increase the size of the
==199627==  main thread stack using the --main-stacksize= flag.
==199627==  The main thread stack size used in this run was 8388608.
==199627==
==199627== HEAP SUMMARY:
==199627==     in use at exit: 1,024 bytes in 1 blocks
==199627==   total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
==199627==
==199627== LEAK SUMMARY:
==199627==    definitely lost: 0 bytes in 0 blocks
==199627==    indirectly lost: 0 bytes in 0 blocks
==199627==      possibly lost: 0 bytes in 0 blocks
==199627==    still reachable: 1,024 bytes in 1 blocks
==199627==         suppressed: 0 bytes in 0 blocks
==199627== Rerun with --leak-check=full to see details of leaked memory
==199627==
==199627== Use --track-origins=yes to see where uninitialised values come from
==199627== For lists of detected and suppressed errors, rerun with: -s
==199627== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```

#### Error 2

```sh
$ valgrind ./buggy 2
==200051== Memcheck, a memory error detector
==200051== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==200051== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==200051== Command: ./buggy 2
==200051==
--- Making error 2: strlen called on string without null terminator

==200051== Conditional jump or move depends on uninitialised value(s)
==200051==    at 0x484ED28: strlen (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==200051==    by 0x10926C: makeError2 (buggy.c:25)
==200051==    by 0x109317: main (buggy.c:41)
==200051==
strlen(non-terminated) = 3
==200051==
==200051== HEAP SUMMARY:
==200051==     in use at exit: 0 bytes in 0 blocks
==200051==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==200051==
==200051== All heap blocks were freed -- no leaks are possible
==200051==
==200051== Use --track-origins=yes to see where uninitialised values come from
==200051== For lists of detected and suppressed errors, rerun with: -s
==200051== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

### 2) Code Study: `strtok`

#### Using `strtok` (10 minutes)

#### `strtok` Implementation (20 minutes)

-   The musl strtok string library function in C, <https://www.youtube.com/watch?v=Eu4pXgvQnK8>

```c
strspn()
strcpy()
```

```c title="token.c"
/**
 * File: token.c
 * -------------
 * Implementation of strtok for code study.
 * Read lab2 writeup for more information.
 */

#include <stdio.h>
#include <string.h>

char* musl_strtok(char* s, const char* delimiters) {
    static char* p = NULL;

    if (s == NULL) {
        s = p;
        if (s == NULL) {
            return NULL;
        }
    }

    s += strspn(s, delimiters);
    if (*s == '\0') {
        p = NULL;
        return p;
    }

    p = s + strcspn(s, delimiters);
    if (p[0] != '\0') {
        p[0] = '\0';
        p++;
    } else {
        p = NULL;
    }

    return s;
}

void tokenizationLoop(char* input, const char* delimiters) {
    char* token = musl_strtok(input, delimiters);
    while (token != NULL) {
        printf("%s\n", token);
        token = musl_strtok(NULL, delimiters);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    char* str = "red-green-blue";
    char* first;
    char copy[strlen(str) + 1];
    strcpy(copy, str);

    // (uncomment line below) attempt to tokenize string constant fails at runtime. Why?
    // first = musl_strtok(str, "-");

    // but ok to tokenize copy. Why? What's different?
    first = musl_strtok(copy, "-");
    printf("First token is %s\n", first);

    // Example tokenization loop
    char path[] = "/home/cs102-shared/labs/lab2";
    tokenizationLoop(path, "/");

    return 0;
}

```



### 3) Code Study: `atoi` (Lab 2 Extra Problem)

<https://web.stanford.edu/class/archive/cs/cs107/cs107.1242/lab2/extra.html>

-   `atoi`
-   `strtol`

```c linenums="1"
 1    int musl_atoi(const char *s) {
 2        while (isspace(*s)) {
 3            s++;
 4        }
 5
 6        bool negative = false;
 7        switch (*s) {
 8            case '-':
 9                negative = true;
10            case '+':
11                s++;
12        }
13   
14        /* Compute as a negative number to avoid overflow on INT_MIN */
15        int number = 0;
16        while (isdigit(*s)) {
17            number = 10 * number - (*(s++) - '0');
18        }
19    
20        return negative ? number : -number;
21    }

```



>   **Q1:** [Line 2] What does the expression `*s` evaluate to? What is another equivalent way to write this expression? (Perhaps this alternate way would be preferred for readability, but alas...)

**A1:** `*s` gets the first character of `s`; an alternate way to write this is `s[0]`.

>   **Q2:** [Line 3] What does the expression`s++` do to `s`?

**A2:** This advances `s` to point to the next character in the string. This loop is advancing the `s` pointer past any space characters at the start of the string.

>   **Q3:** [Lines 6-12] If the string begins with a leading minus, at what point does it advance `s` past that char? This is subtle! (The [*fallthrough*](https://en.wikipedia.org/wiki/Switch_statement#Fallthrough) behavior of a switch statement can be surprising and often triggered by accident, so a comment noting there is intentionally no break statement would probably have been a good idea, but alas...)

**A3:** This `switch` statement is looking for a possible leading sign character (+/-). If the string begins with a leading minus, it will execute *both* cases because it "falls through" to the second one. If it finds a "-" sign, it updates the boolean to reflect this, and *also increments s* to advance past that character. Switch statement cases "fall through" by default, unless they hit a `break` statement, and continue executing the case code below them. If it finds a "+" sign, it just increments s to advance past that character.

>   **Q4:** The code has two loops that advance along the string, but neither has an explicit test to stop at the null terminator. Why is this not necessary?

**A4:** The `isspace` and `isdigit` functions return `false` when the parameter value is the null terminator, so loops will already stop correctly.

>   **Q5:** How is a single digit character converted to its numeric value? How is that value combined with the number being built up so far?

**A5:** Subtracting `'0'` gives us the numeric value of a character digit, because ASCII digits are numbered sequentially. This code builds up the numeric value, after initializing it to zero. It loops over each character in the remaining string as long as the character is numeric; as soon as it finds a non-digit, the function stops and returns whatever value it has constructed so far. It constructs the number one digit at a time; it sets `number`'s new value to be its previous value times 10, *minus* the new digit. Note that the number is built up as a negative number and then potentially negated at the end.

>   **Q6:** [Line 17] One quirky note about `s++` is that the expression not only modifies `s`, but it also *evaluates to the original value of s* (Check out [this link](https://stackoverflow.com/questions/7031326/what-is-the-difference-between-prefix-and-postfix-operators) for more about this quirky syntax). In other words, `s++` will modify `s` but then evaluate to `s` rather than the incremented value. How is this used to make the string processing more concise?

**A6:** In the expression `number = 10 * number - (*(s++) - '0');`, `s++` increments the pointer one space but evaluates as a whole to the character `s` originally points to. This allows us to advance the string pointer in the same expression where we are accessing the current character.

>   **Q7:** [Lines 15-20] The loop builds up `n` as a negative value and later negates it. The comment indicates this choice avoids overflow on `INT_MIN`. Why does `INT_MIN` seem to necessitate its own special case? Why does `atoi` construct a numeric value as a negative number instead of a positive number?

**A7:** The number is built up as a negative number because, if the user wants to convert `INT_MIN`, that cannot be represented as a positive number, because it would overflow. Conversely, every positive number has a representable negative equivalent. That being said, *technically* it will still work even without the special case, since the overflow will result in `INT_MIN` and `-INT_MIN` is still `INT_MIN`. But this special case avoids this overflow behavior.

>   **Q8:** What happens when the input string contains a non-digit char? What if that non-digit char is the very first character?

**A8:** If it's a space, `atoi` will move to the next character. If it's any other character, `number` is initialized at 0, and so `atoi` will return 0. This is because in the digit-processing loop, as soon as it finds a non-digit, the loop stops and returns whatever value it has constructed so far (which is initially 0).

>   **Q9:** [Line 20] Note that the *ternary* expression (with the question mark and colon) is evaluated using the form "CONDITION ? IF_TRUE : IF_FALSE". Try applying this to interpret the return statement above.

**A9:** Another way to read this is "if `negative` is true, return `number`; otherwise, return `-number`."

>   **Q10:** What about an input that is outside the representable range of integer? If the string is a number larger than `INT_MAX`, will it overflow, saturate, return 0, raise an error, or do something else entirely?

**A10:** It overflows in constructing the value `number` in the while loop, but otherwise doesn't crash or raise an error.

