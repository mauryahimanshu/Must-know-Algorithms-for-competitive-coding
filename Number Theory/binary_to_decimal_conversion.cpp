#include<iostream>
#include<cmath>
using namespace std;
int binatodeciconvert(int n)
{
    int bi_no=0,power=0;
	long int num;
	num = n;
	while(num!=0)
	{
	   if(num%10 == 1)
	   {
            bi_no = bi_no + pow(2,power);
		    power++;
		    num = num/10;
	   }
	   else
	   {
		   power++;
		   num = num/10;
	   }
	}
	return bi_no;
}

int main()
{
	long int n, result;
	cin>>n;
	result = binatodeciconvert(n);
	cout<<result;

	return 0;
}
