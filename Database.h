#ifndef DATABASE_H
#define DATABASE_H

#include <libpq-fe.h>
#include "task.h"

class Database
{
private:
    PGconn* conn;

public:
    Database();
    ~Database();

    bool connect();
    bool insertTask(const Task& task);
};

#endif