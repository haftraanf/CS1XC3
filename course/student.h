/**
 * @file student.h
 * @author Khanh Ha Tran (you@domain.com)
 * @brief Create the typedef struct Student and declare the functions that are defined in student.c file
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Construct the typedef _student using struct storing a student data: First name, Last name, ID, Array of grades, Number of grades
 *  Consists of functions to add the student's grades, determine the student's grade average, displays the student's information, and generate a random student. 
 */

typedef struct _student 
{ 
  char first_name[50]; /**< students first name */
  char last_name[50]; /**< students last name */
  char id[11]; /**< student ID */
  double *grades; /**< list of student's grades */
  int num_grades; /**< number of grades */
} Student;

/**
 * @brief Adds the grade  to a list of students grades
 * 
 * @param student 
 * @param grade 
 */
void add_grade(Student *student, double grade);

/**
 * @brief Calculates the average of a student
 * 
 * @param student 
 * @return double 
 */
double average(Student *student);

/**
 * @brief Prints the members/information of the given student
 * 
 * @param student 
 */
void print_student(Student *student);

/**
 * @brief Randomly generates a student with the number of grades provided
 * 
 * @param grades 
 * @return Student* 
 */
Student* generate_random_student(int grades); 