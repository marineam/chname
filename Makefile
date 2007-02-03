CFLAGS:=-Wall

all: chname

chname: chname.c
	$(CC) $(CFLAGS) -o chname chname.c

clean:
	$(RM) chname
