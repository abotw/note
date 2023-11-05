---
date: 2023-09-27
---

# `Make`



``` makefile
CC = gcc

CFLAGS = -g -Wall -std=c17 -Og -Iinclude
LDFLAGS = -lm

hello: hello.o
	$(CC) $(CFLAGS) -o hello hello.o $(LDFLAGS)
	
hello.o: hello.c include/hello.h
	$(CC) -c hello.c -Iinclude
```

``` makefile
libm.a
LDFLAGS = -lm
```

``` makefile
CC = gcc

CFLAGS = -g -Wall -std=c17 -Og -Iinclude -Icslib/include
LDFLAGS = -Lcslib lSimpleCSLib

SRC = \
	src/piglating.c \
	src/tokenscanner.c
OBJ = $(SRC:.c=.0)

TARGET = piglating

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)
```

