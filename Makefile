CFLAGS += -Wall

all: chname

chname: chname.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o chname chname.c

clean:
	$(RM) chname
