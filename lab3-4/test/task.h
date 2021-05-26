#ifndef TASK_H
#define TASK_H

#include <Option.h>
#include <string>
#include <vector>



class Task
{
public:
    Task();
    int getId() const;
    void setId(int value);

    std::string getTitle() const;
    void setTitle(const std::string &value);

    Option getOption1() const;
    void setOption1(const Option &value);

    Option getOption2() const;
    void setOption2(const Option &value);

    Option getOption3() const;
    void setOption3(const Option &value);

private:
    int id;
    std::string title;
    Option option1;
    Option option2;
    Option option3;
};

#endif // TASK_H
