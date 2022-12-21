#include "MainWindow.h"
#include "common/config.h"
#include "table/table.h"

#include <QMessageBox>
#include <QPushButton>
#include <memory>

window::MainWindow::MainWindow() {
  setMinimumSize(QSize(SIZE_WINDOW, SIZE_WINDOW));

  m_table = std::make_shared<cwidget::MainTable>(SIZE_TABLE, SIZE_TABLE);
  m_table->setShowGrid(true);

  m_box = new QVBoxLayout();
  if (m_box) {
    m_box->addWidget(m_table.get());

    m_target_function = new QComboBox();
    if (m_target_function) {
      m_target_function->addItems(QStringList() << "Максимум"
                                                << "Минимум");
      m_target_function->setFont(config::MAIN_FONT);
      m_box->addWidget(m_target_function);
    }

    m_btn_decide = new QPushButton("Решить");
    if (m_btn_decide) {
      m_btn_decide->setFont(config::MAIN_FONT);
      m_box->addWidget(m_btn_decide);
      connect(m_btn_decide, SIGNAL(clicked(bool)), this, SLOT(Solve));
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
  delete m_target_function;
  delete m_btn_decide;
}
