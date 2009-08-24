#include <iostream>
#include <string>
#include <fstream>
#define GMAIL_USERNAME "your_gmail_username"
#define GMAIL_PASSWORD "your_gmail_password"
using namespace std;

int main ()
{
	string status_str;
	int status;
	string user = GMAIL_USERNAME;
	string passwd = GMAIL_PASSWORD;
	
	cout <<"GMAIL NOTIFY - by pH"<< endl;
		system(("curl https://" + user + ":" + passwd + "@mail.google.com/mail/feed/atom | grep fullcount > count_status.txt").c_str());
		ifstream infile;
		infile.open("count_status.txt");
		getline(infile, status_str);
		infile.close();
		system("rm count_status.txt");
		
		status_str.erase(0, 11);
		status_str.erase(1, strlen(status_str.c_str()));
		status = atoi(status_str.c_str());		
		cout << status << endl;
		if (status == 0)
		{
			system("/Users/fastshop/Desktop/NerdKits/Code/write_msg/comunicator/arduino-serial -b 115200 -p /dev/cu.PL* -s 0");
		}
		if (status > 0)
		{
			system("/Users/fastshop/Desktop/NerdKits/Code/write_msg/comunicator/arduino-serial -b 115200 -p /dev/cu.PL* -s 1");
		}
}