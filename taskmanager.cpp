#include "taskmanager.h"

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
   

    cout<<" Enter the task id: ";
    cin>>task_id;
            while(isTaskExists(task_id)){
        cout<<"The task ID is already here \n\n";
        cout<<"Please enter the another task id:";
        cin>>task_id;
     }
    cin.ignore();
    cout<<" Enter the task name: ";
    getline(cin, name);
    cout<<" Enter the task description: ";
    getline(cin, description);
    cout<<" Enter the task priority(1-5): ";
    cin>>priority;
     while(priority<1 || priority>5){
         cout<<"invalid priority\n";
         cin>>priority;
     }
    cout<<" Enter the task deadline: ";
    cin.ignore();
    getline(cin, deadline);
        Task newTask(task_id, name, description, priority, deadline);
        tasks.push_back(newTask);
        cout<<" Task added successfully! "<<endl;
        cout<<" total tasks= "<<tasks.size()<<endl;
}

void TaskManager::displayTasks() const{
    if(tasks.empty()){
        cout<<"\nno task available\n";
    }
    else{
        for (const auto &t : tasks)
        {
            t.displayTask();
        }
        
    }

}
 
void TaskManager::updateTask(){
    if(tasks.empty()){
        cout<<"\n no task available\n";
        return;
    }
    else{
        int id;
        cout<<" Enter the task id to update: ";
        cin>>id;
        
       
        std::string name;        //  declare to its own local variable 
         std::string description;  //to avoid confusion with the member variables of the Task class
         int priority;
         std::string deadline;

        for(auto &t : tasks){
            if(t.getTaskId()==id){
             cout<<" Enter the new task name: ";
             cin.ignore();
             getline(cin, name);
             cout<<" Enter the new task description: ";
             getline(cin, description);
             cout<<" Enter the new task priority(1-5): ";
             cin>>priority;
              while(priority<1 || priority>5){
                  cout<<"invalid priority\n";
                  cin>>priority;
              }
             cout<<" Enter the new task deadline: ";
             cin.ignore();
             getline(cin, deadline);

             t.setName(name);
             t.setDescription(description);
             t.setPriority(priority);
             t.setDeadline(deadline);
              
                cout<<" Task updated successfully! "<<endl;
                return;
            }
        }
        cout<<" Task not found! "<<endl;
    }
}

// implementing the mark Task as completed function 

 void TaskManager::markTaskCompleted(){
    if(tasks.empty()){  // looking if task is empty or not
        cout<<"\n No task available:\n";
        return;
    }
    
        int id;
        cout<<"Enter the task id for marking completed\n";
        cin>>id;

        for (auto &t : tasks)
        {
            if(t.getTaskId()==id){  // matching the entered id with task id
                t.markCompleted();
                cout<<"the task successfuly marked as completed\n";
                return;
            }
        }
        cout<<"Task not found\n";
        
    }

    // implement the search engieen for searching the task

    void TaskManager::searchTask(){
        if (tasks.empty())
        {
            cout<< "no task avialable>\n ";
            return ;
        }
        int id;
        cout<<"Enter the Task id for search..:";
        cin>>id;
        for (const auto &t : tasks)
        {
            if(t.getTaskId()==id){
                t.displayTask();
                return;
            }
        }
        cout<<"\nTask not found\n";
        
    }

    void TaskManager::deleteTask(){

        if(tasks.empty()){

            cout<<"No Task available ..\n";
            return ;
        }

        int id;
        cout<<"Enter the task ID:";
        cin>>id;
        for(size_t i=0;i<tasks.size(); i++){
            
            if(tasks[i].getTaskId()==id){
                 tasks.erase(tasks.begin()+i);
                    cout<<"Task deleted successfully\n";
                    return;
            }
        }
        cout<<"Task not found\n";
    }
 
   void TaskManager::saveToFile(){

      ofstream outfile("tasks.txt");
      if(!outfile){
         cout<<" cannot open file \n";
        }
        else{
            cout<<"the file open successfuly.\n";
        }
       for(const auto &t : tasks ){
        outfile<<t.getTaskId()<<"|"<<t.getName()<<"|"<<t.getDescription()<<"|"<<t.getPriority()<<"|"<<t.getStatus()<<"|"<<t.getDeadline()<<"\n";
         cout<<"total task"<<tasks.size()<<endl;

       }
       outfile.close();
   }

   void TaskManager::loadFromFile(){
    ifstream  readFile("tasks.txt");
    if(!readFile){

        cout<<"file not open.\n";
        return;
    }
       string line;
      while(getline(readFile,line)){
        stringstream ss(line);
        string id;
        string name;
        string description;
        string priority;
        string status;
        string deadline;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, description, '|');
        getline(ss, priority, '|');
        getline(ss, status, '|');
        getline(ss, deadline);
        
        cout << "id = [" << id << "]\n";
        cout << "priority = [" << priority << "]\n";
        int taskId= stoi(id);
        int taskpriority=stoi(priority);

        Task::Status taskStatus;
        if(status=="panding"){
            taskStatus= Task::Status::Panding;           
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
                saveToFile();
      }

     
      
       
   
}
 