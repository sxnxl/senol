#include<stdio.h>/*©Şenol Korkmaz*/
#define W for(rewind(M);fscanf(M,"\
%d %d %d %d %c",&s,&r,&n,&p,&h)>0;)
#include<stdlib.h>/*License:WTFPL*/
typedef struct q{struct q*p[2];int 
d[2];}Q;main(int i,char**v){Q*m,*t
;FILE*M=fopen("a","r"),*T=fopen("b"
,"r");int s,r,n,p,h;i=0;W i=i>s
?i:s;m=calloc(i,sizeof(Q));W{m[s].
p[r]=h=='H'?0:m+n;m[s].d[r]=2*(h==
'R')+p;}t=malloc(sizeof(Q));
*t = {{0,0},{0,0}};
/*t->p[0] =NULL;
t->p[1] =NULL;
t->d[0]=0;*/
Q*u=t;
while((h=getc(T))>0)
{
    printf("a\n");fflush(stdout);
    if (t->p[0] == NULL){
    printf("b\n");fflush(stdout);
        t->p[0]=malloc(sizeof(Q));
        (*(t->p[0])).p[0]=NULL;
        (*(t->p[0])).p[1]=t->p[0];
    }
    if (t->p[1] == NULL){
    printf("c\n");fflush(stdout);
        t->p[1]=malloc(sizeof(Q));
        (*(t->p[1])).p[1]=NULL;
        (*(t->p[1])).p[0]=t->p[1];}
    if(h=='1') {
    printf("d\n");fflush(stdout);
        t->d[0]=1;
        t=t->p[1];}
    if(h=='0'){
    printf("e\n");fflush(stdout);
        t->d[0]=0;
        t=t->p[1];}
}

while (u->p[1] != NULL)
{
    printf("%d",u->d[0]);
        u=u->p[0];
}
}
    //W{m[s].p[r]=&(m[n]);m[s].d[r]=4*(h=='H')+2*(h=='R')+p;}
    //m[s].d[r]=p+(h=='H'?6:2*(h=='R'));
