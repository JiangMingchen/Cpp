#include <iostream>
#include<string>
enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
std::string state;
class CPU
{
private:
	std::string name;
	CPU_Rank rank;
	int frequency;
	float voltage;
	std::string state;
public:
	
	CPU();
	CPU(std::string nm,CPU_Rank rk, int fr, float vol);
	~CPU();
	void run();
	void stop();
};
CPU::CPU()
{
	name = "Default CPU";
	rank = P1;
	frequency = 0;
	voltage = 0.0;
	state = "uknown.";
}
CPU::~CPU()
{
	std::cout<<name<< ": CPU deleted." << std::endl;
}

CPU::CPU(std::string nm,CPU_Rank rk, int fr, float vol)
{
	name = nm;
	rank = rk;
	frequency = fr;
	voltage = vol;
	std::cout <<name<< ": Construction succeed." << std::endl;
}
void CPU::run() {
	std::cout<<name<< ": CPU rank: " << rank << " Frequency: " << frequency << " MHz " << "Voltage; " << voltage << " V is running.\n";
	state = "runing";
}
void CPU::stop() {
	std::cout<<name<< ": CPU rank: " << rank << " Frequency: " << frequency << " MHz " << "Voltage; " << voltage << " V is stopped.\n";
	state = "stopped";
}
int main()
{
	CPU a("a",P1, 2, 3);
	CPU b("b",P2, 1, 4);
	CPU c("c",P3, 5, 3);
	a.run();
	b.run();
	a.stop();
	b.stop();
	c.run();
	c.stop();	
}

