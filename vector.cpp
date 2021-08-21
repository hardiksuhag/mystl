# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define int ll

class Vector{
private:
	int vsize; // total alloted size 
	int* begin; // start pointer of vector
	int ptr; // used size of vector/ index for next addition


	void cast_to_size(int nvsize){ // function for resizing vector
		int* nb = new int[nvsize];
		for(int i = 0; i<ptr ; i++){
			nb[i] = begin[i];
		}
		delete begin;
		begin = nb;
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
		this->begin = new int[vsize];
		this->ptr = 0;
	}
	int size(){ // function that returns size
		return(ptr);
	}
	void push_back(int val){ // insert at end in O(1)
		check_and_table_double();
		begin[ptr] = val;
		ptr++;
	}
	void pop_back(){ // delete from end in O(1)
		if(ptr==0) return; // this is a safety check
		ptr--;
		check_and_table_halve();
		return;
	}
	int at(int pos){ // random access in O(1)
		return (begin[pos]);
	}
};

int32_t main(){

	// cout << a.size() << "\n";

	// Vector a;
	// int i = 1;
	// while(a.size() < 1005){
	// 	if(!(i%10==3 || i%3==0)){
	// 		a.push_back(i);
	// 	}
	// 	i++;
	// }
	// int t; cin>>t;
	// while(t--){
	// 	int k; cin>>k;
	// 	cout << a.at(k-1) << "\n";
	// }

	return(0);
}
