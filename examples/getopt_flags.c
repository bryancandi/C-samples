/*
 * Example program demonstrating getopt() usage.
 *
 * Parses command-line options using getopt(). Exactly one option must be
 * specified, followed by a single non-option argument.
 *
 * Demonstrates option parsing, error handling, and use of optind.
 */

#include <getopt.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *prog = argv[0];

    /* Allowable argument options. */
    char *options = "abc";

    /* Optionally turn off getopt built in error reporting */
    opterr = 0;

    /* Check that provided option is valid. */
    char selection = 0;
    int selected = 0;
    int opt;
    while ((opt = getopt(argc, argv, options)) != -1)
    {
        switch (opt)
        {
        case 'a':
            selected++;
            selection = opt;
            break;
        case 'b':
            selected++;
            selection = opt;
            break;
        case 'c':
            selected++;
            selection = opt;
            break;
        default: /* '?' */
            fprintf(stderr, "%s: invalid option: -%c\n", prog, optopt);
            return 1;
        }
    }

    /* Ensure that only one option was selected. */
    if (selected != 1)
    {
        fprintf(stderr, "%s: one option must be selected.\n", prog);
        return 1;
    }

    /*
     * Ensure proper usage; in this case one option and one non-option arg following.
     * optind is the index in argv of the first argv-element that is not an option.
     */
    if (argc != optind + 1)
    {
        fprintf(stderr, "Usage: %s (-a | -b | -c) arg\n", prog);
        return 1;
    }

    /* All checks passed; print results. */
    printf("Option: %c\n", selection);
    printf("Arg: %s\n", argv[optind]);

    return 0;
}
