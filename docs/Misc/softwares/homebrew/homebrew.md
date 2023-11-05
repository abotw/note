# Homebrew

软件包管理工具

-   [Homebrew 0.1](https://github.com/Homebrew/brew/releases/tag/0.1), May 21, 2009

---

-   formula, formulae 配方
-   bottle 瓶装版
-   cask 木桶

``` sh
$ which brew
/opt/homebrew/bin/brew
```

---

Install & Configure

``` sh
# 1. Install
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
# 2. add Homebrew to PATH
(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> /Users/abotw/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```

## 代码片段

```
export https_proxy=http://127.0.0.1:7890 http_proxy=http://127.0.0.1:7890 all_proxy=socks5://127.0.0.1:7890
```



``` sh title="修改 homebrew 源"
cd "$(brew --repo)"
git remote set-url origin https://mirrors.ustc.edu.cn/brew.git
// homebrew-core 
cd "$(brew --repo)/Library/Taps/homebrew/homebrew-core"
git remote set-url origin https://mirrors.ustc.edu.cn/homebrew-core.git
```

``` sh title="修改 Homebrew Bottles 源"
echo 'export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.ustc.edu.cn/homebrew-bottles' >> ~/.zshrc
source ~/.zshrc
```

``` sh title="重置 Homebrew 源"
cd "$(brew --repo)"
git remote set-url origin https://github.com/Homebrew/brew.git
// homebrew-core
cd "$(brew --repo)/Library/Taps/homebrew/homebrew-core"
git remote set-url origin https://github.com/Homebrew/homebrew-core.git
```

### Homebrew 设置代理

https://blog.csdn.net/CaptainDrake/article/details/129172826

ClashX 终端代理命令

```sh
export ALL_PROXY=socks5://127.0.0.1:7980 # export VARNAME="value", To export an environment variable
```

## Supplemental materials

-   [Homebrew homepage](https://brew.sh/)
-   [Homebrew docs](https://docs.brew.sh/)
-   [Homebrew cheatsheet @ devhints.io](https://devhints.io/homebrew)

**使用教程**

-   [ ] [Homebrew / Linuxbrew 镜像使用帮助 @ TUNA 清华大学开源软件镜像站](https://mirrors.tuna.tsinghua.edu.cn/help/homebrew/) , 2023-08-25

-   [ ] [在 M1 芯片 Mac 上使用 Homebrew @ neverland](https://type.cyhsu.xyz/2020/12/use-homebred-on-m1-macs/), 2020-12-07

**评论**

-   [x] [评 Homebrew 4.0.0 @ neverland](https://type.cyhsu.xyz/2023/03/brew4/) ([Homebrew 升级 4.0.0，麦金塔上的啤酒会更香吗？ @ sspai](https://sspai.com/post/78587)), 2023-03-01
-   [ ] [partialupgrade @ ubuntu](https://help.ubuntu.com/community/partialupgrade)
