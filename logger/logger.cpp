#include "logger.h"
#include "../common/config.h"

logging_in::Logger::Logger() {
  setWindowTitle("Вывод приложения");
  setMinimumSize(QSize(500, 500));

  m_label = new QLabel();
  m_label->setWordWrap(true);
  m_label->setFont(config::MAIN_FONT);
  m_label->setAlignment(Qt::AlignTop | Qt::AlignLeft);

  m_vbox = new QVBoxLayout();
  m_vbox->addWidget(m_label);
  setLayout(m_vbox);
}

logging_in::Logger::~Logger() {
  delete m_label;
  delete m_vbox;
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
