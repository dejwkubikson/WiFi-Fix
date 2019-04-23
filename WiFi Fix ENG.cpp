#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
	cout << "Do you want to repair the network connection? (YES / NO) ";
	string zgoda;
	cin >> zgoda;
	
	if( zgoda == "YES" || zgoda == "Yes" || zgoda == "yes")
	{
		system("ipconfig /release");
		system("ipconfig /flushdns");
		system("ipconfig /registerdns");
		system("ipconfig /renew");
			
		system("netsh wlan show profiles");
		string nazwa_sieci;
		cout << endl;
		cout << "Network name: ";
		cin.clear();
		cin.sync();
		getline(cin, nazwa_sieci);
		
		string polecenie = "netsh wlan delete profile name =\"";
		polecenie += nazwa_sieci;
		string koniec = "\"";
		polecenie += koniec;
		
		system(polecenie.c_str());
		
		cout << "The computer will be restarted!" << endl;
		Sleep(5000);
		system("shutdown /r /f");
	
	}
	
	system("pause");
	return 0;
}
