void InsertionSort(int *a, int len)
{
	for (int j=1; j<len; j++)
	{
		int key = a[j];
		int i = j-1;
		while (i>=0 && a[i]>key)
		{
			a[i+1] = a[i];
			i--;//不断左移寻找比j大的 （之前一直习惯性的认为是左右相邻的转换 后来发现傻逼了）
		}
		a[i+1] = key;
	}
}
