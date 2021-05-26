#include "task.h"

Task::Task()
{

}

int Task::getId() const
{
    return id;
}

void Task::setId(int value)
{
    id = value;
}

std::string Task::getTitle() const
{
    return title;
}

void Task::setTitle(const std::string &value)
{
    title = value;
}

Option Task::getOption1() const
{
    return option1;
}

void Task::setOption1(const Option &value)
{
    option1 = value;
}

Option Task::getOption2() const
{
    return option2;
}

void Task::setOption2(const Option &value)
{
    option2 = value;
}

Option Task::getOption3() const
{
    return option3;
}

void Task::setOption3(const Option &value)
{
    option3 = value;
}
