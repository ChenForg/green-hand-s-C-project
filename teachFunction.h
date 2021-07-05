#ifndef _TEACHFUNTION_
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "class.h"
#include "sort.h"
using namespace std;
#define _TEACHFUNTION_

void CalculateScore(Student stu[], int i) //计算总成绩
{
    stu[i].TestScore = (stu[i].chinese + stu[i].math + stu[i].english) / 3;
    stu[i].FinalScore = stu[i].TestScore * 0.6 + stu[i].PereReview * 0.1 + stu[i].moral * 0.1 + stu[i].TeacherReat * 0.1 + stu[i].extra;
}

void readInformation() //教师查询学生信息
{
readInformationFlage:
    system("cls");
    for (;;)
    {
        cout << "输入学生学号: " << endl;
        int Stu_num;
        cin >> Stu_num;
        if (Stu_num == 0)
            return;
        for (int i = 0; i < getCount(); i++)
        {
            if (Stu_num == stu[i].stunum)
            {
                //输出该学生全部信息；

                cout << "学号： " << stu[i].stunum << endl;
                cout << "姓名： " << stu[i].name << endl;
                cout << "性别： " << stu[i].gender << endl;
                cout << "住址： " << stu[i].place << endl;
                cout << "电话： " << stu[i].telnum << endl;
                cout << "语文成绩：" << stu[i].chinese << endl;
                cout << "数学成绩：" << stu[i].math << endl;
                cout << "英语成绩：" << stu[i].english << endl;
                cout << "同学互评分： " << stu[i].PereReview << endl;
                cout << "品德成绩： " << stu[i].moral << endl;
                cout << "教师评分： " << stu[i].TeacherReat << endl;
                cout << "额外加分： " << stu[i].extra << endl;
                cout << "考试平均成绩： " << stu[i].TestScore << endl;
                cout << "综合测评总分： " << stu[i].FinalScore << endl;
                system("pause");
                system("cls");
                cout << "1.继续查询   0.返回  " << endl;
                int j;
                cin >> j;
                if (j == 1)
                    goto readInformationFlage;
                else
                    return;
            }
        }
        cout << "未查询到相关信息，请重新输入！" << endl;
    }
}
void input()
{
    //输入数据；
    for (;;)
    {
        int num;
        cout << "请输入学号： ";
        cin >> num;
        for (int i = 0; i < getCount(); i++)
        {
            if (num == stu[i].stunum)
            {
                num = i;
            }
        }
        cout << endl;
        cout << "语文成绩： ";
        cin >> stu[num].chinese;
        cout << "数学成绩： ";
        cin >> stu[num].math;
        cout << "英语成绩： ";
        cin >> stu[num].english;
        cout << "同学互评成绩： ";
        cin >> stu[num].PereReview;
        cout << "品德成绩： ";
        cin >> stu[num].moral;
        cout << "教师评分： ";
        cin >> stu[num].TeacherReat;
        CalculateScore(stu, num);
        cout << "综合测评总分：" << stu[num].FinalScore << endl;
        void write(Student stu[]);
        cout << "1.继续录入成绩  0.返回" << endl;
        int j;
        cin >> j;
        if (j == 1)
            continue;
        else if (j == 0)
            return;
    }
}
void readApply(Student stu[])
{
    fstream f;
    f.open("C:\\OfficeSystemField\\applyCount.txt", ios::in);
    int allCount;
    f >> allCount;
    int applyCount = allCount;
    //cout<<allCount;
    f.close();
    f.open("C:\\OfficeSystemField\\apply.txt", ios::in);
    int status[MAX];
    string name[MAX];
    int number[MAX];
    string award[MAX];
    int addgrade[MAX];
    for (int i = 0; i < allCount; i++)
    {
        f >> status[i] >> name[i] >> number[i] >> award[i] >> addgrade[i];
        if (status[i] != 1)
            applyCount--;
    }
    if (applyCount == 0)
    {
        cout << " 无待处理加分申请！" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = allCount - 1; i >= 0 && status[i] == 1; i--)
    {
        cout << name[i] << " " << number[i] << " " << award[i] << "  加" << addgrade[i] << "分" << endl;
        cout << "输入1同意加分，输入2暂不处理，输入0否认加分" << endl;
        int judge = 0;
        cin >> judge;
        if (judge == 1)
        {
            for (int j = 0; j < getCount(); j++)
            {
                if (stu[j].stunum == number[i])
                {
                    stu[j].extra += addgrade[i];
                    CalculateScore(stu, j);
                    write(stu);
                    cout << "操作成功！" << endl;
                    name[i] = name[i] + "已处理";
                    status[i] = 0;
                    applyCount--;
                }
            }
        }
        else if(judge == 0)
        {
            cout << "操作成功！" << endl;
            name[i] = name[i] + "已处理";
            status[i] = 0;
            applyCount--;
        }else if(judge==2)
        {
            continue;
        }
        system("pause");
    }
    f.close();
    f.open("C:\\OfficeSystemField\\apply.txt", ios::out);
    for (int i = 0; i < allCount; i++)
    {
        f << status[i] << " " << name[i] << " " << number[i] << " " << award[i] << " " << addgrade[i] << endl;
    }
    f.close();
    if (applyCount == 0)
    {
        cout << "加分申请已全部处理！" << endl;
        system("pause");
        system("cls");
        return;
    }
    system("pause");
    system("cls");
}
void Modified(Student stu[]) //修改学生成绩
{
reinputFlage:
    int k;
    for (;;)
    {
        cout << "输入需要修改的学生学号： ";
        int Id, num, reStuSerial;
        cin >> Id;
        for (int i = 0; i < getCount(); i++)
        {
            if (stu[i].stunum == Id)
            {
                reStuSerial = i;
                break;
            }
            if (i == getCount() - 1)
            {
                cout << "查无此人,请重新输入学号" << endl;
                system("cls");
                goto reinputFlage;
            }
        }
        cout << "选择需要修改的项目： " << endl;
        cout << 1 << "."
             << "语文  " << 2 << "."
             << "数学  " << 3 << "."
             << "英语  " << 4 << "."
             << "同学互评分  "
             << 5 << "."
             << "品德成绩  " << 6 << "."
             << "教师评分  " << 7 << "."
             << "额外加分  " << 8 << "."
             << "测试成绩" << endl;
        cin >> num;
        for (int i = 1; i <= 8; i++)
        {
            if (i == num)
            {
                cout << "输入修改后的成绩： ";
                int grade;
                cin >> grade;
                switch (i)
                {
                case 1:
                    stu[reStuSerial].chinese = grade;
                    break;
                case 2:
                    stu[reStuSerial].math = grade;
                    break;
                case 3:
                    stu[reStuSerial].english = grade;
                    break;
                case 4:
                    stu[reStuSerial].PereReview = grade;
                    break;
                case 5:
                    stu[reStuSerial].moral = grade;
                    break;
                case 6:
                    stu[reStuSerial].TeacherReat = grade;
                    break;
                case 7:
                    stu[reStuSerial].extra = grade;
                    break;
                case 8:
                    stu[reStuSerial].TestScore = grade;
                    break;
                }
                //算总成绩
                CalculateScore(stu, i);
                cout << "修改成功！" << endl;
                cout << "按任意键继续，输入0返回" << endl;
                cin >> k;
                if (k == 0)
                    break;
            }
        }
        if (k == 0)
        {
            break;
        }
    }
    //返回；
}

void TeacherSelect()
{
teacherSelectFlage:
    cout << "请选择功能：" << endl;
    cout << "1：查看学生信息|| 2：录入学生成绩 || 3：查看加分申请 ||4：修改学生成绩||5：查看学生排名|| 0：退出" << endl;
    int sel;
    cin >> sel;
    switch (sel)
    {
    case 1:
        system("cls");
        readInformation();
        goto teacherSelectFlage;
        break;
    case 2:
        system("cls");
        input();
        goto teacherSelectFlage;
        break;
    case 3:
        system("cls");
        readApply(stu);
        goto teacherSelectFlage;
        break;
    case 4:
    system("cls");
        Modified(stu);
        goto teacherSelectFlage;
        break;
    case 5:
    system("cls");
        returnIndexSort(stu);
        goto teacherSelectFlage;
        break;
    case 0:
        break;
    }
}
#endif
