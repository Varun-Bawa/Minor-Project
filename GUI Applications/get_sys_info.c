#include <gtk/gtk.h>

static void
get_sys_info (GtkWidget *widget,
             gpointer   data)
{
  g_print("Linux Version   : ");
  system("lsb_release -sd");
  g_print("Computer Name   : ");
  system("hostname");
  g_print("Current User    : ");
  system("echo $USER");
  g_print("Memory(kbs)     : ");
  system("cat /proc/meminfo | grep MemTotal | awk '{ print $2 }'");
  system("cat /proc/cpuinfo | grep 'model name' | uniq");
  g_print("Architecture    : ");
  system("uname -p");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "System Details");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Get System info in Terminal");
  g_signal_connect (button, "clicked", G_CALLBACK (get_sys_info), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);

  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
