#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct student {
	int id;
	char name[50];
	float grade;
};

void displayMenu() {
	printf("\n1. Add Student\n");
	printf("2. Display All students\n");
	printf("3. Exit\n");
	
	return;
}

void addStudent(struct student students[], int *count) {
	if(*count < MAX_STUDENTS) {
		printf("Enter student Name:");
		scanf("%s", students[*count].name);
		printf("Enter student Id:");
		scanf("%d", &students[*count].id);
		printf("Enter student Grade:");
		scanf("%f", &students[*count].grade);
		(*count)++;
		printf("Student added successfully.\n");
	}
	else{
		printf("Student database is full.\n");
	}
}

void displayStudents(struct student students[], int count) {
	if(count > 0) {
		printf("\nStudent Database:\n");
		int i;
		for(i=0;i<count;i++) {
			printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
		}
		
	}
	else {
		printf("No student in the database.\n");
	}
}

int main() {
	struct student students[MAX_STUDENTS];
	int studentCount = 0;
	int choice;
	
	do {
		displayMenu();
		printf("Please enter your choice");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				addStudent(students, &studentCount);
				break;
			case 2:
				displayStudents(students, studentCount);
				break;
			case 3:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please try agoin.\n");			
		}
	} while(choice != 3);
	
	return 0;
}
