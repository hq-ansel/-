#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	printf("\n型号:  计算器FGC101,实验初代机1.2版\n\n");
	printf("WARNING:此程序仅支持顺序计算（从左至右，不按四则运算顺序），请提前调好输入顺序！\n\n");
	printf("WARNING:此程序仅支持不多于100个数字的加减乘除与乘方运算（+ - * / ^）！结果默认保留六位小数。\n\n");
	printf("WARNING:使用时请输入完整的计算式，到‘=’结束，之后按回车键运行！\n\n");
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
			default: {printf("WARNING:非法输入！\n"); }
			}
		}
		if (fl)
		{
			printf("%f\n", last);
		}
		else
		{
			printf("输入有误，数据中出了个机关的卧底，分母不能为零，EL PSY KONGROO！\n");
		}
		printf("是否计算下一个式子？<Y/N>\n");
		do
		{
			fl = 0;
			scanf_s("%c", &b);
			rewind(stdin);
			if (b == 'Y')
			{
				sw = 1;
				printf("请输入下一个作战目标:\n");
			}
			else if (b == 'N')
				sw = 0;
			else
			{
				printf("非法输入，请重新输入:<Y/N>\n");
				fl = 1;
			}
		} while (fl);
	}
	printf("作战成功,已停止运行！\n");
	system("pause");
	return 0;
}