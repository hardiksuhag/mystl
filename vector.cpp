# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define int ll

class Vector{
public:
	int size;
	int* begin;
	int ptr;
	Vector(){
		this->size = 10;
		this->begin = new int[size];
		this->ptr = 0;
	}
	void cast_to_size(int nsize){
		int* nb = new int[nsize];
		for(int i = 0; i<ptr ; i++){
			nb[i] = begin[i];
		}
		delete begin;
		begin = nb;
		size = nsize;
		return;
	}
	void check_and_table_double(){
		if(ptr!=size) return;
		int nsize = size*2;
		cast_to_size(nsize);
	}
	void check_and_table_halve(){
		if(size<20 || ((ptr*3 + 10) > size)) return;
		int nsize = (size/2)+1;
		cast_to_size(nsize);
	}
	void push_back(int val){
		check_and_table_double();
		begin[ptr] = val;
		ptr++;
	}
	void pop_back(){
		if(ptr==0) return; // this is a safety check
		ptr--;
		check_and_table_halve();
		return;
	}
	int at(int pos){
		return (begin[pos]);
	}
};

int32_t main(){
	return(0);
}
