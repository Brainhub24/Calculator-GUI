#include <gtk/gtk.h>
#include "util.h"

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *label = gtk_label_new("Calculator");
    GtkWidget *result = gtk_label_new("Result");

    gtk_window_set_default_size(GTK_WINDOW(window), DEFAULT_SIZE,
                                                    DEFAULT_SIZE);

    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 6);

    //GtkWidget *button1 = gtk_button_new_with_label("Press 1");
    GtkWidget *button2 = gtk_button_new_with_label("Show Result");
    GtkWidget *button3 = gtk_button_new_with_label("Quit");
    TextView = gtk_label_new(" ");

    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 3, 1);
    //gtk_grid_attach(GTK_GRID(grid), button1, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button3, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), result, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), TextView, 2, 2, 1, 1);

    // create box for input text
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(entry), 0);
    gtk_grid_attach(GTK_GRID(grid), entry, 3, 1, 1, 1);
    // end text box

    gtk_window_set_child(GTK_WINDOW(window), grid);
    //g_signal_connect_swapped(button1, "clicked", print_hello, NULL);
    g_signal_connect_swapped(button2, "clicked", restultOf, inputText);
    g_signal_connect_swapped(button3, "clicked",
                                G_CALLBACK(gtk_window_close), window);
    g_signal_connect(entry, "changed",
                                    enter_callback, (GtkEditable*)entry);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
