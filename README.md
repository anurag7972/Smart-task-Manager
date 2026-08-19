# 🚀 Smart Task Manager

A console-based Task Manager application built in **C++** using **Object-Oriented Programming (OOP)**, **STL**, and **File Handling**.

The project is being developed incrementally to practice real-world C++ software development concepts, STL algorithms, data structures, file handling, input validation, and Git/GitHub workflow.

---

## 📌 Features

### Task Management

- ✅ Add a Task
- ✅ Display All Tasks
- ✅ Update Existing Tasks
- ✅ Delete Tasks
- ✅ Mark Tasks as Completed
- ✅ Prevent Duplicate Task IDs

### Search

- ✅ Search Tasks by ID
- ✅ Search Tasks by Name
- ✅ Partial Name Matching
- ✅ Case-Insensitive Name Search
- ✅ Display Multiple Matching Tasks
- ✅ Whitespace Validation
- ✅ Leading and Trailing Whitespace Trimming

### Sorting

- ✅ Sort Tasks by Priority
- ✅ Sort Tasks by Name
- ✅ Sort Tasks by Deadline
- ✅ Sort Tasks by Status

### File Handling

- ✅ Save Tasks to File
- ✅ Load Tasks from File

### Validation

- ✅ Deadline Format Validation
- ✅ `YYYY-MM-DD` Deadline Format
- ✅ Year Validation
- ✅ Month Validation
- ✅ Day Validation
- ✅ Leap-Year Validation

---

## 🔃 Sorting Options

The Task Manager currently supports four sorting options:

| Sorting Option | Order |
|---|---|
| Priority | Highest → Lowest |
| Name | A → Z |
| Deadline | Earliest → Latest |
| Status | Pending → Completed |

### Priority

Tasks are sorted from the highest priority to the lowest priority.

### Name

Tasks are sorted alphabetically by task name.

### Deadline

Tasks are sorted from the earliest deadline to the latest deadline.

Deadlines use the following format:

YYYY-MM-DD

---

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- File Handling
- Git
- GitHub

---

## 📂 Project Structure

```text
Smart-Task-Manager/
│
├── main.cpp
├── task.h
├── task.cpp
├── taskmanager.h
├── taskmanager.cpp
├── README.md
├── CHANGELOG.md
└── .gitignore

## 🚀 How to Compile

```bash
g++ *.cpp -o taskmanager
./taskmanager
```

---

## 📚 Concepts Practiced

- Classes and Objects
- Encapsulation
- Constructors
- Enum Class
- Vectors
- File Handling
- Functions
- Helper Functions
- String Processing
- Input Validation
- Input Sanitization
- STL Algorithms
- std::find_if()
- std::for_each()
- std::transform()
- std::sort()
- Lambda Expressions
- Custom Comparators
- Iterators
- Code Refactoring
- Git & GitHub

---


## 🔮 Future Improvements

- Filter Tasks
- Statistics Dashboard
- Advanced Task Search
- Task Categories or Tags
- Improved Date Handling
- Better User Interface
- Task Prioritization Improvements

---

## 👨‍💻 Author

**Anurag Singh**

Learning C++ and Data Structures by building real-world projects.