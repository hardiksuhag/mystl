# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define int ll

class Vector{
private:
	int vsize; // total alloted size 
	int* vbegin; // start pointer of vector
	int ptr; // used size of vector/ index for next addition
	void cast_to_size(int nvsize){ // function for resizing vector
		int* nb = new int[nvsize];
		for(int i = 0; i<ptr ; i++){
			nb[i] = vbegin[i];
		}
		delete vbegin;
		vbegin = nb;
		vsize = nvsize;
		return;
	}
	void check_and_table_double(){ // table doubling if alloted size = allocated size
		if(ptr!=vsize) return;
		int nvsize = vsize*2;
		cast_to_size(nvsize);
	}
	void check_and_table_halve(){ // table halving if less that a third filled
		if(vsize<20 || ((ptr*3 + 10) > vsize)) return;
		int nvsize = (vsize/2)+1;
		cast_to_size(nvsize);
	}
public:
	Vector(){ // constructor
		this->vsize = 10;
		this->vbegin = new int[vsize];
		this->ptr = 0;
	}
	Vector(int given_size){
		this->vsize = 2*given_size;
		this->vbegin = new int[vsize];
		this->ptr = given_size;
	}
	Vector(int given_size, int def_val){
		this->vsize = 2*given_size;
		this->vbegin = new int[vsize];
		this->ptr = given_size;
		for(int i = 0; i<ptr ; i++){
			*(vbegin + i) = def_val;
		}
	}
	int* begin(){ // returns the begin pointer
		return(vbegin);
	}
	int* end(){ // return the end pointer
		return(vbegin + ptr);
	}
	int size(){ // function that returns size
		return(ptr);
	}
	void push_back(int val){ // insert at end in O(1)
		check_and_table_double();
		vbegin[ptr] = val;
		ptr++;
	}
	void pop_back(){ // delete from end in O(1)
		if(ptr==0) return; // this is a safety check
		ptr--;
		check_and_table_halve();
		return;
	}
	int& at(int pos){ // random access in O(1)
		return (vbegin[pos]);
	}
	int& operator[](int pos){ // random access in O(1)
		return (vbegin[pos]);
	}
};

int32_t main(){

int n; cin>>n;
Vector a(n); 
for(int i = 0; i<n ; i++){
	cin >> a[i];
}

sort(a.begin(), a.end());

for(int i = 0; i<n ; i++){
	cout << a[i] << " ";
}
cout << "\n";


return(0);
}
