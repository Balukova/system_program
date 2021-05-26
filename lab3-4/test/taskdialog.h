#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include "test.h"

#include <QDialog>
#include <Task.h>

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(Test test, int number, std::vector<Option> options, QWidget *parent = nullptr);
    ~TaskDialog();

    Test getTest() const;
    void setTest(const Test &value);

    std::vector<Option> getOptions() const;
    void setOptions(const std::vector<Option> &value);

    int getNumber() const;
    void setNumber(int value);

public slots:
    void buttonPressed();

private:
    Ui::TaskDialog *ui;
    Test test;
    std::vector<Option> options;
    int number;
};

#endif // TASKDIALOG_H
