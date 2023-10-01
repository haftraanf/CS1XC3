/**
 * @file course.h
 * @author Khanh Ha Tran (you@domain.com)
 * @brief Create the typedef struct Course and declare the functions that are defined in student.c file
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "student.h"
#include <stdbool.h>
 
/**
  @brief Construct the typedef _course using struct storing a course data: Course name, Course code, List of students, Number of students
*  Consists of functions to enroll the students, print the course information, determine who has the higest average, list out the students who are passing
*/
typedef struct _course 
{
  char name[100]; /**< course name */
  char code[10]; /**< course code */
  Student *students; /**< list of students */
  int total_students; /**< number of students */
} Course;

/**
 * @brief Enrolls a new student to the course by dynamically allocating the memory for storage for new student and append them to the list
 * 
 * @param course 
 * @param student 
 */
void enroll_student(Course *course, Student *student);

/**
 * @brief Prints the members/information about the given course of typedef struct Course 
 * 
 * @param course 
 */
void print_course(Course *course);
/**
 * @brief Determines the student who got highest average mark in the course
 * 
 * @param course 
 * @return Student* 
 */
Student *top_student(Course* course);

/**
 * @brief Determines the students whose average grade is higher than 50%, meaning they pass the course
 * 
 * @param course 
 * @param total_passing 
 * @return Student* 
 */
Student *passing(Course* course, int *total_passing);