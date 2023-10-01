/**
 * @file main.c
 * @author Khanh Ha Tran (you@domain.com)
 * @brief Demonstrates creating courses with students.
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief Creates a course named MATH101, adds randomly generated 20 student, 
 * finds the top student and passing students and then print them out using the 
 * helper functions located the files of 'student.c' and 'course.c'
 *
 * @return int 
 */
int main ()
{  // Integer value to be used as a seed for a random number generator. 
  srand((unsigned) time(NULL));

  // Create course struct for MATH101 
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  // Randomly generates 20 students to be enrolled into the MATH101 course 
  for (int i = 0; i < 20; i++) 
    // Generates each student to have 8 grades
    enroll_student(MATH101, generate_random_student(8));
  
  // Print MATH101 course information
  print_course(MATH101);

  // Get the student with highest average in Math101 and print it
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  // Get the number of students passing and loops through the passing list to print information about each student
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}