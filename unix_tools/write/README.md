# write

Classic Unix `write(1)` utility.

This program allows one logged-in user to send messages to another user's
terminal.

## Source

Originally based on:
- OpenBSD usr.bin/write/write.c

## Notes

- Some Linux distributions no longer ship `write(1)`.
- This is a Linux-portable version for educational purposes.
- On Linux, receiving messages requires the terminal to be group-writable.
    - You can run `chmod g+w $(tty)` in the terminal to allow receiving messages.
    - Sending messages still works, but may warn if write permissions are off.

## Files

- `write.c` - Linux-portable version (**work in progress**)
- `write_bsd.c` - unmodified OpenBSD source
