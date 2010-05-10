#!/usr/bin/env python
# -*- coding: utf-8 -*-

#  test.py - Runs test programs
#
#  Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>
#  Copyright © 2010 Sarı Çizmeli Mehmet Ağa (aka. John Doe) <scma@senolkorkmaz.info>
#
#  This file is part of flibc.
#
#  flibc is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  flibc is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with flibc.  If not, see <http://www.gnu.org/licenses/>.

# TODO: use subprocess module instead of os.system

import os
import sys

cmdRun = os.system

tests = ["strlen","strchr","strrchr","memchr","memrchr"]

prefixStd = "std"
prefixFlibc = "f"

buildCheck = dict()
runCheck  = dict()
testCheck  = dict()

outDir = "./test_out/"
binDir = "./test_bin/"
logDir = "./test_log/"

stdDir = prefixStd + "libc/"
flibcDir = prefixFlibc + "libc/"

outNull = " 1>/dev/null"
errNull = " 2>/dev/null"
allNull = outNull + errNull

def die(msg):
    print ("Fatal: " + msg)
    sys.exit(1)

def err(msg):
    print ("Error: " + msg)

def warn(msg):
    print ("Warning: " + msg)

def info(msg):
    print ("Info: " + msg)

def prnt(msg):
    print(msg),
    sys.stdout.flush()

def prntnl(msg):
    print(msg)
    sys.stdout.flush()


#remove previous test outputs and builds
cmdRun("rm -rf "+ binDir + allNull);
cmdRun("rm -rf "+ outDir + allNull);
cmdRun("rm -rf "+ logDir + allNull);
cmdRun("make remove" + allNull);

# create test directories
cmdRun("mkdir -p " + outDir + allNull);
cmdRun("mkdir -p " + outDir + stdDir + allNull);
cmdRun("mkdir -p " + outDir + flibcDir + allNull);
cmdRun("mkdir -p " + binDir + stdDir + allNull);
cmdRun("mkdir -p " + binDir + flibcDir + allNull);
cmdRun("mkdir -p " + logDir + stdDir + allNull);
cmdRun("mkdir -p " + logDir + flibcDir + allNull);



for test in tests:
    # build and test executable
    prnt ("Testing : " + test + " ...\t"),

    buildCheck[test] = cmdRun ("make "+ prefixStd +"_"+ test + allNull)
    buildCheck[test] &= cmdRun ("make " + prefixFlibc +"_"+ test + allNull)

    if buildCheck[test] == 0:
        runCheck[test] = cmdRun(binDir + stdDir + "tst-" + test + " 1>" + outDir + stdDir + test + ".txt" + " 2>" + logDir + stdDir + test + ".log")
        runCheck[test] &= cmdRun(binDir + flibcDir + "tst-" + test + " 1>" + outDir + flibcDir + test + ".txt" + " 2>" + logDir + flibcDir + test + ".log")
	if runCheck[test] == 0:
	    testCheck[test] = cmdRun("diff " + outDir + stdDir +" "+ outDir + flibcDir + allNull);
    	    if testCheck[test] == 0:
                prntnl ("OK.")
	    else:
	    	prntnl ("Failed!")
	else:
	    err ("Run Failed!")
    else:
        err ("Build Failed!")

# $Id$
