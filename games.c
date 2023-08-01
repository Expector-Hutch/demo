void snake(int W){int S=W*W,*m,z[2]={0},l=3,i,c='D',C,*p,f;for(srand(m=calloc(S,
4)),C=m[1]=-1;C-27;_sleep(99)){char*o;_cputs("\033[?25l\033[2J\033[H");if(_kbhit
())C=_getch()&95,C-65&&C-68&&C-83&&C-87||(C^c)&20^4&&(c=C);p=z+!!(c&2),*p+=c/3&2
,*p=(--*p+W)%W;f=1,*(p=m+*z+z[1]*W)>0&&(C=27);for(;*p&&(m[i=rand()%S]||(--m[i],
++l,--f)););for(i=0,*p=l;i<S;++i%W||_cputs("\033[47m \033[0m\n"))_cputs(m[i]>0?m
[i]-=f,"\033[41m  \033[0m" : m[i] ? "\033[42m  \033[0m" : "  ");}
_cputs("\033[2J\033[H\033[?25h");}

/*#define G(C)for(C,i=n[T];j=X+i%4,k=Y+i/4%4,k=k*W+j,i;i>>=4)
int W=10,H=25,S,i,j,k,c,d=1,X=0,Y=0,T=0,*m,n[]={51264,12816,21520,21520,25872,
34113,21537,38208,25921,38481,38484,38209,25922,43345,34388,38160,25920,38177,
42580,38993};M(int*v,int l){G(*v+=l)j+1&&j-W&&k<S&&!m[k]||(c=0);return c||(*v-=l
,v-&Y||(c=-1));}tetris(){for(srand(m=calloc(S=W*H,4));c-27;_sleep(50),_cputs(
"\033[?25l\033[2J\033[H")){G(c=kbhit()?getch()&95:1)m[k]=0;c^65&&c^68||M(&X,c&1?
-1:1),c^83||M(&Y,1);c^87||(i=T<8?1:3,M(&T,T&i^i?1:-i));G(++d-9||M(&Y,d=c=1))m[k]
=1;for(;i<S;++i%W||puts("\033[47m \033[0m"))printf(m[i]?"\033[42m  \033[0m":"  "
);if(c==-1)for(j=Y||(c=27),T=rand()%20,Y=X=0,i=S;i;i--%W||(j=W),j-=m[i])if(!j)
for(k=i+=W;--k-W;m[k]=m[k-W]);}_cputs("\033[?25h");}*/

int W = 13, S, *m, z = 0, c = 1, r = 2, M = 0, i, j, k, *p;
int *sum(int *v, int l) { return *v - v[l] ? v + l : sum(v + l, l); }
void down(int v) {
	for (m[v] = r ^= 3, i = 2; j = i % 3 - 1 + (i / 3) * W, i < 6; ++i) {
		p = sum(m + v, j), k = (p - sum(m + v, -j)) / j;
		*p || (p[S * r] += 1 << k), p -= k * j, *p || (p[S * r] += 1 << k);
		m[v + S] = m[v + S * 2] = 0, k > 5 && (r ^= 3, r += 4, i = 8);
	}
}
void ai() {
	for (j = k = 0, i = S; i < S * 3 || (k = rand() % k, k || ++k, 0);)
		j == m[i] && ++k, j < m[i] && (j = m[i], k = 1), ++i;
	for (i = S; k && i < 3 * S || (down(i % S), 0);)m[++i] == j && --k;
}
void five() {
	for (W += 2, S = W * W, m = calloc(i = S * 3, 4), srand((int)m); i--;)
		i % W && -~i % W && !(i % S < W || (i + W) % S < W) || (m[i] = -1);
	for (z = S / 2; r < 4 && c - 27 && !system("cls"); c = _getch() & 95) {
		c - 87 || m[z - W] + 1 && (z -= W), c - 68 || m[++z] + 1 || --z;
		c - 83 || m[z + W] + 1 && (z += W), c - 65 || m[--z] + 1 || ++z;
		if (!c)M - 2 ? !m[z] && (down(z), r < 4 && M && (ai(), 0)) : ai();
		for (i = W; i < S - W; ++i % W || (_cprintf("%d\n", i / W - 1)))
			m[i] + 1 && _cprintf("%c%c", " >"[i == z], " 0@"[m[i]]);
		for (i = 1, c - 81 || ++M; ++i < W;)_cprintf(" %c", 95 + i);
		M %= 3, _cprintf("\n%s|", "PvP\0PvE\0EvE" + M * 4);
		_cputs(r & 1 ? "White" : "Black"), r < 4 || _cputs(" win!");
	}
}

