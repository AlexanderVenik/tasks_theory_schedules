#include <QApplication>

#include "MainWindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  auto main_window = std::make_unique<window::MainWindow>();

  return QApplication::exec();
}
