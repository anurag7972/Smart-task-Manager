# Changelog

All notable changes to the Smart Task Manager are documented here.

---

## [1.4.0] - 2026-08-20

### Added

- Added Task Statistics menu option.
- Added total task count.
- Added completed task count using `std::count_if()`.
- Added pending task count.
- Added lambda expression for status-based task counting.
- Added high-priority and low-priority task counts.
- Added Task Filtering menu option.
- Added filtering by task status.
- Added filtering by task priority.
- Added filtering for Pending and Completed tasks.
- Added filtering for High-Priority (4–5) and Low-Priority (1–3) tasks.

### Technical

- Used `std::count_if()` with a lambda expression to count completed tasks.
- Used `tasks.size()` to calculate the total number of tasks.
- Calculated pending tasks using total tasks minus completed tasks.
- Used `std::copy_if()` to create filtered task collections.
- Used temporary vectors to store filtered tasks without modifying the original task list.
- Used lambda expressions for status and priority filtering.

## [1.3.0] - 2026-08-11

### Added

- Added task sorting by priority.
- Added task sorting by name.
- Added task sorting by deadline.
- Added task sorting by status.
- Added deadline format validation using `YYYY-MM-DD`.
- Added year validation for deadlines (2026–2030).
- Added month and day range validation.
- Added Search Task menu with search by ID and search by name.
- Added partial matching for task names.
- Added case-insensitive task name searching.
- Added support for displaying multiple tasks matching a search.
- Added whitespace validation for task name search input.
- Added leading and trailing whitespace trimming for task name searches.

### Changed

- Task sorting now supports multiple sorting criteria.
- Tasks are sorted by priority from highest to lowest.
- Tasks are sorted by name alphabetically (A–Z).
- Tasks are sorted by deadline from earliest to latest.
- Tasks are sorted by status with Pending tasks shown before Completed tasks.
- Deadline input is now validated before a task is accepted.
- Deadline storage is standardized using the `YYYY-MM-DD` format.
- Task name search now accepts partial and case-insensitive input.

### Technical

- Used `std::sort()` with lambda comparators for task sorting.
- Used `std::find_if()` for whitespace validation and trimming.
- Used `std::transform()` for case-insensitive task name searching.
- Added a private `isValidDeadline()` helper to `TaskManager`.
- Added iterator-based string processing for search input validation.

--

### Refactoring

- Refactored `searchTask()` to use reusable helper functions.
- Added `trim()` helper function to remove leading and trailing whitespace.
- Added `toLower()` helper function for case-insensitive string conversion.
- Removed duplicated trimming logic from `searchTask()`.
- Removed duplicated lowercase conversion logic from `searchTask()`.
- Improved code reusability and readability.

## [1.2.0] - 2026-08-06

### Refactoring

1. Added `findTaskById()` helper function.
2. Refactored `markTaskCompleted()` to use the helper.
3. Refactored `updateTask()` to use the helper.
4. Refactored `searchTask()` to use the helper.
5. Kept `deleteTask()` unchanged because `std::vector::erase()` works naturally with an index/iterator.
6. Improved code reusability by removing duplicated search logic.



## [1.1.0] - August 2026

### Bug Fixes

1. Fixed the `"Pending"` vs `"pending"` mismatch while loading tasks.
2. Removed the unnecessary `saveToFile()` call from `loadFromFile()`.
3. Added `return` in `saveToFile()` when the file cannot be opened.
4. Replaced `using namespace std;` with explicit `std::` usage.
5. Simplified `displayTask()` by using `getStatus()`.

---

## [1.0.0] - Initial Release

### Features

1. Added Task.
2. Display Tasks.
3. Update Task.
4. Delete Task.
5. Search Task.
6. Mark Task as Completed.
7. Save tasks to a file.
8. Load tasks from a file.