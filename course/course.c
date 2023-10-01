/**
 * @file course.c
 * @author Khanh Ha Tran (you@domain.com)
 * @brief Defines all functions handling the course's infromation
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Enrolls a new student to the course by dynamically allocating the memory for storage for new student and append them to the list
 * 
 * @param course A pointer of the typdef 'Course' pointing to the variable/dynamic array holding information about the overall course 
 * @param student A pointer of the typdef 'Student' pointing to the variable/dynamic array holding all of a student's information 
 */
void enroll_student(Course *course, Student *student)
{
  // Increment the total number of students
  course->total_students++;
  
  // Check whether if there is any students resgistration exist
  if (course->total_students == 1) 
  { // If none, allocate the size to be 1 using calloc
    course->students = calloc(1, sizeof(Student));
  }
  // If there are students registered before, reallocates the memory for new students to store all students
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  // Add the current student to the end of students list
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Prints the members/information about the given course of typedef struct Course 
 * 
 * @param course Represents a pointer of the typdef struct Course which points to the dynamic array consisting of information about the course
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  // Calls the fucntion print_student to print each student's information who are enrolled in the course
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief Determines the student who got highest average mark in the course
 * 
 * @param course Represents a pointer of the typdef struct Course which points to the dynamic array that consists of information about the course
 * @return Student* 
*/
Student* top_student(Course* course)
{
  // Check whether the course has no students, if none, ends function
  if (course->total_students == 0) return NULL;

  double student_average = 0;

  // Sets the max average to the first student in the list
  double max_average = average(&course->students[0]);

  Student *student = &course->students[0];


  for (int i = 1; i < course->total_students; i++)
  {
    // Looping through each student in the course, the student is the new top student if their avergage is higher than the max average
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      // Modify the max average if a higher average is found
      max_average = student_average;
      student = &course->students[i];
    }   
  }
  return student;
}

/**
 * @brief Determines the students whose average grade is higher than 50%, meaning they pass the courses
 * 
 * @param course Represents a pointer of the typdef struct Course which points to the dynamic array consisting of information about the course
 * @param total_passing Represents a pointer of the type int which points to the dynamic array consisting of the total number of students passing the course
 * @return Student* List of students with a passing grade
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  // Calculate the number of students with an average bigger than 50
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  passing = calloc(count, sizeof(Student));

  int j = 0;

  // Adds all passing students to the passing array
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  // Update the pointer to store the number of passed students 
  *total_passing = count;

  // Return the list of students who pass
  return passing;
}