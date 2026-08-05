#include "task.h"
#include <iostream>

Task::Task(int id,
     const std::string& name,
     const std::string& description,
     int priority,
     const std::string& deadline): task_id(id),
      name(name), description(description),
       priority(priority), status(Status::Pending), deadline(deadline)
        {}

Task::Task(int id,
     const std::string& name,
      const std::string& description,
      int priority,
      Status status,
      const std::string& deadline): task_id(id),
      name(name), description(description),
      priority(priority),status(status),   deadline(deadline)
       {}

 void Task::displayTask() const{
    std::cout<<" Task ID:"<<task_id<<std::endl;
    std::cout<<" Task Name:"<<name<<std::endl;
    std::cout<<" Task Description:"<<description<<std::endl;
    std::cout<<" Task Priority:"<<priority<<std::endl;
    std::cout<<" Task Status:"<<getStatus()<<std::endl;
    std::cout<<" Task Deadline:"<<deadline<<std::endl;
    std::cout<<std::endl;

 }

   int Task::getTaskId() const{
    return task_id;
 }
 
 void Task::setName(const std::string& name){
    this->name=name;
 }
 void Task::setPriority(int priority){
    this->priority=priority;
 }
 void Task::setDescription(const std::string& description){
    this->description=description;
 }
 void Task::setDeadline(const std::string& deadline){
    this->deadline=deadline;
 }
 void Task::markCompleted(){
    status=Status::Completed;
 }
 // implementing the getter functions for the Task class

 
 
  std::string Task::getName() const{
    return name;
  }
  std::string Task::getDescription() const{
    return description;
  }
  int Task::getPriority() const{
    return priority;
  }
  std::string Task::getStatus() const{
    if(status==Status::Pending){
        return "Pending";
    }
   
        return "Completed";
    
  }
  std::string Task::getDeadline() const{
    return deadline;
  }
