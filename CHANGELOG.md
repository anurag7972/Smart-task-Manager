# Changelog

All notable changes to the Smart Task Manager are documented here.

---


## [1.3.0] - 2026-08-10

### Added
- Added task sorting by priority.
- Added task sorting by name.
- Added task sorting by deadline.
- Added task sorting by status.
- Added deadline format validation using `YYYY-MM-DD`.
- Added year validation for deadlines (2026–2030).
- Added month and day validation.
- Added days-per-month validation.
- Added leap-year validation for February deadlines.

### Changed
- Task sorting now supports multiple sorting criteria.
- Deadline input is now validated before a task is accepted.
- Tasks are sorted by priority from highest to lowest.
- Tasks are sorted by name alphabetically (A–Z).
- Tasks are sorted by deadline from earliest to latest.
- Tasks are sorted by status with Pending tasks shown before Completed tasks.

### Technical
- Used `std::sort()` with lambda comparators for task sorting.
- Added a private `isValidDeadline()` helper to `TaskManager`.
- Standardized deadline storage as `YYYY-MM-DD`.

## Version 1.2 (August 2026) 2026-08-06

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