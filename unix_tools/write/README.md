# write

Classic Unix `write(1)` utility.

This program allows one logged-in user to send messages to another user's
terminal.

## Source

Originally based on:
- OpenBSD usr.bin/write/write.c

## Notes

- Some Linux distributions no longer ship `write(1)`
- This is a Linux-portable version for educational purposes

## Files

- `write.c` - Linux-portable version (**work in progress**)
- `write_bsd.c` - unmodified OpenBSD source
