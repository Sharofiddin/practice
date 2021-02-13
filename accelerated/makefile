SHELL=/bin/sh
CXX = g++
CC = g++

SUBS = chapter00 chapter01 chapter02 chapter03 chapter04 \
	chapter05 chapter05/5-1 chapter05/5-2 chapter05/5-5 \
	chapter06 chapter07 chapter08\
	chapter09  chapter09/9-5 \
	chapter10 chapter10/10-1 chapter10/10-2 chapter10/10-4-5-6 \
	chapter11 chapter11/11-5 chapter11/7 chapter11/8 \
	chapter12 chapter13 chapter14 \
	chapter15 chapter16 

all:
	-for c in $(SUBS); do echo "=== $$c =="; (cd $$c; $(MAKE) "CXX=$(CXX)" "CC=$(CC)") done

test:
	-for c in $(SUBS); do echo "=== $$c =="; (cd $$c; $(MAKE) "CXX=$(CXX)" "CC=$(CC)" test); done

clobber:
	-for c in $(SUBS); do echo "=== $$c =="; (cd $$c; $(MAKE) "CXX=$(CXX)" "CC=$(CC)" clobber);done
