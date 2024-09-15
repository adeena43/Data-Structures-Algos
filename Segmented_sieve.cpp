#include<iostream>
#include<vector>

vector<long long> prime;

void sieve(int n)
{
	vector<bool> isPrime(n+1, true);
	
	for(long long i = 2; i<= n; i++)
	{
		if(isPrime[i])
		{
			prime.push_back(i);
			
			for(j = i*i; j<=n; j++)
			{
				isPrime[i] = false;
			}
		}
	}
}

void segmented_sieve(int h, int l)
{
	long long sq = sqrt(h);
	sieve(sq);
	vector<bool> isPrime(h-l+1, true);
	
	for(long long p:prime)
	{
		long long sm = (l/p)*p;
		if(sm<l)
		{
			sm+=p;
		}
		
		for(long long m = sm; m <=h; m+=p)
		{
			isPrime[m-l] false;
		}
		
		
	}
	
	for(long long i = l; i <= h; i++)
	{
		if(isPrime[i-l] == true)
		{
			cout<<i<<" ";
		}
	}
}

int main()
{
	
	return 0;
}
