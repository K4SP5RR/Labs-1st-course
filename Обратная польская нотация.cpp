#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "ctype.h"
#include "locale.h"

struct Stek {
	char n;
	double res;
	struct Stek* ptr;
};

Stek* CreateNewOp(char op) {
	Stek* stek = (Stek*)malloc(sizeof(Stek));
	stek->n = op;
	stek->ptr = NULL;

	return stek;
}

Stek* CreateNewRE(double x) {
	Stek* stek = (Stek*)malloc(sizeof(Stek));
	stek->res = x;
	stek->ptr = NULL;

	return stek;
}

Stek* Add(Stek* head, Stek* nw_st) {
	nw_st->ptr = head;
	head = nw_st;
	return head;
}

Stek* Delete(Stek* head) {
	Stek* nw_head = head->ptr;
	free(head);
	return nw_head;
}

void Print(Stek* head) {
	Stek* current = head;
	while (current != NULL)
	{
		printf_s("%f ", current->res);
		current = current->ptr;
	}
	return;
}

int Priority(char oper) {
	switch (oper) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '~': return 3;
	default: return 0;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	char str[100];
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	Stek* operations = NULL;
	char output[50][20] = {0};
	int num_count = 0, num_len = 0;
	int l = strlen(str);
	if (str[0] == '-') {
		str[0] = '~';
	}
	for (int i = 0; i < l-1; i++)
	{
		if (str[i] == '(' && str[i+1] == '-')
		{
			str[i + 1] = '~';
		}
	}
	for (int i = 0; i < l; i++) {
		if (strchr("1234567890", str[i]) != NULL)
		{
			output[num_count][num_len++] = str[i];
		}
		else {
			if (strchr("+-*/()~", str[i]) != NULL)
			{
				if (num_len > 0) {
					output[num_count++][num_len] = '\0';
					num_len = 0;
				}
				Stek* operation = NULL;

				switch (str[i])
				{
				case '~': case '+': case '-': case '*': case '/':
					operation = CreateNewOp(str[i]);
					while (operations != NULL && operations->n != '(' && Priority(str[i]) <= Priority(operations->n)) {
						output[num_count][0] = operations->n;
						output[num_count++][1] = '\0';
						operations = Delete(operations);
					}
					operations = Add(operations, operation);
					break;
				case '(':
					operation = CreateNewOp(str[i]);
					operations = Add(operations, operation);
					break;
				case ')':
					while (operations != NULL && operations->n != '(') {
						output[num_count][0] = operations->n;
						output[num_count++][1] = '\0';
						operations = Delete(operations);
					}
					if (operations == NULL) {
						printf_s("ERROR: Отсутствует (");
						return 1;
					}
					operations = Delete(operations);
					break;
				default:
					break;
				}
			}
			else {
				printf_s("ERROR: Неопознанный символ '%c'", str[i]);
				return 1;
			}
		}
	}
	if (num_len > 0) {
		output[num_count][num_len] = '\0';
		num_count++;
	}
	while (operations != NULL)
	{
		if (operations -> n == '(')
		{
			printf_s("ERROR: Отсутствует )");
			return 1;
		}
		output[num_count][0] = operations->n;
		output[num_count++][1] = '\0';
		operations = Delete(operations);
	}
	for (int i = 0; i < num_count; i++)
	{
		printf_s("%s ", output[i]);
			
	}
	printf_s("\n");
	int len = 0;
	for (int i = 0; i < num_count; i++)
	{
		Stek* operation = NULL;
		if (isdigit(output[i][0]))
		{
			double num = atof(output[i]);
			operation = CreateNewRE(num);
			operations = Add(operations, operation);
		}
		else if (strchr("+-*/~", output[i][0])){
			if (output[i][0] == '~')
			{
				if (operations == NULL)
				{
					printf_s("ERROR: Много операторов");
					return 1;
				}
				double a = operations->res;
				operations = Delete(operations);
				operations = Add(operations, CreateNewRE(-a));
			}
			else 
			{
				if (operations == NULL || operations->ptr == NULL)
				{
					printf_s("ERROR: Много операторов");
					return 1;
				}
				double a = operations->res;
				operations = Delete(operations);
				double b = operations->res;
				operations = Delete(operations);
				double res;
				switch (output[i][0])
				{
				case '+': res = b + a; break;
				case '-': res = b - a; break;
				case '*': res = b * a; break;
				case '/': 
					if (a == 0) {
						printf_s("ERROR: Деление на 0");
						return 1;
					}
					res = b / a; 
					break;
				default:
					break;
				}
				operations = Add(operations, CreateNewRE(res));
			}
		}
	}
	if (operations->ptr != NULL)
	{
		printf_s("ERROR: Мало операторов");
		return 1;
	}
	Print(operations);
}