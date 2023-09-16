# Note 3.

### ssh

``` sh
$ mkdir .ssh
$ touch config
```

```
Host hostname
		HostName localhost
		Port 22
		User root
		IdentifyFile ~/.ssh/aliyun
```

SSH 免密码登录

``` sh
$ ssh-keygen
$ shh-copy-id -i /path/to/identify root@xxx
```

