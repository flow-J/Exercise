" An example for a vimrc file.
"
" Maintainer:	Bram Moolenaar <Bram@vim.org>
" Last change:	2015 Mar 24
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"	    for OpenVMS:  sys$login:.vimrc

" When started as "evim", evim.vim will already have done these settings.
"



" 相关vim脚本文档 http://vimdoc.sourceforge.net
" 相关好文 https://github.com/yangyangwithgnu/use_vim_as_ide
" 导入vim插件管理文件
if filereadable(expand("~/.vimrc.bundles"))
    source ~/.vimrc.bundles
endif
 
" 基本配置
set nocompatible "不要vim模仿vi模式，建议设置，否则会有很多不兼容的问题
set mouse=a      " 启动鼠标所有模式，但是右键功能不可用, 可以保证鼠标滚屏在当前屏幕内
set mousehide    " 输入文件时隐藏鼠标
set backspace=indent,eol,start   " 退格键分别可删除缩进，上一行结束，insert之前的字
set showmatch     " 设置匹配模式 
set nobackup      " 不备份
set nowritebackup " 不写入备份文件
set noswapfile    " 关闭交换文件
set history=500	  " history存储长
set ruler         " 显示标尺 
set showcmd       " 显示输入命令 
set incsearch     " 搜索时自动匹配 
set hlsearch      " 高亮搜索项 
set ignorecase    " 无视大小写 
set smartcase     " 如果有大写就区别大小写匹配 
set laststatus=2  " 总是显示状态栏 
" set autowrite     " 切换文件自动保存 https://github.com/terryma/vim-multiple-cursors/raw/master/assets/example1.gif?raw=true
set shortmess=atI"  " 关闭欢迎页面
set viewoptions=cursor,folds,slash,unix " viminfo 记录的内容
set virtualedit=onemore             " 光标可以移到当行最后一个字符之后 
set hidden                          " 切换文件不保存，隐藏 
"set confirm       " 退出前验证
" set spell         " 拼写检查
set linespace=0   " 行之间没有多余的空格
set wildmenu      " 自动补全时的文件菜单
set wildmode=list:longest,full " 自动补全时，匹配最长子串，列出文件
set whichwrap=b,s,h,l,<,>,[,]  " 行尾可右移到下行，行首左移到上行,b：退格，s：空格，hl：左右，<>：n/v模式下的左右，[]：i/r模式下的左右
set scrolljump=5  " 光标离开屏幕范围 
set scrolloff=3   " 光标移动至少保留行数
 
" 格式
set nowrap        " 取消自动折行
"set smarttab
set tabstop=4     " tab=4空格 
set softtabstop=4 " 回退可以删除缩进 
set shiftwidth=4  " 缩进位宽=4个空格位
set autoindent    " 自动缩进 
set expandtab     " tab由空格表示
 
set nojoinspaces  " 用J合并两行用一个空格隔开
set splitright    " 用vsplit新建窗口，让新的放右边
set splitbelow    " 用split新建窗口，让新的放下面
set pastetoggle=<F12> " 指定F12进入黏贴模式，可以正常复制缩进
set iskeyword-=.  " 让'.' 作为单词分割符
set iskeyword-=#  " 让'#' 作为单词分割符
set iskeyword-=-  " 让'-' 作为单词分割符
set listchars=tab:›\ ,trail:•,extends:#,nbsp:. " 空格等无效字符显示
set textwidth=80  " 内容宽度
set fileencodings=utf-8,gb18030,gbk,big5 " 文件编码
 
" 开启新的buffer时，自动转到对应文件目录
let g:autochdir = 1
if exists('g:autochdir')
    autocmd BufEnter * if bufname("") !~ "^\[A-Za-z0-9\]*://" | lcd %:p:h | endif
endif
 
" 设置u的返回步数限制
if has('persistent_undo')
    set undofile               " 开启u回滚文件记录
    set undolevels=1000         " 最大数量的改变回滚
    set undoreload=10000        " 最大数量重载可回滚行数
endif
 
" 特殊文件打开
autocmd BufNewFile,BufRead *.py,*.pyw set filetype=python
autocmd BufNewFile,BufRead *.html.twig set filetype=html.twig
autocmd FileType haskell setlocal expandtab shiftwidth=2 softtabstop=2
autocmd BufNewFile,BufRead *.coffee set filetype=coffee
autocmd FileType haskell setlocal commentstring=--\ %s
autocmd FileType haskell setlocal nospell
 