int W = 15, S, c = 81, i, j, k, *m, *L, l[4] = {1, -1};
void init(){
	for (i = S; i-- || (c = m[i = rand() % S] == 2, k = 0);)
		m[i] = 2 + ((i + 1) % W < 2) + (i % (S - W) < W);
	for (c && (L[k++] = i); k && (j = L[i = rand() % k], 1);)
		for (L[i] = L[--k], i = m[j] & 3 ? m[j] = 0 : 4; i < 4; ++i)
			c = j + l[i], m[c] & 3 && ++m[c], m[c] & 3 && (L[k++] = c);
	for (i = c ? W : S; i >= S ? init(), 0 : m[i - W]; i += W)
		m[i] & 3 | m[S - 1 - i] & 3 || (m[j = i] = m[k = S - 1 - i] = 0);
}
int main(){
	srand(m = calloc(S = W * W, 4)), L = calloc(S, 4), l[2] -= l[3] = W;
	for (; c - 81 && j - k ? 0 : init(), c - 27; c = _getch() & 95){
		c - 87 || m[j - W] || (j -= W), c - 68 || m[j + 1] || ++j;
		c - 83 || m[j + W] || (j += W), c - 65 || m[j - 1] || --j;
		for (i = system("cls"); i < S; ++i % W || _cputs("\n"))
			_cputs(i - j ? m[i] ? "[]" : "  " : "<>");
	}
}

int m[36] = { 0 }, s = 0, can = 0, air = 16, c = 0, i = 6, j, *p;
void move(int *q, int v) {
	if (*q < 1 ? 0 : q[v] || (q[v] = *q, move(q + v, v), *q = can = 0))
		q[v] - *q || (q[v] = ~*q, s += 1 << *q, *q = can = 0, ++air);
}
void index(int b, int v) { b - j && ((move(m + b, v), index(b + i, v), 0)); }
int main() {
	for (p = malloc(1); i--;)m[i] = m[35 - i] = m[i * 6] = m[35 - i * 6] = -1;
	for (srand(p), free(p); (air || can) && c - 27; c = _getch() & 95) {
		c - 'A' && c - 'W' || (j = 30, i = 1, index(6, c - 'A' ? -6 : -1), 0);
		c - 'D' && c - 'S' || (j = 6, i = -1, index(30, c - 'D' ? 6 : 1), 0);
		if (!air || can || (--air, (system("cls"))))continue;
		while (m[i = rand() % 30] || (m[i] = rand() % 5 ? 1 : 2, 0));
		for (p = m + 30; --p - m - 6; *p < -1 && (*p = -*p));
		for (; ++p - m - 31; *p + 1 && _cprintf("%5d|", *p ? 1 << *p : 0))
			*p + 1 && (*p ^ p[1] && *p ^ p[6] || ++can),
			(p - m) % 6 || _cputs("\n----- ----- ----- -----\n");
		air || can || _cputs("Game over!"), _cprintf("score:%d", s);
	}
	//for (_cputs("\n### Press space to exit ###\n"); _getch() - ' ';);
}

int S, W = 9, H = 9, B = 10, s, p = 0, c = 1, i, *m, *M, (*f)(int, int);
int edge(int x, int y) { return !(-~x % -~W && -~y % -~H); }
void tmp(int x, int y) { edge(x, y) || m[x += W * y] - 9 && ++m[x]; }
void dig(int v, int l) {
    for (l = edge(v, l) || M[v += W * l] || (++M[v], --s, m[v]) ? 0 : 9; l;)
        --l - 4 || --l, f(v % W + l % 3 - 1, v / W + l / 3 - 1);
}
void set(int x, int y) {
    for (f = tmp, srand(m); c < B || (f = dig, f(x, y), s += B, 0);)
        if (m[i = rand() % S] < 9 && 1 < (abs(x - i % W) | abs(y - i / W)))
            m[i] = 0, dig(i % W, i / W), m[i] = 9, --M[i], ++c;
}
int main() {
    f = set, s = S = W * H, m = calloc(S * 2, 4), M = m + S;
    for (; c - 27 && !system("cls"); c = B % s ? _getch() & 95 : 27) {
        c - 68 || ++p, c - 65 || --p, c - 83 || (p += W), c - 87 || (p -= W);
        p = (p + S) % S, c || (f(p % W, p / W), m[p] < 9 || (B = 0));
        for (i = 0; B || m[i] - 9 || ++M[i], i < S; ++i % W || _cputs("\n"))
            _cprintf("%c%c", " >"[p == i], " 12345678@*"[M[i] ? m[i] : 10]);
    }
    _cputs(B - s ? "Game over!" : "You win!"), _getch();
}

int main(){five();}

// https://www.myness.cn/2022/07/26/%e8%ae%a9%e4%bd%a0%e7%9a%84cli%e7%a8%8b%e5%ba%8f%e5%9c%a8windows%e8%87%aa%e5%b8%a6%e7%bb%88%e7%ab%af%e4%b8%8a%e4%bd%bf%e7%94%a8ansi%e6%8e%a7%e5%88%b6%e7%ac%a6/

system("REG ADD HKCU\\CONSOLE /f /v VirtualTerminalLevel /t REG_DWORD /d 1 > NULL && del NULL");