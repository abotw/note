# 实验 0：上手 Linux 开发环境

boaw

boaw1256

-   Server IP Address: `106.14.165.94`
-   ssh, secure shell

``` sh
$ ssh boaw@106.14.165.94
The authenticity of host '106.14.165.94 (106.14.165.94)' can't be established.
ED25519 key fingerprint is SHA256:LHvn4qDvTdM1+GcJtG2f+uywxDA2JSys.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes

Warning: Permanently added '106.14.165.94' (ED25519) to the list of known hosts.
boaw@106.14.165.94's password:
Welcome to Ubuntu 22.04.3 LTS (GNU/Linux 5.15.0-52-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Wed Sep 13 06:31:28 PM CST 2023

  System load:  0.0                Processes:             108
  Usage of /:   36.8% of 39.01GB   Users logged in:       0
  Memory usage: 7%                 IPv4 address for eth0: 172.24.202.82
  Swap usage:   0%

 * Strictly confined Kubernetes makes edge and IoT secure. Learn how MicroK8s
   just raised the bar for easy, resilient and secure K8s cluster deployment.

   https://ubuntu.com/engage/secure-kubernetes-at-the-edge

Expanded Security Maintenance for Applications is not enabled.

17 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

11 additional security updates can be applied with ESM Apps.
Learn more about enabling ESM Apps service at https://ubuntu.com/esm



The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.


Welcome to Alibaba Cloud Elastic Compute Service !
```

查看服务器信息常用命令

-   查看主机名：`hostname`
-   查看用户名：`whoami`
-   查看硬盘空间：`df -h` （仅 `root` 权限）
-   查看内存状态：`free -h`
-   查看当前文件夹空间：`du --max-depth=1 -h`
-   修改登录密码：`passwd`

``` sh
$ hostname
stickmind
$ whoami
boaw
$ df -h
Filesystem      Size  Used Avail Use% Mounted on
tmpfs           359M  1.0M  358M   1% /run
/dev/vda3        40G   15G   23G  39% /
tmpfs           1.8G     0  1.8G   0% /dev/shm
tmpfs           5.0M     0  5.0M   0% /run/lock
/dev/vda2       197M  282K  197M   1% /boot/efi
tmpfs           359M  4.0K  359M   1% /run/user/1040
$ free -h
               total        used        free      shared  buff/cache   available
Mem:           3.5Gi       215Mi       1.9Gi       2.0Mi       1.4Gi       3.1Gi
Swap:          4.0Gi          0B       4.0Gi
$ du --max-depth=1 -h
4.0K	./.cache
20K	.
$ passwd
Changing password for boaw.
Current password:
New password:
Retype new password:
passwd: password updated successfully
```

```  json title="./.vscode/sftp.json"
{
    "name": "CSE-CS102",
    "host": "106.14.165.94",
    "protocol": "sftp",
    "port": 22,
    "username": "boaw",
    "password": "boawboaw",
    "remotePath": "/home/boaw/cs102/labs/lab0",
    "uploadOnSave": true,
    "useTempFile": true,
    "openSsh": true
}
```

*[终端]: 
