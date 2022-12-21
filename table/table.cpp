#include "table.h"

#include <QDebug>
#include <algorithm>

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

quint64 cwidget::MainTable::GetCountRowWithData() const {
  for(quint64 idx = 0; idx < rowCount(); ++idx) {
    auto item_table = item(0, idx);
    if (!item_table || item_table->text().isEmpty()) {
      return idx;
    }
  }
}

quint64 cwidget::MainTable::GetCountColWithData() const {
  for(quint64 idx = 0; idx < columnCount(); ++idx) {
    auto item_table = item(idx, 0);
    if (!item_table || item_table->text().isEmpty()) {
      return idx;
    }
  }
}

std::vector<std::vector<double>> cwidget::MainTable::GetElements(quint64 row, quint64 col) const {
  std::vector<std::vector<double>> result;

  for(quint64 idx_r = 0; idx_r < row; ++idx_r) {
    std::vector<double> data_in_row;

    for(quint64 idx_c = 0; idx_c < col; ++idx_c) {
      auto item_table = item(idx_r, idx_c);
      if (item_table) {
        auto text_item = item_table->text();
        if (!text_item.isEmpty()) {
          data_in_row.push_back(text_item.toDouble());
        }
      }
    }
    result.push_back(data_in_row);
  }

  return result;
}
