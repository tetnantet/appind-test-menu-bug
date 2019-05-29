#include <gtk/gtk.h>
#include <libappindicator/app-indicator.h>

/* See -DLOGO_PNG compiler flag
 * #define LOGO_PNG "/home/super/men/logo.png"
 * */

AppIndicator* c_indicator;
GtkWidget* c_menu;

void menu_quit_cb(GtkMenuItem* menuitem, gpointer user_data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    int i;
    GtkWidget* item;
    char title[128];

    c_menu = gtk_menu_new();

    item = gtk_menu_item_new_with_label("Quit");
    g_signal_connect(item, "activate", G_CALLBACK(menu_quit_cb), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(c_menu), item);
    gtk_widget_show(item);

    gtk_menu_shell_append(GTK_MENU_SHELL(c_menu), gtk_separator_menu_item_new());

    for (i = 1; i <= 100; ++i) {
        snprintf(title, sizeof(title), "Item #%03u", i);
        item = gtk_menu_item_new_with_label(title);
        gtk_menu_shell_append(GTK_MENU_SHELL(c_menu), item);
        gtk_widget_show(item);
    }

    //

    c_indicator = app_indicator_new("Menu Test", LOGO_PNG, APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
    app_indicator_set_status(c_indicator, APP_INDICATOR_STATUS_ACTIVE);
    app_indicator_set_icon(c_indicator, LOGO_PNG);
    app_indicator_set_menu(c_indicator, GTK_MENU(c_menu));

    gtk_main();

    return 0;
}
