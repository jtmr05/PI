float multInt1 (int n, float m){
	int i;
	float r=0.0;

	for(i=0; i<n; i++)
		r+=m;

	return r;
}

float multInt2 (int n, float m){
	float r=0.0;

	while(n>0){

		if(n%2)
			r+=m;

		n=n/2;
		m=m*2;
	}

	return r;
}