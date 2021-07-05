#ifndef _OFFICEFUNTION_
#include <fstream>
#include <iostream>
#include <string>
#include "class.h"
#include"password.h"
using namespace std;
#define _OFFICEFUNTION_
void write1(StuAccount stuA[], int c) //逐个存入学生的学号和密码
{
    ofstream ofs;
    ofs.open("C:\\OfficeSystemField\\ID.txt", ios::app);
    ofs << stuA[c].num << " " << stuA[c].pass <<" "<<stuA[c].status<< endl;
    ofs.close();
}
void reduce() //在减少的时候先清空学生的学号和密码
{
    ofstream ff;
    ff.open("C:\\OfficeSystemField\\ID.txt", ios::trunc);
    ff.close();
}
void write2(Teacher tea) //存入老师的工号和密码
{
    ofstream f;
    f.open("C:\\OfficeSystemField\\TD.txt", ios::app|ios::binary);
    f << tea.number << " " << tea.password << endl;
    f.close();
}
void StudentCounter(int count) //计算人数
{
    ofstream of;
    of.open("C:\\OfficeSystemField\\StudentCount.txt", ios::out|ios::binary);
    of << count;
    of.close();
}
void OfficerSelect() //录入和修改信息
{
    system("cls");
    int i, j, k=2;
    int studentcount = getCount();
    int num = 1;
    string pass;
    int status;
SignFlage:
    while (1)
    {
        system("cls");
        cout << "请选择功能" << endl;
        cout << "录入学生账号：1 || 录入教师账号：2 || 修改学生信息：3 || 退出：0" << endl;
        cin >> i;
        if (i == 0)
        {
            system("cls");
            return ;
        }
        if (i == 1)
        {
            for (; 1; studentcount++)
            {
                cout << "输入0退出" << endl;
                if (studentcount == 0)
                {
                    cout << "输入学生学号："<<endl;
                    cin >> num;
                    if (num == 0)
                    {
                        break;
                    }
                    cout << "输入学生密码："<<endl;
                    pass=getpassword();
                    stuA[studentcount].num = num;
                    stuA[studentcount].pass = pass;
                    stuA[studentcount].status = 1;
                    stu[studentcount].stunum = num;
                    stu[studentcount].name = "暂未填写";
                    stu[studentcount].place="暂未填写";
                    stu[studentcount].telnum="暂未填写";
                    stu[studentcount].gender="暂未填写";

                    //
                    write1(stuA, studentcount);
                    system("cls");
                    cout<<"录入成功！"<<endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << "输入学生学号：" << endl;
                    cin >> num;
                    if (num == 0)
                    {
                        break;
                    }
                    //
                    ifstream read;
                    read.open("C:\\OfficeSystemField\\ID.txt", ios::in|ios::binary);
                    for (int l = 0; l < studentcount; l++)
                    {
                        read >> stuA[l].num >> stuA[l].pass;
                    }
                    read.close();

                    for (int l = 0; l < studentcount; l++)
                    {
                        if (num == stuA[l].num)
                        {
                            k = 1;
                            break;
                        }
                        else
                        {
                            k = 2;
                        }
                    }
                    if (k == 1)
                    {
                        cout << "学生学号重复" << endl;
                        studentcount--;
                    }
                    else if (k == 2)
                    {
                        cout << "输入学生密码"<<endl;
                        pass=getpassword();
                        stuA[studentcount].num = num;
                        stuA[studentcount].pass = pass;
                        stuA[studentcount].status = 1;
                        stu[studentcount].stunum = num;
                        stu[studentcount].name = "暂未填写";
                    stu[studentcount].place="暂未填写";
                    stu[studentcount].telnum="暂未填写";
                    stu[studentcount].gender="暂未填写";
                       //
                        write1(stuA, studentcount);
                        system("cls");
                        cout<<"录入成功！"<<endl;
                        system("pause");
    
                    }
                }
            }
            StudentCounter(studentcount);
        }
        else if (i == 2)
        {
            cout << "输入教师工号："<<endl;
            cin >> num;
            cout << "输入密码： "<<endl;
            pass=getpassword();
            tea.number = num;
            tea.password = pass;
            write2(tea);
        }
        else if (i == 3)
        {
            int a=0;
            fstream f1; //把计入的人数重新拿出来
            f1.open("C:\\OfficeSystemField\\StudentCount.txt", ios::in|ios::binary);
            f1 >> studentcount;
            f1.close();
            cout << "1： 修改学生的密码 || 2： 修改学生的状态" << endl;
            cin >> j;
            if (j == 1)
            {
                cout << "输入需要修改密码的学生学号：" << endl;
                cin >> num;
                //
                ifstream read;
                read.open("C:\\OfficeSystemField\\ID.txt", ios::in|ios::binary);
                for (int l = 0; l < studentcount; l++)
                {
                    read >> stuA[l].num >> stuA[l].pass >>stuA[l].status;
                }
                read.close();
                for (int l = 0; l < studentcount; l++)
                {
                    if (num == stuA[l].num)
                    {
                        k = 1;
                        break;
                    }
                    else
                    {
                        a++;
                        k = 2;
                    }
                }
                if (k == 1)
                {
                    cout << "输入学生新密码： " << endl;
                    pass=getpassword();
                    stuA[a].pass = pass;
                    reduce();
                    for(int l=0; l<studentcount;l++)
                    {
                        write1(stuA, l);
                    }
                    system("cls");
                    cout<<"修改成功！"<<endl;
                    system("pause");
                }
                else if (k == 2)
                {
                    cout << "查无此人！" << endl;
                    system("pause");
                }
            }
            else if (j == 2)
            {
                cout <<"输入修改状态的学生学号:"<<endl;
                cin >> num;
                ifstream read;
                read.open("C:\\OfficeSystemField\\ID.txt", ios::in|ios::binary); //把学生基本信息的文件读出来
                for (int l = 0; l < studentcount; l++)
                {
                    read >> stuA[l].num >> stuA[l].pass>>stuA[l].status;
                }
                read.close();
                for (int l = 0; l < studentcount; l++)
                {
                    if (num == stuA[l].num)
                    {
                        k = 1;
                        break;
                    }
                    else
                    {
                        a++;
                        k = 2;
                    }
                }
                if (k == 1)
                {
                    cout<<"1:在读  2：休学  3：退学"<<endl;
                    cout<<"输入该学生的新状态："<<endl;
                    cin>>status;
                    stuA[a].status=status;
                    reduce(); //删除之前的学生基本信息，下方重新录入减少后的学生基本信息
                    for(int l=0;l<studentcount;l++)
                    {
                        write1(stuA,l);
                    }
                    system("cls");
                    cout<<"修改成功！"<<endl;
                    system("pause");
                }
                else if (k == 2)
                {
                    cout << "查无此人！" << endl;
                }
            }
            goto SignFlage;
        }
    }
}
#endif
