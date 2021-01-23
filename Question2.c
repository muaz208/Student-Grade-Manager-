#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"




student **create_class_list(char *filename, int *sizePtr){

	student **class_list;


	int i=0;




	/*write your implementation here*/
	FILE *fpointer=fopen(filename,"r"); // open the given file for reading,a pointer fpointer is used to keep track of the file were reading

	fscanf(fpointer,"%d",sizePtr);//read the first integer which is the number of students we have and put that into the sizePtr variable, we pass in the pointer directly since a pointer is a array to start with

	class_list=calloc(*sizePtr,sizeof(student*)); //allocate memory for the array of pointers, *sizePtr is how many students we have, so we need that times the size of a pointer of type student much memory for the array of pointers

	for (i=0;i<*sizePtr;i++){ //for loop to go through each pointer in the array of pointers
		class_list[i]=calloc(1,sizeof(student));//we need to allocate memory for variable of type student that each pointer points to, hence we need sizeof(student)
		fscanf(fpointer,"%d %s %s",&(class_list[i]->student_id),class_list[i]->first_name,class_list[i]->last_name);//here we are reading the next integer and the first and second strings. We are putting the integer (which is the student number) at the address of the pointer class_list[i] (deref) for the studentid member and we use class_list[i] directly (since it points to the first element) and store it in the member firstname and lastname of the variable of type student this pointer points to

	}

	fclose(fpointer);//close the file

	/* finally return the created class list*/
	return class_list;
}



int find(int idNo, student **list, int size)
{
	
	int i=0;
	int m=-1; //this variable will track if we find the student, initially we assume they are not as set it to -1

	for(i=0;i<size;i++){ //loop to go through every pointer in the array of pointers so we can check each student
		if ((list[i]->student_id)==idNo){ //check to see if the student_id member that the pointer at index i in the array of pointers points to equals the idNo that we are seraching for
			m=i; //if we find a match, set the tracking variable to the index we found it at
		}

	}


	/*write your implementation here and update the return accordingly*/


	return m; //return the tracking variable we used
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/

	int i=0;
	int j=0;
	int n=0;

	FILE *fpointer=fopen(filename,"r"); //open the grade file for reading

	for(i=0;i<size;i++){ //loop to go through each student ID and find where this student is so we can put there grades in there info

		fscanf(fpointer,"%d",&n); //read the first int (The student ID) and put the value of the first ID in variable n (we are dealing with one student at a time and moving to the next)

		for(j=0;j<size;j++){ //loop to go through and see what index the student with the ID in var n is. This way we take care of the fact that the file is not sorted too since it will deal with each ID at a time. This loop has a certain ID and goes through the array of pointers to find the pointer that points to the student with this ID
			if(n==(list[j]->student_id)){ //if the student ID's match, we have found where this student is position wise in the array of pointer and we have their grades (there the next two ints on the same line)
				fscanf(fpointer,"%d %d",&list[j]->project1_grade,&list[j]->project2_grade); //read the next two ints (project 1 and project 2 grades respectivley) and access that students project grades memeber and put the value there
				break; //break out because we found the student, no need to keep checking


			}
		}


	}
	fclose(fpointer); // close the file since we have found every students grades


}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/

	int i=0;


	for(i=0;i<size;i++){ //loop through each student
		(list[i]->final_grade)=((list[i]->project1_grade) + (list[i]->project2_grade))/2.0; //access each pointer and get the project grade members for the student they point to and compute the average of those ints
	}



}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/

	FILE *fpointer=fopen(filename,"w"); //open file for writing, pointer fpointer will keep track of the file were writing to

	fprintf(fpointer,"%d\n",size); //first write into it the value of size which is the number of students we have (we got this value in a previous fuinction)

	int i=0;

	for(i=0;i<size;i++){ //loop to iterate for each student (e.x if we have 5 students, loop 5 times, once for each student)
		fprintf(fpointer,"%d %f\n",(list[i]->student_id),(list[i]->final_grade)); //write onto the line first the student id then a space and then that students final grade (their final grade was determined in another function and stored in the final_grade member for the respectice student)
	}

	fclose(fpointer); //close the file

}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/

	int i=0;
	int j=0;
	int m=0; //index variable
	int flag=1; //a flag to determine if we have found a student or not

	for(i=0;i<*sizePtr;i++){ //loop to go through each individual pointer (that points to a student) in the array
		if((list[i]->student_id)==idNo){//check to see if the given student id matches any of the students

			flag=0; //if we find a match, change or flag to 0 to indicate the student was found

			free(list[i]); //here we free the memory alloacted for the student that is being withdrawn
			list[i]=NULL; //set the pointer that was pointing to that student to NULL so that the pointer isnt pointing to anything RIGHT NOW (this will change). The student is gone at this point


			for(j=i;j<(*sizePtr)-1;j++){ //since we found a match, we need to move the remaining students with larger student numbers ahed (to the position infront of them) since we lost a student and dont want to leave that spot empty (thats just random)
				m=j; //our index variable equals j, which is where we start because the matching student id was found here (e.x at student 2 which is index 1)
				list[m]=list[m+1]; //the pointer that pointed to the student that is now withdrawn, points to the next student (so its like that student moved up) and this repeats for the rest of the students
				m++; //increment our index variable so we can deal with the next student
			}

			list[(*sizePtr)-1]=NULL; //the last element should point to nothing anymore since we removed a student and the remaining students moved up to fill that gap, at the end there will be two pointers pointing to the last student, we set the LAST student pointer in the array of pointers to NULL (point to nothing since memory for the removed student is gone and every other student moved up to fill the gap)
			break; //break out because we found the student
		}

	}

	if(flag==1){ // this is for the case a id is entered for a student not there, our flag will have not changed and if it is still 1, then we inform the user the student is not there
		//printf("The Student Could Not Be Found\n");    //Prof said not to include printf statments for submission so i just added it in comments
	}
	//list[(*sizePtr)-1]=0;




}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	int i=0;

	for(i=0;i<*sizePtr;i++){// go through each pointer (that points to a student)
		free(list[i]); //free that pointer
		list[i]=NULL; //set that pointer equal to null
	}
	free(list); //free the array of pointers
	*sizePtr=0; //set the size variable to 0
}
