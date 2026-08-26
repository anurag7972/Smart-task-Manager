#include "taskmanager.h"
#include <iostream>
#include <limits>
int main(){
    TaskManager tm;
    tm.loadFromFile();
    int choice;
    do{
        std::cout<<"\n================================\n";
        std::cout<<"********* Task Manager *********\n";
        std::cout<<"================================\n";
        std::cout<<"1. Add Task"<<std::endl;
        std::cout<<"2. Display Tasks"<<std::endl;
        std::cout<<"3. Update Task"<<std::endl;
        std::cout<<"4. Mark Task Completed"<<std::endl;
        std::cout<<"5. Search Task"<<std::endl;
        std::cout<<"6. Delete Task"<<std::endl;
        std::cout<<"7. Sort Task"<<std::endl;
        std::cout<<"8. Display Statistics"<<std::endl;
        std::cout<<"9. Filter Tasks"<<std::endl;
        std::cout<<"10. Exit"<<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cout<<"Invalid choice. Please enter a number.\n";
             continue;
        }

        switch(choice){
            case 1:
                tm.addTask();
                tm.saveToFile();
                break;
            case 2:
                tm.displayTasks();
                break;
            case 3:
                tm.updateTask();
                tm.saveToFile();
                break;
            case 4:
                tm.markTaskCompleted();
                tm.saveToFile();
                break;
            case 5:
                tm.searchTask();
                break;
            case 6:
                tm.deleteTask();
                tm.saveToFile();
                break;
            case 7:
                tm.sortTask();
                tm.displayTasks();
                break;
            case 8:
                 tm.displayStatistics();
                break;
            case 9:
                tm.filterTasks();
                break;
            case 10:
                std::cout<<"Exiting...";
                break;
            default:
                std::cout<<"invalid choice";
        }
    }
    while (choice!=10);
    
    return 0;
    
}