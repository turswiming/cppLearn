/**
 * 一、目的
 * 掌握程序设计的思想，能够使用现有知识解决实际问题。独立完成程序设计和编码，学会科学地撰写总结报告，加深对所学知识的理解和掌握。 
二、要求
　　(1)独立完成编码和报告撰写工作；
　　(2)报告提交方式：发送到5507533的qq邮箱，提交时间11月8号22：00点之前。
      （3）报告做成一word文档，分三部分：
                 1：设计思路，简单介绍你的程序结构和思路，100字以内即可。
                 2：程序源代码
                 3.程序执行结果截图
 三、实验题目
 定义一个职工类，在该类定义中包括：一个数据成员工资及两个静态数据成员总工资和职工人数；
 成员函数scoretotalcount(double s) 用于设置工资、求总工资和累计职工人数；
 静态成员函数sum()用于返回总工资；
 静态成员函数average()用于求平均工资。
在main函数中，输入全部职工的工资，并调用上述函数求全部职工的总工资和平均工资。

*/
#include <iostream>
#include <vector>
using namespace std;
class Worker
{
public:
    vector<double> salarys;
    Worker();
    void scoretotalcount(double s);
    double sum();
    double average();

private:
    double sumSalary;
    int sumWorkerNumber;
};
Worker::Worker()
{
    sumSalary = 0;
    sumWorkerNumber = 0;
}
void Worker::scoretotalcount(double s)
{
    salarys.push_back(s);
    sumSalary += s;
    sumWorkerNumber += 1;
}
double Worker::sum()
{
    return sumSalary;
}
double Worker::average()
{
    return sumSalary / sumWorkerNumber;
}
int main()
{
    Worker worker;
    for (size_t i = 0; i < 15; i++)
    {
        worker.scoretotalcount(12.3 * i);
    }
    cout << "平均数是：" << worker.average() << endl;
    cout << "工资总和是：" << worker.sum() << endl;

    return 0;
}