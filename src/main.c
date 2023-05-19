#include "main.h"

int main(int argc, char *argv[])
{
    bool verbose = false;
    bool output_set = false;
    FILE *output;
    bool tests = false;
    size_t optind;

    for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++)
    {
        switch (argv[optind][1])
        {
        case 'v':
            verbose = true;
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
                output = fopen(argv[++optind], "w+");

                if (output == NULL)
                {
                    perror("Opening output file caused an error.");
                    fprintf(stderr, "'%s' could not be opened.\n", argv[optind]);

                    exit(EXIT_FAILURE);
                }

                output_set = true;
            }
            break;
        default:
            fprintf(stderr, "Usage: %s [-vto] [file...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    argv += optind;

    if (!output_set)
    {
        output = stdout;
    }

    if (tests)
    {
        exit(run_tests(output, verbose) ? EXIT_SUCCESS : EXIT_FAILURE);
    }

    if (argv == NULL)
    {
        fprintf(stderr, "Usage: %s [-vto] [file...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < argc - optind; i++)
    {
        parse_file(argv[i], output, verbose);
    }

    int closed = fclose(output);

    if (closed != 0)
    {
        perror("Closing output file caused an error.");
        fprintf(stderr, "'%s' could not be closed.\n", argv[optind]);

        exit(EXIT_FAILURE);
    }

    free(output);

    exit(EXIT_SUCCESS);
}