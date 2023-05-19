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

                set_output(OUTPUT);
            }
            break;
        default:
            fprintf(stderr, "Usage: %s [-vto] [file...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    argv += optind;

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

    close_output();
}