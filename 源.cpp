#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	printf("\n�ͺ�:  ������FGC101,ʵ�������1.2��\n\n");
	printf("WARNING:�˳����֧��˳����㣨�������ң�������������˳�򣩣�����ǰ��������˳��\n\n");
	printf("WARNING:�˳����֧�ֲ�����100�����ֵļӼ��˳���˷����㣨+ - * / ^�������Ĭ�ϱ�����λС����\n\n");
	printf("WARNING:ʹ��ʱ�����������ļ���ʽ������=��������֮�󰴻س������У�\n\n");
	float a[100], last;
	int i = 0, flag, j, sw = 1, fl;
	char ch[100], b;
	while (sw)
	{
		flag = 1;
		fl = 1;
		for (i = 0; flag; i++)
		{
			scanf_s("%f%c", &a[i], &ch[i]);
			if (ch[i] == '=')
			{
				flag = 0;
			}
		}
		rewind(stdin);
		last = a[0];
		for (i = 0, flag = 1, j = 1; flag; i++, j++)
		{
			switch (ch[i])
			{
			case '+': {last = last + a[j]; }break;
			case '-': {last = last - a[j]; }break;
			case '*': {last = last * a[j]; }break;
			case '/':
			{
				if (fabs(a[j]) <= 0.000001)
					fl = 0;
				else
					last = last / a[j];
			}break;
			case '^': {last = pow(last, a[i + 1]); }break;
			case '=': {flag = 0; }break;
			default: {printf("WARNING:�Ƿ����룡\n"); }
			}
		}
		if (fl)
		{
			printf("%f\n", last);
		}
		else
		{
			printf("�������������г��˸����ص��Եף���ĸ����Ϊ�㣬EL PSY KONGROO��\n");
		}
		printf("�Ƿ������һ��ʽ�ӣ�<Y/N>\n");
		do
		{
			fl = 0;
			scanf_s("%c", &b);
			rewind(stdin);
			if (b == 'Y')
			{
				sw = 1;
				printf("��������һ����սĿ��:\n");
			}
			else if (b == 'N')
				sw = 0;
			else
			{
				printf("�Ƿ����룬����������:<Y/N>\n");
				fl = 1;
			}
		} while (fl);
	}
	printf("��ս�ɹ�,��ֹͣ���У�\n");
	system("pause");
	return 0;
}