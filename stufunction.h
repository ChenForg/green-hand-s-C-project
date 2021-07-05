#ifndef _STUFUNTION_
#include<fstream>
#include<iostream>
#include<string>
#include"class.h"
using namespace std;
#define MAX 100
#define _STUFUNTION_
void apply()
{
    fstream f;
    f.open("C:\\OfficeSystemField\\applyCount.txt",ios::in);
    int count=0; 
    f>>count;
    f.close();
	f.open("C:\\OfficeSystemField\\apply.txt",ios::out|ios::app);
    flage:
    string awardName;
    int addGrade;
    cout<<"奖项名称"<<endl;
    cin>>awardName;
    cout<<"请输入奖项类别的序号：" <<endl<<"1.学院级"<<endl<<"2.校级"<<endl<<"3.省级"<<endl<<"4.国家级"<<endl;
    cin>>addGrade;
	f<< 1 <<" "<<stu[stuSerial].name<<" "<<stu[stuSerial].stunum<<" "<<awardName<<" "<<addGrade<<endl;
    count++;
    cout<<"提交成功，等待老师审核中！"<<endl<<"输入1继续提交 输入0退出"<<endl;
    int jude=0;
    cin>>jude;
    if(jude==1) {goto flage;}
    else
    f.close();
    f.open("C:\\OfficeSystemField\\applyCount.txt",ios::out);
    f<<count<<endl;
    f.close();
}
void IntputBasicData(Student stu[], int i){
        cout<<"请输入姓名：";
        cin>>stu[i].name;
        cout<<"请输入性别：";
        cin>>stu[i].gender;
        cout<<"请输入家庭住址：";
        cin>>stu[i].place;
        cout<<"请输入电话：";
        cin>>stu[i].telnum;
        write(stu);
        cout<<"录入成功！"<<endl;
        system("pause");
        
}

void modify(Student stu[],int i){      //学生修改信息
    cout<<"请输入新的家庭住址：";
    cin>>stu[i].place;
    cout<<"新的联系电话：";
    cin>>stu[i].telnum;
    write(stu);
    cout<<"修改成功！"<<endl;
    system("pause");
}

void CheckScore(Student stu[],int i){
    cout<<"考试成绩："<<stu[i].TestScore<<endl;
    cout<<"综测成绩："<<stu[i].FinalScore<<endl;
    system("pause");
}

void StudentSelect()
    {
        stuSelectFlage:
        system("cls");
        cout<<"   请选择功能："<<endl;
        cout<<"1：录入个人基本信息|| 2：修改个人信息 || 3：提出加分申请 ||4：查询个人成绩|| 0：退出"<<endl;
        int n;
        l1:  cin>>n;
        if(n<1&&n>5)
        {
            cout<<"输入信息有误！"<<endl;
            goto l1;
        }
        switch (n)
        {
        case 1:
        IntputBasicData(stu,stuSerial);
        goto stuSelectFlage;
            break;
        case 2:
        modify(stu,stuSerial);
        goto stuSelectFlage;
        break;
        case 3:
        apply();
        goto stuSelectFlage;
        break;
        case 4:
        CheckScore(stu,stuSerial);
        goto stuSelectFlage;
        break;
        case 0:
        return;
        }
    }

#endif