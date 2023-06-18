# Process

## ps

`-e, -A`

:	-

`-f`

:	-

``` sh linenums="1" hl_lines="3-4 24-25 30-31"
$ curl cheat.sh/ps
 cheat:ps 
# To list every process on the system:
ps aux

# To list a process tree:
ps axjf

# To list every process owned by foouser:
ps -aufoouser

# To list every process with a user-defined format:
ps -eo pid,user,command

# Exclude grep from your grepped output of ps.
# Add [] to the first letter. Ex: sshd -> [s]shd
ps aux | grep '[h]ttpd'

 tldr:ps 
# ps
# Information about running processes.
# More information: <https://manned.org/ps>.

# List all running processes:
ps aux

# List all running processes including the full command string:
ps auxww

# Search for a process that matches a string:
ps aux | grep string

# List all processes of the current user in extra full format:
ps --user $(id -u) -F

# List all processes of the current user as a tree:
ps --user $(id -u) f

# Get the parent PID of a process:
ps -o ppid= -p pid

# Sort processes by memory consumption:
ps --sort size

$
```

## ` top`

``` sh linenums="1" hl_lines="32" title="cheat.sh/top"
$ curl cheat.sh/top
 cheat:top 
# To update every <interval> samples:
top -i <interval>

# To set the delay between updates to <delay> seconds:
top -s <delay>

# To set event counting to accumulative mode:
top -a

# To set event counting to delta mode:
top -d

# To set event counting to absolute mode:
top -e

# To not calculate statistics on shared libraries, also known as frameworks:
top -F

# To calculate statistics on shared libraries, also known as frameworks (default):
top -f

# To print command line usage information and exit:
top -h

# To order the display by sorting on <key> in descending order:
top -o <key>

 tldr:top 
# top
# Display dynamic real-time information about running processes.
# More information: <https://manned.org/top>.

# Start top:
top

# Do not show any idle or zombie processes:
top -i

# Show only processes owned by given user:
top -u username

# Sort processes by a field:
top -o field_name

# Show the individual threads of a given process:
top -Hp process_id

# Show only the processes with the given PID(s), passed as a comma-separated list. (Normally you wouldn't know PIDs off hand. This example picks the PIDs from the process name):
top -p $(pgrep -d ',' process_name)

# Get help about interactive commands:
?

$
```





pr: priority

virt: 虚拟内存总量

top 的字段

## linux wchan worker

## 操控进程

### kill

* `ps` / `top` -> **pid** -> `kill`

* signal
* terminate 15 -> kill 9
* kill
  * 无响应程序
  * 恶意程序

``` sh linenums="1" hl_lines="3-4 6-7 11-12 18-19 30-31"
$ curl cheat.sh/kill
 cheat:kill 
# To kill a process gracefully:
kill -15 <pid> # 15) SIGTERM

# To kill a process forcefully:
kill -9 <pid> # 9) SIGKILL

 tldr:kill 
# kill
# Sends a signal to a process, usually related to stopping the process.
# All signals except for SIGKILL and SIGSTOP can be intercepted by the process to perform a clean exit.
# More information: <https://manned.org/kill>.

# Terminate a program using the default SIGTERM (terminate) signal:
kill process_id

# List available signal names (to be used without the `SIG` prefix):
kill -l

# Terminate a background job:
kill %job_id

# Terminate a program using the SIGHUP (hang up) signal. Many daemons will reload instead of terminating:
kill -1|HUP process_id

# Terminate a program using the SIGINT (interrupt) signal. This is typically initiated by the user pressing `Ctrl + C`:
kill -2|INT process_id

# Signal the operating system to immediately terminate a program (which gets no chance to capture the signal):
kill -9|KILL process_id

# Signal the operating system to pause a program until a SIGCONT ("continue") signal is received:
kill -17|STOP process_id

# Send a `SIGUSR1` signal to all processes with the given GID (group id):
kill -SIGUSR1 -group_id

$
```

``` sh title="List available signal names (to be used without the `SIG` prefix)"
$ kill -l # 显示所有信号名称
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
63) SIGRTMAX-1  64) SIGRTMAX

```

### `pkill`

= `kilall`

``` sh linenums="1" hl_lines="3-4"
$ curl cheat.sh/pkill
 cheat:pkill 
# To kill a process using its full process name:
pkill <process-name>

# To kill a process by its partial name:
pkill -f <string>

 tldr:pkill 
# pkill
# Signal process by name.
# Mostly used for stopping processes.
# More information: <https://www.man7.org/linux/man-pages/man1/pkill.1.html>.

# Kill all processes which match:
pkill "process_name"

# Kill all processes which match their full command instead of just the process name:
pkill -f "command_name"

# Force kill matching processes (can't be blocked):
pkill -9 "process_name"

# Send SIGUSR1 signal to processes which match:
pkill -USR1 "process_name"

# Kill the main `firefox` process to close the browser:
pkill --oldest "firefox"

$
```

### `killall`

``` sh linenums="1"
$ curl cheat.sh/killall
# killall
# Send kill signal to all instances of a process by name (must be exact name).
# All signals except SIGKILL and SIGSTOP can be intercepted by the process, allowing a clean exit.
# More information: <https://manned.org/killall>.

# Terminate a process using the default SIGTERM (terminate) signal:
killall process_name

# [l]ist available signal names (to be used without the 'SIG' prefix):
killall -l

# Interactively ask for confirmation before termination:
killall -i process_name

# Terminate a process using the SIGINT (interrupt) signal, which is the same signal sent by pressing `Ctrl + C`:
killall -INT process_name

# Force kill a process:
killall -KILL process_name

$
```



### `xkill`

``` sh linenums="1" hl_lines="3"
$ curl cheat.sh/xkill
# xkill
# Kill a window interactively in a graphical session.
# See also `kill` and `killall`.
# More information: <https://www.x.org/releases/current/doc/man/man1/xkill.1.xhtml>.

# Display a cursor to kill a window when pressing the left mouse button (press any other mouse button to cancel):
xkill

# Display a cursor to select a window to kill by pressing any mouse button:
xkill -button any

$
```



