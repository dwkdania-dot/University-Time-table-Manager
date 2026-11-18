# University-TIme-table-Manager
This project is a console-based C++ application that stores course schedules, lets users search and update them, displays daily timetables, and automatically detects scheduling conflicts. The data structures and algorithms are chosen so that each core operation is efficient and can be analysed.

## Workflow
| File | Owner | Job |
|---|---|---|
| `Scheduling.cpp` | Hifza | `hasConflict`, `updateClass`, `deleteClass` (`addClass` is already wired up) |
| `Display.cpp` | Aiman | `displayWeek` and the four searches (`displayDay` is a finished example) |
| `FileIO.cpp` | Daniya | `saveToFile`, `loadFromFile` (CSV format is documented in the file) |
| `TEST_CASES.md` | Daniya | fill in the test table + complexity notes for the report |
| `ClassRecord.h`, `Timetable.h`, `Timetable_core.cpp`, `main.cpp` | shared | already finished; **tell the group before changing**, especially function signatures |

## Rules
- Times are stored as minutes since midnight (`09:30` -> 570). Opening hours: 08:00-17:00.
- Room names have no spaces (`CS-Lab-1`), so the CSV stays simple.
- A class is identified by (`courseCode`, `section`, `day`).
- Every file starts with the course boilerplate: `#include <iostream>`, then `//include any header` (our own headers, and `<fstream>` in `FileIO.cpp`), then `using namespace std;`.

## Roadmap
1. Development: add/display/update/delete, conflict check, file I/O, all on one linked list.
2. Enhancement: undo (stack), fast lookup (hash table or BST), sorting, faster conflict detection.
3. Final: testing, complexity analysis, report, demo.


## Why a linked list (for the report)
- The timetable changes all the time (add, update, delete). In a linked list, adding or removing a class
  only changes pointers; an array would have to shift every later element.
- Sorted insertion is natural: walk to the right spot and link the new node in.
- No fixed size: we do not need to guess the maximum number of classes in advance, and no memory is wasted.
- The cost: no direct access by index, so searches and the conflict check scan the list (O(n)).
  For a university timetable (a few hundred classes) this is fast enough, and it is easy to analyse.
