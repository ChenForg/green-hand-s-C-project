#define MAX 100
#ifndef _CLASS_
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
#define _CLASS_
int stuSerial;
class Student{
    public:
    int stunum; 
    string name;
    string gender;
    string place;
    string telnum;
    int chinese;
    int math;
    int english;
    int PereReview;
    int moral;
    int TeacherReat;
    int extra;
    int TestScore;
    int FinalScore;
};
Student stu[MAX];

class StuAccount
{
public:
    int num;
    string pass;
    int status;
} stuA[MAX];

class Teacher
{
public:
    int number;
    string password;
} tea;

int getCount()
{
    fstream f;
    f.open("C:\\OfficeSystemField\\StudentCount.txt",ios::in);
    int count;
    f>>count;
    f.close();
    return count;
}
void write(Student stu[]){
    fstream f;
    int count = getCount();
    f.open("C:\\OfficeSystemField\\score.txt",ios::out);
    for(int i = 0;i < count;i++){
         f<<stu[i].stunum<<endl<<stu[i].chinese<<endl
         <<stu[i].math<<endl<<stu[i].english<<endl
         <<stu[i].PereReview<<endl  <<stu[i].moral<<endl
         <<stu[i].TeacherReat<<endl <<stu[i].extra<<endl
         <<stu[i].TestScore<<endl<<stu[i].FinalScore<<endl;
    }
    f.close();
    f.open("C:\\OfficeSystemField\\basicInformation.txt",ios::out);
    for(int i = 0;i< count;i++)
    {
        f<<stu[i].name+" "<<endl<<stu[i].gender+" "<<endl<<stu[i].place+" "<<endl<<stu[i].telnum+" "<<endl;
    }
    f.close();
}
void read(Student stu[]){
    fstream f;
    int count = getCount();
    f.open("C:\\OfficeSystemField\\basicInformation.txt",ios::in);
    for(int i = 0;i< count;i++)
    {
        f>>stu[i].name>>stu[i].gender>>stu[i].place>>stu[i].telnum;
        cout<<stu[i].name<<"test"<<endl;
    }
    f.close();
    f.open("C:\\OfficeSystemField\\score.txt",ios::in);
    for(int i = 0;i < count;i++){
        f>>stu[i].stunum>>stu[i].chinese
         >>stu[i].math>>stu[i].english
         >>stu[i].PereReview>>stu[i].moral
         >>stu[i].TeacherReat>>stu[i].extra
         >>stu[i].TestScore>>stu[i].FinalScore;
         //cout<<stu[i].stunum<<" test "<<endl;
    }
    f.close();
}
 
#endif
