#ifndef OPTION_H
#define OPTION_H

#include <string>



class Option
{
public:
    Option();
    int getId() const;
    void setId(int value);

    std::string getTitle() const;
    void setTitle(const std::string &value);

    bool getIsTrue() const;
    void setIsTrue(bool value);

private:
    int id;
    std::string title;
    bool isTrue;
};

#endif // OPTION_H
