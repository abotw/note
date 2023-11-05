# Vim

## Reference

* [Vim Basics | CS61C](https://cs61c.org/sp23/labs/lab00/#vim-basics)

- [Vim | CS 61A Spring 2023](https://cs61a.org/articles/vim/)
- [Vim | Albert Wu](http://albertwu.org/cs61a/notes/vim.html)
- [Vim - CS自学指南](https://csdiy.wiki/%E5%BF%85%E5%AD%A6%E5%B7%A5%E5%85%B7/Vim/)
- [Editors (Vim) - TMSOYCSE](https://missing.csail.mit.edu/2020/editors/)
- [ ] [Unix Vi Guide](https://networking.ringofsaturn.com/Unix/viguide.php)
- [ ] [Vim Cheat Sheat for Programmers by Michael Pohoreski](http://michael.peopleofhonoronly.com/vim/)

##  1. Vim Editing Modes

1. normal mode
2. insert mode
3. command mode
4. visual mode

## Some useful Vim commands

| **Command**                      | **Explanation**                                              |
| -------------------------------- | ------------------------------------------------------------ |
| `[ESC]` `#!vim :tabe <filepath>` | Opens the file at `filepath` in a new tab. You can use `[Tab]` for autocompletion |
| `[Esc]` `#!vim :tabn`            | Go to the next tab in the tab bar                            |
| `[Esc]` `#!vim :tabp`            | Go to the previous tab in the tab bar                        |

## Vim Tutor

## Multiple Windows

``` vim
:split filename
:vsplit filename
```

* `CTRL-w` + one of the `hjkl` keys - To navigate between windows.

## 常用 Vim 命令总结

### 复制当前文件全部内容

`ggVG` - 将光标移动到文件的第一行（`gg`），然后选择整个文件的内容（`V`），并将光标移动到文件的最后一行（`G`）。

`"+y` - 将复制选择的内容到系统剪贴板。

`Ctrl + Shift + V` 或右键点击粘贴 - 粘贴内容

# Vimrc

## Reference

- [Vimrc | Albert Wu](http://albertwu.org/cs61a/notes/vimrc.html)

```vim linenums="1"
" Syntax highlighting
syntax on
colorscheme default
filetype plugin indent on

set nu 						" Line numbers
set number " To enable line numbers

" Here are common settings that work well with Python
set expandtab     " Uses spaces instead of tabs
set tabstop=4     " Each tab is 4 spaces
set autoindent

" Key bindings
nnoremap ; :      " Enter command mode by typing semicolon
nnoremap j gj     " Move along rows,
nnoremap k gk     " not lines

set mouse=a 			" To enable your mouse

set nocompatible " which tells Vim not to be compatible with Vi, Vim's predecessor.
```



