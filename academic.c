// 12S22001 - Winfrey Nainggolan
// 12S22012 - Reinhard Batubara

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) { return NULL; }

float calculate_performance(enum grade_t _grade, unsigned short _credit)
{

    if(_grade == 1) return 0.0;
    else if(_grade == 2) return _credit * 0.0;
    else if(_grade == 3) return _credit * 1.0;
    else if(_grade == 4) return _credit * 2.0;
    else if(_grade == 5) return _credit * 2.5;
    else if(_grade == 6) return _credit * 3.0;
    else if(_grade == 7) return _credit * 3.5;
    else if(_grade == 8) return _credit * 4.0;

    return 0.0;
}

void print_course(struct course_t _course)
{   
    char huruf_course[6];
    char str_a[2] = "A", str_b[2] = "B", str_c[2] = "C",str_d[2] = "D", str_e[2] = "E", str_t[2] = "T", str_ab[3] = "AB", str_bc[3] = "BC", str_none[5] = "None" ;

    char *p_huruf_course = huruf_course;
    if( _course.passing_grade == 0) strcpy(p_huruf_course,str_none);
    else if(_course.passing_grade == 1)  strcpy(p_huruf_course,str_t);
    else if(_course.passing_grade == 2)  strcpy(p_huruf_course, str_e);
    else if(_course.passing_grade == 3)  strcpy(p_huruf_course ,str_d);
    else if(_course.passing_grade == 4)  strcpy(p_huruf_course,str_c);
    else if(_course.passing_grade == 5)  strcpy(p_huruf_course ,str_bc);
    else if(_course.passing_grade == 6)  strcpy(p_huruf_course,str_b);
    else if(_course.passing_grade == 7)  strcpy(p_huruf_course,str_ab);
    else if(_course.passing_grade == 8)  strcpy(p_huruf_course,str_a);
    printf("%s|%s|%d|%s\n", _course.code, _course.name, _course.credit, p_huruf_course);

}

void print_student(struct student_t _student)
{
    printf("%s|%s|%s|%s", _student.id, _student.name, _student.year, _student.study_program);
}

void print_enrollment(struct enrollment_t _enrollment)
{   
    char huruf_student[4];
    char *p_huruf_student = huruf_student;
    if( _enrollment.grade == 0) p_huruf_student = "None";
    else if(_enrollment.grade == 1)  *p_huruf_student = 'T';
    else if(_enrollment.grade == 2)  *p_huruf_student = 'E';
    else if(_enrollment.grade == 3)  *p_huruf_student = 'D';
    else if(_enrollment.grade == 4)  *p_huruf_student = 'C';
    else if(_enrollment.grade == 5)  p_huruf_student = "BC";
    else if(_enrollment.grade == 6)  *p_huruf_student = 'B';
    else if(_enrollment.grade == 7)  p_huruf_student = "AB";
    else if(_enrollment.grade == 8)  *p_huruf_student = 'A';
    else  p_huruf_student = "None";

    printf("\n%s|%s|%s|%.2f", _enrollment.course.code, _enrollment.student.id,p_huruf_student, calculate_performance(_enrollment.grade,_enrollment.course.credit));
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,enum grade_t _passing_grade)
{
    struct course_t crs;
    strcpy(crs.code, _code);
    strcpy (crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;


    return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,char *_study_program)
{
    struct student_t std;
    strcpy(std.id, _id);
    strcpy(std.name,_name);
    strcpy(std.year, _year);
    strcpy(std.study_program, _study_program);

    return std;
}

struct enrollment_t create_enrollment(struct course_t _course,struct student_t _student, char *_year,enum semester_t _semester)
{
    struct enrollment_t emt;

    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year,_year);
    emt.semester = _semester;

    return emt;
}
