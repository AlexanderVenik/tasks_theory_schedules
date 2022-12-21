#ifndef TASKS_THEORY_SCHEDULES_LOGGER_H
#define TASKS_THEORY_SCHEDULES_LOGGER_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

namespace logging_in {
class Logger : public QWidget {
  Q_OBJECT
 public:
  explicit Logger();
  ~Logger() override;

  [[maybe_unused]] void WriteLine(const QString& data = " ");
  [[maybe_unused]] void Write(const QString& data);
  [[maybe_unused]] void Clear();
  [[maybe_unused]] void Show();

 private:
  QLabel* m_label;
  QVBoxLayout* m_vbox;
};
}  // namespace logging_in

#endif  //TASKS_THEORY_SCHEDULES_LOGGER_H
