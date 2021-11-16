int fib1(int n){

	if(n<1)
		return 0;

	if(n==1 || n==2)
		return 1;

	int r;
	r = fib1(n-1) + fib1(n-2);

	return r;
}

int fib2(int n){

	if(n==1 || n==2)
		return 1;

	int u1 = 1, u2 = 1, i = 3, r=0;
	
	while(i<=n){
		r=u1+u2;
		u1=u2;
		u2=r;
		i++;
	}

	return r;
}