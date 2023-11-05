# 文件检索

检索

文件检索

信息检索

搜索引擎/服务

搜索软件

---

检索完，检索到之后，怎么处理这些信息？

## Commands

### `find`

-   `find` - search for files - macOS version

-   `gfind` - the GNU version

    ``` sh
    $ brew install findtools # install the `findtools` package, which will install the GNU versions of the tools
    $ gfind
    ```

**parameters**







``` sh
usage: find [-H | -L | -P] [-EXdsx] [-f path] path ... [expression]
       find [-H | -L | -P] [-EXdsx] -f path [path ...] [expression]
```

``` sh title="cht.sh/find" linenums="1" hl_lines="15-16 18-19 124-125 127-128 147-148 153-154 213-214 216-217 222-223"
$ curl cheat.sh/find

 cheat.sheets:find 
# find
# Search for files in a directory hierarchy

# Find files by case-insensitive extension, such as `.jpg`, `.JPG`, & `.jpG`).
# By default, find(1) uses glob pathname pattern matching. To avoid shell
# interpretation, the glob either must be expanded or the string quoted.
#
# Period is optional; it's implied unless a path is provided. find(1) works
# recursively unless otherwise directed (IE: `-maxdepth [N]`).
find . -iname '*.jpg'

# Find directories.
find . -type d

# Find files. Specifically files; not directories, links, FIFOs, etc.
find . -type f

# Find files set to the provided octal mode (permissions).
find . -type f -perm 777

# Find files with setuid bit set, keeping to the same filesystem.
find . -xdev \( -perm -4000 \) -type f -print0 | xargs -0 ls -l
# The above is a useful demonstration of some pitfalls into which a user can
# fall, where the below is the above but corrected. Here is why:
#
#   * The `.` (current working directory) is assumed when no path is provided.
#   * Group syntax (parentheses) was used, but nothing was actually grouped.
#   * A lot of people have their ls(1) command aliased in many ways, -
#     potentially causing problems with the output and how xargs(1) handles it.
#     By escaping the command, we temporarily override any aliases and even
#     functions by the same name.
#   * At least in my experience, the prior xargs(1) is not as reliable.
#   * The `-print0` and `xargs -0` is great, but unnecessary (except when?).
#
# However, it might be more preferred to simply use find(1)'s own `-printf`
# flag, in order to avoid the need for xargs(1) and ls(1), which should be many
# times faster, and allows for more specificity.
find -perm -4000 -type f -print0 | xargs -I '{}' -0 \ls -l '{}'

# Find and remove files with case-sensitive extension of `.txt`.
find [PATH] -name '*.txt' -exec rm '{}' \;
# The above is much more efficiently written as shown below, as find(1) has its
# own built-in delete function, not to mention a single rm(1) process was
# previously executed for each file processed, which is comparatively slow.
find [PATH] -name '*.txt' -delete

# Find files with extension '.txt' and look for a string into them.
find ./path/ -name '*.txt' | xargs grep 'string'

# Find files with size bigger than 5 Mb and sort them by size.
find . -size +5M -type f -print0 | xargs -0 ls -Ssh | sort -z

# Find files bigger thank 2 MB and list them.
find . -type f -size +20000k -exec ls -lh {} \; | awk '{ print $9 ": " $5 }'
# Alternative, faster approach* to the above.
#
# Why it's faster:
#
#   * No need for an external process, like ls(1).
#   * The use of `;` with the `-exec` flag executes an ls(1) process for each
#     file found, which is comparatively very slow.
#   * The `printf` feature is built in and special to awk(1).
#
# That said, awk(1) or gawk(1) is doing a little more here, in order to get
# somewhat of a human-readable file size, but its impact is likely negligible.
find -type f -size +20000k -printf '%s %P\n' |
    awk "{printf(\"%'dM %s\n\", \$1 / (1024 * 1024), \$2)}"

# Find files modified more than 7 days ago and list file information.
find . -type f -mtime +7d -ls

# Find symlinks owned by the given user, then list file information.
find -type l -user [NAME] -ls
# The following may be the syntax used on a Mac, however this is not valid on
# Linux, or at least version 4.7.0. All flags in GNU find(1) are one `-` only.
find . -type l --user=[NAME] -ls

# Search for and delete empty directories.
find . -type d -empty -exec rmdir {} \;
# A far more efficient approach to the above. If no path is provided, then the
# current working directory (CWD) is assumed, making the `.` superfluous.
find -type d -empty -delete

# Search for directories named `build` at a maximum depth of 2 directories.
# This means that find will not recursively search beyond two levels.
find . -maxdepth 2 -name build -type d

# Search all files which are not in a `.git` directory. Depending on the shell
# used, the bang (`!`) may need to be escaped, to avoid shell interpretation.
# Alternatively, although non-POSIX, the `-not` flag can be used.
find . \! -iwholename '*.git*' -type f

# Find all files that have the same inode (indicating hard link) as FILE. All
# output going to STDERR (typically error messages) will also be redirected to
# `/dev/null`, a special pseudo-file where data is sent to die.
find . -type f -samefile [FILE] 2>/dev/null

# Find all files in the current directory and modify their permissions.
find . -type f -exec chmod 644 {} \;

# Find files with extension `.txt` and edit all of them with vim(1).
#
# The use of `+` (escaped to avoid shell interpretation) with `-exec` means
# that only one process (in this case, `vim`) per `exec`ution is used. If `;`
# is instead used (would also need escaping), then one `vim` process would be
# used per file.
find . -iname '*.txt' -exec vim {} \+

# Find files with extension `.png`, then rename their extension to `.jpg`. It's
# highly important that `\;` is used here, instead of `\+`, otherwise it'd make
# a right mess of the files, due to the way in which mv(1) works.
find . -type f -iname '*.png' -exec bash -c 'mv "$0" "${0%.*}.jpg"' {} \;

# Use logic and grouping to delete extension-specific files.
find \( -iname "*.jpg" -or -iname "*.sfv" -or -iname "*.xspf" \) -type f -delete

# List executable files, by basename, found within PATH.
find ${PATH//:/ } -type f -executable -printf "%P\n"

 cheat:find 
# To find files following symlinks (otherwise the symlinks are not followed):
find -L . -type f

# To find files by case-insensitive extension (ex: .jpg, .JPG, .jpG):
find . -iname "*.jpg"

# To find directories:
find . -type d

# To find files:
find . -type f

# To find files by octal permission:
find . -type f -perm 777

# To find files with setuid bit set:
find . -xdev \( -perm -4000 \) -type f -print0 | xargs -0 ls -l

# To find files newer than 1 day old and copy elsewhere (remove -p flag in xargs to not be asked):
find . -type f -ctime -1 -print0 | xargs -0 -p cp -t <dir>
# or:
find . -type f -ctime -1 -print0 | xargs -0 -p -J % cp % <dir>

# To find files with extension '.txt' and remove them:
find ./path/ -name '*.txt' -delete

# To find files with tilde as postfix and remove them:
find ./path/ -name '*~' -delete

# To find files with extension '.txt' and dump their contents:
find ./path/ -name '*.txt' -exec cat '{}' \;

# To find files with extension '.txt' and look for a string into them:
find ./path/ -name '*.txt' | xargs grep 'string'

# To find files with size bigger than 5 Mebibyte and sort them by size:
find . -size +5M -type f -print0 | xargs -0 ls -Ssh | sort -z

# To find files bigger than 2 Megabyte and list them:
find . -type f -size +200000000c -exec ls -lh {} \; | awk '{ print $9 ": " $5 }'

# To find files modified more than 7 days ago and list file information:
find . -type f -mtime +7d -ls

# To find symlinks owned by a user and list file information:
find . -type l -user <username-or-userid> -ls

# To search for and delete empty directories:
find . -type d -empty -exec rmdir {} \;

# To search for directories named build at a max depth of 2 directories:
find . -maxdepth 2 -name build -type d

# To search all files who are not in .git directory:
find . ! -iwholename '*.git*' -type f

# To find all files that have the same node (hard link) as MY_FILE_HERE:
find . -type f -samefile MY_FILE_HERE 2>/dev/null

# To find all files in the current directory and modify their permissions:
find . -type f -exec chmod 644 {} \;

# To find all files changed in last 2 days:
find . -type f -ctime -48h
find . -type f -ctime -2
# Or created in last 2 days:
find . -type f -Btime -2
# Or accessed in last 2 days:
find . -type f -atime -2

# To find and rename (imperfect) all files and dirs that have a comma in the
# name (dry-run):
find . -name '*,*' | while read f; do echo mv "$f" "${f//,/}"; done

# To find all broken links. Note -L returns a file unless it is a broken link:
find -L /usr/ports/packages -type l

# To find and run multiple shell commands (without multiple execs):
# See: https://stackoverflow.com/questions/5119946/find-exec-with-multiple-commands
find . -type f -exec sh -c "echo '{}'; cat '{}';" \;

# To find files that are newer than a file:
find <path> -newer <target-file>

 tldr:find 
# find
# Find files or directories under the given directory tree, recursively.
# More information: <https://manned.org/find>.

# Find files by extension:
find root_path -name '*.ext'

# Find files matching multiple path/name patterns:
find root_path -path '**/path/**/*.ext' -or -name '*pattern*'

# Find directories matching a given name, in case-insensitive mode:
find root_path -type d -iname '*lib*'

# Find files matching a given pattern, excluding specific paths:
find root_path -name '*.py' -not -path '*/site-packages/*'

# Find files matching a given size range, limiting the recursive depth to "1"::
find root_path -maxdepth 1 -size +500k -size -10M

# Run a command for each file (use `{}` within the command to access the filename):
find root_path -name '*.ext' -exec wc -l {} \;

# Find files modified in the last 7 days:
find root_path -daystart -mtime -7

# Find empty (0 byte) files and delete them:
find root_path -type f -empty -delete

$
```



