//
// Created by sasha on 20.12.2022.
//

#ifndef TASKS_THEORY_SCHEDULES_TABLE_H
#define TASKS_THEORY_SCHEDULES_TABLE_H

#include <QTableWidget>

namespace cwidget {
class MainTable : public QTableWidget {
  Q_OBJECT
 public:
  explicit MainTable(qint32 rows = 0, qint32 columns = 0,
                     QWidget* parent = nullptr);
  ~MainTable() override = default;
 private slots:
  void ChangeCell(qint32 row, qint32 column);
};
}  // namespace cwidget

#endif  //TASKS_THEORY_SCHEDULES_TABLE_H
