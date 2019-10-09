#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<fstream>
#include<cmath>
#include<string>
#include <iomanip>
using namespace std;
bool b;
int renewal = -1;

class user
{
public:
	string Register();//注册
	string Enter();//登录
	string Display();//调用display显示switch()菜单
};

string user::Register()//注册
{
	ofstream outFile;
	outFile.open("web1.txt", ios_base::out | ios_base::app);//把注册的用户名、密码保存到web1.txt文件当中
	if (!outFile.is_open())
	{
		cout << "很遗憾，未检测到用户数据文件\n";
		cout << "程序结束\n";
		cin.get();
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	cout << "Please Enter members name请输入用户名名称: \n";
	cin.get();
	getline(cin, name);
	name = name + "name";
	outFile << name << endl;//记录注册的资料到web1.txt文件中
	cout << "Please Enter members code请输入密码: \n";
	getline(cin, code);
	code = "code" + code;
	outFile << code << endl;//记录注册的资料到web1.txt文件中
	cout << "注册成功！\n";
	outFile.close();
	name = Display();
	return name;
}

string user::Enter()//登录
{
	int flag = 0;
	cin.get();
	ifstream inFile;
	inFile.open("web1.txt");//读取web1.txt文件中的注册资料
	if (!inFile.is_open())
	{
		cout << "很遗憾，未检测到用户数据文件\n";
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	string temp;
	cout << "Please Enter members name请输入用户名名称: \n";
	getline(cin, name);
	name = name + "name";
	while (getline(inFile, temp))//匹配用户名
	{
		if (temp == name)
		{
			flag = 1;
			cout << "Please Enter members code请输入密码: \n";
			getline(cin, code);
			code = "code" + code;
			getline(inFile, temp);//匹配密码
			if (temp == code)
			{
				cout << "登录成功\n";
				return name;

			}
			else
			{
				cout << "密码错误\n";
				name = Display();//返回
				return name;
			}
		}
	}
	if (flag == 0)
	{
		cout << "未找到此用户！请重新输入" << endl;
		name = Display();
		return name;//返回
	}
}

string user::Display()//菜单
{
	string name;
	cout << "1.Register注册\n2.Enter登录\n3.Exit退出" << endl << "Choice:";
	int choice;//选择菜单
	cin >> choice;
	switch (choice)
	{
	case 1://注册
		name = Register();
		break;
	case 2://登录
		name = Enter();
		break;
	case 3://退出
		exit(EXIT_FAILURE);
	}
	return name;
}

class CURRENT
{

public:
	int outyear, outmon, outday;//支取日期
	int inyear, inmon, inday;//存款日期
	void choose();
	void inputtime(void);
	int calctime();
	int estimate();
	CURRENT currenttimepass(int day, CURRENT c);
	CURRENT fixedtimepass(int type, CURRENT c);
};

void CURRENT::choose()//选择存款类型
{
	cout << "请选择存储类型：0活期存款 1定期存款" << endl;
	cin >> b;
}
void CURRENT::inputtime(void)//输入日期
{
	cout << "请输入存款时间：" << endl << "输入格式为：XXXX XX XX" << endl;
	cin >> inyear >> inmon >> inday;
	cout << "请输入支取时间：" << endl << "输入格式为：XXXX XX XX" << endl;
	cin >> outyear >> outmon >> outday;
}
int CURRENT::calctime()//计算日期
{
	int dur;
	dur = (outyear - inyear) * 360 + (outmon - inmon) * 30 + (outday - inday);
	return(dur);
}
int CURRENT::estimate()//定期存款计算
{
	int es, est = 0, cur = 0;
	es = calctime() / 30;
	if (es >= 3 && b == 1)
	{
		cout << "可存为定期存款！" << endl;
		if (es < 6)
		{
			est = 3;
		}
		else if (es >= 6 && es < 12)
		{
			est = 6;
		}
		else if (es >= 12 && es < 24)
		{
			est = 12;
		}
		else if (es >= 24 && es < 36)
		{
			est = 24;
		}
		else if (es >= 36 && es < 60)
		{
			est = 36;
		}
		else if (es >= 60)
		{
			est = 60;
		}
		cur = calctime() - est * 30;
		switch (est)
		{
		case 3:
			cout << "可存为三个月期定期存款！和" << cur << "天活期存款！" << endl;
			break;
		case 6:
			cout << "可存为六个月期定期存款！和" << cur << "天活期存款！" << endl;
			break;
		case 12:
			cout << "可存为一年期定期存款！和" << cur << "天活期存款！" << endl;
			break;
		case 24:
			cout << "可存为两年期定期存款！和" << cur << "天活期存款！" << endl;
			break;
		case 36:
			cout << "可存为三年期定期存款！和" << cur << "天活期存款！" << endl;
			break;
		case 60:
			cout << "可存为五年期定期存款！和" << cur << "天活期存款！" << endl;
			break;
		}
	}

	else
		cout << "您的活期存款时长为：" << calctime() << "天" << endl;
	return est;
}
CURRENT fixedtimepass(int type,CURRENT c)
{
	while (type > 0)
	{
		c.inmon++;
		if (c.inmon > 12)
		{
			c.inmon = 1;
			c.inyear++;
		}
		type--;
	}
	return c;
}
int yearjudge(CURRENT c)//闰平年判断
{
	if ((c.inyear % 4 == 0 && c.inyear % 100 != 0) || c.inyear % 400 == 0)
		return 1;
	else
		return 0;
}
CURRENT currenttimepass(CURRENT c)//日期变化
{
	int flag;
	flag = yearjudge(c);
	c.inday++;
	if ((c.inmon == 1 || c.inmon == 3 || c.inmon == 5 || c.inmon == 7 || c.inmon == 8 || c.inmon == 10 || c.inmon == 12) && c.inday == 32)
	{
		c.inmon++;
		c.inday = 1;
		if (c.inmon == 13)
		{
			c.inmon = 1;
			c.inyear++;
		}
	}
	if ((c.inmon == 4 || c.inmon == 6 || c.inmon == 9 || c.inmon == 11) && c.inday == 31)
	{
		c.inmon++;
		c.inday = 1;
	}
	if (c.inmon == 2 && c.inday == 29 && flag == 0)
	{
		c.inmon++;
		c.inday = 1;
	}
	if (c.inmon == 2 && c.inday == 30 && flag == 1)
	{
		c.inmon++;
		c.inday = 1;
	}
	return c;
}
int typechoose()
{
	int number;
	int exptype;//期望类型
	cout << "请选择定期存款方式" << endl;
	cout << "1.三个月" << endl;
	cout << "2.六个月" << endl;
	cout << "3.一年" << endl;
	cout << "4.两年" << endl;
	cout << "5.三年" << endl;
	cout << "6.五年" << endl;
    
	cin >> number;

	cout << "请选择是否约转" << endl;
	cout << "1.是" << endl;
	cout << "0.否" << endl;
	cin >> renewal;
	if (number == 1)
	{
		exptype = 3;
	}
	else if (number == 2)
	{
		exptype = 6;
	}
	else if (number == 3)
	{
		exptype = 12;
	}
	else if (number == 4)
	{
		exptype = 24;
	}
	else if (number == 5)
	{
		exptype = 36;
	}
	else if (number == 6)
	{
		exptype = 60;
	}

	return exptype;
}
class Rate
{
public:
	int year;//年
	int month;//月
	int day;//日
	float RateOfCall;//活期利率
	float ThreeMonthRate;//三个月利率
	float SixMonthRate;//六个月利率
	float OneYearRate;//一年利率
	float TwoYearRate;//两年利率
	float ThreeYearRate;//三年利率
	float FiveYearRate;//五年利率
	Rate(int yr, int mon, int dy,
		float roc, float tmr, float smr,
		float oyr, float tyr, float thyr,
		float fyr);
	Rate ratejudger(CURRENT c);
	~Rate();
	void Display();
};

Rate::Rate(int yr = 2007, int mon = 5, int dy = 19,
	float roc = 0.72, float tmr = 2.07, float smr = 2.61,
	float oyr = 3.06, float tyr = 3.69, float thyr = 4.41,
	float fyr = 4.95)
{
	year = yr;
	month = mon;
	day = dy;
	RateOfCall = roc;
	ThreeMonthRate = tmr;
	SixMonthRate = smr;
	OneYearRate = oyr;
	TwoYearRate = tyr;
	ThreeYearRate = thyr;
	FiveYearRate = fyr;
}

Rate::~Rate()
{

}

int readinterest(Rate a[])//读取利率信息
{
	int i;
	int count = 0;
	ifstream in("rate.txt");
	for (i = 0; ; i++)
	{
		if (!in.eof())
		{
			in >> a[i].year >> a[i].month >> a[i].day >> a[i].RateOfCall >> a[i].ThreeMonthRate >> a[i].SixMonthRate >> a[i].OneYearRate >> a[i].TwoYearRate >> a[i].ThreeYearRate >> a[i].FiveYearRate;
			count++;
		}
		else
			break;
	}
	return count;
}
void Rate::Display()
{
	cout << year << "." << month << "." << day << endl;
	cout << "活期： " << RateOfCall << " %" << endl;
	cout << "3个月： " << ThreeMonthRate << " %" << endl;
	cout << "6个月： " << SixMonthRate << " %" << endl;
	cout << "一年： " << OneYearRate << " %" << endl;
	cout << "二年： " << TwoYearRate << " %" << endl;
	cout << "三年： " << ThreeYearRate << " %" << endl;
	cout << "五年： " << FiveYearRate << " %" << endl;
	cout << endl;
}

Rate ratejudger(CURRENT c)
{
	int count;
	int i;
	Rate a[20];
	Rate use;
	count = readinterest(a);
	for (i = 0; i < count; i++)
	{
		if (c.inyear > a[i].year)
		{
			use = a[i];
		}
		else if (c.inyear == a[i].year)
		{
			if (c.inmon > a[i].month)
			{
				use = a[i];
			}
			else if (c.inmon == a[i].month)
			{
				if (c.inday >= a[i].day)
				{
					use = a[i];
				}
			}
			else use = use;
		}
		else use = use;
	}
	return use;
}

class Data
{
public:
	string username;
	CURRENT dat;
	float Principal;
	bool bb;
	int Exptype;
	int Renewal;
	float money;
	Data(){}
	~Data(){}
};

double CurrentDeposit(int principal, CURRENT c)//活期利息计算函数
{
	if((c.inyear == c.outyear) && (c.inmon == c.outmon) && (c.inday == c.outday))
	{
		return 0.0;
	}
	double interest = 0;
	double addinterest = 0;
	Rate use;
	int daycount = 0;
	CURRENT d = c;
	daycount++;
	d = currenttimepass(d);
	while (!((d.inyear == d.outyear) && (d.inmon == d.outmon ) && (d.inday == d.outday)))
	{

		daycount++;
		d = currenttimepass(d);
		if ((d.inmon ==2 || d.inmon == 4 || d.inmon == 6 || d.inmon == 9 || d.inmon == 11) && d.inday == 1)
		{
			daycount--;
		}
		if (d.inmon == 3 && d.inday == 1)
		{
			int flag;
			flag = yearjudge(d);
			if (flag == 0)
			{
				daycount += 2;
			}
			else if (flag == 1)
			{
				daycount += 1;
			}
		}
		if ((d.inmon == 3 || d.inmon == 6 || d.inmon == 9 || d.inmon == 12) && d.inday == 21)
		{
			use = ratejudger(d);
			interest = (principal * (use.RateOfCall / 36000) * daycount);
		    interest = ((long long int)(interest * 100 + 0.5)) / 100.0;
			addinterest += interest;
			principal += interest;
			daycount = 0;
		}
	}
	use = ratejudger(d);
	interest = addinterest + (principal * (use.RateOfCall / 36000) * daycount);
	interest = ((long long int)(interest * 100 + 0.5)) / 100.0;
	return interest;
}

double FixTermDeposit(int principal, int type, Rate r)//定期利息计算函数
{
	double interest;
	if (type == 3)
	{
		interest = (r.ThreeMonthRate / 100) * principal / 4;
	}
	if (type == 6)
	{
		interest = (r.SixMonthRate / 100) * principal / 2;
	}
	if (type == 12)
	{
		interest = (r.OneYearRate / 100) * principal;
	}
	if (type == 24)
	{
		interest = (r.TwoYearRate / 100) * principal * 2;
	}
	if (type == 36)
	{
		interest = (r.ThreeYearRate / 100) * principal * 3;
	}
	if (type == 60)
	{
		interest = (r.FiveYearRate / 100) * principal * 5;
	}
	return interest;
}

void search(string name)//用户信息查看
{
	ifstream in("data.txt");
	int count = 0;
	int i;
	Data d[100];
	for (i = 0; ; i++)
	{
		if (!in.eof())
		{
			in >> d[i].username >> d[i].Principal>>d[i].dat.inyear >> d[i].dat.inmon >> d[i].dat.inday >> d[i].dat.outyear >> d[i].dat.outmon >> d[i].dat.outday >> d[i].bb >> d[i].Exptype>> d[i].Renewal>>d[i].money;
			count++;
		}
		else
			break;
	}
	int k = 0;
	for (i = 0; i < count; i++)
	{
		if (d[i].username == name)
		{
			k++;
			cout << k << ". " << "存款金额： " << d[i].Principal << " 存款日期： " << d[i].dat.inyear << "." << d[i].dat.inmon << "." << d[i].dat.inday << " 取款日期： " << d[i].dat.outyear << "." << d[i].dat.outmon << "." << d[i].dat.outday;
			if (d[i].bb == 0)
			{
				cout << " 存款类型：活期存款";
			}
			
			else if (d[i].bb == 1)
			{
				cout << "存款类型： 定期存款";
			}
			if (d[i].Exptype == 0)
			{
				cout << " 存款期限： 无";
		    }
			if (d[i].Exptype == 3)
			{
				cout << " 存款期限： 三个月";
			}
			else if (d[i].Exptype == 6)
			{
				cout << " 存款期限： 六个月";
			}
			else if (d[i].Exptype == 12)
			{
				cout << " 存款期限： 一年";
			}
			else if (d[i].Exptype == 24)
			{
				cout << " 存款期限： 两年";
			}
			else if (d[i].Exptype == 36)
			{
				cout << " 存款期限： 三年";
			}
			else if (d[i].Exptype == 60)
			{
				cout << " 存款期限： 五年";
			}

			if (d[i].Renewal == -1)
			{
				cout << " 是否约转： 活期";
			}
			else if (d[i].Renewal == 0)
			{
				cout << " 是否约转： 否";
			}
			else if (d[i].Renewal == 1)
			{
				cout << " 是否约转： 是";
			}

			cout << " 结算后存款总额： " << fixed << setprecision(2) << d[i].money << endl;
		}
	}
	if (k == 0)
	{
		cout << "无记录！" << endl;
	}
}

string login()
{
	string name;
	user u;
	name = u.Display();//显示菜单 １注册；２登录
	cin.get();
	return name;
}
void Calculate(string name)
{
	ofstream outout;
	outout.open("data.txt", ios_base::out | ios_base::app);
	outout << name << " ";
	int type;//实际类型
	int exptype = 3;//期望类型
	int count;
	int day;
	double addinterest = 0.00;
	float principal,newprincipal;//本金
	double interest;
	double total;
	Rate a[20];
	count = readinterest(a);
	Rate use;
	CURRENT c;
	cout << "请输入存款金额" << endl;
	cin >> principal;
	outout << principal<<" ";
	c.inputtime();
	outout << c.inyear << " " << c.inmon << " " << c.inday << " " << c.outyear << " " << c.outmon << " " << c.outday << " " ;
	use = ratejudger(c);
	c.choose();
	day = c.calctime();
    type = c.estimate();
	if (b == 1)//定期存款类型选择
	{
		exptype = typechoose();
		outout << 1 <<" "<< exptype << " " << renewal << " ";
	}
	if (b == 0)//活期利息计算
	{
		interest = CurrentDeposit(principal, c);
		addinterest = interest;
		outout << 0 << " " << 0 << " " << -1 << " ";
	}
	if (type >= exptype)
	{
		interest = FixTermDeposit(principal, exptype, use);
		addinterest += ((long long int)(interest * 100 + 0.5)) / 100.0;
		newprincipal = principal + interest;
		type = type - exptype;
		while (type >= exptype && renewal == 1)
		{
			c = fixedtimepass(exptype, c);
			use = ratejudger(c);
			interest = FixTermDeposit(newprincipal, exptype, use);
			addinterest += ((long long int)(interest * 100 + 0.5)) / 100.0;
			newprincipal += interest;
			type = type - exptype;
		}
		c = fixedtimepass(exptype, c);
		use = ratejudger(c);
		//day = day - exptype * 30;
		interest = CurrentDeposit(newprincipal, c);
		addinterest += ((long long int)(interest * 100 + 0.5)) / 100.0;
	}
	total = principal + addinterest;
	cout << "利息为： " << addinterest << " 元" << endl;
	cout << "存款到期后共获得存款";
	printf("%.2lf", total);
	cout << " 元" << endl;
	outout << fixed << setprecision(4) << total << endl;
}

void menu()
{
	string name;
	int choose;
	int c;
	Rate r[100];
	int count;
	int i;
	count = readinterest(r);
	cout << "欢迎进入存款利息计算系统！" << endl;
	name = login();
aa:cout << "请选择你要进行的操作：" << endl;
	cout << "1. 利息计算" << endl;
	cout << "2. 用户计算记录查询" << endl;
	cout << "3.利率表查看" << endl;
	cin >> choose;
	if (choose == 1)
	{
		Calculate(name);
	}
	if (choose == 2)
	{
		search(name);
	}
	if (choose == 3)
	{
		for (i = 0; i < count; i++)
		{
			r[i].Display();
		}
	}
	cout << "是否返回上一步：(1.是 2.否)" << endl;
	cin >> c;
	if (c == 1)
	{
		goto aa;
	}
	if (c == 2)
	{

	}
}
int main()
{
	system("color 3f");
	menu();
}