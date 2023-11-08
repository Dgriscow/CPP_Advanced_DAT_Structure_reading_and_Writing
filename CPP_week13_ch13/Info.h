#pragma once

const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;

class Info //class structure for users
{
public:

	
	char name[NAME_SIZE];
	int age;
	char address1[ADDR_SIZE];
	char address2[ADDR_SIZE];
	char phone[PHONE_SIZE];
};