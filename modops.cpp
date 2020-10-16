const int mod = (int) 1e9 + 7;

int add(int a, int b) {
	a += b;
	while (a >= mod) {
		a -= mod;
	}
	while (a < 0) {
		a += mod;
	}
	return a;
}


void add_self(int& a, int b) {
	a = add(a, b);
}

void sub_self(int& a, int b) {
	a = add(a, -b);
}

int mult(int a, int b) {
	return (long long) a * b % mod;
}

void mult_self(int& a, int b) {
	a = mult(a, b);
}

int powmod(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b % 2 == 0) {
		return mult(a, powmod(a, b >> 1));
	}
	else {
		int c = powmod(a, b - 1);
		return mult(c, c);
	}
}


