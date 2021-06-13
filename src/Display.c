#include <stdio.h>
#include <stdlib.h>

#include<../inc/Student.h>
/**
 * @brief displaying the record of already existing student
 * 
 * @return int 
 */

int Display(void) {
  Student_t Student;
  FILE *fptr;
  int count = 0;
  if ((fptr = fopen("Students.bin", "rb")) == NULL) {
    return -2;
  }

  printf("\n### Student_Records ###\n");
  while (fread(&Student, sizeof(Student), 1, fptr) == 1) {
    printf("Name = %s\nStandard = %s\nEmail ID = %s\nGPA = %f\nsports activity = %s\n\n ", Student.name,
             Student.standard, Student.email_id,Student.GPA,Student.sports);
    count++;
  }
  printf("### Student_Records ###\n\n");
  fclose(fptr);
  return count;
}