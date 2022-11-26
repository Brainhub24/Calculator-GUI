#include "util.h"
#include <math.h>

char *inputText;
GtkWidget *TextView;

/*
void print_hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}
*/

static int operationRet(char buff)
{
    int ret;
    switch (buff)
    {
    case '+':
        ret = 1;
        break;
    case '-':
        ret = 2;
        break;
    case '/':
        ret = 3;
        break;
    case '*':
        ret = 4;
        break;
    default:
        ret = 0;
        break;
    }

    return ret;
}

/*
 * Update GUI interface
 */
static void showResult(float input) {
    int len = (int)log10((int)input < 0 ? -input : input) + 1;
    char *output;
    len = len + 5;
    output = (char *)calloc(len, sizeof(char));
    gcvt(input, len, output);
    gtk_label_set_text(TextView, output);
}

static void scanInput(char *data)
{
    /*
     * The GTK box use \0 for end string.
     * Then we can use strlen()
     */
    int i, c = 0, opt, temp = 0;
    float ret = 0;
    //int *number;
    int number[2] = {0};
    int len = strlen(data);
    // for (i = 0; data[i] != '\0'; ++i)
    //     g_print("\nChar: %c", data[i]);
    
    //number = malloc(len * sizeof(int));
    //g_print("Size: %d", len);

    for (i  = 0; i != len; ++i) {
        opt = operationRet(data[i]);
        
        if (ret == 0 && opt != 0)
            ret = opt;
        
        /*
         * If opt is 0 is one number.
         * Then don't increase index of pointer (dynamic array).
         */
        if (!opt) {
            temp = (temp * 10) + ((int)data[i] - 48);
            //g_print("\n%d", temp);
        } else {
            c++;
            temp = 0;
        }
        number[c] = temp;
    }

    switch ((int)ret)
    {
    case 1:
        ret = number[0] + number[1];
        break;
    case 2:
        ret = number[0] - number[1];
        break;
    case 3:
        ret = (float)number[0] / number[1];
        break;
    case 4:
        ret = number[0] * number[1];
        break;
    default:
        break;
    }

    g_print("\nIl risultato dell'operazione è: %f", ret);

    showResult(ret);
}

/*
 * This function scan input of enter_callback() with inputText
 * pointer. This is a string (or char pointer).
 * Is allocated with dynamic memory.
 * We need to scan string to split operation from number.
 */
void restultOf(GtkWidget *widget, gpointer data)
{
    scanInput(inputText);
}

/*
 * data = buffer of box
 * enter_callback() take input from box
 */
void enter_callback(GtkWidget *widget, GtkEditable *data)
{
    // take last string with input (fix input and export)
    inputText = (char *)calloc(data, sizeof(char));
    inputText = gtk_editable_get_chars(data, 0, -1);
    // printf("%s", inputText);
}
