#include <stdio.h>

/**
* is_palindrome - Function to check if the num is palindrome.
* @n: number to check
* Return: 1 if n is palindrome or 0 if not is palindrome
*/
int is_palindrome(unsigned long n)
{
unsigned long reversed = 0, temp = n;

while (temp != 0)
{
reversed = reversed * 10 + temp % 10;
temp = temp / 10;
}

return (n == reversed);
}
