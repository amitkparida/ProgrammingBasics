


#include <iostream>
using namespace std;

// Implementation of atoi()
int StringToInt(char* str)
{
	int result = 0;
	int sign = 1;
	int i = 0; //Initialize index of first digit

	if (str[0] == '-') {
		sign = -1; //Update the sign
		i++;       //Update the index of first digit
	}

	// Iterate through all digits and update the result
	for (; str[i] != '\0'; i++) {
		result = result * 10 + str[i] - '0';
	}

	// Return result with sign
	return sign * result;
}

int StringToInt1(char* str)
{
	int result = 0;
	bool isNegative = false;

	int i = 0;     //Initialize index of first digit
	if (str[0] == '-') {
		isNegative = true; //Update the sign
		i = 1;             //Update the index of first digit
	}

	for (; str[i] != '\0'; i++) {
		result = result * 10 + str[i] - '0';
	}

	return isNegative? -result : result;
}


/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	while (start < end)
	{
		swap(*(str + start), *(str + end));
		start++;
		end--;
	}
}

// Implementation of itoa()

// For any positive integer X, the least significant digit in the decimal representation of X is (X % 10).
// The remaining digits are X / 10.

char* IntToString(int num, char* str, int base)
{
	int i = 0;
	bool isNegative = false;

	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	// In standard itoa(), negative numbers are handled only with base 10. Otherwise numbers are considered unsigned.
	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}

	// Process individual digits
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	// If number is negative, append '-'
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0'; // Append string terminator

	// Reverse the string
	reverse(str, i);

	return str;
}

// Only Decimal
// For any positive integer X, the least significant digit in the decimal representation of X is (X % 10).
// The remaining digits are X / 10.
char* IntToString1(int num, char* str)
{
	int i = 0;
	bool isNegative = false;

	if (num < 0)
	{
		isNegative = true;
		num = -num;
	}

	//Handle 0 explicitely, otherwise empty string is printed for 0. 
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	// Process individual digits
	while (num != 0)
	{
		str[i++] = '0' + num % 10;
		num = num / 10;
	}

	//If you use do while loop, no need to handle (num == 0) condition explicity as above.
	//do
	//{
	//	str[i++] = '0' + num % 10;
	//	num = num / 10;
	//} while (num != 0);

	if (isNegative)
		str[i++] = '-';

	str[i] = '\0'; // Append string terminator

	// Reverse the string
	reverse(str, i);

	return str;
}



int main()
{
	char str[10];
	int num, result;

	printf("Enter a number: ");
	scanf_s("%d", &num);
	IntToString(num, str, 10);
	printf("Number converted to string: %s\n", str);
	result = StringToInt1(str);
	printf("String converted back to number: %d\n", result);

	//char str[100];
	//cout << "Base:10 " << IntToStr(1567, str, 10) << endl;
	//cout << "Base:10 " << IntToStr(-1567, str, 10) << endl;
	//cout << "Base:2 " << IntToStr(1567, str, 2) << endl;
	//cout << "Base:8 " << IntToStr(1567, str, 8) << endl;
	//cout << "Base:16 " << IntToStr(1567, str, 16) << endl;

	return 0;
}