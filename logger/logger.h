#ifndef TASKS_THEORY_SCHEDULES_LOGGER_H
#define TASKS_THEORY_SCHEDULES_LOGGER_H

#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QMainWindow>

namespace logging_in {
class Logger : public QMainWindow {
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
  QScrollArea* m_scroll_area;
  QVBoxLayout* m_vbox;
};
}  // namespace logging_in

#endif  //TASKS_THEORY_SCHEDULES_LOGGER_H
