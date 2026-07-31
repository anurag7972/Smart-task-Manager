#include "taskmanager.h"
int main(){
    TaskManager tm;
    tm.loadFromFile();
    int choice;
    do{
        cout<<"\n================================\n";
        cout<<"********* Task Manager *********\n";
        cout<<"================================\n";
        cout<<"1. Add Task"<<endl;
        cout<<"2. Display Tasks"<<endl;
        cout<<"3. Update Task"<<endl;
        cout<<"4. Mark Task Completed"<<endl;
        cout<<"5. Search Task"<<endl;
        cout<<"6. Delete Task"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

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
                cout<<"Exiting...";
                break;
            default:
                cout<<"invalid choice";
        }
    }
    while (choice!=7);
    
    return 0;
    
}