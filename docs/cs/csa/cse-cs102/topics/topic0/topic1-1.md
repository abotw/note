# Note 1. Windows 模拟 Linux 环境

*阅读：<https://cs102.stickmind.com/reader/topic_0/linux_on_windows.html>*

### Who Is Using MSYS2?

-   [Git for Windows](https://gitforwindows.org/) is based on MSYS2

-   [Neovim](https://github.com/neovim/neovim) uses MSYS2 for its Windows building and running ([Documentation](https://github.com/neovim/neovim/wiki/Building-Neovim#windows--msys2--mingw)).

### What is MSYS2?

>   **MSYS2** is a collection of tools and libraries providing you with an easy-to-use environment for building, installing and running native Windows software.

---

>   MSYS2 isn't "one tool to rule them all", but tries to focus on what it's good at. It provides **a native build environment**, based on open source software, and makes you feel right at home when you are already comfortable with Linux.

---

>   MSYS2 allows you to build native Windows programs.

---

>   MSYS2 focuses on **building native software** built against the Windows APIs.

---

>   Cygwin is an operating system wrapper
>
>   The goal of Cygwin is to provide a Linux Programming API.
>
>   Msys is a command shell substitute
>
>   The goal of Msys is to provide a POSIX scripting environment.
>
>   Scoop is an installer
>
>   The goal of Scoop is to let you use Unix-y programs in a normal Windows environment
>
>   *参见：<https://github.com/ScoopInstaller/Scoop/wiki/Cygwin-and-MSYS-Comparison>*

## Installation

*参见：<https://www.msys2.org/#installation>*

## Pacman

``` sh
# Synchronize and update all packages
$ pacman -Suy	# -u, --upgrades; -y, --refresh
# Install a new package
$ pacman -S package_name	# -S, --sync
# Remove a package and its dependencies
$ pacman -Rs package_name	# -R, --remove
```

## Others

**Main**

-   [MSYS2](https://www.msys2.org/) - Software Distribution and Building Platform for Windows
    -   [MSYS2 Packages](https://packages.msys2.org/base)
        -   [Base Package: make](https://packages.msys2.org/base/make)
        -   [Base Package: openssh](https://packages.msys2.org/base/openssh)
        -   [Group: mingw-w64-ucrt-x86_64-toolchain](https://packages.msys2.org/groups/mingw-w64-ucrt-x86_64-toolchain)
            -   gcc
            -   gdb
            -   pkgconf
            -   ...
        -   [Package: mingw-w64-ucrt-x86_64-cmake](https://packages.msys2.org/package/mingw-w64-ucrt-x86_64-cmake?repo=ucrt64)
        -   [Package: mingw-w64-ucrt-x86_64-ninja](https://packages.msys2.org/package/mingw-w64-ucrt-x86_64-ninja?repo=ucrt64)
    -   [x] [Package Management](https://www.msys2.org/docs/package-management/)
    -   [ ] [Mirrors](https://www.msys2.org/dev/mirrors/) TODO
-   [Pacman](https://archlinux.org/pacman/) - A simple library-based package manager.
    -   [pacman(8)](https://archlinux.org/pacman/pacman.8.html)

**Windows Terminal Emulators**

-   [Mintty](https://mintty.github.io/) - Mintty is a [terminal emulator](http://en.wikipedia.org/wiki/Terminal_emulator) for [Cygwin](http://cygwin.com/), [MSYS](https://web.archive.org/web/20210101000000*/mingw.org/wiki/MSYS) or [Msys2](https://github.com/msys2), and derived projects, and for [WSL](https://github.com/mintty/wsltty).

-   [Cygwin](https://cygwin.com/) - Get that [Linux](https://www.linuxfoundation.org/) feeling - on Windows
-   WSL

**Windows Package Managers**

-   [Chocolatey](https://chocolatey.org/) - The Package Manager for Windows & Modern Software Automation
-   [Scoop](https://scoop.sh/) - A command-line installer for Windows

**Linux Distributions & Development Tools**

-   [Arch Linux](https://archlinux.org/) - A simple, lightweight distribution
-   [Mingw-w64](https://www.mingw-w64.org/)

-   [GCC](https://gcc.gnu.org/) - the GNU Compiler Collection
-   [GDB](https://www.sourceware.org/gdb/) - The GNU Project Debugger
-   [CMake](https://cmake.org/)
-   [Ninja](https://ninja-build.org/)
-   [GNU Make](https://www.gnu.org/software/make/)

**SSH & Security Tools**

-   [OpenSSH](https://www.openssh.com/)

## Doc Backup

>   **录播 🎥**：**开发环境 Linux & C**/1. Windows 模拟 Linux 环境-V230911.mp4

### [本节目标](https://cs102.stickmind.com/reader/topic_0/linux_on_windows.html#本节目标)

由于大部分同学使用 Windows 系统，在 Windows 平台体验 Linux 开发工具也是可以的。完成本节内容的学习，你应该能够尝试解决以下问题：

-   什么是 MSYS2？如何安装 MSYS2？
-   如何使用 `pacman` 包管理工具更新、安装、删除软件包？
-   如何修改 MSYS2 国内源？
-   如何使用 MSYS2 编译/运行 C 程序？

### [安装 MSYS2 开发工具](https://cs102.stickmind.com/reader/topic_0/linux_on_windows.html#安装-msys2-开发工具)

[MSYS2](https://www.msys2.org/) 提供了一个易于使用的类 Linux 环境来构建、安装和运行本机 Windows 软件。配合 VS Code 等开发工具，可以搭建一个较为轻量的开发环境。对于一些 POSIX 依赖不太严格的测试，比起使用 Linux 虚拟机更为直接、方便。

安装过程，有以下几点需要注意：

-   国内用户建议**断网安装**，避免中途出现更新密钥卡死的问题
-   安装完后，国内用户建议**修改国内软件源**，提高下载速度
-   后续软件体积较大，建议安装在非 C 盘根目录
-   建议使用 MSYS2 UCRT 子系统，和课程保持一致
-   优先安装 `mingw-w64-ucrt-x86_64-` 前缀的软件包

常用命令总结如下，方便后续使用查询，参考连接：[Package Management](https://www.msys2.org/docs/package-management/)

-   更新 MSYS2 组件，修改源后建议更新两次

    ```
    pacman -Suy
    ```

-   安装 `openssh` 可用于后续连接远程服务器

    ```
    pacman -S openssh
    ```

-   安装 `gcc`、`gdb`、`pkg-config` 等常用开发工具

    ```
    pacman -S mingw-w64-ucrt-x86_64-toolchain
    ```

-   安装 `make`，`cmake`，`ninja` 等构建工具

    ```
    pacman -S make mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja
    ```

### [编译运行 C 程序](https://cs102.stickmind.com/reader/topic_0/linux_on_windows.html#编译运行-c-程序)

在 MSYS2 当前目录创建一个 `hello.c` 文件，输入以下代码：

```c
#include <stdio.h>

int main(void) {
    printf("Hello World.\n");
    return 0;
}
```

使用以下命令编译你的第一个 C 程序：

```
gcc hello.c -o hello
```

运行该程序，需要以 `./` 开头执行以下命令：

```
./hello
```

前缀 `./` 表示在当前目录下寻找 `hello` 程序。

*[ucrt]: universal c run time