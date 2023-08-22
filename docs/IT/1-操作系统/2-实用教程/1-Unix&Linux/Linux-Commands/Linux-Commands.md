# Linux Commands

## References

- [Unix Commands Quick Reference](https://networking.ringofsaturn.com/Unix/UnixQuickReference.php)
- [Command Reference](https://networking.ringofsaturn.com/Unix/unix.php)

## CLI Keyboard Shortcuts

- [x] [Bash Shortcuts](https://gist.github.com/tuxfight3r/60051ac67c5f0445efee)
- [x] [Cheatsheet terminal](https://blog.benediktsvogler.com/blog/cheatsheet%20terminal)
- [x] [Readline keyboard shortcuts illustrated](https://loicpefferkorn.net/2014/04/readline-keyboard-shortcuts-illustrated/)
- [x] [CLI Keyboard Shortcuts | Command Line Essentials | CS61C](https://cs61c.org/sp23/labs/lab00/#cli-keyboard-shortcuts)
- [ ] [Navigating and Editing the Command Line – Bash Edition](https://mehmandarov.com/navigating-and-editing-the-command-line/)
- [ ] [Effective Shell Part 1: Navigating the Command Line](https://dwmkerr.com/effective-shell-part-1-navigating-the-command-line/)
- [ ] [一些用来提升Linux 终端操作效率的快捷键](http://blog.jcix.top/2021-10-05/shell-shortcuts/)
- [ ] [Linux terminal keyboard shortcuts](https://www.reddit.com/r/coolguides/comments/pc4f4a/linux_terminal_keyboard_shortcuts/)

<figure markdown>
  ![img](./assets/moving_cli.png){ width="500" }
  <figcaption>Windows Version, from: https://gist.github.com/tuxfight3r/60051ac67c5f0445efee</figcaption>
</figure>

<figure markdown>
  ![Cheatsheet for iTerm](./assets/cheatsheet%20Terminal%20Navigation.png){ width="500" }
  <figcaption>macOS Version, from: https://blog.benediktsvogler.com/blog/cheatsheet%20terminal</figcaption>
</figure>



<figure markdown>
  ![img](./assets/readline.png){ width="500" }
  <figcaption>Readline keyboard shortcuts illustrated, from https://loicpefferkorn.net/2014/04/readline-keyboard-shortcuts-illustrated/</figcaption>
</figure>

- [Tab] -  **autocompletion** 自动补全: autocomplete the current term 
- [Up Arrow] & [Down Arrow] - **checkout history**: move through commands you've used previously
- [Ctrl] + [a] - move the cursor to the beginning of the current line (helpful for fixing mistakes)
- [Ctrl] + [e] - move the cursor to the end of the current line (also helpful for fixing mistakes)
- [Ctrl] + [r] - let you search through your recently used commands

## Shell

### `man`

??? man
	``` sh linenums="1" hl_lines="1"
	$ curl cheat.sh/
	man
	cheat:man 
	# To convert a man page to pdf:
	man -t bash | ps2pdf - bash.pdf

	# To view the ascii chart:
	man 7 ascii
	
	# To see config:
	cat /private/etc/man.conf
	
	# To check the existence of a keyword in all of man pages:
	man -k <keyword>
	
	tldr:man 
	# man
	# Format and display manual pages.
	# More information: <https://www.man7.org/linux/man-pages/man1/man.1.html>.
	
	# Display the man page for a command:
	man command
	
	# Display the man page for a command from section 7:
	man 7 command
	
	# List all available sections for a command:
	man -f command
	
	# Display the path searched for manpages:
	man --path
	
	# Display the location of a manpage rather than the manpage itself:
	man -w command
	
	# Display the man page using a specific locale:
	man command --locale=locale
	
	# Search for manpages containing a search string:
	man -k "search_string"
	
	$
	```

### `exit`

??? exit
	``` sh linenums="1" hl_lines="4 7-8"
	$ curl cheat.sh/
	exit
	# exit
	# Exit the shell.
	# More information: <https://manned.org/exit>.

	# Exit the shell with the exit code of the last command executed:
	exit
	
	# Exit the shell with the specified exit code:
	exit exit_code
	
	$
	```

### `clear` = ⌘K - 清屏

??? clear
	``` sh linenums="1" hl_lines="4 7-8"
	$ curl cheat.sh/
	clear
	# clear
	# Clears the screen of the terminal.
	# More information: <https://manned.org/clear>.

	# Clear the screen (equivalent to pressing Control-L in Bash shell):
	clear # (1)
	
	# Clear the screen but keep the terminal's scrollback buffer:
	clear -x
	
	# Indicate the type of terminal to clean (defaults to the value of the environment variable `TERM`):
	clear -T type_of_terminal
	
	# Show the version of `ncurses` used by `clear`:
	clear -V
	
	$
	```
	
	1. equivalent to pressing **Command-K** (⌘K) in manOS

### `history`

??? history
	``` sh linenums="1" hl_lines="1"
	$ curl cheat.sh/
	history
	cheat:history 
	# To see most used top 10 commands:
	history | awk '{CMD[$2]++;count++;}END { for (a in CMD)print CMD[a] " " CMD[a]/count*100 "% " a;}' | grep -v "./" | column -c3 -s " " -t | sort -nr | nl | head -n10

	tldr:history 
	# history
	# Command-line history.
	# More information: <https://www.gnu.org/software/bash/manual/html_node/Bash-History-Builtins.html>.
	
	# Display the commands history list with line numbers:
	history
	
	# Display the last 20 commands (in `zsh` it displays all commands starting from the 20th):
	history 20
	
	# Clear the commands history list (only for current `bash` shell):
	history -c
	
	# Overwrite history file with history of current `bash` shell (often combined with `history -c` to purge history):
	history -w
	
	# Delete the history entry at the specified offset:
	history -d offset
	
	$
	
	```

## Navigate

### pwd

??? pwd
	``` sh linenums="1" hl_lines="1"
	$ curl cheat.sh/
	pwd
	cheat:pwd 
	# Show the absolute path of your current working directory:
	pwd

	tldr:pwd 
	# pwd
	# Print name of current/working directory.
	# More information: <https://www.gnu.org/software/coreutils/pwd>.
	
	# Print the current directory:
	pwd
	
	# Print the current directory, and resolve all symlinks (i.e. show the "physical" path):
	pwd -P
	
	$
	```

### cd P92-考

??? cd
	``` sh linenums="1" hl_lines="27-28 30-31 33-34 36-37 39-40 42-43"
	$ curl cheat.sh/
	cd
	cheat:cd 
	# Go to the given directory:
	cd path/to/directory

	# Go to home directory of current user:
	cd
	
	# Go up to the parent of the current directory:
	cd ..
	
	# Go to the previously chosen directory:
	cd -
	
	# Go to a physical dir instead of default -L:
	cd -P path/to/dir
	
	# Some people alias cd="cd -P" and pwd="pwd -P"
	# So that `ls ..` and `cd ..; ls .` yield the same thing.
	
	tldr:cd 
	# cd
	# Change the current working directory.
	# More information: <https://manned.org/cd>.
	
	# Go to the specified directory:
	cd path/to/directory
	
	# Go up to the parent of the current directory:
	cd ..
	
	# Go to the home directory of the current user:
	cd # (1)
	
	# Go to the home directory of the specified user:
	cd ~username
	
	# Go to the previously chosen directory:
	cd -
	
	# Go to the root directory:
	cd /
	
	$
	```

	1. `cd` = `cd ~`

### ls P93 考

!!! ls
	``` sh linenums="1" hl_lines="4-5 7-8 55-56 71"
	$ curl cheat.sh/
	ls
	cheat:ls 
	# To display everything in <dir>, excluding hidden files:
	ls <dir>

	# To display everything in <dir>, including hidden files:
	ls -a <dir>
	
	# To display all files, along with the size (with unit suffixes) and timestamp:
	ls -lh <dir>
	
	# To display files, sorted by size:
	ls -S <dir>
	
	# To display directories only:
	ls -d */ <dir>
	
	# To display directories only, include hidden:
	ls -d .*/ */ <dir>
	
	# To display all files sorted by changed date, most recent first:
	ls -ltc 
	
	# To display files sorted by create time:
	ls -lt
	
	# To display files in a single column:
	ls -1
	
	# To show ACLs (MacOS):
	# see also `cheat chmod` for `/bin/chmod` options for ACLs
	/bin/ls -le
	
	# To show all the subtree files (Recursive Mode):
	ls -R
	
	tldr:ls 
	# ls
	# List directory contents.
	# More information: <https://www.gnu.org/software/coreutils/ls>.
	
	# List files one per line:
	ls -1
	
	# List all files, including hidden files:
	ls -a
	
	# List all files, with trailing `/` added to directory names:
	ls -F
	
	# Long format list (permissions, ownership, size, and modification date) of all files:
	ls -la
	
	# Long format list with size displayed using human-readable units (KiB, MiB, GiB):
	ls -lh
	
	# Long format list sorted by size (descending):
	ls -lS
	
	# Long format list of all files, sorted by modification date (oldest first):
	ls -ltr
	
	# Only list directories:
	ls -d */
	
	$
	
	# Others
	
	ll # = `ls -hl`
	```
	
#### Long Listing Format



## View File Contents

### cat

??? cat
	``` sh linenums="1" hl_lines="22-23 25-26 33"
	$ curl cheat.sh/
	cat
	cheat.sheets:cat 
	# POSIX way in which to cat(1); see cat(1posix).
	cat -u [FILE_1 [FILE_2] ...]

	# Output a file, expanding any escape sequences (default). Using this short
	# one-liner let's you view the boot log how it was show at boot-time.
	cat /var/log/boot.log
	
	# This is an ever-popular useless use of cat.
	cat /etc/passwd | grep '^root'
	# The sane way:
	grep '^root' /etc/passwd
	
	# If in bash(1), this is often (but not always) a useless use of cat(1).
	Buffer=`cat /etc/passwd`
	# The sane way:
	Buffer=`< /etc/passwd`
	
	cheat:cat 
	# To display the contents of a file:
	cat <file>
	
	# To display file contents with line numbers
	cat -n <file>
	
	# To display file contents with line numbers (blank lines excluded)
	cat -b <file>
	
	tldr:cat 
	# cat
	# Print and concatenate files.
	# More information: <https://www.gnu.org/software/coreutils/cat>.
	
	# Print the contents of a file to the standard output:
	cat path/to/file
	
	# Concatenate several files into an output file:
	cat path/to/file1 path/to/file2 ... > path/to/output_file
	
	# Append several files to an output file:
	cat path/to/file1 path/to/file2 ... >> path/to/output_file
	
	# Copy the contents of a file into an output file without buffering:
	cat -u /dev/tty12 > /dev/tty13
	
	# Write `stdin` to a file:
	cat - > path/to/file
	
	$
	```

### more

??? more
	``` sh linenums="1" hl_lines="9"
	$ curl cheat.sh/
	more
	cheat:more 
	# To show <file> beginning at line number 5:
	more +5 <file>

	tldr:more 
	# more
	# Open a file for interactive reading, allowing scrolling and search.
	# More information: <https://manned.org/more>.
	
	# Open a file:
	more path/to/file
	
	# Open a file displaying from a specific line:
	more +line_number path/to/file
	
	# Display help:
	more --help
	
	# Go to the next page:
	<Space>
	
	# Search for a string (press `n` to go to the next match):
	/something
	
	# Exit:
	q
	
	# Display help about interactive commands:
	h
	
	$
	```

### less

??? less
	``` sh linenums="1" hl_lines="56"
	$ curl cheat.sh/
	less
	cheat:less 
	# Go to end of file:
	G

	# Go to start of file:
	g
	
	# To edit the current file in $EDITOR:
	v
	
	# Search in file:
	/<searchterm>
	
	# Filter content:
	&
	
	# Next result:
	n
	
	# Previous result:
	N
	
	# Toggle search highlighting:
	Alt-u
	
	# Follow (tail -f) a file after opening it:
	F
	# To start less in follow-mode:
	less +F <filename>
	
	# To disable the terminal refresh when exiting:
	less -X
	
	# Move to next file (if multiple files opened, eg. `less file1 file2`):
	:n
	
	# Move to previous file:
	:p
	
	# Don't wrap long lines:
	less -S <filename>
	# or if already in less:
	-S
	
	# To save the contents to a file:
	# Method 1 - Only works when the input is a pipe
	s <filename>
	
	# Method 2 - This should work whether input is a pipe or an ordinary file:
	Type g or < (g or less-than) | $ (pipe then dollar) then cat > <filename> and Enter.
	
	tldr:less 
	# less
	# Open a file for interactive reading, allowing scrolling and search.
	# More information: <https://greenwoodsoftware.com/less/>.
	
	# Open a file:
	less source_file
	
	# Page down / up:
	<Space> (down), b (up)
	
	# Go to end / start of file:
	G (end), g (start)
	
	# Forward search for a string (press `n`/`N` to go to next/previous match):
	/something
	
	# Backward search for a string (press `n`/`N` to go to next/previous match):
	?something
	
	# Follow the output of the currently opened file:
	F
	
	# Open the current file in an editor:
	v
	
	# Exit:
	q
	
	$
	```

### head

??? head
	``` sh linenums="1" hl_lines="4-5 7-8"
	$ curl cheat.sh/
	head
	cheat:head 
	# To show the first 10 lines of <file>:
	head <file> # (1)

	# To show the first <number> lines of <file>:
	head -n <number> <file>
	
	# To show the first <number> bytes of <file>:
	head -c <number> <file>
	
	tldr:head 
	# head
	# Output the first part of files.
	# More information: <https://www.gnu.org/software/coreutils/head>.
	
	# Output the first few lines of a file:
	head -n count path/to/file
	
	$
	```
	
	1. default line nums: **10**

### tail

??? tail
	``` sh linenums="1" hl_lines="4-5 7-8 16-17"
	$ curl cheat.sh/
	tail
	cheat:tail 
	# To show the last 10 lines of <file>:
	tail <file>

	# To show the last <number> lines of <file>:
	tail -n <number> <file>
	
	# To show the last lines of <file> starting with <number>:
	tail -n +<number> <file>
	
	# To show the last <number> bytes of <file>:
	tail -c <number> <file>
	
	# To show the last 10 lines of <file> and to wait for <file> to grow:
	tail -f <file>
	
	tldr:tail 
	# tail
	# Display the last part of a file.
	# See also: `head`.
	# More information: <https://www.gnu.org/software/coreutils/tail>.
	
	# Show last 'count' lines in file:
	tail --lines count path/to/file
	
	# Print a file from a specific line number:
	tail --lines +count path/to/file
	
	# Print a specific count of bytes from the end of a given file:
	tail --bytes count path/to/file
	
	# Print the last lines of a given file and keep reading file until `Ctrl + C`:
	tail --follow path/to/file
	
	# Keep reading file until `Ctrl + C`, even if the file is inaccessible:
	tail --retry --follow path/to/file
	
	# Show last 'num' lines in 'file' and refresh every 'n' seconds:
	tail --lines count --sleep-interval seconds --follow path/to/file
	
	$
	```

## 操作文件

### `file`

``` sh
$ file /etc/shadow
/etc/shadow: regular file, no read permission
```

??? file
	``` sh linenums="1" hl_lines="4 7-8"
	$ curl cheat.sh/
	file
	# file
	# Determine file type.
	# More information: <https://manned.org/file>.

	# Give a description of the type of the specified file. Works fine for files with no file extension:
	file path/to/file
	
	# Look inside a zipped file and determine the file type(s) inside:
	file -z foo.zip
	
	# Allow file to work with special or device files:
	file -s path/to/file
	
	# Don't stop at first file type match; keep going until the end of the file:
	file -k path/to/file
	
	# Determine the MIME encoding type of a file:
	file -i path/to/file
	
	$
	```

### `ln`

创建符号链接（换言之，快捷方式、替身文件、软链接）。

??? ln
	``` sh linenums="1" hl_lines="4-5"
	$ curl cheat.sh/
	ln
	cheat:ln 
	# To create a symlink:
	ln -s <source-location> <symlink-location>

	# To symlink, while overwriting existing destination files
	ln -sf <source-location> <symlink-location>
	
	tldr:ln 
	# ln
	# Creates links to files and directories.
	# More information: <https://www.gnu.org/software/coreutils/ln>.
	
	# Create a symbolic link to a file or directory:
	ln -s /path/to/file_or_directory path/to/symlink
	
	# Overwrite an existing symbolic link to point to a different file:
	ln -sf /path/to/new_file path/to/symlink
	
	# Create a hard link to a file:
	ln /path/to/file path/to/hardlink
	
	$
	```

### `chmod` P81-考

??? chmod
	``` sh linenums="1" hl_lines="7-8 62-66 105-106 108-109"
	$ curl cheat.sh/
	chmod
	cheat.sheets:chmod 
	# chmod
	# Change file mode bits

	# Give the [u]ser who owns a file the right to e[x]ecute it.
	chmod u+x PATH
	
	# Give the [u]ser rights to [r]ead and [w]rite to a file/directory.
	chmod u+rw PATH
	
	# Remove e[x]ecutable rights from the [g]roup.
	chmod g-x PATH
	
	# Give [a]ll users rights to [r]ead and e[x]ecute.
	chmod a+rx PATH
	
	# Give [o]thers (not in the file owner's group) the same rights as the [g]roup.
	chmod o=g PATH
	
	# Remove all rights from [o]thers.
	chmod o= PATH
	
	# Change permissions recursively, allowing [g]roup and [o]thers to [w]rite.
	chmod -R g+w,o+w PATH
	
	# Set access rights using numeric (octal) form.
	chmod 750 PATH
	
	# Add the execute permission bit to directories only. This works because the
	# 'X' is uppercase, meaning only directories will be executable. However, if
	# an existing file is executable, this bit will not be removed.
	chmod a+X PATH
	
	# Convert string representation of the access right into numeric form and back.
	curl cheat.sh/chmod/750
	curl cheat.sh/chmod/rwxr-x---
	
	cheat:chmod 
	# Add execute for all (myscript.sh)
	chmod a+x myscript.sh
	
	# Set user to read/write/execute, group/global to read only (myscript.sh), symbolic mode
	chmod u=rwx, go=r myscript.sh 
	
	# Remove write from user/group/global (myscript.sh), symbolic mode
	chmod a-w myscript.sh
	
	# Remove read/write/execute from user/group/global (myscript.sh), symbolic mode
	chmod = myscript.sh
	
	# Set user to read/write and group/global read (myscript.sh), octal notation
	chmod 644 myscript.sh
	
	# Set user to read/write/execute and group/global read/execute (myscript.sh), octal notation
	chmod 755 myscript.sh
	
	# Set user/group/global to read/write (myscript.sh), octal notation
	chmod 666 myscript.sh
	
	# Roles 对象助记符
	u - user (owner of the file) 文件的所有者
	g - group (members of file's group) 文件组用户
	o - global, others (all users who are not owner and not part of group)
	a - all (all 3 roles above) 所有用户
	
	# Numeric representations
	7 - full (rwx)
	6 - read and write (rw-)
	5 - read and execute (r-x)
	4 - read only (r--)
	3 - write and execute (-wx)
	2 - write only (-w-)
	1 - execute only (--x)
	0 - none (---)
	
	# Delete ACL number 0 (MacOS):
	# See: `man -M /usr/share/man chmod`
	/bin/chmod -a# 0 /path/to/file
	
	tldr:chmod 
	# chmod
	# Change the access permissions of a file or directory.
	# More information: <https://www.gnu.org/software/coreutils/chmod>.
	
	# Give the [u]ser who owns a file the right to e[x]ecute it:
	chmod u+x path/to/file
	
	# Give the [u]ser rights to [r]ead and [w]rite to a file/directory:
	chmod u+rw path/to/file_or_directory
	
	# Remove e[x]ecutable rights from the [g]roup:
	chmod g-x path/to/file
	
	# Give [a]ll users rights to [r]ead and e[x]ecute:
	chmod a+rx path/to/file
	
	# Give [o]thers (not in the file owner's group) the same rights as the [g]roup:
	chmod o=g path/to/file
	
	# Remove all rights from [o]thers:
	chmod o= path/to/file
	
	# Change permissions recursively giving [g]roup and [o]thers the ability to [w]rite:
	chmod -R g+w,o+w path/to/directory # (1)
	
	# Recursively give [a]ll users [r]ead permissions to files and e[X]ecute permissions to sub-directories within a directory:
	chmod -R a+rX path/to/directory
	
	$
	```
	
	1. `-R`, `--recursive`：对目录以及目录下的文件递归执行更改权限操作。

#### To change file modes symbolically

``` sh
$ chmod u+r,g=rx,o-rwx hello.sh
```

* 助记符
	* 对象助记符
	* 操作助记符
	* 权限助记符

![img](https://sites.ualberta.ca/dept/chemeng/AIX-43/share/man/info/C/a_doc_lib/cmds/aixcmds1/figures/cmds1141.jpg)


### mv

**Move** or **rename** files and directories.

??? mv
	``` sh linenums="1" hl_lines="24 27-28 30-31"
	$ curl cheat.sh/
	mv
	cheat:mv 
	# To move a file from one place to another:
	mv <src> <dest>

	# To move a file from one place to another and automatically overwrite if the destination file exists:
	# (This will override any previous -i or -n args)
	mv -f <src> <dest>
	
	# To move a file from one place to another but ask before overwriting an existing file:
	# (This will override any previous -f or -n args)
	mv -i <src> <dest>
	
	# To move a file from one place to another but never overwrite anything:
	# (This will override any previous -f or -i args)
	mv -n <src> <dest>
	
	# To move listed file(s) to a directory
	mv -t <dest> <file>...
	
	tldr:mv 
	# mv
	# Move or rename files and directories.
	# More information: <https://www.gnu.org/software/coreutils/mv>.
	
	# Rename a file or directory when the target is not an existing directory:
	mv source target
	
	# Move a file or directory into an existing directory:
	mv source existing_directory
	
	# Move multiple files into an existing directory, keeping the filenames unchanged:
	mv source1 source2 source3 existing_directory
	
	# Do not prompt for confirmation before overwriting existing files:
	mv -f source target
	
	# Prompt for confirmation before overwriting existing files, regardless of file permissions:
	mv -i source target
	
	# Do not overwrite existing files at the target:
	mv -n source target
	
	# Move files in verbose mode, showing files after they are moved:
	mv -v source target
	
	$
	```

### cp P83-考

??? cp
	``` sh linenums="1" hl_lines="26 29-30 44-45"
	$ curl cheat.sh/
	cp
	cheat:cp 
	# To copy a file:
	cp ~/Desktop/foo.txt ~/Downloads/foo.txt

	# To copy a directory:
	cp -r ~/Desktop/cruise_pics/ ~/Pictures/
	
	# To create a copy but ask to overwrite if the destination file already exists:
	cp -i ~/Desktop/foo.txt ~/Documents/foo.txt
	
	# To create a backup file with date:
	cp foo.txt{,."$(date +%Y%m%d-%H%M%S)"}
	
	# To copy a symlink that points to a directory (and is thus soft) and not
	# 'expand' the symlink (aka, preserve its nature as a symlink):
	# Note this does NOT work (note trailing '/'):  cp -P /path/to/symlink-dir/
	cp -P <symlink-dir> <dest-dir>
	
	# To copy sparsely:
	cp --sparse=always <src> <dest>
	
	tldr:cp 
	# cp
	# Copy files and directories.
	# More information: <https://www.gnu.org/software/coreutils/cp>.
	
	# Copy a file to another location:
	cp path/to/source_file.ext path/to/target_file.ext # (1)
	
	# Copy a file into another directory, keeping the filename:
	cp path/to/source_file.ext path/to/target_parent_directory
	
	# Recursively copy a directory's contents to another location (if the destination exists, the directory is copied inside it):
	cp -R path/to/source_directory path/to/target_directory
	
	# Copy a directory recursively, in verbose mode (shows files as they are copied):
	cp -vR path/to/source_directory path/to/target_directory
	
	# Copy multiple files at once to a directory:
	cp -t path/to/destination_directory path/to/file1 path/to/file2 ...
	
	# Copy text files to another location, in interactive mode (prompts user before overwriting):
	cp -i *.txt path/to/target_directory
	
	# Follow symbolic links before copying:
	cp -L link path/to/target_directory
	
	# Use the first argument as the destination directory (useful for `xargs ... | cp -t <DEST_DIR>`):
	cp -t path/to/target_directory path/to/file_or_directory1 path/to/file_or_directory2 ...
	
	$
	```
	
	1. `cp 你想复制的文件? 你想复制到哪儿？` 或者 `cp oldFile newFile`

### `rm`

Remove **files** or **directories**.

``` sh
# 删库跑路
$ rm -rf /*
```

??? rm
	``` sh linenums="1" hl_lines="4-5 15 19-20 22-23 31-32"
	$ curl cheat.sh/
	rm
	cheat:rm 
	# To remove all files and subdirs in <dir>:
	rm -rf <dir>

	# To ignore non-existent files:
	rm -f <dir>
	
	# To remove a file with this inode:
	find /tmp/ -inum 6666 -exec rm -i '{}' \;
	
	tldr:rm 
	# rm
	# Remove files or directories.
	# See also: `rmdir`.
	# More information: <https://www.gnu.org/software/coreutils/rm>.
	
	# Remove specific files:
	rm path/to/file1 path/to/file2 ...
	
	# Remove specific files ignoring nonexistent ones:
	rm -f path/to/file1 path/to/file2 ...
	
	# Remove specific files [i]nteractively prompting before each removal:
	rm -i path/to/file1 path/to/file2 ...
	
	# Remove specific files printing info about each removal:
	rm -v path/to/file1 path/to/file2 ...
	
	# Remove specific files and directories [r]ecursively:
	rm -r path/to/file_or_directory1 path/to/file_or_directory2 ...
	
	$
	```

## 下载 Download

### `wget`

??? wget
	``` sh linenums="1" hl_lines="24-25 66-67"
	$ curl cheat.sh/
	wget
	cheat.sheets:wget 
	# wget
	# The non-interactive network downloader

	# Quietly download a file, continuing where it left of, if the connection
	# fails. The file will be downloaded to the current working directory.
	wget -qc [URL]
	
	# Specify a location to download the given file.
	wget -qcO [PATH] [URL]
	
	# Download URL using the user agent string provided to the `-U` flag.
	wget -U 'Mozilla/5.0' [URL]
	
	cheat:wget 
	# To download <url>:
	wget <url>
	#
	# To download multiples files with multiple URLs:
	wget <url>...
	
	# To download <url> and change its name:
	wget <url> -O <outfile>
	
	# To download <url> into <dir>:
	wget -P <dir> <url>
	
	# To continue an aborted downloaded:
	wget -c <url>
	
	# To parse a file that contains a list of URLs to fetch each one:
	wget -i url_list.txt
	
	# To mirror a whole page locally:
	wget -pk <url>
	
	# To mirror a whole site locally:
	wget -mk <url>
	
	# To download files according to a pattern:
	wget http://example.com/files-{1..15}.tar.bz2
	
	# To download all the files in a directory with a specific extension if directory indexing is enabled:
	wget -r -l1 -A.extension http://example.com/directory
	
	# To download only response headers (-S --spider) and display them on stdout (-O -).:
	wget -S --spider -O - <url>
	
	# To change the User-Agent to 'User-Agent: toto':
	wget -U 'toto' <url>
	
	# To download a file with specific speed EX:500kb/sec:
	wget --limit-rate=500k <url>
	
	tldr:wget 
	# wget
	# Download files from the Web.
	# Supports HTTP, HTTPS, and FTP.
	# More information: <https://www.gnu.org/software/wget>.
	
	# Download the contents of a URL to a file (named "foo" in this case):
	wget https://example.com/foo
	
	# Download the contents of a URL to a file (named "bar" in this case):
	wget --output-document bar https://example.com/foo
	
	# Download a single web page and all its resources with 3-second intervals between requests (scripts, stylesheets, images, etc.):
	wget --page-requisites --convert-links --wait=3 https://example.com/somepage.html
	
	# Download all listed files within a directory and its sub-directories (does not download embedded page elements):
	wget --mirror --no-parent https://example.com/somepath/
	
	# Limit the download speed and the number of connection retries:
	wget --limit-rate=300k --tries=100 https://example.com/somepath/
	
	# Download a file from an HTTP server using Basic Auth (also works for FTP):
	wget --user=username --password=password https://example.com
	
	# Continue an incomplete download:
	wget --continue https://example.com
	
	# Download all URLs stored in a text file to a specific directory:
	wget --directory-prefix path/to/directory --input-file URLs.txt
	
	$
	
	```

### `curl`

- - [x] [Week 6: Web | Practical Unix](https://practicalunix.org/content/week-8)
- - [x] [Week 7: Advanced Web | Practical Unix](https://practicalunix.org/content/week-7-web)

---

- [-f, --fail](https://curl.se/docs/manpage.html#-f)
- [-S, —-show-error](https://curl.se/docs/manpage.html#-S)
- [-s, —-silent](https://curl.se/docs/manpage.html#-s)

??? curl
	``` sh linenums="1" hl_lines="1"
	$ curl cheat.sh/
	curl
	cheat.sheets:curl 
	# curl
	# Command-line tool for transferring data with URL syntax

	# Process a single GET request, and show its output on stdout.
	curl http://path.to.the/file
	
	# Download a file and specify a new filename.
	curl http://example.com/file.zip -o new_file.zip
	
	# Download multiple files.
	curl -O URLOfFirstFile -O URLOfSecondFile
	
	# Download all sequentially-numbered files (1-24).
	curl http://example.com/pic[1-24].jpg
	
	# Download a file and follow redirects.
	curl -L http://example.com/file
	
	# Download a file and pass HTTP Authentication.
	curl -u username:password URL
	
	# Download a file with a Proxy.
	curl -x proxysever.server.com:PORT http://addressiwantto.access
	
	# Download a file from FTP.
	curl -u username:password -O ftp://example.com/pub/file.zip
	
	# Get an FTP directory listing.
	curl ftp://username:password@example.com
	
	# Resume a previously failed download.
	curl -C - -o partial_file.zip http://example.com/file.zip
	
	# Fetch only the HTTP headers from a response.
	curl -I http://example.com
	
	# Fetch your external IP and network info as JSON.
	curl http://ifconfig.me/all/json
	
	# Limit the rate of a download.
	curl --limit-rate 1000B -O http://path.to.the/file
	
	# POST to a form.
	curl -F "name=user" -F "password=test" http://example.com
	
	# POST JSON Data.
	curl -H "Content-Type: application/json" -X POST -d '{"user":"bob","pass":"123"}' http://example.com
	
	# POST data from the standard in / share data on sprunge.us.
	curl -F 'sprunge=<-' sprunge.us
	
	cheat:curl 
	# To download a file:
	curl <url>
	
	# To download and rename a file:
	curl <url> -o <outfile>
	
	# To download multiple files:
	curl -O <url> -O <url>
	
	# To download all sequentially numbered files (1-24):
	curl http://example.com/pic[1-24].jpg
	
	# To download a file and pass HTTP authentication:
	curl -u <username>:<password> <url>
	
	# To download a file with a proxy:
	curl -x <proxy-host>:<port> <url>
	
	# To download a file over FTP:
	curl -u <username>:<password> -O ftp://example.com/pub/file.zip
	
	# To get an FTP directory listing:
	curl ftp://username:password@example.com
	
	# To resume a previously failed download:
	curl -C - -o <partial-file> <url>
	
	# To fetch only the HTTP headers from a response:
	curl -I <url>
	
	# To fetch your external IP and network info as JSON:
	curl http://ifconfig.me/all.json
	
	# To limit the rate of a download:
	curl --limit-rate 1000B -O <outfile>
	
	# To get your global IP:
	curl httpbin.org/ip 
	
	# To get only the HTTP status code:
	curl -o /dev/null -w '%{http_code}\n' -s -I URL
	
	tldr:curl 
	# curl
	# Transfers data from or to a server.
	# Supports most protocols, including HTTP, FTP, and POP3.
	# More information: <https://curl.se>.
	
	# Download the contents of a URL to a file:
	curl http://example.com --output path/to/file
	
	# Download a file, saving the output under the filename indicated by the URL:
	curl --remote-name http://example.com/filename
	
	# Download a file, following location redirects, and automatically continuing (resuming) a previous file transfer and return an error on server error:
	curl --fail --remote-name --location --continue-at - http://example.com/filename
	
	# Send form-encoded data (POST request of type `application/x-www-form-urlencoded`). Use `--data @file_name` or `--data @'-'` to read from STDIN:
	curl --data 'name=bob' http://example.com/form
	
	# Send a request with an extra header, using a custom HTTP method:
	curl --header 'X-My-Header: 123' --request PUT http://example.com
	
	# Send data in JSON format, specifying the appropriate content-type header:
	curl --data '{"name":"bob"}' --header 'Content-Type: application/json' http://example.com/users/1234
	
	# Pass a username and password for server authentication:
	curl --user myusername:mypassword http://example.com
	
	# Pass client certificate and key for a resource, skipping certificate validation:
	curl --cert client.pem --key key.pem --insecure https://example.com
	
	$
	```

## Directory

路径分隔符：

| Linux      | Windows                          |
| ----------- | ------------------------------------ |
| `/` 正斜线       | `\` 反斜线  |

### `mkdir` P92-考

* options
	1. `-p, [p]arent`
	2. `-m, [m]ode`

??? mkdir
	``` sh linenums="1" hl_lines="4-5 15 18-19 24-25"
	$ curl cheat.sh/
	mkdir
	cheat:mkdir 
	# To create nested directories:
	mkdir -p foo/bar/baz # (1)

	# To create foo/bar and foo/baz directories:
	mkdir -p foo/{bar,baz}
	
	# To create the foo/bar, foo/baz, foo/baz/zip and foo/baz/zap directories:
	mkdir -p foo/{bar,baz/{zip,zap}}
	
	tldr:mkdir 
	# mkdir
	# Create directories and set their permissions.
	# More information: <https://www.gnu.org/software/coreutils/mkdir>.
	
	# Create specific directories:
	mkdir path/to/directory1 path/to/directory2 ...
	
	# Create specific directories and their [p]arents if needed:
	mkdir -p path/to/directory1 path/to/directory2 ...
	
	# Create directories with specific permissions:
	mkdir -m rwxrw-r-- path/to/directory1 path/to/directory2 ... # (2)
	
	$
	```
	
	1. [p]arents
	2. [m]ode

### `rmdir`

??? rmdir
	``` sh linenums="1" hl_lines="21"
	$ curl cheat.sh/
	rmdir
	cheat:rmdir 
	# Command syntax:
	rmdir [option] directory_name 

	# Outputs a message that the directory is being removed:
	rmdir -v directory_name
	
	# adding the -p option deletes the child directory then its parent directory:
	rmdir-p directory_name
	
	# Shows the syntax of the command:
	rmdir --help
	
	# Get the command version:
	rmdir --version
	
	tldr:rmdir 
	# rmdir
	# Remove directories without files.
	# See also: `rm`.
	# More information: <https://www.gnu.org/software/coreutils/rmdir>.
	
	# Remove specific directories:
	rmdir path/to/directory1 path/to/directory2 ...
	
	# Remove specific nested directories recursively:
	rmdir -p path/to/directory1 path/to/directory2 ...
	
	$
	```

## grep

??? grep
	``` sh linenums="1" hl_lines="4-5 7-8 10-11 38"
	$ curl cheat.sh/
	grep
	cheat:grep 
	# To search a file for a pattern:
	grep <pattern> <file>

	# To perform a case-insensitive search (with line numbers):
	grep -in <pattern> <file> # (1) # (2)
	
	# To recursively grep for string <pattern> in <dir>:
	grep -R <pattern> <dir> # (3)
	
	# Read search patterns from a file (one per line):
	grep -f <pattern-file> <file>
	
	# Find lines NOT containing pattern:
	grep -v <pattern> <file>
	
	# Set how many lines to show before (-B) and after (-A) pattern:
	grep -B 3 -A 2 <pattern> <file>
	
	# To grep with regular expressions:
	grep "^00" <file>                                               # Match lines starting with 00
	grep -E "[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}" <file> # Find IP add
	
	# To find all files that match <pattern> in <dir>
	grep -rnw <dir> -e <pattern>
	
	# To exclude grep from your grepped output of ps:
	# (Add [] to the first letter. Ex: sshd -> [s]shd)
	ps aux | grep '[h]ttpd'
	
	# Colour in red {bash} and keep all other lines
	ps aux | grep -E --color 'bash|$'
	
	tldr:grep 
	# grep
	# Find patterns in files using regular expressions.
	# More information: <https://www.gnu.org/software/grep/manual/grep.html>.
	
	# Search for a pattern within a file:
	grep "search_pattern" path/to/file
	
	# Search for an exact string (disables regular expressions):
	grep --fixed-strings "exact_string" path/to/file
	
	# Search for a pattern in all files recursively in a directory, showing line numbers of matches, ignoring binary files:
	grep --recursive --line-number --binary-files=without-match "search_pattern" path/to/directory
	
	# Use extended regular expressions (supports `?`, `+`, `{}`, `()` and `|`), in case-insensitive mode:
	grep --extended-regexp --ignore-case "search_pattern" path/to/file
	
	# Print 3 lines of context around, before, or after each match:
	grep --context|before-context|after-context=3 "search_pattern" path/to/file
	
	# Print file name and line number for each match with color output:
	grep --with-filename --line-number --color=always "search_pattern" path/to/file
	
	# Search for lines matching a pattern, printing only the matched text:
	grep --only-matching "search_pattern" path/to/file
	
	# Search `stdin` for lines that do not match a pattern:
	cat path/to/file | grep --invert-match "search_pattern"
	
	$
	```
	
	1. `-i`: a case-**i**nsensitive search
	2. `-n`: with line **n**umbers
	3. `-r`: **r**ecursively grep

### Use Cases

``` sh
$ grep -nri <match_pattern> <file_name> | cat --number
```

## date

### cal

??? cal
	``` sh linenums="1" hl_lines="4 7-8 16-17 19-20"
	$ curl cheat.sh/
	cal
	# cal
	# Prints calendar information, with the current day highlighted.
	# More information: <https://manned.org/cal>.

	# Display a calendar for the current month:
	cal
	
	# Display previous, current and next month:
	cal -3
	
	# Use Monday as the first day of the week:
	cal --monday
	
	# Display a calendar for a specific year (4 digits):
	cal year
	
	# Display a calendar for a specific month and year:
	cal month year
	
	$
	```

### date

??? date
	``` sh linenums="1" hl_lines="1"
	$ curl cheat.sh/
	date
	cheat:date 
	---
	tags: [ date, time ]
	---
	# To print Abbreviated weekday name:
	date +"%a"

	# To print Full month name:
	date +"%B"
	
	# To print ISO date (same as %Y-%m-%d):
	date +"%F"
	
	# To print Time (same as %H:%M:%S):
	date +"%T"
	
	# To print Sunday week number (00 to 53):
	date +"%U"
	
	# To print Monday week number (00 to 53):
	date +"%W"
	
	# To print Time (localized):
	date +"%X"
	
	# To print 4-digit year:
	date +"%Y"
	
	# To print Timezone name:
	date +"%Z"
	# To print the date in a format suitable for affixing to file names:
	date +"%Y%m%d_%H%M%S"
	
	# To convert a Unix timestamp to Date (Linux):
	date -d @1440359821
	
	# To convert a Unix timestamp to Date (OSX):
	date -r 1440359821
	
	# To show the current timezone:
	date +%Z
	
	# To show date in RFC format with TZ offset:
	date -R
	
	# To show date in UTC/GMT:
	date -u
	
	# To show date in CET:
	TZ=CET date
	
	# To show the time on the west coast of the US (use tzselect(1) to find TZ):
	TZ='America/Los_Angeles' date
	
	tldr:date 
	# date
	# Set or display the system date.
	# More information: <https://www.gnu.org/software/coreutils/date>.
	
	# Display the current date using the default locale's format:
	date +%c
	
	# Display the current date in UTC, using the ISO 8601 format:
	date -u +%Y-%m-%dT%H:%M:%S%Z
	
	# Display the current date as a Unix timestamp (seconds since the Unix epoch):
	date +%s
	
	# Convert a date specified as a Unix timestamp to the default format:
	date -d @1473305798
	
	# Convert a given date to the Unix timestamp format:
	date -d "2018-09-01 00:00" +%s --utc
	
	# Display the current date using the RFC-3339 format (`YYYY-MM-DD hh:mm:ss TZ`):
	date --rfc-3339=s
	
	# Set the current date using the format `MMDDhhmmYYYY.ss` (`YYYY` and `.ss` are optional):
	date 093023592021.59
	
	# Display the current ISO week number:
	date +%V
	
	$
	```
