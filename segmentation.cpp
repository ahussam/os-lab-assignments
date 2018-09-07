#include <iostream>
#include<conio.h>
using namespace std;

int i, j, seg_no, table_size;
int aAscii = 65;
int address;
char my_data;
char main_memory[32];
int offset;

struct segments {

	int seg_no;
	int base_address; 
	int limit;
	char value[10];
};

segments segs[10];

void main() {

	cout << "Enter table size: " << endl;
	cin >> table_size;

	for (i = 0; i < table_size; i++)
	{
		cout << "Enter base address for segment #" << i + 1 << endl;
		cin >> segs[i].base_address;
		cout << "Enter limit #" << i + 1 << endl;
		cin >> segs[i].limit;
		for ( j = 0; j < segs[i].limit; j++)
		{
			segs[i].value[j] = char(aAscii);
			aAscii ++;
		}
	
	}

	

	for (i = 0; i < table_size; i++)
	{
		for (j = 0; j <segs[i].limit; j++)
		{
			offset = j;
			address = segs[i].base_address + offset;
			main_memory[address] = segs[i].value[j];
		}
	}

	cout << "Enter a char to look for :" << endl;
	cin >> my_data;

	for ( i = 0; i < table_size; i++)
	{
		for (j = 0; j <segs[i].limit; j++)
		{
			if (segs[i].value[j] == my_data) {
			 offset = j;
			 address = segs[i].base_address + offset ;			
			}
		}
	}


	cout << "Address in physical memory is: " << address << endl;

	for ( i = 0; i < 32; i++)
	{
		if (main_memory[i] > 0) {
			cout << " " <<main_memory[i];
		}else {
			cout << " + ";
		}
	}

	_getch();
}