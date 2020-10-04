#include<bits/stdc++.h> 

using namespace std;

// Primality Test using Sieve of Eratosthenes

int main() {

	bool sieve[1000001];	// Sieve Array - 0 is Prime and 1 is Not Prime
	
	for(int i=0;i<1000001;i++) sieve[i]=false;
	
	sieve[0]=sieve[1]=true;	//0 and 1 are not prime

	int i=2;
	while(i<1000001) {
		int j=i+i;			// i is Prime
		while(j<1000001) {
			sieve[j]=true;	// multiples of i are not prime
			j+=i;
		}
		i++;
		while(sieve[i]==1) i++;
	}

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		if(sieve[n]==0) cout<<"Prime\n";
		else cout<<"Not Prime\n";
	}

	return 0;

}
