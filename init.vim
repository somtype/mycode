"插件
call plug#begin('~/.config/nvim/plugged')
Plug 'lifepillar/vim-solarized8'
Plug 'mhinz/vim-startify'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'preservim/nerdtree'
Plug 'kien/ctrlp.vim'
Plug 'easymotion/vim-easymotion'
Plug 'tpope/vim-surround'
call plug#end()

"设置主题
set background=dark
colorscheme solarized8
"日常使用
set number
set tabstop=4
set softtabstop=4
set shiftwidth=4
"映射
let mapleader=','
inoremap jj <Esc>`^
nnoremap <C-h> <C-w><C-h>
nnoremap <C-j> <C-w><C-j>
nnoremap <C-k> <C-w><C-k>
nnoremap <C-l> <C-w><C-l>
inoremap ' ''<Esc>i
inoremap " ""<Esc>i
inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap { {<Cr>}<Esc>O
nmap ss <Plug>(easymotion-s2)

nnoremap <C-n> :NERDTreeToggle<CR>
nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <leader>f :NERDTreeFind<CR>

let g:ctrlp_map = '<c-p>'
