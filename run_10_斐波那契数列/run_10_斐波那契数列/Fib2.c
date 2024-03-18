int Fib2(int n)//用递归写的斐波那契数列
{
	if (n <= 2)
		return 1;
	else
		return (Fib2(n - 1) + Fib2(n - 2));
}