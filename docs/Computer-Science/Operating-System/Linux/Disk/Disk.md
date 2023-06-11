# Disk

??? df
    ``` sh linenums="1" hl_lines="5 10-11 57"
    $ curl cheat.sh/
    df
    cheat.sheets:df 
    # df
    # Report file system disk space usage

    # Print free disk space in a [h]uman-readable format.
    df -h

    # Free disk space for [t]ype EXT2 file systems.
    df -t ext2

    # Free disk space for filesystems, e[x]cluding EXT2.
    df -x ext2

    # Show [i]node usage.
    df -i

    # Show information about a distinct filesystem path.
    df [PATH]

    # List [a]ll filesystems, + unreadable, duplicates, pseudo, and inaccessible.
    df -a

    # Fetch a grand total of disk usage.
    df --total

    cheat:df 
    # To print free disk space in a human-readable format:
    df -h

    # To print the disk for a given path:
    df -d <path>

    tldr:df 
    # df
    # Gives an overview of the filesystem disk space usage.
    # More information: <https://www.gnu.org/software/coreutils/df>.

    # Display all filesystems and their disk usage:
    df

    # Display all filesystems and their disk usage in human-readable form:
    df -h

    # Display the filesystem and its disk usage containing the given file or directory:
    df path/to/file_or_directory

    # Display statistics on the number of free inodes:
    df -i

    # Display filesystems but exclude the specified types:
    df -x squashfs -x tmpfs

    $

    # -T或--print-type：显示文件系统的类型；
    ```