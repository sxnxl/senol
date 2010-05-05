#!/usr/bin/env python

import os

tests = ["strlen"]
outNull = " 1>/dev/null"
errNull = " 2>/dev/null"
allNull = outNull + errNull

os.system("rm -rf ./test_out/" + allNull);
os.system("make remove" + allNull);
buildCheck = os.system("make tests" + allNull);
os.system("mkdir -p test_out/" + allNull);
os.system("mkdir -p test_out/std/" + allNull);
os.system("mkdir -p test_out/flibc/" + allNull);

for t in tests:
	os.system("./bin/std/tst-" + t + " 1>./test_out/std/tst-" + t + "_out.txt" + errNull)

	os.system("./bin/flibc/tst-" + t + " 1>./test_out/flibc/tst-" + t + "_out.txt" + errNull)

	check = os.system("diff ./test_out/std/ ./test_out/flibc/ > /dev/null");

	if buildCheck != 0:
	  print "Error: Build Error!"
	elif check != 0:
	  print "Error: Some tests were failed !"
	  # TODO: show a list of failed functions and arguments
	  os.system("diff -q ./test_out/std/ ./test_out/flibc/");
	else:
	  print "Success: All tests passed successfully!"


