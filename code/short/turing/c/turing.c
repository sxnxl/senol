#define W for(rewind(F);fscanf(F,"%d %d %d %d %c",&s,&r,&n,&p,&h)>0;)
#include<stdlib.h>/* Copying and distribution of this file, with   */
#include<stdio.h> /* or without modification, are permitted in any */
#define C(N,S) N  /* medium provided this notice is preserved.     */\
=calloc(S,sizeof(Q));for(j=0;j<S;){N[j].p[0]=N[j].p[1]=0;N[j++].d=0;}
typedef struct q{struct q*p[2];int d;}Q;int main(int i,char**v){int s,
r,n,p,h,j;FILE*F=fopen(v[1],"r"),*G=fopen(v[2],"r");Q*M,*m,*T,*C(t,1)T
=t;i=0;W i=i>s?i:s;C(M,i)W{M[s].p[r]=h=='H'?0:M+n;M[s].d+=(2*(h=='R')+
p)<<(2*r);}while((h=fgetc(G))=='1'||h=='0'){if(!(t->p[1])){C(t->p[1],1
)t->p[1]->p[0]=t;}t->d=(h=='1');t=t->p[1];}t=T;m=M;for(;m!=0;){r=t->d;
h=((m->d)>>(r*2+1))&1;t->d=((m->d)>>(r*2))&1;if(!(t->p[h])){C(t->p[h],
1)t->p[h]->p[!h]=t;}t=t->p[h];m=m->p[r];}t=T;while(t){printf("%d",t->d
);t=t->p[1];}return 0;}/* © 2010 John Doe & Sarı Çizmeli Mehmet Ağa */
