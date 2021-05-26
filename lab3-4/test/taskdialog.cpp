#include "option.h"
#include "result.h"
#include "taskdialog.h"
#include "ui_taskdialog.h"

#include <Task.h>
#include <task.h>

TaskDialog::TaskDialog(Test test, int number, std::vector<Option> options, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    setTest(test);
    setOptions(options);
    setNumber(number);
    ui->setupUi(this);
    ui->label->setText(QString::fromStdString(test.getTasks().at(number).getTitle()));
    ui->radioButton->setText(QString::fromStdString(test.getTasks().at(number).getOption1().getTitle()));
    ui->radioButton_2->setText(QString::fromStdString(test.getTasks().at(number).getOption2().getTitle()));
    ui->radioButton_3->setText(QString::fromStdString(test.getTasks().at(number).getOption3().getTitle()));
    connect(ui->pushButton, &QAbstractButton::pressed, this, &TaskDialog::buttonPressed);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::buttonPressed()
{

    if(ui->radioButton->isChecked() == true){
        options.push_back(test.getTasks().at(number).getOption1());
    };
    if(ui->radioButton_2->isChecked() == true){
        options.push_back(test.getTasks().at(number).getOption2());
    };
    if(ui->radioButton_3->isChecked() == true){
        options.push_back(test.getTasks().at(number).getOption3());
    };
    if(number+1 == static_cast<int>(test.getTasks().size())){
        Result* res = new Result(getTest(), options);
        res->show();
        this->close();
    }
    else{
        TaskDialog* td = new TaskDialog(test, number+1, options);
        td->show();
        this->close();
    }
}

int TaskDialog::getNumber() const
{
    return number;
}

void TaskDialog::setNumber(int value)
{
    number = value;
}

std::vector<Option> TaskDialog::getOptions() const
{
    return options;
}

void TaskDialog::setOptions(const std::vector<Option> &value)
{
    options = value;
}

Test TaskDialog::getTest() const
{
    return test;
}

void TaskDialog::setTest(const Test &value)
{
    test = value;
}
