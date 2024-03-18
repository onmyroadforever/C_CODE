int fac(int x)
{
	if (x > 1)
	{
		return x * fac(x - 1);
	}
	else
		return 1;
}