/*
 * evil.cpp
 * CS15 —— Lab 03: make, diff
 * 
 * This class is a representation of a course roster. Clients can "do evil" on 
 * a roster by changing the grades of the students on the roster.
 * 
 * NOTE: keep this class away from malicious professors!
 *
 */

#ifndef ROSTER
#define ROSTER

#include <string>

#include "Student.h"

class Roster
{
public:
        Roster();
        ~Roster();
        void do_evil(std::string filename);

private:
        Student *list;
        int      capacity;
        int      size;

        void read_file(std::string filename);
        void write_out(std::string filename);
        void change_grades();
        void add_student(std::string name, int grade);
        void expand();
};

#endif
