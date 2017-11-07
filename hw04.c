#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major_field;
  int year; 
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    int calculated_years;
	case NAME_ONLY:
		printf("%s %s\n", s.first_name, s.last_name);
		break;
	case MAJOR_AND_NAME:
	    	printf("%s %s %s\n", s.major_field, s.first_name, s.last_name);
	    	break;
	 case YEAR_AND_NAME:
	    	printf("%d %s %s\n", s.year, s.first_name, s.last_name);
	    	break;
	 case YEARS_LEFT_AND_NAME:
		calculated_years = s.year - 2017;
		printf("%d %s %s\n", calculated_years, s.first_name, s.last_name);
		break;	
  }
}

/*
	argv[1] will be the Mode integer
	argv[2...] will be student info in the form [first_name, last_name, major, year]
	the fields are all strings (char[])
	except year is a number (int)
*/
int main(int argc, char* argv[]) {
	//identify name of file, assign file text to a pointer
	char *filename = argv[1];
	//printf("the file name is %s", argv[1]);
	FILE *fp;
	fp = fopen(filename, "r");
	
	//dummy variable to be used when parsing file lines
	char buffer[256];
	
	//assign an array to hold all of the student info extracted from the file
	Student all_students[256];
	
	
	if (fp == NULL) {
		printf("Could not open %s\n", filename);
		return -1;
	}
	
	//read one line at a time from file and assign it to the student structs 
  
	char *s;
	int i = 0;
	while ((s = fgets(buffer, 255, fp)) != NULL) {
		
		Student s1;
		
		size_t len = strlen(buffer);
		size_t len_bytes = (len + 1) * sizeof(char);
		
		s1.first_name = malloc(len_bytes);
		s1.last_name = malloc(len_bytes);
		s1.major_field = malloc(len_bytes);
		
		sscanf(buffer, "%s %s %s %d", s1.first_name, s1.last_name, s1.major_field, &s1.year);
		
		all_students[i] = s1;
		i++;
	}
	
	fclose(fp);
	
	
	while(1) {
		int input_index = 0;
		int input_mode = 0;
		fscanf(stdin, "%d %d", &input_index, &input_mode);
		print_student(input_mode, all_students[input_index]);
	}
	
	for (int a = 0; a < i; a++) {
		if (all_students[a].first_name != NULL){
			free(all_students[a].first_name);
		}	
		if (all_students[a].last_name != NULL){
			free(all_students[a].last_name);
		}
		if (all_students[a].major_field != NULL){
			free(all_students[a].major_field);
		}
	}
	
	return 0;
  

}
