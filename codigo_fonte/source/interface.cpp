#include "interface.h"
#include <gtk/gtk.h>
#include <fstream>
#include <string>

using namespace std;

// Função para adicionar uma nova placa ao arquivo
void add_plate(const char* plate) {
  ofstream file;
  file.open("../base_de_dados/placas_cadastradas.txt", ios::app);
  file << plate << endl;
  file.close();
}

// Função para remover uma placa do arquivo
void remove_plate(const char* plate) {
  ifstream file;
  file.open("../base_de_dados/placas_cadastradas.txt");
  string line;
  string content;
  while (getline(file, line)) {
    if (line != plate) {
      content += line + "\n";
    }
  }
  file.close();
  ofstream output;
  output.open("../base_de_dados/placas_cadastradas.txt");
  output << content;
  output.close();
}

// Função de callback para o botão de cadastro
void on_add_clicked(GtkWidget* widget, gpointer entry) {
  const char* plate = gtk_entry_get_text(GTK_ENTRY(entry));
  add_plate(plate);
}

// Função de callback para o botão de exclusão
void on_remove_clicked(GtkWidget* widget, gpointer entry) {
  const char* plate = gtk_entry_get_text(GTK_ENTRY(entry));
  remove_plate(plate);
}

int dialogo(int argc, char *argv[]) {
  // Inicialização da biblioteca GTK+
  gtk_init(&argc, &argv);

  // Criação da janela principal
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Cadastro de veiculos");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  // Criação do caixa de entrada de texto
  GtkWidget* entry = gtk_entry_new();

  // Criação dos botões
  GtkWidget* add_button = gtk_button_new_with_label("Cadastrar placa");
  g_signal_connect(add_button, "clicked", G_CALLBACK(on_add_clicked), entry);
  GtkWidget* remove_button = gtk_button_new_with_label("Remover placa");
  g_signal_connect(remove_button, "clicked", G_CALLBACK(on_remove_clicked), entry);

  // Criação da caixa vertical para organizar os widgets
  GtkWidget* vbox = gtk_vbox_new(FALSE, 5);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  // Adicionando os widgets à caixa vertical
  gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), add_button, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), remove_button, FALSE, FALSE, 5);

  // Exibindo a janela
  gtk_widget_show_all(window);

  // Iniciando a biblioteca GTK+
  gtk_main();

  return 0;
}

