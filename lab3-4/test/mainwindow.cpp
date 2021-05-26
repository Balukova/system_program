
#include "mainwindow.h"
#include "taskdialog.h"
#include "QFileDialog"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<Test> tests = CreateTests();
    setTests(tests);
    for(Test t : tests){
        ui->listWidget->addItem(QString::fromStdString(t.getTitle()));
    }
    connect(ui->pushButton, &QAbstractButton::pressed, this, &MainWindow::buttonPressed);
    connect(ui->pushButton_2, &QAbstractButton::pressed, this, &MainWindow::openFromPC);
}

std::vector<Test> MainWindow::CreateTests(){
    Task task1;
    task1.setId(1);
    task1.setTitle("Скільки сердець у восьминога?");

    Task task2;
    task2.setId(2);
    task2.setTitle("У якої тварини найшвидший метаболізм?");

    Task task3;
    task3.setId(3);
    task3.setTitle("Фотосинтез відбувається у:");

    Option op1;
    op1.setTitle("3");
    op1.setId(1);
    op1.setIsTrue(true);

    Option op2;
    op2.setTitle("1");
    op2.setId(2);
    op2.setIsTrue(false);

    Option op3;
    op3.setTitle("0");
    op3.setId(3);
    op3.setIsTrue(false);

    Option op4;
    op4.setTitle("Корова");
    op4.setId(4);
    op4.setIsTrue(false);

    Option op5;
    op5.setTitle("Колібрі");
    op5.setId(5);
    op5.setIsTrue(true);

    Option op6;
    op6.setTitle("Кит");
    op6.setId(6);
    op6.setIsTrue(false);

    Option op7;
    op7.setTitle("Лейкопластах");
    op7.setId(7);
    op7.setIsTrue(false);

    Option op8;
    op8.setTitle("Корені");
    op8.setId(8);
    op8.setIsTrue(false);

    Option op9;
    op9.setTitle("Хлоропластах");
    op9.setId(9);
    op9.setIsTrue(true);

    task1.setOption1(op1);
    task1.setOption2(op2);
    task1.setOption3(op3);

    task2.setOption1(op4);
    task2.setOption2(op5);
    task2.setOption3(op6);

    task3.setOption1(op7);
    task3.setOption2(op8);
    task3.setOption3(op9);

    std::vector<Task> tasks1;
    tasks1.push_back(task1);
    tasks1.push_back(task2);

    Test test1;
    test1.setId(1);
    test1.setTitle("Тваринний світ");
    test1.setTasks(tasks1);

    std::vector<Task> tasks2;
    tasks2.push_back(task3);

    Test test2;
    test2.setId(2);
    test2.setTitle("Рослинний світ");
    test2.setTasks(tasks2);

    std::vector<Test> tests;
    tests.push_back(test1);
    tests.push_back(test2);

    return tests;
}

void MainWindow::buttonPressed(){
    Test test = tests.at(ui->listWidget->currentIndex().row());
    std::vector<Option> options;
    TaskDialog* td = new TaskDialog(test, 0, options);
    td->show();
}

void MainWindow::openFromPC(){
    QString path = QFileDialog::getOpenFileName(this, "Open Text File", "C:/Temp", "Text files(*.txt);;All files (*.*)");
     if(!path.isEmpty())
     {
     QFile myFile(path);
     if (myFile.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         QTextStream in(&myFile);
          if(!in.atEnd())
          {
              QString line = in.readLine();
              Test test1;
              test1.setTitle(line.toStdString());
              std::vector<Task> tasks1;
              while(!in.atEnd()){
                  line = in.readLine();
                  Task task;
                  task.setTitle(line.toStdString());

                  line = in.readLine();
                  Option op1;
                  op1.setTitle(line.toStdString());

                  line = in.readLine();
                  Option op2;
                  op2.setTitle(line.toStdString());

                  line = in.readLine();
                  Option op3;
                  op3.setTitle(line.toStdString());

                  line = in.readLine();
                  switch (line.toUInt()) {
                  case 1:
                      op1.setIsTrue(true);
                      break;
                  case 2:
                      op2.setIsTrue(true);
                      break;
                  case 3:
                      op3.setIsTrue(true);
                      break;
                  }
                  line = in.readLine();
                  task.setOption1(op1);
                  task.setOption2(op2);
                  task.setOption3(op3);
                  tasks1.push_back(task);

              }
              test1.setTasks(tasks1);
              std::vector<Option> options;
              TaskDialog* td = new TaskDialog(test1, 0, options);
              td->show();
          }
          myFile.close();
     }
     }

}


std::vector<Test> MainWindow::getTests() const
{
    return tests;
}

void MainWindow::setTests(const std::vector<Test> &value)
{
    tests = value;
}

MainWindow::~MainWindow()
{
    delete ui;
}

