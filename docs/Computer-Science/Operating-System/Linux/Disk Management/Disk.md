# Disk

## Commands

### df

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

### lsblk

### fdisk

1. 分区
2. 查看分区信息

## Linux 中块设备命名规则

### 设备文件

- [x] [D.1. Linux 里的设备](https://www.debian.org/releases/stable/s390x/apds01.zh-cn.html)

`sr`

:	CD-ROM/DVD-ROM 光驱

`nvme`

:	NVMe 接口的硬盘

`sd`

: SCSI/SATA/USB 接口的硬盘 / U 盘

??? question "**`nvme0n2p3` 什么意思？**"

    `nvme0n2p3` 是一种 Linux 系统中的设备名称。它表示一个 NVMe（Non-Volatile Memory Express）存储设备的第三个分区。

    1. `nvme`: 表示使用 NVMe 协议进行通信的存储设备。NVMe 是一种高性能、低延迟的存储协议，用于连接计算机系统与固态硬盘（SSD）之间的通信。

    2. `0`: 代表{==控制器编号==}，表示第一个 NVMe 控制器。一个系统可能有多个 NVMe 控制器，它们分别编号为 0、1、2 等等。

    3. `n2`: 代表{==命名空间编号==}，表示在第二个 NVMe 控制器上的存储设备。类似地，如果有多个存储设备连接到系统上的同一个控制器上，它们将按照n0、n1、n2等方式编号。

    4. `p3`: 代表{==分区编号==}，表示第三个分区。在一个存储设备上，分区是对存储空间进行逻辑划分的方式。每个分区可以独立使用，并且可以在其中存储文件和数据。

    综上所述，nvme0n2p3 指的是第一个NVMe控制器上的第二个存储设备的第三个分区。
    
??? question "`sdc5` 什么意思？"

    `sdc5` 是一种 Linux 系统中的设备名称。它表示一个SCSI（Small Computer System Interface）或SATA（Serial ATA）设备的第五个分区。

    1. `sdc`: `c` 代表{==设备编号==}。表示一个SCSI或SATA设备。SCSI和SATA是两种不同的接口标准，用于连接计算机系统与各种存储设备（如硬盘、光驱等）之间的通信。

    2. `5`: 代表{==分区编号==}，表示第五个分区。在一个存储设备上，分区是对存储空间进行逻辑划分的方式。每个分区可以独立使用，并且可以在其中存储文件和数据。

    综上所述，sdc5 指的是一个SCSI或SATA设备的第五个分区。具体设备的类型可能需要根据上下文进一步确定，例如，它可以是一块硬盘、固态硬盘或其他类型的存储设备。