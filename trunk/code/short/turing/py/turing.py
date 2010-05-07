#!/usr/bin/env python
# -*- coding: utf-8 -*-

#  Simple obfuscated code turing machine simulator

#  Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>
#  Copyright © 2010 Sarı Çizmeli Mehmet Ağa (aka. John Doe) <scma@senolkorkmaz.info>

#  Copying and distribution of this file, with or without modification,
#  are permitted in any medium without royalty provided the copyright
#  notices and this notice are preserved.

import sys
f=map(open,sys.argv[1:3])
m=dict((x[0]+x[1],x[2:])for x in map(str.split,list(f[0])))
t=filter(str.isalnum,list(f[1].read()))
h,s,a,d=0,m["0"+t[0]],t[0],{'R':1,'L':-1,'H':1}
while 1:
    t[h],h=s[1],h+d[s[2]]
    if h==len(t):t.append(a)
    elif h<0:
        t.insert(a)
        h=0
    if s[2]=="H":break
    s=m[s[0]+t[h]]
print "".join(t)
