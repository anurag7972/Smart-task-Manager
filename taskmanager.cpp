#include "taskmanager.h"
#include <iostream>

bool TaskManager::isTaskExists(int id){
    for (const auto &t: tasks){
     
        if(t.getTaskId()==id){
            return true;
        }

    }
    return false;
 
}

void TaskManager::addTask(){
   
    int task_id;
    std::string name;
    std::string description;
    int priority;
    std::string deadline;
   

    std::cout<<" Enter the task id: ";
    std::cin>>task_id;
            while(isTaskExists(task_id)){
        std::cout<<"The task ID is already here \n\n";
        std::cout<<"Please enter the another task id:";
        std::cin>>task_id;
     }
    std::cin.ignore();
    std::cout<<" Enter the task name: ";
    std::getline(std::cin, name);
    std::cout<<" Enter the task description: ";
    std::getline(std::cin, description);
    std::cout<<" Enter the task priority(1-5): ";
    std::cin>>priority;
     while(priority<1 || priority>5){
         std::cout<<"invalid priority\n";
         std::cin>>priority;
     }
    std::cout<<" Enter the task deadline: ";
    std::cin.ignore();
    std::getline(std::cin, deadline);
        Task newTask(task_id, name, description, priority, deadline);
        tasks.push_back(newTask);
        std::cout<<" Task added successfully! "<<std::endl;
        std::cout<<" total tasks= "<<tasks.size()<<std::endl;
}

void TaskManager::displayTasks() const{
    if(tasks.empty()){
        std::cout<<"\nno task available\n";
    }
    else{
        for (const auto &t : tasks)
        {
            t.displayTask();
        }
        
    }

}
  // implement the heper function to find the task by id and return a pointer to the task object
  Task* TaskManager::findTaskById(int id){

    for( auto &t: tasks){
         if(t.getTaskId()==id){
            return &t;
         }
    }
    return nullptr;
  }
 
  // implement the update task function using the helper function to find the task by id and update its attributes  
void TaskManager::updateTask(){
   
        int id;
        std::cout<<" Enter the task id to update: ";
        std::cin>>id;

        Task* task= findTaskById(id);
        if(task==nullptr){
            std::cout<<" Task not  Found! "<<std::endl;
            return;
        }
        
       
        std::string name;        //  declare to its own local variable 
         std::string description;  //to avoid confusion with the member variables of the Task class
         int priority;
         std::string deadline;

      
             std::cout<<" Enter the new task name: ";
             std::cin.ignore();
             std::getline(std::cin, name);
             std::cout<<" Enter the new task description: ";
             std::getline(std::cin, description);
             std::cout<<" Enter the new task priority(1-5): ";
             std::cin>>priority;
              while(priority<1 || priority>5){
                  std::cout<<"invalid priority\n";
                  std::cin>>priority;
              }
             std::cout<<" Enter the new task deadline: ";
             std::cin.ignore();
             std::getline(std::cin, deadline);

             task->setName(name);
             task->setDescription(description);
             task->setPriority(priority);
             task->setDeadline(deadline);
             
                std::cout<<" Task updated successfully! "<<std::endl;
                return;
            
        
       
     }


// implementing the mark Task as completed function  using helper function 

 void TaskManager::markTaskCompleted(){

      
       int id;
       std::cout << "Enter the task ID to mark as completed: ";
       std::cin >> id;
        Task* t = findTaskById(id);
     
      if(t == nullptr){

        std::cout<<" No Task Found.\n";
        return;
      }
        t->markCompleted();
        std::cout<<" Task marked as completed successfully! "<<std::endl;
 }

    // implement the search engieen for searching the task

    void TaskManager::searchTask(){
       
        int id;
        std::cout<<"Enter the Task id for search..:";
        std::cin>>id;
        Task* task= findTaskById(id);
       if(task==nullptr){
          std::cout<<"Task not found\n";
          return;
       }

        task->displayTask();
        
        
    }

    void TaskManager::deleteTask(){

        if(tasks.empty()){

            std::cout<<"No Task available ..\n";
            return ;
        }

        int id;
        std::cout<<"Enter the task ID:";
        std::cin>>id;
        for(size_t i=0;i<tasks.size(); i++){
            
            if(tasks[i].getTaskId()==id){
                 tasks.erase(tasks.begin()+i);
                    std::cout<<"Task deleted successfully\n";
                    return;
            }
        }
        std::cout<<"Task not found\n";
    }
 
   void TaskManager::saveToFile(){

      std::ofstream outfile("tasks.txt");
      if(!outfile){
         std::cout<<" cannot open file \n";
         return;
        }
        else{
            std::cout<<"the file open successfuly.\n";
        }
       for(const auto &t : tasks ){
        outfile<<t.getTaskId()<<"|"<<t.getName()<<"|"<<t.getDescription()<<"|"<<t.getPriority()<<"|"<<t.getStatus()<<"|"<<t.getDeadline()<<"\n";
         std::cout<<"total task"<<tasks.size()<<std::endl;

       }
       outfile.close();
   }

   void TaskManager::loadFromFile(){
    std::ifstream  readFile("tasks.txt");
    if(!readFile){

        std::cout<<"file not open.\n";
        return;
    }
       std::string line;
      while(std::getline(readFile,line)){
        std::stringstream ss(line);
        std::string id;
        std::string name;
        std::string description;
        std::string priority;
        std::string status;
        std::string deadline;

        std::getline(ss, id, '|');
        std::getline(ss, name, '|');
        std::getline(ss, description, '|');
        std::getline(ss, priority, '|');
        std::getline(ss, status, '|');
        std::getline(ss, deadline);
        
        std::cout << "id = [" << id << "]\n";
        std::cout << "priority = [" << priority << "]\n";
        int taskId= stoi(id);
        int taskpriority=stoi(priority);

        Task::Status taskStatus;
        if(status=="Pending"){
            taskStatus= Task::Status::Pending;           
        }else{
            taskStatus=Task::Status::Completed;
        }
         Task newtask( taskId,
                 name,
                description,
                taskpriority,
                taskStatus,
                deadline);
                tasks.push_back(newtask);
               
      }

     
      
       
   
}
 