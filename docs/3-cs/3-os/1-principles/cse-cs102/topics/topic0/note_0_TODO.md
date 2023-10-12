# Lecture 01

## Linux

## C

-   Designed by [Dennis Ritchie 丹尼斯·里奇](https://en.wikipedia.org/wiki/Dennis_Ritchie)
-   First appeared: 1972
-   [TIOBE Index](https://www.tiobe.com/tiobe-index/) - The *TIOBE* Programming Community index is an indicator of the popularity of programming languages.

``` c title="hello.c"
/* File: hello.c
 * -------------
 * This program prints a welcome message to the user.
 */

#include <stdio.h> // for printf

int main(int argc, char * argc[]) {
    printf("Hello, World!\n");
  	return 0;
}
```

### 工作流程

-   ssh
-   vim / emacs
-   gcc
-   gdb

``` c title="args.c"
/* args.c
 * ------
 * This program prints out information about its received
 * command-line arguments.
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
  	printf("This program received %d argument(s)\n", argc);
  	for (int i = 0; i < argc; i ++ ) {
      	printf("Argument %d: %s\n", i, argv[i]);
    }
  	return 0;
}
```

### printf

``` c
printf(format_string, arg1, arg2, ...);
```

-   print format
-   console output
-   placeholder 格式化占位符
    -   `%s` - **s**tring
    -   `%d` - integer, **d**ecimal
    -   `%f` - double, **f**loat
    -   `%p` - **p**ointer

### bool

``` c title="C99"
#include <stdbool.h>

bool flag = true;
flag = false;
```

## 推荐阅读

-   [x] [**The Strange Birth and Long Life of Unix**](https://cs102.stickmind.com/static_files/the-strange-birth-and-long-life-of-unix.pdf), Warren Toomey, IEEE Spectrum, 28 Nov 2011
-   [x] [**“A damn stupid thing to do” - the origins of C**](https://arstechnica.com/features/2020/12/a-damn-stupid-thing-to-do-the-origins-of-c/), Arstechnica, 12/9/2020
-   [ ] [**The history of C**](https://www.bell-labs.com/usr/dmr/www/chist.html), Dennis Ritchie
-   [x] [**Dennis Ritchie: the giant whose shoulders we stand on**](https://arstechnica.com/information-technology/2011/10/dennis-ritchie-the-giant-whose-shoulders-we-stand-on/), Arstechnica, [SEAN GALLAGHER](https://arstechnica.com/author/sean-gallagher/), 10/14/2011
-   [x] K&R, ch1, cn
-   [ ] K&R, ch1, en
-   [ ] CSAPP, ch1

---

-   [BCPL](https://www.cl.cam.ac.uk/~mr10/BCPL.html)