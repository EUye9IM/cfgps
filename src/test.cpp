#include <cfgps/cfgps.h>
#include <cstring>
#include <iostream>
using namespace std;
using namespace cfgps;
int main(int argc, const char **argv) {
	Parser p;
	p.set("子进程数量", 10);
	p.readFile("test.cfg");
	cout<<p.success()<<endl;
	cout << p.getInt("子进程数量") << endl;
	return 0;
}
