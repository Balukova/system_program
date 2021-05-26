#include "option.h"

Option::Option()
{

}

int Option::getId() const
{
    return id;
}

void Option::setId(int value)
{
    id = value;
}

std::string Option::getTitle() const
{
    return title;
}

void Option::setTitle(const std::string &value)
{
    title = value;
}

bool Option::getIsTrue() const
{
    return isTrue;
}

void Option::setIsTrue(bool value)
{
    isTrue = value;
}
