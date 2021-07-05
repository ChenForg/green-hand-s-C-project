#include<fstream>
#include<iostream>
#include<string>
#include <io.h>
#include <direct.h>
#include"class.h"
#include"teachFunction.h"
#include"stuFunction.h"
#include"officeFunction.h"
#include"login.h"
using namespace std;

void createTxt( string fname)
{
	fstream fs;
	fs.open(fname, ios::in);
	if (!fs)
	{
		//创建文件
		ofstream fout(fname);
		if (fout)
		{
			fout.close();
		}
    }
}
void createDirectory(std::string folderPath)
{
     if (access(folderPath.c_str(), 0) == -1)    //如果文件夹不存在
        mkdir(folderPath.c_str());

    createTxt(folderPath+"\\basicInformation.txt");
    createTxt(folderPath+"\\ID.txt");
    createTxt(folderPath+"\\StudentCount.txt");
    createTxt(folderPath+"\\score.txt");
}
int main()
{
    read(stu);
    createDirectory("C:\\OfficeSystemField");//可选择存放文件的地方
    OSflage:
    system("cls");
    cout<<" ___________________________"<<endl;
    cout<<"| 欢迎使用学生信息管理系统! |"<<endl;
    cout<<"| 请选择登陆方式:           |"<<endl;
    cout<<"| 1.学生登陆                |"<<endl;
    cout<<"| 2.教师登录                |"<<endl;
    cout<<"| 3.教务处管理员登陆        |"<<endl;
    cout<<"| 0.退出系统                |"<<endl;
    
    int login_status = AllLogin();
    switch(login_status)
    {
        case 1:
        StudentSelect();
        goto OSflage;
        break;
        case 2:
        TeacherSelect();
        goto OSflage;
        break;
        case 3: 
        OfficerSelect() ;
        goto OSflage;
        break;
    }
    write(stu);
    return 0;
}
 