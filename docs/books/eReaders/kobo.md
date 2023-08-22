# Kobo Clara 2E

## 书籍

### 1. 本地传书

### 2. Wi-Fi 传书

-   [Send to Kobo/Kindle](https://send.djazz.se/)
-   [kepubify](https://pgaskin.net/kepubify/)

电子书的文件名**不能包含中文**，否则会传输失败。

## Kobo's Dictionary

### Format: `dicthtml`

### 词典文件存放路径

`/Volumes/KOBOeReader/.kobo/custom-dict`

### Kobo 字典资源

-   [Index of Custom Dictionaries for Kobo eReader](https://www.mobileread.com/forums/showthread.php?t=232883)

---

-   Chinese-English: [https://www.mobileread.com/forums/showthread.php?t=202182](https://www.mobileread.com/forums/showthread.php?t=202182)

-   English-Chinese (Mandarin?) : [https://www.mobileread.com/forums/sh...&postcount=445](https://www.mobileread.com/forums/showpost.php?p=3740383&postcount=445) (Semwize, 2018-08-25)
-   -: [https://basic.lanzoul.com/b036too4b](https://basic.lanzoul.com/b036too4b)，密码：`1234`

## 字体

-   字体文件存放目录
-   支持的字体文件格式

## 配置

```sh title="/Volumes/KOBOeReader/.kobo/Kobo/Kobo eReader.conf"
# 导出划线注释
[FeatureSettings]
ExportHighlights=true
```

## [NickelMenu](https://pgaskin.net/NickelMenu/)

### 配置

-   [x] [**Exporting annotations, bookmarks and reading progress to the cloud**](https://www.mobileread.com/forums/showthread.php?t=349637)

```sh title="/Volumes/KOBOeReader/.adds/nm/config"
# 主菜单设置

menu_item :main :Reboot 重启 :power :reboot

## dark_mode       - ReadingSettings.DarkMode
menu_item :main :Dark Mode 夜间模式 :nickel_setting :toggle :dark_mode

## screenshots     - FeatureSettings.Screenshots
menu_item :main :Screenshots 截图 :nickel_setting :toggle :screenshots

menu_item :main :Broser 浏览器 :nickel_browser :modal
menu_item :main :Reading Life 阅读统计 :nickel_open :reading_life:reading_life

# 导出全部注释
menu_item :main    :Sync Annotations 导出全部注释    :nickel_wifi     :autoconnect
  chain_success                         :cmd_spawn       :quiet:/mnt/onboard/.adds/notes/notes.sh
  chain_success                         :dbg_toast       :Syncing Notes 导出成功
  chain_failure                         :dbg_toast       :Syncing Notes 导出失败

## GAMES
menu_item :main :Sketch Pad涂鸦板 :nickel_extras :sketch_pad
menu_item :main :Sudoku 数独 :nickel_extras :sudoku
menu_item :main :Unblock It 华容道 :nickel_extras :unblock_it

# 阅读界面设置
menu_item :reader :Screenshots 截图 截图 :nickel_setting :toggle :screenshots
menu_item :reader :Dark Mode 夜间模式 :nickel_setting :toggle :dark_mode
```

``` sh title="/Volumes/KOBOeReader/.adds/notes/notes.sh"
NOTES="/mnt/onboard/.adds/notes"
# Note: Depending on your language this folder may have a different name
EXPORT_FOLDER="/mnt/onboard/Exported Annotations"
```

## [NickelClock](https://github.com/shermp/NickelClock) - Show time while reading



## 支持的电子书格式

>   转换的方式有两种，一种是使用 Calibre 的插件进行转换，不过据我的观察有一部分书籍会出现标题和目录字体乱码现象。第二种更为简单易用，通过 Wi-Fi 网页传书的方式在传输过程中顺便转换，具体也在后文介绍。

*   ePub, PDF - 支持较差
*   Kobo ePub (.kepub) - 支持
    *   支持阅读时间统计
    *   支持快速翻页

*   mobi
*   .azw & .azw3 - 不支持

### 格式转换：ePub -> Kobo ePub

#### 1. 命令行工具：kepubify

#### 2. App：Calibre

安装插件：

1.   KePub Input 
2.   kePub Output

## 参考

-   [ ] [Kobo漫画制作备忘录](https://www.douban.com/note/819353316/)
-   [x] [Kobo Libra H2O 使用体验和设置指南 - 少数派](https://sspai.com/post/78528)
-   [ ] [Kobo_Tips - Github](https://github.com/Megumi-B/Kobo_Tips)
-   [ ] [kobo自制词典下载（kobo英英词典，kobo英汉词典，kobo汉语词典，kobo日语词典）](https://do1024.com/archives/1093/)
-   [ ] [Kobo Firmware Downloads Kobo 固件下载](https://pgaskin.net/KoboStuff/kobofirmware.html)
-   [ ] [**A Guide to Customize Kobo for New Simplified Chinese Readers**](https://www.mobileread.com/forums/showthread.php?t=339630)