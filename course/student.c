/**
 * @file student.c
 * @author Khanh Ha Tran (you@domain.com)
 * @brief Defines the functions handling the information of students that has the type Student struct.
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief Adds the grade  to a list of students grades
 * 
 * @param student Represents the pointer of the typdef struct Student that points to the dynamic array containing the information of the student
 * @param grade Represents the grade of each student that will get appended to the dynamic array
 */
void add_grade(Student* student, double grade)
{ 
  student->num_grades++; // Increment the number of grades attached to the student
  
  // Check whether the student has any grade before, if none, then set the size of the array to be 1
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else //If they have prior grades, then dynamically reallocate the size of the array so that it can hold all the existing grades
  { 
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }

  //Append the grade to the list
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief Calculates the average of a student
 * 
 * @param student Represents the pointer of the typdef struct Student that points to the dynamic array containing the information of the student
 * @return double The average grade of the student
 */
double average(Student* student)
{
  // Check whether they have any grade, if none, then their average is 0
  if (student->num_grades == 0) return 0;
  
  double total = 0;
  // Sums up the grades by adding all the grades in the list together
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  // Returns the average of the grades by dividing the total by the number of the grades
  return total / ((double) student->num_grades);
}

/**
 * @brief Prints the members/information of the given student
 * 
 * @param student Represents a pointer of the typedef struct Student, pointing to the variable/dynamic array where the information of the student in question is held.
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  // Loop through the array "grades" of the student and print each one out
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief Randomly generates a student with the number of grades provided
 * 
 * @param grades Represents the number of grades a student should have
 * @return Student* Represents a variable/instance of the typedef struct Student containing all the information about the student
 */
Student* generate_random_student(int grades)
{
  // Create first names and last names
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  // Create a typedef struct Student array and allocate its size to be 1
  Student *new_student = calloc(1, sizeof(Student));

  // Assign student's first name and last name with random ones
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  /* Sets student ID to a random series of one digit number 
    ranging from 0-9 and then converts that to a ASCII 
    character, stores that char into the ID character array
  */
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  /* Fill up the array grade of the student with random numbers by 
    randomly generating a double value between 0-75, and then 
    storing that grade  into the 'grades' dynamic array. The loop
    is repeated the number of grades the student have.
  */ 
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  // Return the new random student.
  return new_student;
}