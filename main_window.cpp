#include "MainWindow.h"
#include "common/algo.h"
#include "common/common.h"
#include "common/config.h"
#include "solution/hungarian.h"
#include "table/table.h"

#include <QMessageBox>
#include <QPushButton>
#include <memory>

window::MainWindow::MainWindow()
  : m_logger(std::make_shared<logging_in::Logger>()),
    m_table(std::make_shared<cwidget::MainTable>(SIZE_TABLE, SIZE_TABLE)) {
  setMinimumSize(QSize(SIZE_WINDOW, SIZE_WINDOW));
  m_table->setShowGrid(true);

  m_box = new QVBoxLayout();
  if (m_box) {
    m_box->addWidget(m_table.get());

    m_btn_decide = new QPushButton("Решить");
    if (m_btn_decide) {
      m_btn_decide->setFont(config::MAIN_FONT);
      m_box->addWidget(m_btn_decide);
      connect(m_btn_decide, &QPushButton::clicked, this, &MainWindow::Solve);
    }

    m_central_widget = new QWidget();
    m_central_widget->setLayout(m_box);

    setCentralWidget(m_central_widget);

    show();
  } else {
    QMessageBox::information(this, "Ошибка открытия",
                             "MainWindow::MainWindow: QVBoxLayout id null");
  }
}

window::MainWindow::~MainWindow() {
  delete m_box;
//  delete m_target_function;
  delete m_btn_decide;
}

void window::MainWindow::Solve() {
  REQUIRE(m_logger)
  if (OpenLogger()) {
    quint64 count_row_of_with_data = m_table->GetCountRowWithData();
    m_logger->WriteLine("Row: " + QString::number(count_row_of_with_data));

    quint64 count_col_of_with_data = m_table->GetCountColWithData();
    m_logger->WriteLine("Col: " + QString::number(count_col_of_with_data));

    auto values_in_range =
        m_table->GetElements(count_row_of_with_data, count_col_of_with_data);

    vector<int> assignment;
    HungarianAlgorithm HungAlgo(m_logger.get());

    auto result = HungAlgo.Solve(values_in_range, assignment);
    m_logger->Write("F = ");
    m_logger->WriteLine(QString::number(result));
  }
}

bool window::MainWindow::OpenLogger() {
  m_logger->Show();
  m_logger->move(QPoint(x() + QWidget::width(), QWidget::y()));
  if (m_logger->isVisible()) {
    return true;
  } else {
    QMessageBox::information(
        this, "Ошибка открытия",
        "MainWindow::MainWindow: is'n can not open Logger");
    return false;
  }
}
