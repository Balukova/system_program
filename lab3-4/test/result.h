#ifndef RESULT_H
#define RESULT_H

#include "Option.h"
#include "Test.h"

#include <QDialog>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(Test test, std::vector<Option> options, QWidget *parent = nullptr);
    ~Result();
    std::vector<Option> getOptions() const;
    void setOptions(const std::vector<Option> &value);

    Test getT() const;
    void setT(const Test &value);

public slots:
    void buttonPressed();

private:
    Ui::Result *ui;
    std::vector<Option> options;
    Test t;
};

#endif // RESULT_H
