#  Makefile - Makefile for test programs
#
#  Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>
#
#  This file is part of flibc.
#
#  flibc is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  flibc is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with flibc.  If not, see <http://www.gnu.org/licenses/>.

CXX = gcc

CXXFLAGS = -Wall

INCLUDE_DIR = ../../include

SRC_DIR = ../

CXXFLAGS += -I $(INCLUDE_DIR)

binDir = test_bin/
prefixStd = std
prefixFlibc = f

all: tests

tests: prep std_strlen f_strlen std_memchr  f_memchr  std_strchr  f_strchr \
                                std_memrchr f_memrchr std_strrchr f_strrchr

std_strlen:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixStd)libc/tst-strlen tst-strlen.c

f_strlen:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixFlibc)libc/tst-strlen \
		tst-strlen.c $(SRC_DIR)strlen.c

std_memchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixStd)libc/tst-memchr tst-memchr.c

f_memchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixFlibc)libc/tst-memchr \
		tst-memchr.c $(SRC_DIR)memchr.c

std_strchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixStd)libc/tst-strchr tst-strchr.c

f_strchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixFlibc)libc/tst-strchr \
		tst-strchr.c $(SRC_DIR)strchr.c

std_memrchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixStd)libc/tst-memrchr tst-memrchr.c \
		-D_GNU_SOURCE
		# memrchr function is a gnu extension so define _GNU_SOURCE

f_memrchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixFlibc)libc/tst-memrchr \
		tst-memrchr.c $(SRC_DIR)memrchr.c

std_strrchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixStd)libc/tst-strrchr tst-strrchr.c

f_strrchr:
		$(CXX) $(CXXFLAGS) -o $(binDir)$(prefixFlibc)libc/tst-strrchr \
		tst-strrchr.c $(SRC_DIR)strrchr.c

prep:
		mkdir -p $(binDir) $(binDir)$(prefixStd)libc/ $(binDir)$(prefixFlibc)libc/
remove:
		rm -rf $(binDir)
