#ifndef TASKS_THEORY_SCHEDULES_MAINWINDOW_H
#define TASKS_THEORY_SCHEDULES_MAINWINDOW_H

#include <QComboBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>

#include "table/table.h"

namespace window {

class MainWindow : public QMainWindow {
  Q_OBJECT
 private:
  enum Size {
    SIZE_WINDOW = 700,
    SIZE_TABLE = 5
  };

 public:
  explicit MainWindow();
  ~MainWindow() override;


 private:
  std::shared_ptr<cwidget::MainTable> m_table;
  QVBoxLayout* m_box;

  QWidget* m_central_widget;

  QComboBox* m_target_function;
  QPushButton* m_btn_decide;
};

}  // namespace window

#endif  //TASKS_THEORY_SCHEDULES_MAINWINDOW_H
