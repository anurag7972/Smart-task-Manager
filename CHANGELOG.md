# Changelog

All notable changes to the Smart Task Manager are documented here.

---

## Version 1.2 (August 2026)

### Refactoring
1. Added `findTaskById()` helper function.
2. Refactored `markTaskCompleted()` to use the helper.
3. Refactored `updateTask()` to use the helper.
4. Refactored `searchTask()` to use the helper.
5. Kept `deleteTask()` unchanged because `std::vector::erase()` works naturally with an index/iterator.
6. Improved code reusability by removing duplicated search logic.

---

## Version 1.1 (August 2026)

### Bug Fixes
1. Fixed the `"Pending"` vs `"pending"` mismatch while loading tasks.
2. Removed the unnecessary `saveToFile()` call from `loadFromFile()`.
3. Added `return` in `saveToFile()` when the file cannot be opened.
4. Replaced `using namespace std;` with explicit `std::` usage.
5. Simplified `displayTask()` by using `getStatus()`.

---

## Version 1.0 (Initial Release)

### Features
1. Added Task.
2. Display Tasks.
3. Update Task.
4. Delete Task.
5. Search Task.
6. Mark Task as Completed.
7. Save tasks to a file.
8. Load tasks from a file.