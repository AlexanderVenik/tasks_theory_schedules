#ifndef TASKS_THEORY_SCHEDULES_MAINWINDOW_H
#define TASKS_THEORY_SCHEDULES_MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>

#include "logger/logger.h"
#include "table/table.h"

namespace window {

class MainWindow : public QMainWindow {
  Q_OBJECT
 private:
  enum Size { SIZE_WINDOW = 700, SIZE_TABLE = 7 };

  //  methods
 public:
  explicit MainWindow();
  ~MainWindow() override;

 protected:
  bool OpenLogger();

  // slots
 private slots:
  void Solve();

  //  fields
 private:
  std::shared_ptr<cwidget::MainTable> m_table;
  QVBoxLayout* m_box;

  QWidget* m_central_widget;

  QComboBox* m_target_function;
  QPushButton* m_btn_decide;
  std::shared_ptr<logging_in::Logger> m_logger;
};

}  // namespace window

#endif  //TASKS_THEORY_SCHEDULES_MAINWINDOW_H
