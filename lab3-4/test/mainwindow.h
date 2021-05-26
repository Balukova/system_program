#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Test.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<Test> CreateTests();

    std::vector<Test> getTests() const;
    void setTests(const std::vector<Test> &value);

public slots:
    void buttonPressed();
    void openFromPC();


private:
    Ui::MainWindow *ui;
    std::vector<Test> tests;
};
#endif // MAINWINDOW_H
