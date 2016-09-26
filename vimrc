set nocompatible              " be iMproved, required

"leader key!
let mapleader = "\<Space>"
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Bundle 'gmarik/Vundle.vim'

Bundle 'scrooloose/syntastic'
let g:syntastic_cpp_compiler = 'g++'
let g:syntastic_cpp_compiler_options = '  -Wall -Werror -ansi -pedantic -std=c++11'

Bundle 'bling/vim-bufferline'
let g:bufferline_echo = 0
Bundle 'bling/vim-airline'
let g:airline#extensions#syntastic#enabled = 1
let g:airline#extensions#bufferline#enabled = 1

" fancy symbols
let g:airline_powerline_fonts=0
if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif
" unicode symbols
let g:airline_left_sep = '»'
let g:airline_left_sep = '▶ '
let g:airline_right_sep = '«'
let g:airline_right_sep = '◀'
let g:airline_symbols.linenr = '␊'
let g:airline_symbols.linenr = '␤'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.branch = '⎇'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.paste = '∥'
let g:airline_symbols.whitespace = 'Ξ'


Bundle 'kien/ctrlp.vim'
Bundle 'tpope/vim-fugitive'

"-------- YCM -----------------"
Bundle 'Valloric/YouCompleteMe'
let g:ycm_global_ycm_extra_conf='~/dotfiles/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf=0
let g:ycm_autoclose_preview_window_after_completion = 1
let g:ycm_autoclose_preview_window_after_insertion = 1
"-------- YCM -----------------"

let g:cpp_class_scope_highlight = 1
let g:cpp_experimental_template_highlight = 1
Bundle 'octol/vim-cpp-enhanced-highlight'
call vundle#end()

let c_no_curly_error=1

set nocompatible   " Disable vi-compatibility
set number
set visualbell
set cursorline
set hidden "allows switching away from buffers wihtout annoying fucking messages

set laststatus=2   " Always show the statusline
set encoding=utf-8 " Necessary to show Unicode glyphs
set ts=2 sw=2 et
set tw=0
set smartindent
set nostartofline
set incsearch
set ignorecase
set smartcase
set t_Co=256
let g:zenburn_old_Visual=1
"colorscheme zenburn

"键盘命令

"Makefile no tab -> spaces issue
autocmd FileType make setlocal noexpandtab

map <C-I> :pyf ~/dotfiles/clang-format.py<CR>
imap <C-I> <ESC>:pyf ~/dotfiles/clang-format.py<CR>i

