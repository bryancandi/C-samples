/* syscalls_ex.h */

#define NULL        0
#define EOF         (-1)
#define BUFSIZ      1024
#define OPEN_MAX    20  /* max files open at once */

typedef struct _iobuf {
    int cnt;            /* characters left */
    char *ptr;          /* next character position */
    char *base;         /* location of buffer */
    unsigned read  : 1; /* file open for reading */
    unsigned write : 1; /* file open for writing */
    unsigned unbuf : 1; /* file is unbuffered */
    unsigned eof   : 1; /* EOF has occurred */
    unsigned err   : 1; /* error has occurred */
    int fd;             /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

enum _flags {
    _READ   = 01,       /* file open for reading */
    _WRITE  = 02,       /* file open for writing */
    _UNBUF  = 04,       /* file is unbuffered */
    _EOF    = 010,      /* EOF has occurred on this file */
    _ERR    = 020       /* error has occurred on this file */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 \
                ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p)   (--(p)->cnt >= 0 \
                ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)
