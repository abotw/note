# MySQL

mysql: root

```
==> Caveats
==> mysql@5.7
We've installed your MySQL database without a root password. To secure it run:
    mysql_secure_installation

MySQL is configured to only allow connections from localhost by default

To connect run:
    mysql -uroot

mysql@5.7 is keg-only, which means it was not symlinked into /opt/homebrew,
because this is an alternate version of another formula.

If you need to have mysql@5.7 first in your PATH, run:
  echo 'export PATH="/opt/homebrew/opt/mysql@5.7/bin:$PATH"' >> ~/.zshrc

For compilers to find mysql@5.7 you may need to set:
  export LDFLAGS="-L/opt/homebrew/opt/mysql@5.7/lib"
  export CPPFLAGS="-I/opt/homebrew/opt/mysql@5.7/include"

To restart mysql@5.7 after an upgrade:
  brew services restart mysql@5.7
Or, if you don't want/need a background service you can just run:
  /opt/homebrew/opt/mysql@5.7/bin/mysqld_safe --datadir\=/opt/homebrew/var/mysql
```

``` sh
$ mysql_secure_installation
zsh: command not found: mysql_secure_installation
$ echo 'export PATH="/opt/homebrew/opt/mysql@5.7/bin:$PATH"' >> ~/.zshrc # If you need to have mysql@5.7 first in your PATH
$ mysql_secure_installation

Securing the MySQL server deployment.

Enter password for user root:
Error: Can't connect to local MySQL server through socket '/tmp/mysql.sock' (2)
$ systemctl status mysql
zsh: command not found: systemctl
$ sudo brew services start mysql
$ brew services list
$ mysql.server start

```

``` sh
brew install mysql@5.7
brew services restart mysql@5.7
/opt/homebrew/opt/mysql@5.7/bin/mysqld_safe --datadir=/opt/homebrew/var/mysql
echo 'export PATH="/opt/homebrew/opt/mysql@5.7/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
which mysql
/opt/homebrew/opt/mysql@5.7/bin/mysql
mysql --version
mysql  Ver 14.14 Distrib 5.7.43, for osx10.18 (x86_64) using  EditLine wrapper
mysql.server
Usage: mysql.server  {start|stop|restart|reload|force-reload|status}  [ MySQL server options ]
```

2023-09-11T01:55:14.588724Z 1 [Note] A temporary password is generated for root@localhost: rcx2Ga5Pkw*W

If you lose this password, please consult the section How to Reset the Root Password in the MySQL reference manual.

``` sh
alias mysql=/usr/local/mysql/bin/mysql

echo 'export PATH="/usr/local/mysql/bin/:$PATH"' >> ~/.zshrc
```

---