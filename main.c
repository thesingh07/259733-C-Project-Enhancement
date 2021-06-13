#include<../inc/Student.h>


typedef enum options {
  NONE,
  ADD_RECORD,
  MODIFY_RECORD,
  DELETE_RECORD,
  DISPLAY_RECORD,
  SEARCH_RECORD,
  EXIT
} options_t;

int main() {
  int choice = NONE;

  printf("\n\t****Welcome to Student Record System****\n");
  for (;;) {

    printf("\nSelect your choice: \n");
    printf("1.Add Record \n2.Modify Record \n3.Delete Record \
        \n4.Display Record \n5.Search for a Record\n6.Exit\n");

    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%d", &choice);

    switch (choice) {
    case ADD_RECORD: {
      Student_t *new_Student = (Student_t *)calloc(1, sizeof(Student_t));

      get_Student_details(new_Student);
      switch (Add(new_Student)) {
      case 0:
        printf("\n\t Add  successful");
        break;
      default:
        printf("\n\t***Error in adding record***");
      }
      free(new_Student);
      break;
    }
    case DELETE_RECORD: {
      int Student_count = display_Student();
      if (0 < Student_count) {
        char name[MAX_NAME_LEN] = "";

        printf("Enter Student's Name from above list:");
        get_data(name);

        switch (Delete(name)) {
        case -1:
          printf("\n\t***No Match found***\n");
          break;
        case -2:
          printf("\n\t***No Student found***\n");
          break;
        case 0:
          printf("\n\t***Student record deleted successfuly***\n");
          break;
        default:
          printf("\n\t***Error in Deleting record***");
        }
      } else if (Student_count == 0) {
        printf("\n\t***No Student found***\n");
      }
      break;
    }
    case MODIFY_RECORD: {
      int Student_count = display_Student();
      if (0 < Student_count) {
        char name[MAX_NAME_LEN] = "";
        Student_t *new_Student = (Student_t *)calloc(1, sizeof(Student_t));

        printf("Student's Name from above list:");

        get_data(name);
        get_Student_details(new_Student);

        switch (Modify(name, new_Student)) {
        case -1:
          printf("\n\t***No Match found***\n");
          break;
        case -2:
          printf("\n\t***No Student found***\n");
          break;
        case 0:
          printf("\n\t***Student record Modified successfully***\n");
          break;
        default:
          printf("\n\t***Error in Modifying***");
        }
        free(new_Student);
      } else if (Student_count == 0) {
        printf("\n\t***No contact found***\n");
      }
      break;
    }
    case DISPLAY_RECORD:
      switch (Display()) {
      case -2:
        printf("\n\t***No Student found***\n\n");
        break;
      case 0:
        printf("\n\t***No Student found***\n\n");
        break;
      default:
        printf("\n\t***Display Student record successfully***\n");
      }
      break;

    case SEARCH_RECORD: {
      int Student_count = display_Student();
      if (0 < Student_count) {
        char name[MAX_NAME_LEN] = "";

        printf("\nEnter name of Student to search\n");
        fflush(stdin);
        get_data(name);

        switch (Find(name)) {
        case -1:
          printf("\n\t***No Matching Student found***\n");
          break;
        case -2:
          printf("\n\t***No Student found***\n\n");
          break;
        case 0:
          printf("\n\t***Search Successful***\n");
          break;
        default:
          printf("\n\t***Error in Search ***");
        }
      }

      else if (Student_count == 0) {
        printf("\n\t***No Student found***\n");
      }
      break;
    }
    case EXIT:
      printf("\n\t****Exiting application****\n");
      exit(0);
      break;

    default:
      printf("\n\t***Selected option not available***");
    }
  }
}