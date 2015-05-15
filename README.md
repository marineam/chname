# chname

Run command or interactive shell with a new system hostname

## SYNOPSIS

    chname hostname [command ...]

## DESCRIPTION

Create a new utsname namespace with a new system hostname
and execute `command`. This is particularly useful for creating
a chroot that has a hostname independent of the rest of the system.

This capability requires Linux 2.6.19 or later with `CONFIG_UTS_NS=y`.

## EXAMPLE

    chname newname chroot /chroot/dir /bin/bash

## AUTHOR

Written by Michael Marineau.

https://github.com/marineam/chname
