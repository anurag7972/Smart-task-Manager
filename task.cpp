#include "task.h"
Task::Task(int id,
     const string& name,
     const string& description,
     int priority,
     const string& deadline): task_id(id),
      name(name), description(description),
       priority(priority), status(Status::Panding), deadline(deadline)
        {}

Task::Task(int id,
     const string& name,
      const string& description,
      int priority,
      Status status,
      const string& deadline): task_id(id),
      name(name), description(description),
      priority(priority),status(status),   deadline(deadline)
       {}

 void Task::displayTask() const{
    cout<<" Task ID:"<<task_id<<endl;
    cout<<" Task Name:"<<name<<endl;
    cout<<" Task Description:"<<description<<endl;
    cout<<" Task Priority:"<<priority<<endl;
    if(status==Status::Panding){
        cout<<" Task Status: Pending"<<endl;
    }
    else{
        cout<<" Task Status: Completed"<<endl;
    }
    cout<<" Task Deadline:"<<deadline<<endl;
    cout<<endl;

 }

   int Task::getTaskId() const{
    return task_id;
 }
 
 void Task::setName(const string& name){
    this->name=name;
 }
 void Task::setPriority(int priority){
    this->priority=priority;
 }
 void Task::setDescription(const string& description){
    this->description=description;
 }
 void Task::setDeadline(const string& deadline){
    this->deadline=deadline;
 }
 void Task::markCompleted(){
    status=Status::Completed;
 }
 // implementing the getter functions for the Task class

 
 
  string Task::getName() const{
    return name;
  }
  string Task::getDescription() const{
    return description;
  }
  int Task::getPriority() const{
    return priority;
  }
  string Task::getStatus() const{
    if(status==Status::Panding){
        return "Pending";
    }
    else{
        return "Completed";
    }
  }
  string Task::getDeadline() const{
    return deadline;
  }
