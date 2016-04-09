#include<stdio.h>
#include<string.h>

typedef struct testcases
{
	char t_date[10];
	char e_form[100];
}testcases;
testcases testcase[4] = { 
	{ "06-10-1995", "sixth october one thousand nine hundred and ninty five " },
	{ "24-12-1993", "twentyfourth december one thousand nine hundred and ninty three " },
	{ "10-09-0456", "tenth september four hundred and fifty six " },
	{"41-10-1996", "invalid date"}
};


typedef struct day
{
	char number[20];
}day;
day date[31] = { { "first " }, { "second " }, { "third " }, { "fourth " }, { "fifth " }, { "sixth " }, { "seventh " }, { "eigth " }, { "nineth " }, { "tenth " }, { "eleventh " }, { "twelveth " }, { "thirteenth " }, { "fourteenth " }, { "fifteenth " }, { "sixteenth " }, { "seventeenth " }, { "eighteenth " }, { "nineth " }, { "twenty " }, { "twentyfirst " }, { "twentysecond " }, { "twentythird " }, { "twentyfourth " }, { "twentyfifth " }, { "twentysixth " }, { "twentyseventh " }, { "twentyeighth " }, { "twentyninth " }, { "thirtyth " }, { "thirtyfirst " } };
day month[12] = { { "january " }, { "february " }, { "march " }, { "april " }, { "may " }, { "june " }, { "july " }, { "august " }, { "september " }, { "october " }, { "november " }, { "december " } };

day x[27] = { { "one " }, { "second " }, { "three " }, { "four " }, { "five " }, { "six " }, { "seven " }, { "eight " }, { "nine " }, { "ten " }, { "eleventh " }, { "twelve " }, { "thirteen " }, { "fourteen " }, { "fifteen " }, { "sixteen " }, { "seventeen " }, { "eighteen " }, { "nineteen " }, { "twenty " }, { "thirty " }, { "fourty " }, { "fifty " }, { "sixty " }, { "seventy " }, { "eighty " }, { "ninty " } };
int validDate(int,int,int);
int isLeap(int y) {
	if (y % 400 == 0)
		return 1;
	else if (y % 100 == 0)
		return 0;
	else if (y % 4 == 0)
		return 1;
	else
		return 0;
}
void test(int index)
{

	char output[100];
	char s[10];
	strcpy(s, testcase[index].t_date);
	int d1, d2, m1, m2, y1, y2, y3, y4;
	d1 = (s[0] - '0');
	d2 = (s[1] - '0');
	m1 = (s[3] - '0');
	m2 = (s[4] - '0');
	y1 = (s[6] - '0');
	y2 = (s[7] - '0');
	y3 = (s[8] - '0');
	y4 = (s[9] - '0');
	if (validDate(d1 * 10 + d2, m1 * 10 + m2, y1 * 1000 + y2 * 100 + y3 * 10 + y4))
	{
		int no = (d1 * 10) + d2 - 1;
		strcpy(output, date[no].number);
		no = m1 * 10 + m2 - 1;
		strcat(output, month[no].number);
		if (y1 != 0)
		{
			no = y1 - 1;
			strcat(output, x[no].number);
			strcat(output, "thousand ");
		}
		if (y2 != 0)
		{
			no = y2 - 1;
			strcat(output, x[no].number);
			strcat(output, "hundred and ");
		}

		if (y3 <= 1)
		{
			no = (y3 * 10) + y4 - 1;
			strcat(output, x[no].number);

		}
		else
		{
			no = y3 + 17;
			strcat(output, x[no].number);
			if (y4 > 0){ no = y4 - 1; strcat(output, x[no].number); }
		}

	}
	else
		strcpy(output, "invalid date");
	if (strcmp(output, testcase[index].e_form))
		printf("FAIL\n");
	else
		printf("PASS\n");
}
int validDate(int d,int m,int y)
{
	if (m < 1 || m > 12 || y < 1) //if month or year is invalid
		return 0;
	int maxDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //if month and year are valid the initialize max days in a month
	if (isLeap(y)) //checks is a leap year or not
		maxDays[1] ++;  //if leap then increases max days of feb
	if (d < 1 || d > maxDays[m - 1])  //validates the date
		return 0;
	return 1;
}
int main()
{
	int index;
	for (index = 0; index<4; index++)
	{
		test(index);
	}
	getchar();
	return 0;
}


