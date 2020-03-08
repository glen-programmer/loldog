/* ANSI_COLOR_8_Bits
 * reference-only, not used in the actual code
 */

#define ANSI_COLOR_BLACK        "\x1b[30m"
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_WHITE        "\x1b[37m"
#define ANSI_COLOR_WHAT        "\x1b[38m"

#define ANSI_TEXT_BOLD          "\x1b[1m"
#define ANSI_TEXT_UNDERSCORE    "\x1b[4m"
#define ANSI_TEXT_BLINK         "\x1b[5m"
#define ANSI_TEST_REVERSE       "\x1b[7m"
#define ANSI_TEST_CONCEALED     "\x1b[8m"

#define ANSI_BCOLOR_BLACK       "\x1b[40m"
#define ANSI_BCOLOR_RED         "\x1b[41m"
#define ANSI_BCOLOR_GREEN       "\x1b[42m"
#define ANSI_BCOLOR_YELLOW      "\x1b[43m"
#define ANSI_BCOLOR_BLUE        "\x1b[44m" 
#define ANSI_BCOLOR_MAGENTA     "\x1b[45m"
#define ANSI_BCOLOR_CYAN        "\x1b[46m"
#define ANSI_BCOLOR_WHITE       "\x1b[47m"

#define ANSI_UNSET              "\x1b[0m"

#define PRINT_BLACK(expr)   printf(ANSI_COLOR_BLACK expr ANSI_UNSET)
#define PRINT_RED(expr)   printf(ANSI_COLOR_RED expr ANSI_UNSET)
#define PRINT_GREEN(expr)   printf(ANSI_COLOR_GREEN expr ANSI_UNSET)
#define PRINT_YELLOW(expr)   printf(ANSI_COLOR_YELLOW expr ANSI_UNSET)
#define PRINT_BLUE(expr)   printf(ANSI_COLOR_BLUE expr ANSI_UNSET)
#define PRINT_MAGENTA(expr)   printf(ANSI_COLOR_MAGENTA expr ANSI_UNSET)
#define PRINT_CYAN(expr)   printf(ANSI_COLOR_CYAN expr ANSI_UNSET)
#define PRINT_WHITE(expr)   printf(ANSI_COLOR_WHITE expr ANSI_UNSET)
