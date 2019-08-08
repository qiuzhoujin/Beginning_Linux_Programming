#include <gnome.h>
#include "app_mysql.h"

enum
{
	COLUMN_TITLE,
	COLUMN_ARTIST,
	COLUMN_CATALOGUE,
	N_COLUMNS
};

GtkWidget *create_main_window();

GtkWidget *create_login_dialog();

GtkWidget *create_addcd_dialog();

/* Callback to quit application */
void quit_app(GtkWidget *window, gpointer data);

/* Callback useful for confirming exit before quitting */
gboolean delete_event_handler(GtkWidget *window, GdkEvent *event, gpointer data);

/* Callback connected to 'response' signal of addcd dialog */
void addcd_dialog_button_clicked(GtkDialog *dialog, gint response, gpointer userdata);

/* Callback for menu and toolbar 'Add CD' button */
void on_addcd_activate(GtkMenuItem *menuitem, gpointer user_data);

/* Callback for menu 'About' button */
void on_about_activate(GtkMenuItem *menuitem, gpointer user_data);

/* Callback for menu 'Quit' button */
void on_quit_activate(GtkMenuItem *menuitem, gpointer user_data);

/* Callback for search button */
void on_search_button_clicked(GtkButton *button, gpointer user_data);

gboolean confirm_exit();

void add_widget_with_label(GtkContainer *box, gchar *caption, GtkWidget *widget);
