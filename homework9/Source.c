#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>


void main()
{
	setlocale(LC_ALL, "RUS");

	char s;
	int a;
	float u;
	puts("������� ������");
	scanf("%c", &s);
	puts("������� �������� ������� ��������");
	scanf("%d", &a);
	puts("������� �������� ���� �������� (����� ��������� � ������� 45 ��������)");
	scanf("%f", &u);
	puts("\n");

	u = fabs(u);   // ���� ������, ������ ��� ���� ��� ����� ������� ���� �� ������
	while (u > 90)
	{
		u -= 90;  // �������� ���� �� ��������� � ������� [0, 90]
	}

	// ��������� ��� [0; 22.5) (67.5; 90]
	// ������������ (= ��������� ���� �� 45) ��� [22.5; 67.5] 


	if (22.5 <= u && u <= 67.5)
	{
		// ������ ������ ������ �����
		for (int i = 1; i <= a - 1; i++) printf("%3c", ' ');
		printf("%3c\n", s);

		// ������ �������� �����
		int count_c_column = 1;
		int count_l_column = a - 2;
		for (int row = 2; row <= a; row++)
		{

			for (int empty_col = count_l_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			for (int empty_col = count_c_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			count_c_column += 2;
			count_l_column--;
			printf("\n");
		}

		// ������ �������� �����
		count_l_column = 1;
		count_c_column -= 4;
		for (int row = 2; row < a; row++)
		{

			for (int empty_col = count_l_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			for (int empty_col = count_c_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			count_c_column -= 2;
			count_l_column++;
			printf("\n");
		}

		// ������ ��������� ������ �����
		for (int i = 1; i <= a - 1; i++) printf("%3c", ' ');
		printf("%3c\n", s);
	}
	else
	{
		// ������ ������ ��������
		for (int i = 1; i <= a; i++) printf("%3c", s);
		printf("\n");

		// �������� ��������
		for (int row = 2; row <= a - 1; row++)
		{
			printf("%3c", s);
			for (int j = 1; j <= a - 2; j++) printf("%3c", ' ');
			printf("%3c\n", s);
		}

		// ��������� ������ ��������
		for (int i = 1; i <= a; i++) printf("%3c", s);
	}

}