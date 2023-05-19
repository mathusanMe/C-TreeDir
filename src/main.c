#include "main.h"

bool VERBOSE = false;
FILE *OUTPUT = NULL;

int main(int argc, char *argv[])
{
    bool tests = false;
    size_t optind;

    for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++)
    {
        switch (argv[optind][1])
        {
        case 'v':
            VERBOSE = true;
            break;
        case 't':
            tests = true;
            break;
        case 'o':
            if (optind + 1 >= argc || argv[optind + 1][0] == '-')
            {
                fprintf(stderr, "-o option requires an argument\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                OUTPUT = fopen(argv[++optind], "w+");

                if (OUTPUT == NULL)
                {
                    perror("Opening output file caused an error.");
                    printf("'%s' could not be opened.\n", argv[optind]);

                    exit(EXIT_FAILURE);
                }
            }
            break;
        default:
            fprintf(stderr, "Usage: %s [-vto] [file...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    argv += optind;

    if (OUTPUT == NULL)
    {
        OUTPUT = stdout;
    }

    if (tests)
    {
        exit(run_tests() ? EXIT_SUCCESS : EXIT_FAILURE);
    }

    if (argv == NULL)
    {
        fprintf(stderr, "Usage: %s [-vto] [file...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < argc - optind; i++)
    {
        parse_file(argv[i]);
    }

    int closed = fclose(OUTPUT);

    if (closed != 0)
    {
        perror("Closing output file caused an error.");
        printf("'%s' could not be closed.\n", argv[optind]);

        exit(EXIT_FAILURE);
    }
}