## 实践

### 关键词的逻辑关系

通过**组合搜索 Combining Searches**，优化搜索范围。

=== "find"

    ``` sh
    # and: `-and`
    $ find /path/to/search -name "*.txt" -and -size +1M
    
    # or: `-or`
    $ find /path/to/search \( -name "*.jpg" -or -name "*.png" \)
    
    # not: `-not`
    $ find /path/to/search -not -name "*.log"
    
    # 组合逻辑关系
    $ find /path/to/search \( -name "*.txt" -or -name "*.md" \) -and -size +100K -not -name "backup*"
    ```

=== "Google 搜索引擎"

    ``` sh
    # and: ` `
    keyword_1 keyword_2
    
    # or: `OR`
    keyword_1 OR keyword_2
    
    # not: `-`
    -keyword_1 -keyword_2
    ```

### 精确搜索

**限定文件类型**

=== "find"

    ``` sh
    # Find directories.
    find . -type d
    
    # Find files. Specifically files; not directories, links, FIFOs, etc.
    find . -type f
    
    # To find files following symlinks (otherwise the symlinks are not followed):
    find -L . -type f
    
    # pdf
    $ find /path/to/search -name "*.pdf"
    
    # txt or doc or docx
    $ find /path/to/search \( -name "*.txt" -or -name "*.doc" -or -name "*.docx" \)
    
    # jpg, not `backup*`
    $ find /path/to/search -name "*.jpg" -not -name "backup*"
    ```

**大小写敏感**

=== "find"

    ``` sh
    # Find files by case-insensitive extension, such as `.jpg`, `.JPG`, & `.jpG`).
    # By default, find(1) uses glob pathname pattern matching. To avoid shell
    # interpretation, the glob either must be expanded or the string quoted.
    #
    # Period is optional; it's implied unless a path is provided. find(1) works
    # recursively unless otherwise directed (IE: `-maxdepth [N]`).
    find . -iname '*.jpg'
    ```



### 模糊搜索

**通配符**

## Supplemental materials

-   [x] [Finding Files @ effective-shell.com](https://effective-shell.com/part-2-core-skills/finding-files)

-   [ ] [如何挖掘网络资源[2]：Google 搜索的基本语法](https://program-think.blogspot.com/2013/03/internet-resource-discovery-2.html)



-   [Google 高级搜索](https://www.google.com/advanced_search)
-   [Google 高级图片搜索](https://www.google.com/advanced_image_search)