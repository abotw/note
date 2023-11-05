# VMWare

## 使用 VMWare Fusion Player 在 Apple Silicon 处理器的机型上配置 Ubuntu 虚拟机

### 下载 VMWare Fusion 13 Player

-   [VMware Fusion Player – Personal Use License](https://customerconnect.vmware.com/evalcenter?p=fusion-player-personal-13)

>   Fusion Player offers a *Personal Use License*, available for free with a valid CustomerConnect account. Home users, Open Source contributors, students, and anyone else can use Fusion Player **Free** for Non-Commercial activity.

### 下载 [Ubuntu Server for ARM](https://ubuntu.com/download/server/arm)

-   Ubuntu 20.04.5 LTS (Focal Fossa)：可以使用，需要经过改动才能修改图形界面的分辨率。
-   Ubuntu 22.04 LTS (Jammy Jellyfish)：从 Ubuntu 22.04.2 LTS 开始可以直接使用。

### 在 VMWare Fusion 上安装 Ubuntu on ARM

<figure markdown>
  ![image-20230914015605329](./assets/image-20230914015605329.png)
  <figcaption>点击左上角的加号创建新的虚拟机</figcaption>
</figure>

<figure markdown>
  ![image-20230914015755010](./assets/image-20230914015755010.png)
  <figcaption>将下载好的镜像拖入框中</figcaption>
</figure>

<figure markdown>
  ![image-20230914015856725](./assets/image-20230914015856725.png)
  <figcaption>导入完成之后使用默认配置即可，你也可以按照自己的需求对 configuration 进行对应的改动</figcaption>
</figure>

![image-20230914020042846](./assets/image-20230914020042846.png)

<figure markdown>
  ![image-20230914020157756](./assets/image-20230914020157756.png)
  <figcaption>选择语言</figcaption>
</figure>

![image-20230914020236802](./assets/image-20230914020236802.png)

![image-20230914020448859](./assets/image-20230914020448859.png)

![image-20230914020557257](./assets/image-20230914020557257.png)

首选会让选择网卡，选择默认的就好。

![image-20230914020741087](./assets/image-20230914020741087.png)

然后会选择输入动态地址。根据描述可知，这是链接外部网络需要配置的。有需要可以配置。

![image-20230914020819689](./assets/image-20230914020819689.png)

![image-20230914020856275](./assets/image-20230914020856275.png)

确认镜像地址，直接选择这个默认的即可。

![image-20230914020912173](./assets/image-20230914020912173.png)

选择默认的完整安装。

![image-20230914020945864](./assets/image-20230914020945864.png)

![image-20230914021004340](./assets/image-20230914021004340.png)

![image-20230914021017610](./assets/image-20230914021017610.png)

直到跳出输入账号密码的页面，输入你要创建的用户密码
注意root和admin是已经被系统创建了的账户。

![image-20230914021149835](./assets/image-20230914021149835.png)

![image-20230914021222258](./assets/image-20230914021222258.png)

这里选择安装ssh服务，键盘上下键挪到install后，回车确认即可。ssh服务用来后续可以通过ssh指令远程连接上虚拟机，很好用，所以推荐安装上

![image-20230914021305380](./assets/image-20230914021305380.png)



这里需要注意的是直接安装的话会出现如下图所示的报错，问题可能是ubantu官方bug导致的，大概是因为内核版本导致

为了规避这个问题我们需要先把网络关闭，然后再选择done

![image-20230914021415509](./assets/image-20230914021415509.png)

![image-20230914021442870](./assets/image-20230914021442870.png)



等待重启，出现这个页面后回车确认，不要傻傻的等他跳转



``` sh
$ sudo apt-get install ubuntu-desktop
```

