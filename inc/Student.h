
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include<string.h>

/**
 * @brief  defining length of all the structure variables used.
 * 
 */
enum max_lengths { 
    MAX_NAME_LEN = 32,
    MAX_CLASS_LEN = 4,
    MAX_EMAIL_ID_LEN = 100,
    MAX_GPA_LEN = 4,
    MAX_SPORTS_LEN = 20,
    MAX_ROLL_NO_LEN = 10,
};

/**
 * @brief structure with the name student and all other related variables.
 * 
 */
typedef struct Student_t{  
    char name[MAX_NAME_LEN];
    char standard[MAX_CLASS_LEN];
    char email_id[MAX_EMAIL_ID_LEN];
    char GPA[MAX_GPA_LEN];
    char sports[MAX_SPORTS_LEN];
    char roll_no[MAX_ROLL_NO_LEN];

}Student_t;
int Add(Student_t *Student);

void create_new(Student_t *Student);


int Delete(const char* name);


int Display(void);


int Modify(char *name, Student_t* update_Student);


int Find(const char* name);


void get_data(char *name);


void get_Student_details(Student_t *Student);

#endif  //__STUDENT_H__