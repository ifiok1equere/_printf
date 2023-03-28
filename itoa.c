/**
 * itoa - converts a decimal number to a string
 * @num: decimal number
 * @str: string conversion result
 * @base: base of the number to be converted
 *
 * Return: a pointer to the converted string
 */
char * itoa(int num, char* str, int base)
{
	int digit, j, k, i = 0, is_negative = 0;
	char temp;

	/* Handle negative numbers for decimal base */
	if (num < 0 && base == 10)
	{
		is_negative = 1;
		num = -num;
	}
	/* Conversion of each digit to ASCII and storing in the string*/
	do {
		digit = num % base;
		str[i++] = digit < 10 ? digit + '0' : digit + 'a' - 10;
		num /= base;
	} while (num > 0);
	/* Add the negative sign if necessary */
	if (is_negative)
		str[i++] = '-';
	/* String reversal */
	str[i] = '\0';
	for (j = 0, k = i - 1; j < k; j++, k--)
	{
		temp = str[j];
		str[j] = str[k];
		str[k] = temp;
	}
	return (str);
}
