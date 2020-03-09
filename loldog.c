#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define MAXLEN      10000
#define MAXFILE     20

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
            "\t-nb/NB/nobold:  Disable default bolding\n", 1,MODE(0),1,MODE(0),1,MODE(0),1,MODE(0),1,MODE(0),1,MODE(0),1,MODE(0));

    printf( "\x1b[%d;38;5;%dm"
            "-Only choose one out of the following:\n"
            "\x1b[%d;38;5;%dm"
            "\t-default:       changing color randomly\n"
            "\x1b[%d;38;5;%dm"
            "\t-g/G/gradual:   changing color gradually\n"
            "\x1b[%d;38;5;%dm"
            "\t-r/R/rainbow:   changing color with rainbow pattern\n\n"
            "\x1b[%d;38;5;%dm"
            "-END\n", 1, MODE(0),1,MODE(0),1,MODE(0),1,MODE(0),1,MODE(0)); 
}


main(int argc, char **argv)
{
    unsigned bold = 1, color_mode= 0, line = 0, word = 0, letter = 0, i;
    char input[MAXLEN];
    char *token = (char *)malloc(sizeof(*token)*MAXLEN), *letterptr;
    FILE *file[MAXFILE];
    int fileidx = 0, filectn = 0;
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
            color_mode = 1;
        else if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "-R") || !strcmp(argv[i], "-rainbow"))
            color_mode = 2;
        else {
            file[filectn] = fopen(argv[i], "r");
            if (file[filectn] == NULL) {
                printf("file: %s cannot be opened...\n", argv[i]);
                exit(EXIT_FAILURE);
            } else {
                printf("file: %s added\n", argv[i]);
                ++filectn;
            }
        }

    }
    if((line+word+letter) > 1) {
        info();
        exit(EXIT_FAILURE);
    } else
        line = 1;

    if (filectn == 0)
        file[filectn++] = stdin;
    
    while (fileidx < filectn) {
        while (fgets(input, MAXLEN, file[fileidx])) {
            strtok(input, "\n");
            if (line) {
                printf("\x1b[%d;38;5;%dm%s", bold, MODE(color_mode), input);
                printf(ANSI_UNSET"\n");
            } else if (word) {
                token = strtok(input, " ");
                do {
                    printf("\x1b[%d;38;5;%dm%s", bold, MODE(color_mode), token);
                    printf(ANSI_UNSET" ");
                } while (token = strtok(NULL, " \n"));
                printf(ANSI_UNSET"\n");
            } else {
                letterptr = input;
                while (*letterptr != '\0')
                    printf("\x1b[%d;38;5;%dm%c", bold, MODE(color_mode), *letterptr++);
                printf(ANSI_UNSET"\n");
            }
        }
        ++fileidx;
    }
   return 0;
}
