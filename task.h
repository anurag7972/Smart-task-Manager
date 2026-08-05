#ifndef TASK_H
#define TASK_H

#include <string>



 class Task{
      public:
       enum class Status { Pending, Completed };
      
    private:
    int task_id ;
    std::string name;
    std::string description;
    int priority;
   
     Status status;
     std::string deadline;
     
    public:
      
      Task(int id,
           const std::string& name,
           const std::string& description,
           int priority,
           const std::string& deadline);
           // second constructor to initialize all attributes including status
     Task(
          int id,
           const std::string& name,
          const std::string& description,
          int priority,
          Status status,
          const std::string& deadline
          );
     
      void displayTask() const;
      // the geeter function for the all 
      int getTaskId() const;  
       
       std::string getName() const;
       std::string getDescription() const;
       int getPriority() const;
       std::string getStatus() const;
       std::string getDeadline() const;
      void setName(const std::string& name);
      void setDescription(const std::string& description);
      void setPriority(int priority);
      void setDeadline(const std::string& deadline);
      
   
       void markCompleted();

      
     

    
 };
  #endif
