#include "keyboard.h"
#include "scancodes.h"
#include "types.h"

int Scancode = -1;

int shift_pressed = FALSE;
int caps_pressed = FALSE;
int escape_pressed = FALSE;
int backspace_pressed = FALSE;
int alt_pressed = FALSE;
int ctrl_pressed = FALSE;
int enter_pressed = FALSE;

unsigned char ProcessScancode(int scancode) {
    if (scancode == SC_ESCAPE)
        escape_pressed = TRUE;

    else if (scancode == SC_1)
        if (shift_pressed == TRUE)
            return '!';
        else
            return '1';

    else if (scancode == SC_2)
        if (shift_pressed == TRUE)
            return '"';
        else
            return '2';

    else if (scancode == SC_3)
        if (shift_pressed == TRUE)
            return '£';
        else
            return '3';

    else if (scancode == SC_4)
        if (shift_pressed == TRUE)
            return '$';
        else
            return '4';

    else if (scancode == SC_5)
        if (shift_pressed == TRUE)
            return '%';
        else
            return '5';

    else if (scancode == SC_6)
        if (shift_pressed == TRUE)
            return '^';
        else
            return '6';

    else if (scancode == SC_7)
        if (shift_pressed == TRUE)
            return '&';
        else
            return '7';

    else if (scancode == SC_8)
        if (shift_pressed == TRUE)
            return '*';
        else
            return '8';

    else if (scancode == SC_9)
        if (shift_pressed == TRUE)
            return '(';
        else
            return '9';

    else if (scancode == SC_0)
        if (shift_pressed == TRUE)
            return ')';
        else
            return '0';

    else if (scancode == SC_MINUS)
        if (shift_pressed == TRUE)
            return '_';
        else
            return '-';

    else if (scancode == SC_EQUALS)
        if (shift_pressed == TRUE)
            return '+';
        else
            return '=';

    else if (scancode == SC_BACKSPACE)
        backspace_pressed = TRUE;

    else if (scancode == SC_TAB)
        return '\t';

    else if (scancode == SC_Q)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'Q';
        else
            return 'q';

    else if (scancode == SC_W)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'W';
        else
            return 'w';

    else if (scancode == SC_E)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'E';
        else
            return 'e';

    else if (scancode == SC_R)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'R';
        else
            return 'r';

    else if (scancode == SC_T)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'T';
        else
            return 't';

    else if (scancode == SC_Y)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'Y';
        else
            return 'y';

    else if (scancode == SC_U)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'U';
        else
            return 'u';

    else if (scancode == SC_I)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'I';
        else
            return 'i';

    else if (scancode == SC_O)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'O';
        else
            return 'o';

    else if (scancode == SC_P)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'P';
        else
            return 'p';

    else if (scancode == SC_LBRACKET)
        if (shift_pressed == TRUE)
            return '{';
        else
            return '[';

    else if (scancode == SC_RBRACKET)
        if (shift_pressed == TRUE)
            return '}';
        else
            return ']';

    else if (scancode == SC_ENTER) {
        enter_pressed = TRUE;
        return '\n';
    }

    else if (scancode == SC_LCTRL)
        ctrl_pressed = TRUE;

    else if (scancode == SC_A)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'A';
        else
            return 'a';

    else if (scancode == SC_S)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'S';
        else
            return 's';

    else if (scancode == SC_D)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'D';
        else
            return 'd';

    else if (scancode == SC_F)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'F';
        else
            return 'f';

    else if (scancode == SC_G)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'G';
        else
            return 'g';

    else if (scancode == SC_H)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'H';
        else
            return 'h';

    else if (scancode == SC_J)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'J';
        else
            return 'j';

    else if (scancode == SC_K)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'K';
        else
            return 'k';

    else if (scancode == SC_L)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'L';
        else
            return 'l';

    else if (scancode == SC_SEMICOLON)
        if (shift_pressed == TRUE)
            return ':';
        else
            return ';';

    else if (scancode == SC_APOSTROPHE)
        if (shift_pressed == TRUE)
            return '@';
        else
            return '\'';

    else if (scancode == SC_GRAVE)
        if (shift_pressed == TRUE)
            return '¬';
        else
            return '`';

    else if (scancode == SC_LSHIFT)
        shift_pressed = TRUE;

    else if (scancode == SC_BACKSLASH)
        if (shift_pressed == TRUE)
            return '|';
        else
            return '\\';

    else if (scancode == SC_Z)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'Z';
        else
            return 'z';

    else if (scancode == SC_X)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'X';
        else
            return 'x';

    else if (scancode == SC_C)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'C';
        else
            return 'c';

    else if (scancode == SC_V)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'V';
        else
            return 'v';

    else if (scancode == SC_B)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'B';
        else
            return 'b';

    else if (scancode == SC_N)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'N';
        else
            return 'n';

    else if (scancode == SC_M)
        if (shift_pressed == TRUE || caps_pressed == TRUE)
            return 'M';
        else
            return 'm';

    else if (scancode == SC_COMMA)
        if (shift_pressed == TRUE)
            return '<';
        else
            return ',';

    else if (scancode == SC_PERIOD)
        if (shift_pressed == TRUE)
            return '>';
        else
            return '.';

    else if (scancode == SC_SLASH)
        if (shift_pressed == TRUE)
            return '?';
        else
            return '/';

    else if (scancode == SC_RSHIFT)
        shift_pressed = TRUE;

    else if (scancode == SC_LALT)
        alt_pressed = TRUE;

    else if (scancode == SC_SPACE)
        return ' ';

    else if (scancode == SC_CAPS)
        if (caps_pressed == TRUE)
            caps_pressed = FALSE;
        else if (caps_pressed == FALSE)
            caps_pressed = TRUE;

    if (scancode == SC_LSHIFT_RELEASE)
        shift_pressed = FALSE;

    if (scancode == SC_RSHIFT_RELEASE)
        shift_pressed = FALSE;

    return '\0';
}
