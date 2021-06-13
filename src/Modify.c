#include<../inc/Student.h>

/**
 * @brief modifying the record of already existing student
 * 
 * @param name 
 * @param update_Student 
 * @return int 
 */
int Modify(char *name, Student_t *update_Student) {
  int result = 0;
  FILE *fptr;
  int flag = 0;
  Student_t old_Student;

  fptr = fopen("Students.bin", "rb+");

  if (fptr == NULL) {
    return -2;
  } else {

    while (fread(&old_Student, sizeof(Student_t), 1, fptr) == 1) {
      if (strcmp(name, old_Student.name) == 0) {
        fseek(fptr, sizeof(Student_t), SEEK_CUR);
        fwrite(update_Student, sizeof(Student_t), 1, fptr);
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      result = 0;
    } else {
      result = -1;
    }
    fclose(fptr);
  }
  return result;
}