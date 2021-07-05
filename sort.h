#ifndef _SORT_
#include<vector>
#include<algorithm>
#include<iostream>
#include"class.h"
using namespace std;
#define _SORT_
typedef struct
{
    int index;
    int value;
}sort_st;
bool compare(sort_st a,sort_st b)
{
    return a.value>b.value; //升序排列，如果改为return a.value<b.value，则为降序
}
void returnIndexSort(Student stu[])
{
    int stucount=getCount();
    vector <sort_st> sort_array(stucount);
    for(int i=0;i<stucount;++i){
        sort_array[i].index=i;
        sort_array[i].value=stu[i].FinalScore;
    }
    sort(sort_array.begin(),sort_array.end(),compare);
    system("cls");
    for(int i=0;i<stucount;++i)
    {
        cout<<stu[sort_array[i].index].stunum<<' '<<stu[sort_array[i].index].name<<' '<<stu[sort_array[i].index].FinalScore<<endl;
    }
    system("pause");
}
#endif