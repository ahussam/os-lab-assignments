#include<iostream>
#include<conio.h>

using namespace std;

int page_size, offset, frame_size, address, logical_size,search_offset,frame_no;

void main() {

	cout << "Enter logical memory size: " << endl;
	cin >> logical_size;
	
	while (logical_size % 2 != 0) {
		cout << "Enter logical memory size: " << endl;
		cin >> logical_size;
	}

	int *offset = new int[logical_size];

	cout << "Enter page size: " << endl;
	cin >> page_size;
	frame_size = page_size;
	
	
	int x = 0;
	for (int i = 0; i < logical_size; i++)
	{

		offset[i] = x;
		x++;
		if (x == page_size) {
			x = 0;
		}
	}

	char *logical_memory = new char[logical_size];
	 x = 65;

	for (int i = 0; i < logical_size; i++) {
		logical_memory[i] = char(x);
		x++;
	}
	


	int *page_table = new int[logical_size / page_size];

	for (int i = 0; i < logical_size / page_size; i++)
	{
		cout << "Enter frame for page " << i + 1<<" : "<<endl;
		cin >> page_table[i];
	}

	char *main_memory = new char[logical_size * 2];

	for (int i = 0; i < logical_size; i++)
	{
		address = page_table[i/page_size] * page_size + offset[i];
		main_memory[address] = logical_memory[i];
	}

	// cout << main_memory[8];

	char y;
	cout << "Enter a letter to look for: " << endl;
	cin >> y;
	for (int i = 0; i < logical_size; i++)
	{
		if (logical_memory[i] == y) {
			search_offset = offset[i];
			frame_no = page_table[i / page_size];
		}
	}

	
	address = (frame_no * page_size) + search_offset;
	cout << "Physical Address is: " << address << endl;

	for (int i = 0; i < logical_size * 2; i++) {
		if (main_memory[i] > 0) {
			cout << main_memory[i]<<endl;
		}
		else {
			cout << "Not used!" << endl;
		}
	}
	_getch();
}