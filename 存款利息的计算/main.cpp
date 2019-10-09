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
	string Register();//ע��
	string Enter();//��¼
	string Display();//����display��ʾswitch()�˵�
};

string user::Register()//ע��
{
	ofstream outFile;
	outFile.open("web1.txt", ios_base::out | ios_base::app);//��ע����û��������뱣�浽web1.txt�ļ�����
	if (!outFile.is_open())
	{
		cout << "���ź���δ��⵽�û������ļ�\n";
		cout << "�������\n";
		cin.get();
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	cout << "Please Enter members name�������û�������: \n";
	cin.get();
	getline(cin, name);
	name = name + "name";
	outFile << name << endl;//��¼ע������ϵ�web1.txt�ļ���
	cout << "Please Enter members code����������: \n";
	getline(cin, code);
	code = "code" + code;
	outFile << code << endl;//��¼ע������ϵ�web1.txt�ļ���
	cout << "ע��ɹ���\n";
	outFile.close();
	name = Display();
	return name;
}

string user::Enter()//��¼
{
	int flag = 0;
	cin.get();
	ifstream inFile;
	inFile.open("web1.txt");//��ȡweb1.txt�ļ��е�ע������
	if (!inFile.is_open())
	{
		cout << "���ź���δ��⵽�û������ļ�\n";
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	string temp;
	cout << "Please Enter members name�������û�������: \n";
	getline(cin, name);
	name = name + "name";
	while (getline(inFile, temp))//ƥ���û���
	{
		if (temp == name)
		{
			flag = 1;
			cout << "Please Enter members code����������: \n";
			getline(cin, code);
			code = "code" + code;
			getline(inFile, temp);//ƥ������
			if (temp == code)
			{
				cout << "��¼�ɹ�\n";
				return name;

			}
			else
			{
				cout << "�������\n";
				name = Display();//����
				return name;
			}
		}
	}
	if (flag == 0)
	{
		cout << "δ�ҵ����û�������������" << endl;
		name = Display();
		return name;//����
	}
}

string user::Display()//�˵�
{
	string name;
	cout << "1.Registerע��\n2.Enter��¼\n3.Exit�˳�" << endl << "Choice:";
	int choice;//ѡ��˵�
	cin >> choice;
	switch (choice)
	{
	case 1://ע��
		name = Register();
		break;
	case 2://��¼
		name = Enter();
		break;
	case 3://�˳�
		exit(EXIT_FAILURE);
	}
	return name;
}

class CURRENT
{

public:
	int outyear, outmon, outday;//֧ȡ����
	int inyear, inmon, inday;//�������
	void choose();
	void inputtime(void);
	int calctime();
	int estimate();
	CURRENT currenttimepass(int day, CURRENT c);
	CURRENT fixedtimepass(int type, CURRENT c);
};

void CURRENT::choose()//ѡ��������
{
	cout << "��ѡ��洢���ͣ�0���ڴ�� 1���ڴ��" << endl;
	cin >> b;
}
void CURRENT::inputtime(void)//��������
{
	cout << "��������ʱ�䣺" << endl << "�����ʽΪ��XXXX XX XX" << endl;
	cin >> inyear >> inmon >> inday;
	cout << "������֧ȡʱ�䣺" << endl << "�����ʽΪ��XXXX XX XX" << endl;
	cin >> outyear >> outmon >> outday;
}
int CURRENT::calctime()//��������
{
	int dur;
	dur = (outyear - inyear) * 360 + (outmon - inmon) * 30 + (outday - inday);
	return(dur);
}
int CURRENT::estimate()//���ڴ�����
{
	int es, est = 0, cur = 0;
	es = calctime() / 30;
	if (es >= 3 && b == 1)
	{
		cout << "�ɴ�Ϊ���ڴ�" << endl;
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
			cout << "�ɴ�Ϊ�������ڶ��ڴ���" << cur << "����ڴ�" << endl;
			break;
		case 6:
			cout << "�ɴ�Ϊ�������ڶ��ڴ���" << cur << "����ڴ�" << endl;
			break;
		case 12:
			cout << "�ɴ�Ϊһ���ڶ��ڴ���" << cur << "����ڴ�" << endl;
			break;
		case 24:
			cout << "�ɴ�Ϊ�����ڶ��ڴ���" << cur << "����ڴ�" << endl;
			break;
		case 36:
			cout << "�ɴ�Ϊ�����ڶ��ڴ���" << cur << "����ڴ�" << endl;
			break;
		case 60:
			cout << "�ɴ�Ϊ�����ڶ��ڴ���" << cur << "����ڴ�" << endl;
			break;
		}
	}

	else
		cout << "���Ļ��ڴ��ʱ��Ϊ��" << calctime() << "��" << endl;
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
int yearjudge(CURRENT c)//��ƽ���ж�
{
	if ((c.inyear % 4 == 0 && c.inyear % 100 != 0) || c.inyear % 400 == 0)
		return 1;
	else
		return 0;
}
CURRENT currenttimepass(CURRENT c)//���ڱ仯
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
	int exptype;//��������
	cout << "��ѡ���ڴ�ʽ" << endl;
	cout << "1.������" << endl;
	cout << "2.������" << endl;
	cout << "3.һ��" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	cout << "6.����" << endl;
    
	cin >> number;

	cout << "��ѡ���Ƿ�Լת" << endl;
	cout << "1.��" << endl;
	cout << "0.��" << endl;
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
	int year;//��
	int month;//��
	int day;//��
	float RateOfCall;//��������
	float ThreeMonthRate;//����������
	float SixMonthRate;//����������
	float OneYearRate;//һ������
	float TwoYearRate;//��������
	float ThreeYearRate;//��������
	float FiveYearRate;//��������
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

int readinterest(Rate a[])//��ȡ������Ϣ
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
	cout << "���ڣ� " << RateOfCall << " %" << endl;
	cout << "3���£� " << ThreeMonthRate << " %" << endl;
	cout << "6���£� " << SixMonthRate << " %" << endl;
	cout << "һ�꣺ " << OneYearRate << " %" << endl;
	cout << "���꣺ " << TwoYearRate << " %" << endl;
	cout << "���꣺ " << ThreeYearRate << " %" << endl;
	cout << "���꣺ " << FiveYearRate << " %" << endl;
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

double CurrentDeposit(int principal, CURRENT c)//������Ϣ���㺯��
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

double FixTermDeposit(int principal, int type, Rate r)//������Ϣ���㺯��
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

void search(string name)//�û���Ϣ�鿴
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
			cout << k << ". " << "���� " << d[i].Principal << " ������ڣ� " << d[i].dat.inyear << "." << d[i].dat.inmon << "." << d[i].dat.inday << " ȡ�����ڣ� " << d[i].dat.outyear << "." << d[i].dat.outmon << "." << d[i].dat.outday;
			if (d[i].bb == 0)
			{
				cout << " ������ͣ����ڴ��";
			}
			
			else if (d[i].bb == 1)
			{
				cout << "������ͣ� ���ڴ��";
			}
			if (d[i].Exptype == 0)
			{
				cout << " ������ޣ� ��";
		    }
			if (d[i].Exptype == 3)
			{
				cout << " ������ޣ� ������";
			}
			else if (d[i].Exptype == 6)
			{
				cout << " ������ޣ� ������";
			}
			else if (d[i].Exptype == 12)
			{
				cout << " ������ޣ� һ��";
			}
			else if (d[i].Exptype == 24)
			{
				cout << " ������ޣ� ����";
			}
			else if (d[i].Exptype == 36)
			{
				cout << " ������ޣ� ����";
			}
			else if (d[i].Exptype == 60)
			{
				cout << " ������ޣ� ����";
			}

			if (d[i].Renewal == -1)
			{
				cout << " �Ƿ�Լת�� ����";
			}
			else if (d[i].Renewal == 0)
			{
				cout << " �Ƿ�Լת�� ��";
			}
			else if (d[i].Renewal == 1)
			{
				cout << " �Ƿ�Լת�� ��";
			}

			cout << " ��������ܶ " << fixed << setprecision(2) << d[i].money << endl;
		}
	}
	if (k == 0)
	{
		cout << "�޼�¼��" << endl;
	}
}

