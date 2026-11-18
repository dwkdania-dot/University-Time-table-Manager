# University-TIme-table-Manager
This project is a console-based C++ application that stores course schedules, lets users search and update them, displays daily timetables, and automatically detects scheduling conflicts. The data structures and algorithms are chosen so that each core operation is efficient and can be analysed.

## Who edits which file
| File | Student | To-do |
|---|---|---|
| `Scheduling.cpp` | Hifza | `hasConflict`, `updateClass`, `deleteClass` (`addClass` is already wired up) |
| `Display.cpp` | Aiman | `displayWeek` and the four searches (`displayDay` is a finished example) |
| `FileIO.cpp` | Daniya | `saveToFile`, `loadFromFile` (CSV format is documented in the file) |
| `TEST_CASES.md` | Daniya | fill in the test table + complexity notes for the report |
| `ClassRecord.h`, `Timetable.h`, `Timetable_core.cpp`, `main.cpp` | shared | already finished; **tell the group before changing**, especially function signatures |

One owner per file means you will almost never get merge conflicts on GitHub.
(These roles come from the proposal's contribution table; swap them if yours differ.)

## Rules
- Times are stored as minutes since midnight (`09:30` -> 570). Opening hours: 08:00-17:00.
- Room names have no spaces (`CS-Lab-1`), so the CSV stays simple.
- A class is identified by (`courseCode`, `section`, `day`).
- Stick to C++11 and no `std::stoi`/`std::to_string`-style extras that old Dev-C++ may reject.

## Roadmap
1. Development: add/display/update/delete, conflict check, file I/O.
2. Enhancement: undo (stack), fast lookup (hash table or BST), sorting, faster conflict detection.
3. Final: testing, complexity analysis, report, demo.
