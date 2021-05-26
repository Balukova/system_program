#ifndef TEST_H
#define TEST_H

#include <Task.h>
#include <string>
#include <vector>



class Test
{
public:
    Test();
    std::string getTitle() const;
    void setTitle(const std::string &value);

    int getId() const;
    void setId(int value);

    std::vector<Task> getTasks() const;
    void setTasks(const std::vector<Task> &value);

private:
    int id;
    std::string title;
    std::vector<Task> tasks;

};

#endif // TEST_H
