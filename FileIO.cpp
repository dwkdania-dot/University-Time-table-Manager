#include <iostream>
#include <fstream>
#include "Timetable.h"
using namespace std;
bool Timetable::saveToFile(const string& filename) const {
    ofstream out(filename.c_str());
    if (!out.is_open()) return false;

    Node* cur = head;
    while (cur != NULL) {
        const ClassRecord& r = cur->data;
        out << r.courseCode << ','
            << r.courseName << ','
            << r.teacher    << ','
            << r.room       << ','
            << r.section    << ','
            << DAY_NAMES[r.day]       << ','
            << formatTime(r.startMin) << ','
            << formatTime(r.endMin)   << '\n';
        cur = cur->next;
    }
    out.close();
    return true;
}
bool Timetable::loadFromFile(const string& filename) {
    ifstream in(filename.c_str());
    if (!in.is_open()) return false;

    clearAll(); 

    string line;
    int lineNo = 0, loaded = 0, skipped = 0;

    while (getline(in, line)) {
        lineNo++;

        if (line.length() == 0 || line == "\r") continue;  
        string f[8];
        int fieldCount = 0;
        string current = "";
        for (int i = 0; i < (int)line.length(); i++) {
            if (line[i] == ',') {
                if (fieldCount < 8) f[fieldCount] = current;
                fieldCount++;
                current = "";
            } else if (line[i] != '\r') { 
                current += line[i];
            }
        }
        if (fieldCount < 8) f[fieldCount] = current; 
        fieldCount++;

        if (fieldCount != 8) {
            cout << "Line " << lineNo << " skipped: expected 8 fields, found " << fieldCount << ".\n";
            skipped++;
            continue;
        }

        ClassRecord r;
        r.courseCode = f[0];
        r.courseName = f[1];
        r.teacher    = f[2];
        r.room       = f[3];
        r.section    = f[4];
        r.day        = parseDay(f[5]);
        r.startMin   = parseTime(f[6]);
        r.endMin     = parseTime(f[7]);

        string err;
        if (addClass(r, err)) {
            loaded++;
        } else {
            cout << "Line " << lineNo << " skipped: " << err << "\n";
            skipped++;
        }
    }

    in.close();
    cout << "File read: " << loaded << " classes loaded, " << skipped << " lines skipped.\n";
    return true;
}
