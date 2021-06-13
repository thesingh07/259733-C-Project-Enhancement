#include<../inc/Student.h>
/**
 * @brief Get the data object
 * 
 * @param name 
 */

void get_data(char *name) {

  int i = 0, j;
  char c, ch;
  fflush(stdin);
  do {
    c = getchar();
    if (c != '\n') {
      *(name + i) = c;
      putchar(c);
      i++;
    }
    if (c == 8) {
      if (i > 0) {
        i--;
      }
      for (j = 0; j < i; j++) {
        ch = *(name + j);
        putchar(ch);
      }
    }
  } while (c != '\n');
  *(name + i) = '\0';
}

/**
 * @brief Get the Student details object
 * 
 * @param Student 
 */
void get_Student_details(Student_t *Student) {
  printf("\nEnter name: ");
  fflush(stdin);
  get_data(Student->name);

  printf("\nEnter the Standard: ");
  fflush(stdin);
  get_data(Student->standard);

  printf("\nEnter Email ID: ");
  fflush(stdin);
  get_data(Student->email_id);

  printf("\nEnter roll no.: ");
  fflush(stdin);
  get_data(Student->roll_no);

  
  printf("\nEnter GPA.: ");
  fflush(stdin);
  get_data(Student->GPA);

  
  printf("\nEnter Sports: ");
  fflush(stdin);
  get_data(Student->sports);
}