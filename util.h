#ifndef _UTILS_FOR_GTK_H_
#define _UTILS_FOR_GTK_H_

#include <gtk/gtk.h>

#define DEFAULT_SIZE    400

extern GtkWidget *TextView;
extern char *inputText;

//void print_hello(GtkWidget *widget, gpointer data);
void restultOf(GtkWidget *widget, gpointer data);
void enter_callback(GtkWidget *widget, GtkEditable *data);

#endif // End _UTILS_FOR_GTK_H_