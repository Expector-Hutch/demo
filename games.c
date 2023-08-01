void snake(int W){int S=W*W,*m,z[2]={0},l=3,i,c='D',C,*p,f;for(srand(m=calloc(S,
4)),C=m[1]=-1;C-27;_sleep(100)){_cputs("\033[?25l\033[2J\033[H");if(_kbhit())C=
_getch()&95,C-65&&C-68&&C-83&&C-87||(C^c)&20^4&&(c=C);p=z+!!(c&2),*p+=c/3&2,*p=(
--*p+W)%W;f=1,*(p=m+*z+z[1]*W)>0&&(C=27);for(;*p&&(m[i=rand()%S]||(--m[i],++l,--
f)););for(i=0,*p=l;i<S;++i%W||_cputs("\033[47m \033[0m\n"))_cputs(m[i]>0?m[i]-=f
,"\033[41m  \033[0m" : m[i] ? "\033[42m  \033[0m" : "  ");}_cputs("\033[?25h");}

#define G(C)for(C,i=n[T];j=X+i%4,k=Y+i/4%4,k=k*W+j,i;i>>=4)
int W=10,H=25,S,i,j,k,c,d=1,X=0,Y=0,T=0,*m,n[]={51264,12816,21520,21520,25872,
34113,21537,38208,25921,38481,38484,38209,25922,43345,34388,38160,25920,38177,
42580,38993};M(int*v,int l){G(*v+=l)j+1&&j-W&&k<S&&!m[k]||(c=0);return c||(*v-=l
,v-&Y||(c=-1));}tetris(){for(srand(m=calloc(S=W*H,4));c-27;_sleep(50),_cputs(
"\033[?25l\033[2J\033[H")){G(c=kbhit()?getch()&95:1)m[k]=0;c^65&&c^68||M(&X,c&1?
-1:1),c^83||M(&Y,1);c^87||(i=T<8?1:3,M(&T,T&i^i?1:-i));G(++d-9||M(&Y,d=c=1))m[k]
=1;for(;i<S;++i%W||puts("\033[47m \033[0m"))printf(m[i]?"\033[42m  \033[0m":"  "
);if(c==-1)for(j=Y||(c=27),T=rand()%20,Y=X=0,i=S;i;i--%W||(j=W),j-=m[i])if(!j)
for(k=i+=W;--k-W;m[k]=m[k-W]);}_cputs("\033[?25h");}


int main(){tetris(20);}