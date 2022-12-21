#include "table.h"
#include "../common/config.h"

cwidget::MainTable::MainTable(qint32 rows, qint32 columns, QWidget* parent)
    : QTableWidget(rows, columns, parent) {
  setFont(config::MAIN_FONT);

  constexpr quint16 row = 5, col = 5;
  constexpr quint16 data[row][col] = {{45, 50, 10, 20, 30},
                                      {50, 40, 70, 80, 90},
                                      {10, 20, 60, 20, 80},
                                      {60, 50, 20, 10, 80},
                                      {10, 50, 40, 30, 20}};

  for (quint32 idx_row = 0; idx_row < row; ++idx_row) {
    for (quint32 idx_col = 0; idx_col < col; ++idx_col) {
      auto item_table = new QTableWidgetItem;
      item_table->setData(Qt::DisplayRole,
                          QVariant(QString::number(data[idx_row][idx_col])));
      setItem(idx_row, idx_col, item_table);
    }
  }

  connect(this, &QTableWidget::cellChanged, this, &MainTable::ChangeCell);
}

void cwidget::MainTable::ChangeCell(qint32 row, qint32 column) {
  if (row == rowCount() - 1) {
    insertRow(rowCount());
  }
  if (column == columnCount() - 1) {
    insertColumn(columnCount());
  }
}
