#include<stdio.h>/*mail @senolkorkmaz.info*/
#include <stdlib.h>/* © 2010 Şenol Korkmaz*/
#define W for(rewind(F);/*License:GNU LGPL*/\
fscanf(F,"%d %d %d %d %c",&s,&r,&n,&p,&h)>0;)
#define R(B) if(!(t->p[B])){t->p[B]=malloc( \
sizeof(Q));t->p[B]->p[B]=0;t->p[B]->p[!B]=t;}
typedef struct q{struct q*p[2];int di[2];}Q;main(
int i,char**v){Q*m,*T,*t=malloc(sizeof(Q));
FILE*F=fopen(*++v,"r"),*G=fopen(*++v,"r");
int s,r,n,p,h;T=t;i=0;W i=i>s?i:s;m=calloc(i,
sizeof(Q));W{m[s].p[r]=h=='H'?0:m+n;m[s].d[r]
=2*(h=='R')+p;};T->p[0]=T->p[1]=0;while((h=
getc(G))=='1'||h=='0'){R(1)t->d[0]=(h=='1');t
=t->p[1];}}
