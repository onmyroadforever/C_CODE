int Fib2(int n)//�õݹ�д��쳲���������
{
	if (n <= 2)
		return 1;
	else
		return (Fib2(n - 1) + Fib2(n - 2));
}