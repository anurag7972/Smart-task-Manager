#ifndef task_h
#define task_h
#include <iostream>
#include <string>
using namespace std;


 class Task{
      public:
       enum class Status { Panding, Completed };
      
    private:
    int task_id ;
    string name;
    string description;
    int priority;
   
     Status status;
     string deadline;
     
    public:
      
      Task(int id,
           const string& name,
           const string& description,
           int priority,
           const string& deadline);
           // second constructor to initialize all attributes including status
     Task(
          int id,
           const string& name,
          const string& description,
          int priority,
          Status status,
          const string& deadline
          );
     
      void displayTask() const;
      // the geeter function for the all 
      int getTaskId() const;  
       
       string getName() const;
       string getDescription() const;
       int getPriority() const;
       string getStatus() const;
       string getDeadline() const;
      void setName(const string& name);
      void setDescription(const string& description);
      void setPriority(int priority);
      void setDeadline(const string& deadline);
      
   
       void markCompleted();

      
     

    
 };
  #endif
