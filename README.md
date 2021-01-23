# Student-Grade-Manager-

This is a project that I worked on in C which manages the grades of a certain set of students. The program uses a student structure which is defined in the program to store the students information such as Full Name, Student Number, Course grades and their final mark. Dynamic memory allocation is used to allocate memory for an array of pointers of type student so that each pointer will point to a student. Memory is the dynamically allocated once again for each pointer to point to a student object that will hold all the information of each student in the class. The program contains a function that takes a .txt file as an input which contains the information of the students such as their name and student number and reads this file to store the relevant information to the students strutures members (such as a char array for their name and a int variable for their student number). A similar fucntion also exists for obtaining the students marks from a .txt file. 

The structure definition is located in the student.h file and the main program with all the functions in the Student-Grades-Manager.c file

Additionally, the program also contains the follwoing functions 

int find(int idNo, student **list, int size) - This function takes as input the student ID of a particular student, the dynamically allocated array for the class list and the size of the student set and return 0 if the student is in the set and -1 otherwise

void input_grades(char *filename, student **list, int size) - This function takes as input a .txt file containing the grades of all the students, the dynamically allocated array for the class list and the size of the student set. The file contains the information for each student on a separate line, first the ID number, then the project 1 grade followed by the project 2 grade, all separated by white spaces and is NOT SORTED. The fucntion assigns each student nuber their corresponding project marks. 

void compute_final_course_grades(student **list, int size) - This function computes the final course mark for each student as the arithmetic average of the project 1 and project 2 grades. The function accordingly modifies the information in the class list.


void output_final_course_grades(char *filename, student **list, int size) - This function outputs the final course marks of all the students in a filewhose name is passed to the function, as follows. The first line in the file must contain the total number of students. Each line after that contains an ID number followed by the corresponding grade, separated by white spaces. The data is sorted in increasing order of ID numbers

void withdraw(int idNo, student **list, int *sizePtr) - The parameter list is a pointer to the beginning of the array of pointers representing the class list. Parameter sizePtr is a pointer to the variable in the caller that stores the number of students in the list. This function removes from the class list the student whose ID number equals idNo. If the student is not in the list the function prints a message specifying that. When a student is removed from the class list the vacated spot in the array of pointers is filled by shifting one position to the left all “students” between the vacated position and the end of the array. If a student is removed, the memory allocated for that student object is dealloacted 

void destroy_list(student **list, int *sizePtr) - Parameter list is a pointer to the beginning of the array of pointers representing the class list. Parameter sizePtr is a pointer to the variable in the caller that stores the number of students in the list. This function deallocates all the memory used to store the class list and sets to 0 the variable in the caller that stores its size. 
