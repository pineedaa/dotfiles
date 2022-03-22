syntax on
set encoding=utf-8
set number
set relativenumber
set showcmd
set showmatch
let mapleader="\<space>"

" tamaño tabulaciones
set tabstop=4     " size of a hard tabstop (ts).
set shiftwidth=4  " size of an indentation (sw).
set expandtab     " always uses spaces instead of tab characters (et).
set softtabstop=0 " number of spaces a <tab> counts for. when 0, featuer is off (sts).
set autoindent    " copy indent from current line when starting a new line.
set smarttab      " inserts blanks on a <tab> key (as per sw, ts and sts).

" atajos de teclado
nmap <leader>fq :q!<cr>
nmap <leader>qq :wq<cr>
nmap <leader>w :w<cr>
inoremap <silent>II <esc>
nmap <leader>tt :colorscheme <c-d>
nmap <leader>nn :NERDTreeToggle<cr>

" navegar entre buffers
map <silent>JJ :bnext<CR>
map <silent>KK :bprev<CR>

" navegar entre las ventanas
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l

" dividir pantalla
nmap <leader>v :vsplit<cr>
nmap <leader>h :split<cr>


" vim coc
inoremap <silent><expr> <tab>
      \ pumvisible() ? "\<c-n>" :
      \ <sid>check_back_space() ? "\<tab>" :
      \ coc#refresh()
inoremap <expr><s-tab> pumvisible() ? "\<c-p>" : "\<c-h>"

function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" remap para renombrar la palabra actual
nmap <leader>rn <plug>(coc-rename)


" nerdtree config
nnoremap <leader>n :nerdtreetoggle<cr>
let NERDTreeQuitOpen=1


" air-line
let g:airline_powerline_fonts = 1
let g:airline_theme='everforest' " tema de airline
let g:airline#extensions#tabline#enabled = 1 " barra superior con los buffers abiertos

if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif

" caracteres unicode
let g:airline_left_sep = '»'
let g:airline_left_sep = '▶'
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

" caracteres airline
let g:airline_left_sep = ''
let g:airline_left_alt_sep = ''
let g:airline_right_sep = ''
let g:airline_right_alt_sep = ''
let g:airline_symbols.branch = ''
let g:airline_symbols.readonly = ''
let g:airline_symbols.linenr = ''


" plugins
call plug#begin('~/.vim/plugged')

Plug 'hdima/python-syntax'
Plug 'scrooloose/nerdtree'
Plug 'vim-jp/vim-cpp'
Plug 'morhetz/gruvbox'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'scrooloose/nerdcommenter'
Plug 'terryma/vim-multiple-cursors'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'jiangmiao/auto-pairs'
Plug 'sainnhe/vim-color-forest-night'

call plug#end()

colorscheme everforest

" pip3 install flake8 for coding check
" sudo pacman -S ccls-git (ccls si falla) the code completion of C/C++
