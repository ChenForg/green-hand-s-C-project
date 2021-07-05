#ifndef _LOGIN_
#include<string>
#include<fstream>
#include<iostream>
#include"class.h"
#include"password.h"
using namespace std;
#define _LOGIN_
int getStunumber(int i)
{
    return i;
}

int stuLogin()
{
    int passCount=0;
    stuflage:
    system("cls");
    cout<<" 输入0退出"<<endl;
    cout<<"请输入学号:"<<endl;
    int stuNum;cin>>stuNum;
    if(stuNum==0) return 0;
    cout<<"请输入密码"<<endl;
    string stuPassword = getpassword();
    if(stuPassword=="0") return 0;
    cout<<"正在登陆，请稍后......"<<endl;
    fstream f;
    f.open("C:\\OfficeSystemField\\ID.txt",ios::in|ios::binary);
    int i=0;
    for(i=0;i<getCount();i++)
    {
        f>>stuA[i].num>>stuA[i].pass>>stuA[i].status;
        if(stuA[i].num==stuNum)
        {
            stuflage1:
            if(stuA[i].pass==stuPassword)
            {
                stuSerial=i;
                cout<<stuA[stuSerial].status<<endl;
                if(stuA[stuSerial].status==1)
                {
                    return 1;
                }
                else
                {
                    cout<<"账号无法登录！"<<endl;
                    system("pause");
                    goto stuflage;
                } 
            }
            else 
            {
                passCount++;
                if(passCount<=5)
                {
                system("cls");
                cout<<"密码错误，请重新输入: "<<endl;
                stuPassword=getpassword();
                goto stuflage1;
                }else
                {
                    cout<<"账号或密码错误超过五次！即将自动退出系统"<<endl;
                    return 0;
                }
            }
        }
    }
    if(i==getCount()&&passCount<=5)
    {
        passCount++;
        cout<<"学号不存在,请重新输入！"<<endl;
        system("pause");
        goto stuflage;
    }
    if(passCount==5)
    {
        cout<<"账号或密码错误超过五次！即将自动退出系统"<<endl;
        system("pause");
        return 0;
    }

    return 0;
}

int teachLogin()
{
    system("cls");
    int passCount=0;
    teachFlage:
    cout<<"请输入工号"<<endl;
    int teachnum;cin>>teachnum;
    cout<<"请输入密码"<<endl;
    teachFlage1:
    string teachpassword = getpassword();
    cout<<"正在登陆，请稍后......"<<endl;
    if(teachnum==123456)
    {
        if(teachpassword=="123456")
        {
            return 2;
        }else
        {
            passCount++;
            if(passCount>5)
            {
                cout<<"账号或密码输入超过五次，即将退出系统"<<endl;
                return 0;
            }
            cout<<"密码错误，请重新输入！";
            goto teachFlage1;
        } 
    }else
    {
        passCount++;
        if(passCount>5)
        {
            cout<<"账号或密码输入超过五次，即将退出系统"<<endl;
            return 0;
        }
        cout<<"账号错误，请重新输入"<<endl;
        goto teachFlage;
    }
    return 0;
}
int officeLogin()
{
    system("cls");
    int passCount=0;
    offFlage:
    cout<<"请输入账号"<<endl;
    int officenum;cin>>officenum;
    cout<<"请输入密码"<<endl;
    string officepassword = getpassword();;
    offFlage1:
    cout<<"正在登陆，请稍后......"<<endl;
    if(officenum==123456)
    {
        if(officepassword=="123456")
        {
            return 3;
        }else
        {
            passCount++;
            if(passCount>5)
            {
                cout<<"账号或密码输入超过五次，即将退出系统"<<endl;
                return 0;
            }
            cout<<"密码错误，请重新输入！"<<endl;
            goto offFlage1;
        } 
    }else
    {
        passCount++;
        if(passCount>5)
        {
            cout<<"账号或密码输入超过五次，即将退出系统"<<endl;
            return 0;
        }
        cout<<"账号错误，请重新输入"<<endl;
        system("pause");
        goto offFlage;
    }
    return 0;
}

int AllLogin()
{
    int judgeFunction;
    cin>>judgeFunction;
    switch(judgeFunction)
    {
        case 1:
        return stuLogin();
        case 2:
        return teachLogin();
        case 3:
        return officeLogin();
        case 0:
        return 0;
    }
    return 0;
}
#endif