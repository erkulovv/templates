struct Error {
	template<class T1, class T2> Error& operator << (pair<T1, T2> p) {
		return *this << "(" << p.first << ", " << p.second << ")";
	}
	template<class T> typename enable_if<is_scalar<T>::value || is_same<T,string>::value, Error&>::type operator << (T a) {
		cerr << boolalpha << a;
		return *this;
	}
	template<class T> typename enable_if<!is_scalar<T>::value && !is_same<T,string>::value, Error&>::type operator << (T a) {
		*this << "{";
		for (auto it = a.begin(); it != a.end(); it++) 
			*this << ", " + 2 * (it == a.begin()) << *it;
		return *this << "}";
	}
	template<class T1, class T2, class T3> Error& operator << (tuple<T1,T2,T3> t) {
		return *this << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
	}
	template<class T1, class T2, class T3, class T4> Error& operator << (tuple<T1, T2, T3, T4> t) {
		return *this << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << ")";
	}
	Error& operator << (vector<bool> v) {
		return *this << vector<int>(v.begin(), v.end());
	}
	template<class T> Error& operator << (queue<T> q) {
		vector<T> res;
		while (!q.empty()) {
			res.push_back(q.front());
			q.pop();
		}
		return *this << res;
	}
	template<class T> Error& operator << (stack<T> s) {
		vector<T> res;
		while (!s.empty()) {
			res.push_back(s.top());
			s.pop();
		}
		return *this << res;
	}
};

#define err Error()

template<class T> void dout(string name, T arg) {
	err << name << " : " << arg << "\n";
}

template<class T1, class... T2> void dout(string names, T1 arg, T2... args) {
	err << names.substr(0, names.find(",")) << " : " << arg << " | ";
	dout(names.substr(names.find(",") + 2), args...);
}

#ifdef LOCAL
	#define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
	#define debug(...) 123
#endif
