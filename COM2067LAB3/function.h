#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

void BubbleSort(struct nodeStudent *studentList);
// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.


void insert (struct nodeClass **classes, int id, int midterm){
	/*CREATING CLASS NODES*/
	int classID = 1;
	struct nodeClass* iterVar;
	if((*classes) == NULL){
		struct nodeClass* classNode;
		(*classes) = (struct nodeClass*)malloc(sizeof(struct nodeClass));
		(*classes) -> classID = classID;
		(*classes) -> studentPtr = NULL;
		(*classes) -> next = NULL;
		iterVar = (*classes);
		while(classID <= 3){
			classNode = (struct nodeClass*)malloc(sizeof(struct nodeClass));
			classNode -> classID = classID + 1;
			classNode -> studentPtr = NULL;
			classNode -> next = NULL;
			iterVar -> next = classNode;
			classID++;
			iterVar = iterVar -> next;
		}
	}
	/*Determining input student's class*/
	if(id < 77000){
		classID = 1;
	}else if(id < 88000){
		classID = 2;
	}else if(id < 99000){
		classID = 3;
	}else{
		classID = 4;
	}

	/*Finding student's class in our linked list*/
	iterVar = (*classes);
	while(iterVar -> classID != classID){
		iterVar = iterVar -> next;
	}
	struct nodeStudent* newStudent;

	if(iterVar -> studentPtr == NULL){
		newStudent = (struct nodeStudent*)malloc(sizeof(struct nodeStudent*));
		newStudent -> midterm = midterm;
		newStudent -> studentID = id;
		newStudent ->next = NULL;
		iterVar -> studentPtr = newStudent;
	}
	else{
		struct nodeStudent* studentIterVar;
		studentIterVar = iterVar -> studentPtr;
		int flag = 1;
		while(studentIterVar -> next != NULL){
			flag = 0;
			studentIterVar = studentIterVar -> next;
		}
		newStudent = (struct nodeStudent*)malloc(sizeof(struct nodeStudent*));
		newStudent -> midterm = midterm;
		newStudent -> studentID = id;
		newStudent ->next = NULL;
		studentIterVar -> next = newStudent;

	}
	
}


void computeClassAverage(struct nodeClass *classList){
	struct nodeClass* classIterVar;
	struct nodeStudent* studentIterVar;
	classIterVar = classList;
	int howManyStudent;
	double gradeSum;

	while(classIterVar != NULL){
		studentIterVar = classIterVar -> studentPtr;
		howManyStudent = 1;
		gradeSum = 0;
		while (studentIterVar != NULL){
			gradeSum = gradeSum + studentIterVar ->midterm;
			howManyStudent++;
			studentIterVar = studentIterVar -> next;
		}
		classIterVar ->classMidtermAverage = gradeSum / (howManyStudent-1);
		classIterVar = classIterVar -> next;
	}
}



void printAll(struct nodeClass *classList){
	struct nodeClass* classIterVar;
	struct nodeStudent* studentIterVar;
	classIterVar = classList;


	while(classIterVar != NULL){
		studentIterVar = classIterVar -> studentPtr;
		printf("%d %.2f\n", classIterVar -> classID, classIterVar -> classMidtermAverage);
		BubbleSort(studentIterVar);
		while(studentIterVar != NULL){
			printf("%d %d\n", studentIterVar -> studentID, studentIterVar -> midterm);
			studentIterVar = studentIterVar -> next;
		}
		classIterVar = classIterVar -> next;
	}
}



void BubbleSort(struct nodeStudent *studentList){
	struct nodeStudent* firstStudent;
	struct nodeStudent* secondStudent;
	struct nodeStudent* listIterVar;
	int tempGrade, tempNumber;
	listIterVar = studentList;

	while(listIterVar -> next != NULL){
		firstStudent = listIterVar;
		struct nodeStudent* secondIter;
		secondIter = listIterVar;
		while(secondIter -> next  != NULL){
			secondStudent = secondIter -> next;
			if(firstStudent ->midterm <= secondStudent -> midterm){
				tempGrade = firstStudent -> midterm;
				tempNumber = firstStudent -> studentID;

				firstStudent -> midterm = secondStudent -> midterm;
				firstStudent -> studentID = secondStudent -> studentID;

				secondStudent -> midterm = tempGrade;
				secondStudent -> studentID = tempNumber;
			}
			secondIter = secondIter -> next;
		}
		listIterVar = listIterVar -> next;
	}

}