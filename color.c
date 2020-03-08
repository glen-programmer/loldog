#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define MAXLEN      10000

#define MODE(x)     x == 0 ?  (17+(rand() % 239)) : \
                    x == 1 ?  (17+(mode_idx++ % 215)) : \
                    (rainbow_arr[rainbow_idx++ % rainbow_size])

#define ANSI_UNSET              "\x1b[0m"

static unsigned mode_idx = 0;
static unsigned rainbow_idx = 0;
static unsigned rainbow_arr[] = {53,54,55,17,18,19,20,21,26,27,32,33,38,39,44,45,51,87,22,28,34,35,36,40,41,46,47,48,49,202,208,214,220,221,222,228,229,196,88,124,160,161,162,197,198};
static unsigned rainbow_size = sizeof(rainbow_arr) / sizeof(unsigned);

void info()
{
    printf( "\x1b[%d;38;5;%dm"
            "loldog:\n\n" 
            "\x1b[%d;38;5;%dm"
            "-h/H/HELP:  help menu\n"
            "\x1b[%d;38;5;%dm"
            "-Only choose one out of the following:\n"
            "\x1b[%d;38;5;%dm"
            "\t-l/L/line:      changing color line-accordingly\n"
            "\x1b[%d;38;5;%dm"
            "\t-w/W/word:      changing color word-accordingly\n"
            "\x1b[%d;38;5;%dm"
            "\t-d/D/letter:    changing color letter-accordingly\n"
            "\x1b[%d;38;5;%dm"
            "\t-nb/NB/nobold:  Disable default bolding\n", 1,MODE(2),1,MODE(2),1,MODE(2),1,MODE(2),1,MODE(2),1,MODE(2),1,MODE(2));

    printf( "\x1b[%d;38;5;%dm"
            "-Only choose one out of the following:\n"
            "\x1b[%d;38;5;%dm"
            "\t-default:       changing color randomly\n"
            "\x1b[%d;38;5;%dm"
            "\t-g/G/gradual:   changing color gradually\n"
            "\x1b[%d;38;5;%dm"
            "\t-r/R/rainbow:   changing color with rainbow pattern\n\n"
            "\x1b[%d;38;5;%dm"
            "-END\n", 1, MODE(2),1,MODE(2),1,MODE(2),1,MODE(2),1,MODE(2)); 
}


main(int argc, char **argv)
{
    unsigned bold = 1, mode = 0, line = 0, word = 0, letter = 0, i;
    char *input = malloc(sizeof(*input) * MAXLEN), *token = malloc(sizeof(*input)), *ptr;
    FILE *file = stdin;
    srand(time(NULL));
    
    for (i = 1; i < argc; ++i)
        printf("%s\n", argv[i]);

    for (i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "-H") || !strcmp(argv[i], "-help")) {
            info();
            exit(EXIT_SUCCESS);
        }
        else if (!strcmp(argv[i], "-l") || !strcmp(argv[i], "-L") || !strcmp(argv[i], "-line"))
            line = 1;
        else if (!strcmp(argv[i], "-w") || !strcmp(argv[i], "-W") || !strcmp(argv[i], "-word"))
            word = 1;
        else if (!strcmp(argv[i], "-d") || !strcmp(argv[i], "-D") || !strcmp(argv[i], "-letter"))
            letter = 1;
        else if (!strcmp(argv[i], "-nb") || !strcmp(argv[i], "-NB") || !strcmp(argv[i], "-nobold"))
            bold = 0;
        else if (!strcmp(argv[i], "-g") || !strcmp(argv[i], "-G") || !strcmp(argv[i], "-gradual"))
            mode = 1;
        else if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "-R") || !strcmp(argv[i], "-rainbow"))
            mode = 2;
        else {
            file = fopen(argv[i], "r");
            if (!file) {
                printf("file: %s cannot be opened...\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }

    }
    assert((line+word+letter) == 1);

    if (argc == -1){}
        /*file();*/
    else {
        while (fgets(input, MAXLEN, file)) {
            strtok(input, "\n");
            if (line) {
                printf("\x1b[%d;38;5;%dm%s", bold, MODE(mode), input);
                printf(ANSI_UNSET"\n");
            } else if (word) {
                token = strtok(input, " ");
                do {
                    printf("\x1b[%d;38;5;%dm%s", bold, MODE(mode), token);
                    printf(ANSI_UNSET" ");
                } while (token = strtok(NULL, " \n"));
                printf(ANSI_UNSET"\n");
            } else {
                ptr = input;
                while (*ptr != '\0')
                    printf("\x1b[%d;38;5;%dm%c", bold, MODE(mode), *ptr++);
                printf(ANSI_UNSET"\n");
            }
        }
    }
   return 0;
}
