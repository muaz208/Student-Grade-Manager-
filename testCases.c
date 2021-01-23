#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    


    


	void TestQ2_find_notThere(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = -1;
		int actual = find(0011,Clist,size);

		CuAssertIntEquals(tc, expected, actual);

		destroy_list(Clist,&size); //deallocate the memory, this is repeated for all the cases below

	}

	void TestQ2_find_There(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 4;
		int actual = find(9000,Clist,size);

		CuAssertIntEquals(tc, expected, actual);

		destroy_list(Clist,&size);

	}

	void TestQ2_find_There2(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 3;
		int actual = find(7000,Clist,size);

		CuAssertIntEquals(tc, expected, actual);

		destroy_list(Clist,&size);

	}

	void TestQ2_inputGradesAndCalculateFinal(CuTest *tc) {

		

		char inputFile[] =  "students.txt";
		char gradesFile[] =  "grades.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);
		//input grades using the grades input file
		input_grades(gradesFile,Clist,size);
		//calculate final grades
		compute_final_course_grades(Clist,size);
		//Output final course marks
		output_final_course_grades("outputGrades.txt",Clist,size);

		//now we open the golden file with the written file and compare line by line

		char actualFile[] =  "outputGrades.txt";
		char goldenFile[] =  "output.txt";

		char actual[1000], expected[1000];
		int actualID,expectedID;
		double actualFinalGrade,expectedFinalGrade;
		FILE *actualPtr, *expectedPtr;
		if ((actualPtr = fopen(actualFile, "r")) == NULL || (expectedPtr = fopen(goldenFile, "r")) == NULL) {
			printf("Error! opening file");
			// Program exits if file pointer returns NULL.
			exit(1);
		}

		int actualNumStudents,expectedNumStudents;


		fscanf(actualPtr,"%d",&actualNumStudents);
		
		fscanf(expectedPtr,"%d",&expectedNumStudents);
		
		CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

		int i;
		for(i=0;i<expectedNumStudents;i++){
		//while (actualPtr != NULL && expectedPtr!=NULL){
			// reads text until newline is encountered
		/*	fscanf(actualPtr, "%[^\n]", actual);
			printf("%s ", actual);
			fscanf(expectedPtr, "%[^\n]", expected);
			printf("%s\n", expected);

			CuAssertStrEquals(tc, expected, actual);

		*/
			fscanf(actualPtr,"%d",&actualID);
			
			fscanf(expectedPtr,"%d",&expectedID);
			
			CuAssertIntEquals(tc, expectedID, actualID);

			fscanf(actualPtr,"%lf",&actualFinalGrade);
			fscanf(expectedPtr,"%lf",&expectedFinalGrade);
			CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade,0.000001);
		}
		if ((actualPtr == NULL && expectedPtr!=NULL)|| (actualPtr != NULL && expectedPtr==NULL)){

			printf("files are not of equal size");
			// Program exits if file pointer returns NULL.
			exit(1);

		}

		destroy_list(Clist,&size);

	}

	void TestQ2_inputGradesAndCalculateFinalMuaz(CuTest *tc) {



		char inputFile[] =  "students2.txt";
		char gradesFile[] =  "grades2.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);
		//input grades using the grades input file
		input_grades(gradesFile,Clist,size);
		//calculate final grades
		compute_final_course_grades(Clist,size);
		//Output final course marks
		output_final_course_grades("outputGrades2.txt",Clist,size);

		//now we open the golden file with the written file and compare line by line

		char actualFile[] =  "outputGrades2.txt";
		char goldenFile[] =  "output2.txt";

		char actual[1000], expected[1000];
		int actualID,expectedID;
		double actualFinalGrade,expectedFinalGrade;
		FILE *actualPtr, *expectedPtr;
		if ((actualPtr = fopen(actualFile, "r")) == NULL || (expectedPtr = fopen(goldenFile, "r")) == NULL) {
			printf("Error! opening file");
			// Program exits if file pointer returns NULL.
			exit(1);
		}

		int actualNumStudents,expectedNumStudents;


		fscanf(actualPtr,"%d",&actualNumStudents);

		fscanf(expectedPtr,"%d",&expectedNumStudents);

		CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

		int i;
		for(i=0;i<expectedNumStudents;i++){
		//while (actualPtr != NULL && expectedPtr!=NULL){
			// reads text until newline is encountered
		/*	fscanf(actualPtr, "%[^\n]", actual);
			printf("%s ", actual);
			fscanf(expectedPtr, "%[^\n]", expected);
			printf("%s\n", expected);

			CuAssertStrEquals(tc, expected, actual);

		*/
			fscanf(actualPtr,"%d",&actualID);

			fscanf(expectedPtr,"%d",&expectedID);

			CuAssertIntEquals(tc, expectedID, actualID);

			fscanf(actualPtr,"%lf",&actualFinalGrade);
			fscanf(expectedPtr,"%lf",&expectedFinalGrade);
			CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade,0.000001);
		}
		if ((actualPtr == NULL && expectedPtr!=NULL)|| (actualPtr != NULL && expectedPtr==NULL)){

			printf("files are not of equal size");
			// Program exits if file pointer returns NULL.
			exit(1);

		}

		destroy_list(Clist,&size);

	}


	void TestQ2_withdraw(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 4580;
		withdraw(1200,Clist,&size);
		int actual=Clist[0]->student_id;


		CuAssertIntEquals(tc, expected, actual);

		destroy_list(Clist,&size);

	}

	void TestQ2_withdraw2(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 6547;
		withdraw(4580,Clist,&size);
		int actual=Clist[1]->student_id;


		CuAssertIntEquals(tc, expected, actual);

		destroy_list(Clist,&size);

	}

	void TestQ2_withdraw3(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 7000;
		withdraw(9000,Clist,&size);
		int actual=Clist[3]->student_id;


		CuAssertIntEquals(tc, expected, actual);

		destroy_list(Clist,&size);

	}

	void TestQ2_destroy_list(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 0;
		destroy_list(Clist,&size);
		int actual=size;


		CuAssertIntEquals(tc, expected, actual);


	}
 

    
  
//===========================================================
	CuSuite* Lab3GetSuite() {


		SUITE_ADD_TEST(suite, TestQ2_find_notThere);
		SUITE_ADD_TEST(suite, TestQ2_find_There);
		SUITE_ADD_TEST(suite, TestQ2_find_There2);
		SUITE_ADD_TEST(suite, TestQ2_inputGradesAndCalculateFinal);
		SUITE_ADD_TEST(suite, TestQ2_inputGradesAndCalculateFinalMuaz);
		SUITE_ADD_TEST(suite, TestQ2_withdraw);
		SUITE_ADD_TEST(suite, TestQ2_withdraw2);
		SUITE_ADD_TEST(suite, TestQ2_withdraw3);
		SUITE_ADD_TEST(suite, TestQ2_destroy_list);
        
       

		return suite;
	}
    
