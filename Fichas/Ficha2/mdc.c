int mdc1 (int a, int b){

	int r;
	
	//a será sempre o mínimo
	if(a>b){
		int temp = b;
		b = a;
		a = temp;
	}

	for(r=a; (a%r || b%r) && r>1; r--);
	
	return r;
} 

int mdc2 (int a, int b){

	while(a!=b){
		if(a>b) 
			a-=b;
		else 
			b-=a;
	}

	return a;
}

int mdc3 (int a, int b){

	int r;

	//a será sempre o mínimo
	if(a>b){
		r = b;
		b = a;
		a = r;
	}

	while (a != 0){
		r = b % a;
	   	b = a;
		a = r;
	}

	return b;
}