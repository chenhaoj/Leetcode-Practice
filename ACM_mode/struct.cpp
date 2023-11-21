#include<iostream>
using namespace std;

/* struct Student
{
    int Code;
    char Name[20];
    char Sex;
    int Age;
    Student(): Code(), Name(), Sex(), Age(){}
}Stu, StuArray[10], *pStu;
// struct Student Stu;
// struct Student StuArray[10];
// struct Student *pStu;
// Student Stu2; */

/* typedef struct
{
    int Code;
    char Name[20];
    char Sex;
    int Age;
    
}Student;
Student Stu,StuArray[10],*pStu; */

struct MyTree{
    MyTree *left;
    MyTree *right;
    int val;
    MyTree(){}
    MyTree(int val):left(NULL),right(NULL),val(val){}
};

int main() {
    // Student *s = new Student();
    // s->Code = 1;
    // cout << s->Code << endl;
    // delete s;

    MyTree T;
    T.val = 1;
    cout << T.val << endl;
    MyTree *t1 = new MyTree(1);
    MyTree *t2 ;
    t2->val = 2;
    cout<<t1->val<<" "<<t2->val;  //输出：1 2
    // t2.val = 3;  //error: request for member 'val' in 't2', whitch is of pointer type 'MyTree*' (maybe you meant to use '->' ?)
    // cout<<t2.val;  //error: request for member 'val' in 't2', which is of pointer type 'MyTree*' (maybe you mean to use '->' ?
    delete t1;
    delete t2;
    return 0;
}