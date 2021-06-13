#include<../inc/Student.h>

/**
 * @brief Searching the name of student in the file
 * 
 * @param name 
 * @return int 
 */
int Find(const char *name) {
  Student_t Student;
  FILE *f;

  f = fopen("Students.bin", "rb");
  if (f == NULL) {
    return -2;
  }

  while (fread(&Student, sizeof(Student_t), 1, f) == 1) {
    if (strcmp(Student.name, name) == 0) {
      printf("\n details for %s:\n", name);
      printf("Name = %s\nStandard = %s\nEmail ID = %s\nGPA = %s\nsports activity = %s\n\n ", Student.name,
             Student.standard, Student.email_id,Student.GPA,Student.sports);
      fclose(f);
      return 0;
    }
  }
  fclose(f);
  return -1;
}