string login()
{
	string name;
	user u;
	name = u.Display();//��ʾ�˵� ��ע�᣻����¼
	cin.get();
	return name;
}
void Calculate(string name)
{
	ofstream outout;
	outout.open("data.txt", ios_base::out | ios_base::app);
	outout << name << " ";
	int type;//ʵ������
	int exptype = 3;//��������
	int count;
	int day;
	double addinterest = 0.00;
	float principal,newprincipal;//����
	double interest;
	double total;
	Rate a[20];
	count = readinterest(a);
	Rate use;
	CURRENT c;
	cout << "����������" << endl;
	cin >> principal;
	outout << principal<<" ";
	c.inputtime();
	outout << c.inyear << " " << c.inmon << " " << c.inday << " " << c.outyear << " " << c.outmon << " " << c.outday << " " ;
	use = ratejudger(c);
	c.choose();
	day = c.calctime();
    type = c.estimate();
	if (b == 1)//���ڴ������ѡ��
	{
		exptype = typechoose();
		outout << 1 <<" "<< exptype << " " << renewal << " ";
	}
	if (b == 0)//������Ϣ����
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
	cout << "��ϢΪ�� " << addinterest << " Ԫ" << endl;
	cout << "���ں󹲻�ô��";
	printf("%.2lf", total);
	cout << " Ԫ" << endl;
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
	cout << "��ӭ��������Ϣ����ϵͳ��" << endl;
	name = login();
aa:cout << "��ѡ����Ҫ���еĲ�����" << endl;
	cout << "1. ��Ϣ����" << endl;
	cout << "2. �û������¼��ѯ" << endl;
	cout << "3.���ʱ�鿴" << endl;
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
	cout << "�Ƿ񷵻���һ����(1.�� 2.��)" << endl;
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