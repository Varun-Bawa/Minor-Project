#include <gtk/gtk.h>

static void
rm_cache (GtkWidget *widget,
	     gpointer   data)
{
  g_print("\nRemoving Cache From System\n\n");
  system("sudo rm -rf ~/.thumbs/*");
  system("sleep 3");
  g_print("Cache Cleared\n");
}

static void
rm_crash (GtkWidget *widget,
	     gpointer   data)
{
  g_print("\nRemoving Crash Reports From System\n\n");
  system("sudo rm -rf /var/crash/*");
  system("sleep 3");
  g_print("Crash Reports Cleared\n");
}

static void
rm_temp (GtkWidget *widget,
	     gpointer   data)
{
  g_print("\nRemoving Temporary Files From System\n\n");
  system("sudo rm -rf /tmp/*");
  system("sleep 3");
  g_print("Temporary Files Cleared\n");
}

static void
quit (GtkWidget *widget,
	     gpointer   data)
{
  g_print("\nSystem Quits\nThankYou for using OSS Cleaner\n\nDeveloped and Maintained by Varun Bawa\n");
  g_print("Feel free to contact at varunbawa62ak@gmail.com\nRead my blog at\ninnovativebit.blogspot.in\n\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "OSS Cleaner");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  button = gtk_check_button_new_with_label ("Clear Cache");
  g_signal_connect (button, "clicked", G_CALLBACK (rm_cache), NULL);

  /* Place the first button in the grid cell (0, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

  button = gtk_check_button_new_with_label ("Clear Crash Report");
  g_signal_connect (button, "clicked", G_CALLBACK (rm_crash), NULL);

  /* Place the second button in the grid cell (1, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 1, 1);

  button = gtk_check_button_new_with_label ("Clear Temp Files");
  g_signal_connect (button, "clicked", G_CALLBACK (rm_temp), NULL);

  /* Place the second button in the grid cell (1, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 2, 1, 1);

  button = gtk_button_new_with_label ("Quit");
  g_signal_connect (button, "clicked", G_CALLBACK (quit), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  /* Place the Quit button in the grid cell (0, 1), and make it
   * span 2 columns.
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 3, 2, 1);

  /* Now that we are done packing our widgets, we show them all
   * in one go, by calling gtk_widget_show_all() on the window.
   * This call recursively calls gtk_widget_show() on all widgets
   * that are contained in the window, directly or indirectly.
   */
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
