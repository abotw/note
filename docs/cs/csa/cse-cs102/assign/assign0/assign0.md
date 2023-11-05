---
Date: Sun Oct  1 21:43:42 CST 2023
---
# Assign 0

- [Assignment 0: Intro to Unix and C](https://web.stanford.edu/class/archive/cs/cs107/cs107.1206/assign0/)

## 入侵者检测

### Q1

**`diff`**

- [x] diff, <https://faculty.cs.niu.edu/~mcmahon/CS241/Notes/Unix_Reference/command_diff.html>
- [ ] cht.sh/diff, <https://cht.sh/diff>
- [ ] <https://www.cs.fsu.edu/~engelen/courses/COP4342/Assignment_2.pdf>
- [ ] <https://users.csc.calpoly.edu/~phatalsk/references/howToTestUsingRedirectionAndDiff.html>
- [ ] <https://www.math.utah.edu/docs/info/diff_3.html>

**`grep`**

- <https://informatics.fas.harvard.edu/short-introduction-to-grep.html>

``` title="readme.txt"
File: readme.txt
Assignment: assign0
----------------------

Hint: You should use Unix commands as much as possible, even if other by-hand alternatives exist (as a clarification, commands within the Emacs text editor are not Unix commands).

Q1: What is the username of the intruder? Include the details on how you figured out the answer, and what Unix command(s) you used.
A1:
    1. `mattv`
    2. 
    ``` sh
    $ cd ~/cs102/assignments/assign0/samples/server_files
    $ ls home | diff - users.list`
```

Q2: There is one file in the intruder's home directory that provides critical information about their activities. What file is that and what does it contain? Include the details on how you figured out the answer, and what Unix command(s) you used.
A2:
    1. `.bash_hisoty`
        2. 该文件用来存储在 bash shell 中已经执行过的所有历史命令。（在每个终端会话中输入的每条命令，都会被记录于此，以便将来在终端中复用这些命令。）
        3. 
        ``` sh
        $ cd ~/cs102/assignments/assign0/samples/server_files/home/mattv
        $ tree -a
        $ cat .bash_history | grep -A 2 -B 2 sudo
        ```

Q3: Which commands did the intruder execute using sudo? Include the details on how you figured out the answer, and what Unix command(s) you used.
A3:
    1. `grep`
    2. 通过 `cat .bash_history | grep -A 2 -B 2 sudo` 可以查看到入侵者 `mattv` 使用 `sudo` 执行了如下命令：
        - `sudo dmesg`
        - `sudo emacs /etc/passwd`
        - `sudo cp -r /etc /mnt/usb/etc`
        - `sudo su`
```

### Q1

Q1: What is the username of **the intruder**? Include the details on how you figured out the answer, and what Unix command(s) you used.

Q1：入侵者的名字是什么呢？你是用什么命令发现的？

1. `mattv`
2. 
``` sh
$ cd ~/cs102/assignments/assign0/samples/server_files
$ ls home | diff - users.list`
```

``` sh
boaw@stickmind:~/cs102/assignments/assign0/samples/server_files$ ls home | diff - users.list
39d38
< mattv
boaw@stickmind:~/cs102/assignments/assign0/samples/server_files$ ls home | diff -u - users.list
--- -	2023-10-01 20:59:41.474670585 +0800
+++ users.list	2023-01-14 22:51:49.867235024 +0800
@@ -36,7 +36,6 @@
 louiek
 marcoa
 martins
-mattv
 meeraj
 nimitg
 paolan
```

---

参考答案（231019）：

```sh
$ diff <(ls home/) <(cat user.list)
```

### Q2

Q2: There is one file in the intruder's home directory that provides critical information about their activities. What file is that and what does it contain? Include the details on how you figured out the answer, and what Unix command(s) you used.

Q2：在这些隐藏的文件中，有一个文件记录了入侵者所有的活动记录，这个文件是什么呢？它包含了什么内容？

1. `.bash_hisoty`
2. 该文件用来存储在 bash shell 中已经执行过的所有历史命令。（在每个终端会话中输入的每条命令，都会被记录于此，以便将来在终端中复用这些命令。）
3. 
    ``` sh
    $ cd ~/cs102/assignments/assign0/samples/server_files/home/mattv
    $ tree -a
    ```

``` sh
boaw@stickmind:~/cs102/assignments/assign0/samples/server_files$ cd home
boaw@stickmind:~/cs102/assignments/assign0/samples/server_files/home$ cd mattv/
boaw@stickmind:~/cs102/assignments/assign0/samples/server_files/home/mattv$ tree -a
.
├── .bash_history
├── .bashrc
└── .emacs

0 directories, 3 files
```

---

参考答案（231019）：

```sh
home$ du --max-depth=1 .
home$ cd mattv && ls -a
mattv$ cat .bash_history | grep sudo
```

#### Explanation of `.bash_history`, `.bashrc`, and `.emacs` Files

These three files, `.bash_history`, `.bashrc`, and `.emacs`, are typically associated with Unix-like operating systems and are used for different purposes. These files play crucial roles in customizing and enhancing your experience with the Bash shell and Emacs text editor, helping you work more efficiently and effectively in a Unix-like environment.

```title=".bash_history"
cd work
ls
cd project/
ls
emacs program.c
make
./program
./program 4
emacs program.c
make
emacs program.c
make
./program
emacs program.c
make
./program 4
./program
gdb program
emacs program.c
make
./program
./program 4
cd ..
cd server
make
make clean
make
./server
./server &
ps
ls
emacs config.h
grep PORT *
emacs config.h
make
./server &
pushd ../project
./program
fg
exit
sudo dmesg
cd work
ls
cd project/
ls
emacs program.c
make
./program
./program 4
emacs program.c
make
emacs program.c
make
./program
emacs program.c
make
./program 4
./program
gdb program
emacs program.c
make
./program
./program 4
cd ..
cd server
make
make clean
make
./server
./server &
ps
ls
emacs config.h
grep PORT *
emacs config.h
make
./server &
pushd ../project
./program
fg
exit
cd work
ls
cd project/
ls
emacs program.c
make
./program
./program 4
emacs program.c
make
emacs program.c
make
./program
emacs program.c
make
./program 4
./program
gdb program
emacs program.c
make
./program
./program 4
cd ..
cd server
make
make clean
make
./server
./server &
ps
ls
emacs config.h
grep PORT *
emacs config.h
make
./server &
pushd ../project
./program
fg
exit
cd work
ls
cd project/
ls
emacs program.c
make
./program
sudo emacs /etc/passwd
sudo cp -r /etc /mnt/usb/etc
./program 4
emacs program.c
make
emacs program.c
make
./program
emacs program.c
make
./program 4
./program
gdb program
emacs program.c
make
./program
./program 4
cd ..
cd server
make
make clean
make
./server
./server &
ps
ls
emacs config.h
grep PORT *
emacs config.h
make
./server &
pushd ../project
./program
fg
exit
cd work
ls
cd project/
ls
emacs program.c
make
./program
./program 4
emacs program.c
make
emacs program.c
make
./program
emacs program.c
make
./program 4
./program
gdb program
emacs program.c
make
./program
./program 4
cd ..
cd server
make
make clean
sudo su
make
./server
./server &
ps
ls
emacs config.h
grep PORT *
emacs config.h
make
./server &
pushd ../project
./program
fg
exit
```

- **Function/Usage**: This file is used **to store a history of commands** that have been executed in the Bash shell. Each time you run a command in a terminal session, it is recorded in this file, allowing you to recall and reuse previous commands.
- **Explanation**: When you press the "up" arrow key in your terminal, you can cycle through previously executed commands, which are retrieved from this history file. It's a helpful feature for saving time and avoiding retyping frequently used commands.

`.bashrc`

``` title=".bashrc"
# Nice work finding this hidden file!  But this might not be the file you're
# looking for.  This is a (blank) "shell" file containing any terminal
# commands the user would like to execute when your myth command-line session
# begins. It looks like this user has a blank one!
#
# While we won't be using .bashrc files in cs102, here is some more information
# if you're interested.  Your .bashrc file is located at ~/.bashrc.  This file
# is used for helpful things, like:
#
# - changing your prompt text (the text that is displayed in your terminal
# that prompts you to type terminal commands).  By default, on Linux this is
# usually something like "xuehao@cs102:~$". You can change it by adding the
# following line:
#
#	PS1="yourprompttexthere: "
#
# If you do this, the prompt text will be changed. Instead of
#
#	xuehao@cs102:~$
#
# you'll see
#
#	yourprompttexthere:
#
# You can also do other things, like defining things called "aliases",
# or change things called "environment variables".  Search online for more
# information about these, and other things you can do in your .bashrc file.
```

- **Function/Usage**: This is **a shell script file** that is executed whenever a new interactive Bash shell session is started. It is commonly used to customize the **behavior** and **appearance** of your Bash shell.
- **Explanation**: You can add various configurations and settings to your `.bashrc` file, such as: 1. setting environment variables, 2. defining aliases for commands, 3. changing the shell prompt (PS1), and more. Any changes you make to this file will take effect the next time you open a terminal or start a new shell session. It's a powerful tool for tailoring your command-line experience to your preferences.

``` title=".emacs"
; Nice work finding this hidden file!  But this might not be the file you're
; looking for.  This is a (blank) configuration file used for the Emacs text
; editor.  It looks like this user is an Emacs user!

; For information for how you can use Emacs, check out the Resources page of
; the course website.  In particular, make sure you follow the instructions to
; download the Emacs configuration file we provide in cs102 so you can have one
; too.  With our configuration file, you can take advantage of convenient
; features like indenting and mouse controls.
```

- **Function/Usage**: This file is associated with **the Emacs text editor**. It is your personal configuration file where you can define custom settings, keybindings, and preferences for your Emacs environment.
- **Explanation**: Emacs is an extensible text editor known for its versatility and powerful customization capabilities. The `.emacs` file allows you to tailor Emacs to your specific needs. You can set up various modes, customize keybindings, load extensions, and define macros, among other things. Your `.emacs` file essentially personalizes your Emacs experience, making it a more efficient and enjoyable text editor for your workflow.

### Q3

如果想对系统实施破坏行为，必须使用 `sudo` 权限执行某些命令。在上述文件中，你会发现整个活动记录非常长，很难发现哪些命令用到了特权权限。

Q3: Which commands did the intruder execute using sudo? Include the details on how you figured out the answer, and what Unix command(s) you used.

Q3：用什么命令可以方便地提取出这些信息？入侵者使用 `sudo` 执行了哪些命令？

1. `grep`
2. 通过 `cat .bash_history | grep -A 2 -B 2 sudo` 可以查看到入侵者 `mattv` 使用 `sudo` 执行了如下命令：
    - `sudo dmesg`
    - `sudo emacs /etc/passwd`
    - `sudo cp -r /etc /mnt/usb/etc`
    - `sudo su`

``` sh
boaw@stickmind:~/cs102/assignments/assign0/samples/server_files/home/mattv$ cat .bash_history | grep sudo
sudo dmesg
sudo emacs /etc/passwd
sudo cp -r /etc /mnt/usb/etc
sudo su
boaw@stickmind:~/cs102/assignments/assign0/samples/server_files/home/mattv$ cat .bash_history | grep -A 2 -B 2 sudo
fg
exit
sudo dmesg
cd work
ls
--
make
./program
sudo emacs /etc/passwd
sudo cp -r /etc /mnt/usb/etc
./program 4
emacs program.c
--
make
make clean
sudo su
make
./server
```

Here's an explanation of each of the provided commands:

1. `sudo dmesg`:
   - `sudo`: This command is used to execute the following command with superuser (administrative) privileges.
   - `dmesg`: This command is used to display the kernel ring buffer, which contains messages related to the operation of the Linux kernel and hardware. It can provide information about system events, hardware, and drivers.

   When you run `sudo dmesg`, you are displaying the kernel messages with elevated privileges. This is often useful for diagnosing hardware-related issues and checking system logs.

2. `sudo emacs /etc/passwd`:
   - `sudo`: As before, this runs the following command with superuser privileges.
   - `emacs`: This command launches the Emacs text editor.
   - `/etc/passwd`: This is the path to the `/etc/passwd` file, which contains user account information on a Unix-like system.

   Running this command opens the `/etc/passwd` file in the Emacs text editor with superuser permissions. You would typically edit this file to make changes to user account information, but it should be done with caution as it can affect system user accounts.

3. `sudo cp -r /etc /mnt/usb/etc`:
   - `sudo`: Executes the following command with superuser privileges.
   - `cp`: The `cp` command is used to copy files and directories.
   - `-r`: This option is used with `cp` to copy directories and their contents recursively.
   - `/etc`: This is the source directory you want to copy, which is the system-wide configuration directory on Unix-like systems.
   - `/mnt/usb/etc`: This is the destination directory where you want to copy the contents of the `/etc` directory, presumably to an external USB drive mounted at `/mnt/usb`.

   This command copies the entire `/etc` directory and its subdirectories to a location on an external USB drive, typically used for creating backups or transferring system configuration files.

4. `sudo su`:
   - `sudo`: Again, this command is used to execute the following command with superuser privileges.
   - `su`: The `su` command stands for "switch user" and is used to open a new shell session as the superuser (root) or another specified user.

   When you run `sudo su`, you're effectively switching to a superuser shell session, which allows you to execute commands as the root user. This can be useful when you need to perform administrative tasks that require elevated permissions.

Please exercise caution when using `sudo` and be mindful of the potential impact of commands, especially when working with system configuration files and as the root user. Mistakes can lead to system instability or data loss.

## 谢尔宾基斯分形

**`error()` <= `<error.h>`**

- [x] [error(3) — Linux manual page](https://man7.org/linux/man-pages/man3/error.3.html)

**`atoi()` <= `<stdlib>`**

- [x] [atoi @OS/161 Reference Manual](https://www.cs.hmc.edu/~geoff/classes/hmc.cs134.201209/man/libc/atoi.html)

- <https://nmu.edu/Webb/ArchivedHTML/MathComputerScience/c_programming/c_068.htm>
- <https://acm2006.scusa.lsu.edu/doc/cppreference/stdstring/atoi.html>
- <https://ld2011.scusa.lsu.edu/cppreference/wiki/c/string/atoi>
- <https://web.stanford.edu/class/archive/cs/cs107/cs107.1236/lab2/extra.html>
- <https://www.cs.swarthmore.edu/~newhall/unixhelp/C_commandlineargs.php>
- <https://web.stanford.edu/class/archive/cs/cs107/cs107.1202/lab2/>
- <https://cs50.harvard.edu/x/2023/problems/3/atoi/>

``` c title="triangle.c" linenums="1"
/**
 * File: triangle.c
 * --
 * This program outputs an ascii representation of the Sierpinski triangle.
 *
 * The pattern of stars is generated using a bitwise AND
 * on the coordinates. This works due to the relationship
 * between the fractal and Pascal's triangle.
 * https://en.wikipedia.org/wiki/Sierpinski_triangle
 */

#include <stdio.h>

// Define a C constant for the level number to use when not specified by the user
#define DEFAULT_LEVELS 3

/**
 * FUNCTION: print_triangle
 * ------------------------
 * This function prints out a sierpinksi triangle of *s of the given
 * number of levels, which is assumed to be non-negative.
 */
void print_triangle(int nlevels) {
    int size = 1 << nlevels;

    for (int row = size - 1; row >= 0; row--) {
        for (int col = 0; col < row; col++) {
            printf(" ");
        }
        for (int col = 0; col + row < size; col++) {
            printf("%c ", (col & row) ? ' ' : '*');
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int nlevels = DEFAULT_LEVELS;

    print_triangle(nlevels);
    return 0;
}
```

