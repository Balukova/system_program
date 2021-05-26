#include "Option.h"
#include "result.h"
#include "ui_result.h"
#include "QFileDialog"

Result::Result(Test test, std::vector<Option> options, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    setOptions(options);
    setT(test);
    ui->setupUi(this);
    int res = 0;
    for(Option o : options){
        if(o.getIsTrue() == true){
            res+=1;
        }
    }
    connect(ui->pushButton, &QAbstractButton::pressed, this, &Result::buttonPressed);
    ui->label->setText(QString::number(res));
}

Result::~Result()
{
    delete ui;
}

void Result::buttonPressed(){
    QString path = QFileDialog::getSaveFileName(this, "Save Text File", "C:/Temp", "Text files(*.txt);;All files (*.*)");
     if(!path.isEmpty())
     {
     QFile myFile(path);
     if (myFile.open(QIODevice::WriteOnly | QIODevice::Text))
     {
         QTextStream out(&myFile);
         out<<QString::fromStdString(getT().getTitle());
         out<<"\n";
         for(Option o:getOptions()){
             out<<QString::fromStdString(o.getTitle());
             out<<"\n";
         }

         myFile.close();
     }
     }
}

Test Result::getT() const
{
    return t;
}

void Result::setT(const Test &value)
{
    t = value;
}

std::vector<Option> Result::getOptions() const
{
    return options;
}

void Result::setOptions(const std::vector<Option> &value)
{
    options = value;
}


