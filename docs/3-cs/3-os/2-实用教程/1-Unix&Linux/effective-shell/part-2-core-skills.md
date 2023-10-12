# Part 2 - Core Skills

## Thinking in Pipelines

!!! abstract

    **commands**
    
    -   `sort`
    -   `sed` - **s**tream **ed**itor
    -   `wc` - **w**ord, line, character and byte **c**ount
    -   `rev` - **rev**ersing the text
    -   `head` - display first lines of a file
    -   `grep` - file pattern searcher
    -   `tr`  - **tr**anslate characters, **t**o **r**eplace
    -   `tee` - 
    
    **symbols**
    
    -   `>` - the redirection symbol/operator
    -   `>>` - append redirection operator
    -   `EOF` - a heredoc
    
    **files**
    
    -   `stdin`
    -   `stdout`
    
    -   `stderr`
    
    **concepts**
    
    -   pipeline
    
    -   file descriptor

A pipeline is just a set of connected programs.

``` sh
$ ls -al /dev/std*
lr-xr-xr-x  1 root  wheel  0 Aug 23 18:51 /dev/stderr -> fd/2
lr-xr-xr-x  1 root  wheel  0 Aug 23 18:51 /dev/stdin -> fd/0
lr-xr-xr-x  1 root  wheel  0 Aug 23 18:51 /dev/stdout -> fd/1
```

-   `fd` - **f**ile **d**escriptor
-   `dev` - **dev**ice

``` sh
$ tty
/dev/ttys000
```

``` sh
$ rev < /dev/stdin
Red Rum
muR deR
```

``` sh
$ echo 'Be quiet, this is a library!' | tr '[:lower:]' '[:upper:]'
BE QUIET, THIS IS A LIBRARY!
```

What would happen is that the shell would write `stderr` to a *new file* with the name `1`! Why don't we need an ampersand *before* the `>` symbol, only for the file descriptor afterwards? This is just because the shell only supports redirecting file descriptors, so an additional ampersand would be superfluous.

## Job Control

!!! abstract

**concepts**

-   *job control*
    -   *job number*
    -   *a job identifier*
    -   *background job*
-   *process*
    -   a *process identifier*, *process ID*
-   *alias*
-   *terminal multiplexer*

**commands**

-   `bg`
-   `jobs`
-   `fg` - foreground
-   `kill` - terminates a process

**symbols**

-   `%` - *a percentage sign*

**tools**

-   screen
-   tmux

### Start the Server in the Background

In most shells, you can run a command and instruct the shell to run it in the *background*. To do this, you end the line with an ampersand.

In the same way ending a command with `&` runs it in the background, ending a job identifier with `&` *continues* it in the background.



``` sh title="Moving Background Jobs to the Foreground"
fg %1   # Explicitly bring Job 1 into the foreground

%1      # ...or in shorthand, just enter the job id...

fg      # ...if not given an id, fg and bg assume the most recent job.
```

## Understanding Commands

!!! abstract

**concepts**

-   `$PATH` - the standard environment variable used to define *where* the shell should search for programs

**commands**

-   `chmod` - change file modes

**symbols**

-   `#!` - the 'shebang'

``` sh
command param1 param2
```

