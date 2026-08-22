#include "taskmanager.h"
#include <iostream>
#include <cctype>
#include <algorithm>


bool TaskManager::isTaskExists(int id){
    for (const auto &t: tasks){
     
        if(t.getTaskId()==id){
            return true;
        }

    }
    return false;
}

bool TaskManager::isValidDeadline(const std::string& deadline){
     
   
    
    if(deadline.length()!=10){
        return false;
    }
    for(int i=0; i<10; i++){
        
        if(i==4 || i==7){

            if(deadline[i]!='-'){
                return false;
            }
        }
        else{
            if(!isdigit(deadline[i])){
                return false;
            }
        }
        
    }

         std:: string year=deadline.substr(0,4 );
         std::string month=deadline.substr(5,2);
         std::string day=deadline.substr(8,2);

          int dateyear=std::stoi(year);
          int datemonth=std::stoi(month);
          int dateday=std::stoi(day);
        // date validatation will go here 
         if (dateyear < 2026 || dateyear > 2030 ||
             datemonth < 1 || datemonth > 12 ||
              dateday < 1 || dateday > 31)
            {
                 return false;
            }
            
            int maxday; // maximum number of days in the given month
           if (datemonth == 2)
        {
             if ((dateyear % 400 == 0) ||
        (dateyear % 4 == 0 && dateyear % 100 != 0))
         {
        maxday = 29;
         }
        else
        {
        maxday = 28;
        }
    
           }
           else if (datemonth==4 || datemonth==6 ||datemonth==9|| datemonth==11)
           {
            maxday=30;
           }
           else
           {
                maxday=31;
           }

           if(dateday>maxday){
            return false;
           }
           
          return true;
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
    std::cout<<" Enter the task deadline (YYYY-MM-DD): ";
    std::cin.ignore();
    std::getline(std::cin, deadline);
    while(!isValidDeadline(deadline)){
        std::cout<<"Invalid deadline format. Please enter in YYYY-MM-DD format: ";
        std::getline(std::cin, deadline);
    }
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
       
        int choice;
        std::cout<<"=*=*=*=*=Search Task=*=*=*=*=*=\n";
        std::cout<<"1. Search by ID\n";
        std::cout<<"2. Search by Name\n";
        std::cout<<"3. Back to Main Menu\n";
        std::cout<<"Enter your choice: ";
        std::cin>>choice;

         switch(choice){

            case 1:
            {
                int id;
                std::cout<<"Enter the Task id for search..:";
                std::cin>>id;
                std::cout<<"Searching for Task with ID: "<<id<<std::endl;
                Task* task= findTaskById(id);
                if(task==nullptr){
                std::cout<<"Task not found\n";
               return;
                }
                task->displayTask();
            }
        
           break;
           
            case 2:
            {
                 std::string searchName;
                 bool found=false;
                 std::cout<<"Enter the Task name for search..:";
                 std::cin.ignore();
                 std::cout<<std::endl;
                 std::getline(std::cin,searchName);
                // Remove leading and trailing whitespace from the search name
                  searchName=trim(searchName);

                 // implementing the input validation for white space
                  
                while(searchName.empty()){
                    std::cout<<"Invalid input: please enter the valid input..\n";
                    std::getline(std::cin,searchName);
                    searchName=trim(searchName);
                }
                 
                 


                 
                // Convert the search name to lowercase for case-insensitive comparison
                 std::string serchNamelower= toLower( searchName);

                 
                 std::for_each(tasks.begin(),tasks.end(),[&](const Task& task){
                    std::string taskName=toLower(task.getName());
                    if(taskName.find(serchNamelower) != std::string::npos){
                        task.displayTask();
                        found=true;
                    }

                 });
                 
                 if(!found){
                     std::cout<<"Task for the name <-"<<searchName<<"-> not found\n";
                 }
                 break;
                }
           
            case 3:
                return;
        }
        
    }


  std::string TaskManager::trim(const std::string& text){
     
       std::string result= text;

       result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char c) {
                    return !std::isspace(c);
                 }));

        result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char c) {
                    return !std::isspace(c);
                    }).base(), result.end());

            return result;
      
  }

    std::string TaskManager::toLower(const std::string& text){
     
             std::string NameLower = text;

             std::transform(NameLower.begin(), NameLower.end(), NameLower.begin(),
                    [](unsigned char c){ return std::tolower(c); });
 
            return NameLower;
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

    void TaskManager::sortTask(){

        int choice;
        std::cout<<"================================\n";
        std::cout<<"********* Sort Task *********\n";
        std::cout<<"================================\n";
        std::cout<<"1. Sort by Priority"<<std::endl;
        std::cout<<"2. Sort by Name"<<std::endl;
        std::cout<<"3. Sort by Deadline"<<std::endl;
        std::cout<<"4. Sort by Status"<<std::endl;
        std::cout<<"5. Back to Main Menu"<<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;

        switch(choice){

            case 1:
                {

                    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                        return a.getPriority() > b.getPriority();
                    });
                    std:: cout<<"Tasks sorted by priority successfully!\n\n";
                }
             break;

            case 2:
                {
                    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                        return a.getName() < b.getName();
                    });
                    std::cout<<"Tasks sorted by name successfully!\n\n";
                }

                break;
            case 3:
            {
                std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                        return a.getDeadline() < b.getDeadline();
                    });
                    std::cout<<"Tasks sorted by deadline successfully!\n\n";
            }
                break;
            
                
            case 4:
                {
                     std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                        return a.getStatus() >  b.getStatus();
                              
                    });
                    std::cout<<"Tasks sorted by status successfully!\n\n";
                }
            
                break;
            case 5:

                return;
            default:
                std::cout<<"invalid choice\n";
        }
    }
       
    void TaskManager::displayStatistics(){

       int completedTasks = std::count_if(tasks.begin(), tasks.end(), [](const Task& task){
         
            return task.getStatus() =="Completed";
       });

       int totalTasks = tasks.size();
       int pendingTasks =totalTasks - completedTasks;
       std::cout<<"=*=*=*=*= Task Statistics =*=*=*=*=\n";
       std::cout<<"Total Tasks: "<<totalTasks<<std::endl;   
       std::cout<<"Completed Tasks: "<<completedTasks<<std::endl;
       std::cout<<"Pending Tasks: "<<pendingTasks<<std::endl;

       int highPriorityTasks = std::count_if(tasks.begin(), tasks.end(), [](const Task& task){
              if(task.getPriority() >=4){
                return true; 
              }
                return false;
            });
       int lowpriorityTasks = totalTasks -highPriorityTasks;
       std::cout<<"High Priority Tasks: "<<highPriorityTasks<<std::endl;
       std::cout<<"Low Priority Tasks: "<<lowpriorityTasks<<std::endl;
    }

    void TaskManager::filterTasks(){

        int choice;
        std::cout<<"=*=*=*=*= Filter Tasks =*=*=*=*=\n";
        std::cout<<"1. Filter by Status\n";
        std::cout<<"2. Filter by Priority\n";
        std::cout<<"3. Back to menu\n";
        std::cout<<" Enter your choice: \n";
        std::cin>>choice;

        switch (choice)
        {
        case 1:
            {
               std::string status;
               std::cout<<"Enter the status to filter (Pending/Completed): "; 
               std::cin>>status;

               std::vector<Task> filteredTasks;
               
               std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(filteredTasks), [&]
                  (const Task& t){
                     return t.getStatus()== status;    
             });
               if(filteredTasks.empty()){
                 std::cout<<"NO task found:\n";
               }else{
                for (const auto &task : filteredTasks)
                {
                    task.displayTask();
                }
            }
                

            }
            break;
        case 2 :
        {
           int priorityChoice;

            std::cout << "1. High Priority (4-5)\n";
            std::cout << "2. Low Priority (1-3)\n";
            std::cout << "Enter your choice: ";
            std::cin >> priorityChoice;
            
             std::vector<Task> filteredTasks;


            if(priorityChoice==1){
                std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(filteredTasks), [&]
                  (const Task& t){
                     return t.getPriority()>=4;
            });
        }else if (priorityChoice==2)
        {
           std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(filteredTasks), []
                  (const Task& t){
                     return t.getPriority()<4;
            });
        }else{
             std::cout<<"invlid choice: please enter 1 and 2:\n";
              break;
        }
        if(filteredTasks.empty()){
            std::cout<<"Task not  found:\n";
        }
          for (const auto &task : filteredTasks)
          {
            task.displayTask();
          }
        
         
        
         break;
        }
        case 3:
              
        return;
        default:
         std::cout<<"Invalid choice: please Enter the Valid choice\n";
            break;
        }
      
    }