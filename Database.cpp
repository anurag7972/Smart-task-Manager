#include "Database.h"
#include <iostream>

Database::Database()
    : conn(nullptr)
{
}

Database::~Database()
{
    if (conn != nullptr)
    {
        PQfinish(conn);
    }
}

bool Database::connect()
{
    conn = PQconnectdb(
        "host=localhost "
        "port=5432 "
        "dbname=smart_task_manager "
        "user=postgres "
        "password=postgres"
    );

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cout << "Database connection failed: "
                  << PQerrorMessage(conn) << '\n';

        return false;
    }

    std::cout << "Connected to PostgreSQL successfully!\n";

    return true;
}

bool Database::insertTask(const Task& task)
{
    const char* values[6];

    std::string taskId = std::to_string(task.getTaskId());
    std::string priority = std::to_string(task.getPriority());
    std::string status = task.getStatus();

     values[0] = taskId.c_str();
     values[1] = task.getName().c_str();
     values[2] = task.getDescription().c_str();
     values[3] = priority.c_str();
     values[4] = status.c_str();
     values[5] = task.getDeadline().c_str();

    const char* query =
        "INSERT INTO tasks "
        "(task_id, name, description, priority, status, deadline) "
        "VALUES ($1, $2, $3, $4, $5, $6);";

    PGresult* result = PQexecParams(
        conn,
        query,
        6,
        nullptr,
        values,
        nullptr,
        nullptr,
        0
    );

    if (PQresultStatus(result) == PGRES_COMMAND_OK)
    {
        PQclear(result);
        return true;
    }

    std::cout << "Failed to insert task: "
              << PQerrorMessage(conn) << '\n';

    PQclear(result);
    return false;
}