let hlstate=0
nnoremap <Leader>h :if (hlstate == 0) \| nohlsearch \| else \| set hlsearch \| endif \| let hlstate=1-hlstate<cr>
" Mappings to access buffers (don't use "\p" because a
" delay before pressing "p" would accidentally paste).
" \l       : list buffers
" \b \f \g : go back/forward/last-used
" \1 \2 \3 : go to buffer 1/2/3 etc
nnoremap <Leader>l :ls<CR>
nnoremap <silent> <Leader>j :bp!<CR>
nnoremap <silent> <Leader>k :bn!<CR>
nnoremap <silent> <Leader>d :bd<CR>
nnoremap <silent> <Leader><Space> :b#<CR>
nnoremap <silent> <Leader>1 :1b!<CR>
nnoremap <silent> <Leader>2 :2b!<CR>
nnoremap <silent> <Leader>3 :3b!<CR>
nnoremap <silent> <Leader>4 :4b!<CR>
nnoremap <silent> <Leader>5 :5b!<CR>
nnoremap <silent> <Leader>6 :6b!<CR>
nnoremap <silent> <Leader>7 :7b!<CR>
nnoremap <silent> <Leader>8 :8b!<CR>
nnoremap <silent> <Leader>9 :9b!<CR>
nnoremap <silent> <Leader>0 :10b!<CR>
"compile and run binds
nnoremap <silent> <Leader><Tab> :!g++ -Wall -Werror -ansi -pedantic -std=c++11 -g %<CR>
nnoremap <silent> <Leader>q :!./a.out<CR>
set nocompatible                 "去掉有关vi一致性模式，避免以前版本的bug和局限    
set nu!                                    "显示行号
set guifont=Source\ Code\ Pro\ for\ Powerline:h13   " 设置字体，字体名称和字号
filetype on                              "检测文件的类型     
set history=1000                  "记录历史的行数
set background=dark          "背景使用黑色
syntax on                                "语法高亮度显示
set autoindent                       "vim使用自动对齐，也就是把当前行的对齐格式应用到下一行(自动缩进）
set cindent                             "（cindent是特别针对 C语言语法自动缩进）
set smartindent                    "依据上面的对齐格式，智能的选择对齐方式，对于类似C语言编写上有用   
set tabstop=4                        "设置tab键为4个空格，
set shiftwidth =4                   "设置当行之间交错时使用4个空格     
set ai!                                      " 设置自动缩进 
set showmatch                     "设置匹配模式，类似当输入一个左括号时会匹配相应的右括号      
set guioptions-=T                 "去除vim的GUI版本中得toolbar   
set vb t_vb=                            "当vim进行编辑时，如果命令错误，会发出警报，该设置去掉警报       
set ruler                                  "在编辑过程中，在右下角显示光标位置的状态行     
set nohls                                "默认情况下，寻找匹配是高亮度显示，该设置关闭高亮显示     
set incsearch                        "在程序中查询一单词，自动匹配单词的位置；如查询desk单词，当输到/d时，会自动找到第一个d开头的单词，当输入到/de时，会自动找到第一个以ds开头的单词，以此类推，进行查找；当找到要匹配的单词时，别忘记回车 
set backspace=2           " 设置退格键可用
"ctags
let Tlist_Sort_Type = "name" " 按照名称排序
let Tlist_Use_Right_Window = 1 " 在右侧显示窗口
let Tlist_Compart_Format = 1 " 压缩方式
let Tlist_Exist_OnlyWindow = 1 " 如果只有一个buffer，kill窗口也kill掉buffer
let Tlist_File_Fold_Auto_Close = 0 " 不要关闭其他文件的tags
let Tlist_Enable_Fold_Column = 0 " 不要显示折叠树
autocmd FileType java set tags+=D:toolsjavatags
autocmd FileType h,cpp,cc,c set tags+=D:toolscpptags
let Tlist_Show_One_File=1 "不同时显示多个文件的tag，只显示当前文件的
"设置tags
set tags=tags;
set autochdir
" 侦测文件类型
filetype on
" 载入文件类型插件
filetype plugin on
" 高亮显示匹配的括号
set showmatch
filetype plugin indent on
"打开文件类型检测, 加了这句才可以用智能补全
set completeopt=longest,menu
set nu!

"""""新文件标题""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"新建.c,.h,.sh,.java,.py文件，自动插入文件头 
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java,*.py exec ":call SetTitle()" 
""定义函数SetTitle，自动插入文件头 
func SetTitle() 
    if &filetype == 'sh' 
        call setline(1,"\#########################################################################") 
        call append(line("."), "\# File Name: ".expand("%")) 
        call append(line(".")+1, "\# Author: anryyang") 
        call append(line(".")+2, "\# mail: anryyang@gmail.com") 
        call append(line(".")+3, "\# Created Time: ".strftime("%c")) 
        call append(line(".")+4, "\#########################################################################") 
        call append(line(".")+5, "\#!/bin/bash") 
        call append(line(".")+6, "")
    else
	if &filetype == 'python' 
		call setline(1,"\#########################################################################") 
		call append(line("."), "\# File Name: ".expand("%")) 
		call append(line(".")+1, "\# Author: anryyang") 
		call append(line(".")+2, "\# mail: anryyang@gmail.com") 
		call append(line(".")+3, "\# Created Time: ".strftime("%c")) 
		call append(line(".")+4, "\#########################################################################") 
		call append(line(".")+5, "\#!/usr/bin/env/ python") 
		call append(line(".")+6, "")
	else  
		call setline(1, "/*************************************************************************") 
		call append(line("."), "    > File Name: ".expand("%")) 
		call append(line(".")+1, "    > Author: anryyang") 
		call append(line(".")+2, "    > Mail: anryyang@gmail.com ") 
		call append(line(".")+3, "    > Created Time: ".strftime("%c")) 
		call append(line(".")+4, " ************************************************************************/") 
		call append(line(".")+5, "")
	endif
    endif
    if &filetype == 'cpp'
        call append(line(".")+6, "#include<iostream>")
        call append(line(".")+7, "using namespace std;")
        call append(line(".")+8, "")
    endif
    if &filetype == 'c'
        call append(line(".")+6, "#include<stdio.h>")
        call append(line(".")+7, "")
    endif
    "新建文件后，自动定位到文件末尾
    autocmd BufReadPost * normal G
endfunc 
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
