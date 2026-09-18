#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;

class Student_crs_mng
{
     ll ID;
     st name;
     ll num_of_courses;
     st *courses;

public:
     Student_crs_mng(ll id, st n, ll count, st course_list[])
     {
          ID = id;
          name = n;
          num_of_courses = count;

          courses = new st[num_of_courses];

          for (ll i = 0; i < num_of_courses; i++)
          {
               courses[i] = course_list[i];
          }
     }
     ~Student_crs_mng()
     {
          delete[] courses;
          cout << "Done!!!" << endl;
     }

     Student_crs_mng(const Student_crs_mng &another_stud)
     {
          ID = another_stud.ID;
          name = another_stud.name;
          num_of_courses = another_stud.num_of_courses;

          courses = new st[num_of_courses];

          for (ll i = 0; i < num_of_courses; i++)
          {
               courses[i] = another_stud.courses[i];
          }
     }

     void set_course_name_in_list(ll index, st course_name)
     {
          if (index >= 0 && index < num_of_courses)
          {
               courses[index] = course_name;
          }
     }

     void display()
     {
          cout << "ID: " << ID << endl;
          cout << "Name: " << name << endl;

          cout << "Courses: ";
          for (ll i = 0; i < num_of_courses; i++)
          {
               cout << courses[i] << (i == num_of_courses - 1 ? "." : ",");
          }
          cout << endl;
     }
};

int main(void)
{
     ll Uid, Num_of_Courses;
     st Std_name;

     cout << "Student ID: ";
     cin >> Uid;

     cout << "Name: ";
     cin.ignore();
     getline(cin, Std_name);

     cout << "Number of courses you want to attend: ";
     cin >> Num_of_Courses;

     st *c = new st[Num_of_Courses];

     cout << "Courses: \n";
     cin.ignore();
     for (int i = 0; i < Num_of_Courses; i++)
     {
          getline(cin, c[i]);
     }
     cout << "\n";

     Student_crs_mng main_student(Uid, Std_name, Num_of_Courses, c);
     Student_crs_mng copy_student = main_student;

     copy_student.set_course_name_in_list(0, "LANG - 201");

     cout << "Main_student Student: " << endl;
     main_student.display();

     cout << "Copied Student (Modified):" << endl;
     copy_student.display();

     delete[] c;
     return 0;
}