" key 映射
let mapleader = ','         " 全局leader设置
let maplocalleader = '_'    " 本地leader设置
 
" 设置tag和window间快速跳转 
let g:easyWindows = 1
if exists('g:easyWindows')
    " 向上
    map <C-J> <C-W>j<C-W>_  
    " 向下
    map <C-K> <C-W>k<C-W>_
    " 向右
    map <C-L> <C-W>l<C-W>_
    " 向左
    map <C-H> <C-W>h<C-W>_
endif
 
" 处理折叠行的左右移动
noremap j gj
noremap k gk
 
" 没sudo却想保存
cmap w!! w !sudo tee % >/dev/null
 
" ,fc查找冲突的地方
map <leader>fc /\v^[<\|=>]{7}( .*\|$)<CR>
 
" ,ff 查找光标后的单词位置，列出选择项
nmap <Leader>ff [I:let nr = input("Which one: ")<Bar>exe "normal " . nr ."[\t"<CR>
 
" 屏幕左移和右移
map zl zL
map zh zH
 
" 映射vsp这些开启新的buffer,默认目录为当前目录
cnoremap %% <C-R>=fnameescape(expand('%:h')).'/'<cr>
map <leader>ew :e %%
map <leader>es :sp %%
map <leader>ev :vsp %%
map <leader>et :tabe %%
 
" 黏贴板
if has('clipboard')
    if has('unnamedplus')
        set clipboard=unnamedplus
    else
        set clipboard=unnamed
    endif
endif
 
"字体的设置
set guifont=Consolas,Bitstream_Vera_Sans_Mono:h9:cANSI "设置gui下的字体
set gfw=幼圆:h10:cGB2312
 
" 语法高亮
syntax on
 
" 缩进和md文件
filetype plugin indent on " 自动根据类型启动对应插件，缩进开启
 
" 设置主题,UI
" solarized 主题
set background=dark
if filereadable(expand("~/.vim/bundle/vim-colors-solarized/colors/solarized.vim"))
	let g:solarized_termcolors=256
	let g:solarized_termtrans=1
	let g:solarized_contrast="normal"
	let g:solarized_visibility="normal"
	color solarized             " Load a colorscheme
endif
 
set cursorline " 选中行高亮 
autocmd BufEnter *.py set cc=81 " 打开py文件81行高亮  
" 之前的高亮线太难看，重新制定颜色，这里的black和iterm2颜色配置中的black一样
hi CursorLine   cterm=NONE ctermbg=black guibg=black  
hi CursorColumn   cterm=NONE ctermbg=black guibg=black " 
highlight ColorColumn ctermbg=black guibg=black
set number " 设置行号
hi LineNr ctermbg=black
 
" Indent Guides 缩进列对齐线
let g:indent_guides_start_level = 2
let g:indent_guides_guide_size = 1
let g:indent_guides_enable_on_vim_startup = 1
 
" airline 就是状态栏的箭头
let g:airline_theme="dark"
let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#buffer_nr_show = 1
 
" NerdTree配置 control+e打开当前文件目录树
map <C-e> :NERDTreeToggle<CR>
map <leader>ee :NERDTreeToggle<CR>
nmap <leader>nt :NERDTreeFind<CR>
 
let NERDTreeShowBookmarks=1
let NERDTreeIgnore=['\.pyc', '\~$', '\.swo$', '\.swp$', '\.git', '\.hg', '\.svn', '\.bzr']
let NERDTreeChDirMode=0
let NERDTreeQuitOnOpen=1
let NERDTreeMouseMode=2
let NERDTreeShowHidden=1
let NERDTreeKeepTreeInNewTab=1
let g:nerdtree_tabs_open_on_gui_startup=0
 
" syntastic 配置
" 设置每次w保存后语法检查
function! ToggleErrors()
    Errors
endfunction
let g:syntastic_check_on_open=1
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_wq = 0
let syntastic_loc_list_height = 5
let g:syntastic_html_tidy_ignore_errors=[" proprietary attribute \"ng-"]
autocmd WinEnter * if &buftype ==#'quickfix' && winnr('$') == 1 | quit |endif
autocmd WinLeave * lclose
 
" 自动补全tab触发
function! InsertTabWrapper()
	let col = col('.') - 1
	if !col || getline('.')[col - 1] !~ '\k'
        return "\<tab>"
	else
        return "\<c-p>"
	endif
endfunction
inoremap <Tab> <c-r>=InsertTabWrapper()<cr>
inoremap <S-Tab> <c-n>
 
" Ctrlp 和 Ctrlp-funky(,fu)
if isdirectory(expand("~/.vim/bundle/ctrlp.vim/"))
    let g:ctrlp_working_path_mode = 'ra'
    nnoremap <silent> <D-t> :CtrlP<CR>
    nnoremap <silent> <D-r> :CtrlPMRU<CR>
    let g:ctrlp_custom_ignore = {
                \ 'dir':  '\.git$\|\.hg$\|\.svn$',
                \ 'file': '\.exe$\|\.so$\|\.dll$\|\.pyc$' }
 
    if executable('ag')
        let s:ctrlp_fallback = 'ag %s --nocolor -l -g ""'
    elseif executable('ack-grep')
        let s:ctrlp_fallback = 'ack-grep %s --nocolor -f'
    elseif executable('ack')
        let s:ctrlp_fallback = 'ack %s --nocolor -f'
        " On Windows use "dir" as fallback command.
    else
        let s:ctrlp_fallback = 'find %s -type f'
    endif
    if exists("g:ctrlp_user_command")
        unlet g:ctrlp_user_command
    endif
    let g:ctrlp_user_command = {
                \ 'types': {
                \ 1: ['.git', 'cd %s && git ls-files . --cached --exclude-standard --others'],
                \ 2: ['.hg', 'hg --cwd %s locate -I .'],
                \ },
                \ 'fallback': s:ctrlp_fallback
                \ }
 
    if isdirectory(expand("~/.vim/bundle/ctrlp-funky/"))
        " CtrlP extensions
        let g:ctrlp_extensions = ['funky']
        "funky
        nnoremap <Leader>fu :CtrlPFunky<Cr>
    endif
endif
 
" complete
autocmd Filetype * if &omnifunc == "" | setlocal omnifunc=syntaxcomplete#Complete | endif
autocmd FileType css setlocal omnifunc=csscomplete#CompleteCSS
autocmd FileType html,markdown setlocal omnifunc=htmlcomplete#CompleteTags
autocmd FileType javascript setlocal omnifunc=javascriptcomplete#CompleteJS
autocmd FileType python setlocal omnifunc=pythoncomplete#Complete
 
"进行版权声明的设置
"添加或更新头
map <F4> :call TitleDet()<cr>'s
autocmd BufNewFile *.py :call AddTitle()
function AddTitle()
    call append(0,"#! /usr/bin/env python")
    call append(1,"# -*- coding: utf-8 -*-")
    call append(2,"# vim:fenc=utf-8")
    call append(3,"#  Copyright © XYM")
    call append(4,"# CreateTime: ".strftime("%Y-%m-%d %H:%M:%S"))
    call append(5,"")
endf
 
let python_highlight_all = 1


set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab







if v:progname =~? "evim"
  finish
endif

" Use Vim settings, rather than Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file (restore to previous version)
  set undofile		" keep an undo file (undo changes after closing)
endif
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" CTRL-U in insert mode deletes a lot.  Use CTRL-G u to first break undo,
" so that you can undo CTRL-U after inserting a line break.
inoremap <C-U> <C-G>u<C-U>

" In many terminal emulators the mouse works just fine, thus enable it.
if has('mouse')
  set mouse=a
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

" Only do this part when compiled with support for autocommands.
if has("autocmd")

  " Enable file type detection.
  " Use the default filetype settings, so that mail gets 'tw' set to 72,
  " 'cindent' is on in C files, etc.
  " Also load indent files, to automatically do language-dependent indenting.
  filetype plugin indent on

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd FileType text setlocal textwidth=78

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  autocmd BufReadPost *
    \ if line("'\"") >= 1 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

  augroup END

else

  set autoindent		" always set autoindenting on

endif " has("autocmd")

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
" Only define it when not defined already.
if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r ++edit # | 0d_ | diffthis
		  \ | wincmd p | diffthis
endif

if has('langmap') && exists('+langnoremap')
  " Prevent that the langmap option applies to characters that result from a
  " mapping.  If unset (default), this may break plugins (but it's backward
  " compatible).
  set langnoremap
endif
