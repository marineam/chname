CFLAGS += -Wall

all: chname

chname: chname.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o chname chname.c

clean:
	$(RM) chname

DESTDIR ?=
install: chname
	mkdir -p $(DESTDIR)/usr/bin $(DESTDIR)/usr/share/man/man1
	install -m755 chname $(DESTDIR)/usr/bin/chname
	install -m644 chname.1 $(DESTDIR)/usr/share/man/man1/chname.1

.PHONY: all clean install
