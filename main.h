#ifndef MAIN_H
#define MIAN_H
/**
 * struct ops - structure for printing
 * @a: character representing format specifier
 * @f: pointer to printing function based on specifier
 *
 * Description: This structure forms is designed to allow for printing to std
 * output based on modifier passed to function.
 */

typedef struct ops
{
	char a;
	void (*f)(void *);
} ops_p;

int _putchar(char c);
int _printf(const char *format, ...);
void op_char(void *);
void op_str(void *);
void op_percent(void *);
void op_int(void *);
void op_bin(unsigned int n);
void op_uint(unsigned int n);
void op_oct(unsigned int n);
void op_hex(unsigned int n);

#endif /* #ifndef MAIN_H */
