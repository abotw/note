# Part 1 - Transitioning to the Shell

Homebrew 安装 bash 的路径：`/opt/homebrew/bin/bash`

``` sh
bash-5.2$ echo $BASH_VERSION
5.2.15(1)-release
```

## Navigating Your System

!!! abstract

    **commands**
    
    1.   `pwd`
    2.   `ls`
    3.   `cd`
    4.   `pushd`
    5.   `popd`
    
    **concepts**
    
    1. 		the working directory: relative paths, absolute paths, the special dot and dot dot folders, the home directory
    2.		the working directory stack
    3.		environment variables
    4.		paths, addresses

``` sh
$ echo "My current working directory is: $PWD"
$ echo "My home directory is: $HOME"
```

The `pushd` command 'pushes' a new working directory onto a stack - moving you there.

The `popd` command 'pops' the working directory off the top of the stack.

These commands can be useful if you need to move to other locations but want to be able to quickly go back to where you were before afterwards.

![pushd-and-popd-stack](https://effective-shell.com/assets/images/pushd-popd-stack-ccd34132d513841c5b1d97c842b0413f.png)

## Managing Your Files

This chapter will introduce the `wget`, `unzip`, `cp`, `mv`, `rm`, `mkdir`, `rmdir`, `cat` and `zip` commands. We'll also briefly look at *wildcards* and *redirection*.

!!! abstract

    **commands**
    
    1. `wget`
    2. `file`
    3. `unzip`
    4. `cp`
    5. `mv`
    6. `rm`
    7. `mkdir`
    8. `rmdir`
    9. `cat`
    10. `zip`
    11. `tree`
    
    **concepts**
    
    1.   wildcards
    2.   redirection

## Becoming a Clipboard Gymnast

!!! abstract

    **commands**
    
    -   `pbcopy`
    -   `pbpaste`
    
    **concepts**
    
    -   *aliases*
    -   *pipelines*
    
    **tools**
    
    -   Clipboard

The vertical bar `|` is the *pipe* operator. It tells the shell to take the output from the command on the left and send it straight to the *input* of the program on the right.

## Getting Help

!!! abstract

    **tools**
    
    -   `man`
    -   pager
    -   `tldr`
    -   `cat.sh`

### less

-   `d` - Scroll down half a page
-   `u` - Scroll up half a page
-   `j` / `k` - Scroll down or up a line. You can also use the arrow keys for this
-   `q` - Quit
-   `/<search>` - Search for text
-   `n` - When searching, find the next occurrence
-   `N` - When searching, find the previous occurrence

``` sh
$ echo $PAGER
less
```

``` sh
$ man 1 intro # man <section> <search>
```

``` sh
$ npm install -g tldr
```

## The Renaissance of the Shell

