# Note 3.

## SSH

-   [Chmod Calculator](https://chmod-calculator.com/)

-   [x] *参见：<https://www.cs.swarthmore.edu/newhelp/ssh_config.html>*
-   [x] 参见：<https://support.cs.wwu.edu/home/survival_guide/tools/Setting_up_SSH_keys_in_Unix_Linux.html>

**相关文件：**

-   local
    -   `~/.ssh/config`
    -   `~/.ssh/filename`
    -   `~/.ssh/filename.pub`
-   remote
    -   `~/.ssh/authorized_keys`

### `~/.ssh/config`

``` sh
$ cd ~
$ mkdir .ssh
$ cd .ssh
$ touch config
$ cat config
```

```filename="PATH: ~/.ssh/config"
#
# ssh config file
#
Host *
  ForwardAgent yes
  ForwardX11 yes
  ServerAliveInterval 30
#
# 
Host cs102
    HostName 106.14.165.94
    User boaw
    Port 22
    IdentityFile ~/.ssh/cs102

Host github.com
    HostName ssh.github.com
    User git
    Port 443
```

### 免密登录远程服务器

1.   Step 1 Generating an ssh public key and private key pair

2.   Step 2 Setup the remote host to accept your public/private key pair

3.   Step 3 Check that everything is working

4.   Step 4 SSH Agent

``` sh
# Generate an ed25519 key & Specify file in which to save the key:
$ ssh-keygen -t ed25519 -f ~/.ssh/filename
# Copy the given public key to the remote with specific port:
$ ssh-copy-id -i path/to/certificate -p port ${username}@${hostname}
$ chmod 600 ~/.ssh/authorized_keys
$ cat ~/.ssh/id_ed25519.pub | ssh -p 922 ${username}@${hostname} 'cat >> ~/.ssh/authorized_keys; chmod 600 ~/.ssh/authorized_keys'
```

>   `id_ed25519.pub` is the public key that will be added to the `~/.ssh/authorized_keys` file on the server to allow you to login.

## `sudo`

-   <https://www.sudo.ws/>

-   [x] [Using sudo in Linux: a mini tutorial](https://home.ubalt.edu/abento/linux/terminal/sudonotfedora.html)

>   全新安装的 Ubuntu 系统默认 `root` 密码是随机的，每次开机都会有一个新的密码。

``` sh
$ su root
Password:
su: Authentication failure
$ sudo passwd
$ sudo -v
[sudo] password for ubuntu:
$ sudo su -
#
```

## 脚本文件

自己写的脚本文件可以放在 `~/.local/bin` 下面。

## 其他

``` sh
$ vim hello.c
$ gcc hello.c -o hello
$ mkdir -p ~/.local/bin/
$ mv hello ~/.local/bin/
$ export PATH=$PATH:$HOME/.local/bin
$ echo $PATH | tr ':' '\n'
$ hello
```

### Command list

-   `which`
-   `whereis`
-   `tac`
