# zsh

``` sh tilte="打印内置shell, macOS“
$ cat /etc/shells
# List of acceptable shells for chpass(1).
# Ftpd will not allow users to connect who are not using
# one of these shells.

/bin/bash
/bin/csh
/bin/dash
/bin/ksh
/bin/sh
/bin/tcsh
/bin/zsh
```

``` sh title="查看当前shell"
$ echo $SHELL
```

``` sh title="安装zsh“
$ brew install zsh # on macOS with homebrew
```

``` sh title="设置默认shell“
$ sudo chsh -s /bin/zsh # 为 root 设置默认 shell
$ sudo chsh -s /bin/zsh <username> # 为特定用户设置默认 shell
```

