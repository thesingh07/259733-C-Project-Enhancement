#include "unity.h"
#include<../inc/Student.h>


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

 
void test_Add_Student(void) {
  Student_t new_Student = {"Rajat singh", "7", "rajaatbikes@gmail.com","9.95","basketball","234567"};
  TEST_ASSERT_EQUAL(0, Add_Student(&new_Student));
}

void test_Delete_Student(void) {
  Student_t new_Student = {"abc xyz", "1", "abc@gmail.com","9.99","kabbadi","111111"};
  TEST_ASSERT_EQUAL(0, Add_Student(&new_Student));
  TEST_ASSERT_EQUAL(0, Delete_Student(new_Student.name));
}

void test_Modify_Student(void) {
  Student_t new_Student = {"Rohan D Kadam", "5", "rdk@gmail.com","9","cricket","152637"};
  Student_t new_Student1 = {"Rohan D Kadam", "6", "rdknew@gmail.com","10","cricket","152637"};
  TEST_ASSERT_EQUAL(0, Add_Student(&new_Student));
  TEST_ASSERT_EQUAL(0, Modify_Student(new_Student.name, &new_Student1));
  TEST_ASSERT_EQUAL(0, Delete_Student(new_Student1.name));
}
void test_Search_Student(void) {
  Student_t new_Student = {"xyz abc", "3", "xyznew@gmail.com","16","baseball","123456"};
  TEST_ASSERT_EQUAL(0, Add_Student(&new_Student));
  TEST_ASSERT_EQUAL(0 , Search_Student(new_Student.name));
  TEST_ASSERT_EQUAL(0 , Delete_Student(new_Student.name));
}
void test_Display_Student(void) 
{ 
  TEST_ASSERT_EQUAL(1, display_Student()>0);
}

int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_Add_Student);
  RUN_TEST(test_Delete_Student);
  RUN_TEST(test_Modify_Student);
  RUN_TEST(test_Search_Student);
  RUN_TEST(test_Display_Student);

  /* Close the Unity Test Framework */
  return UNITY_END();
}