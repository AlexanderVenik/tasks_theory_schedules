#include "logger.h"
#include "../common/config.h"

logging_in::Logger::Logger() {
  setWindowTitle("Вывод приложения");
  setMinimumSize(QSize(500, 500));

  m_scroll_area = new QScrollArea();

  m_label = new QLabel();
  m_label->setWordWrap(true);
  m_label->setFont(config::MAIN_FONT);
  m_label->setAlignment(Qt::AlignTop | Qt::AlignLeft);

  m_scroll_area->setWidget(m_label);
  m_scroll_area->setWidgetResizable(true);

  setCentralWidget(m_scroll_area);
}

logging_in::Logger::~Logger() {
  delete m_label;
//  delete m_vbox;
  delete m_scroll_area;
}

[[maybe_unused]]
void logging_in::Logger::WriteLine(const QString& data) {
  m_label->setText(m_label->text() + data + "\n");
}

[[maybe_unused]]
void logging_in::Logger::Clear() {
  m_label->setText("");
}

[[maybe_unused]]
void logging_in::Logger::Show() {
  show();
}

void logging_in::Logger::Write(const QString& data) {
  m_label->setText(m_label->text() + data);
}
