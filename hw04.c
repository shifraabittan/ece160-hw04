#include <stdio.h>
#include <stdlib.h>

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
  int  year; 
  // TODO: add fields here for major and year
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
	case MAJOR_AND_NAME:
	    printf("%s %s %s\n", s.major_field, s.first_name, s.last_name);
	    break;
	 case YEAR_AND_NAME:
	    printf("%s %s %s\n", s.year, s.first_name, s.last_name);
	    break;
	 //case YEARS_LEFT_AND_NAME:
		
		printf("")
	
  }
}

/*
	argv[1] will be the Mode integer
	argv[2...] will be student info in the form [first_name, last_name, major, year]
	the fields are all strings (char[])
	except year is a number (int)
*/
int main(int argc, char* argv[]) {

  for (int i = 2; i < argc; i = i+4){
  int mode_value;
  mode_value = atof(argv[1]);

  Student s1;
  s1.first_name = argv[i];
  s1.last_name = argv[i+1];
  s1.major_field = argv[i+2];
  s1.year = argv[i+3];
  
  print_student(mode_value, s1);
  }
  return 0;
  
  // TODO: parse argv to populate student structs 
  // for now, here's two hardcoded students:

}
