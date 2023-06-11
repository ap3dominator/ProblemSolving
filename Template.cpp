/*
	Author : virtualDedic
*/

#include<bits/stdc++.h>
using namespace std;
#define nline "\n";


class Library{
protected:

	template<typename T>
	class Response{
	public:
		bool success;
		string message;
		T value;
		Response(bool success){
			this->success = success;
		}
		Response(bool success ,T value){
			this->success = success;
			this->value = value;
		}
		Response(bool success,string message){
			this->success = success;
			this->message = message;
		}
	};

	template<typename T>
	class Set{
		set<T> set_;
	public:
		void add(T element){
			set_.insert(element);
		}

	    const Response<T> findLower(const T& element){

	      if (set_.empty()) {
	        return Response<T>(false , "Set is empty.");
	      }

	      auto it = set_.find(element);

	      if (it == set_.begin() || element < *set_.begin()) {
	        return Response<T>(false,"No previous element.");
	      }

	      return Response<T>(true , *--it);
	     }

	    const Response<T> findGreater(const T& element){
	      if (set_.empty()) {
	        return Response<T>(false ,"Set is empty.");
	      }
	      	
	      auto it = set_.upper_bound(element);

	      if (it == set_.end()) {
	        return Response<T>(false ,"No Next Element.");
	      }

	      return Response<T>(true,*it);
	    }

	    const Response<T> get(const T& element){
	      if (set_.empty()) {
	        return Response<T>(false ,"Set is empty.");
	      }
	      
	      auto it = set_.find(element);

	      if (it == set_.end()) {
	        return Response<T>(false ,"Element Not Found.");
	      }

	      return Response<T>(true,*it);
	    }

		void printAll(){
			for(auto currentElement : set_){
				cout<<currentElement<<" ";
			}
			cout<<nline;
		}
	};
};

class Solver : protected Library{
protected:
	void Solve(int testCaseNum = 1){
		
	}
};

class Driver : protected Solver {

	void READ_FROM_IO_FILE(){
		#ifndef ONLINE_JUDGE
        	freopen("./input.txt", "r", stdin);
        	freopen("./output.txt", "w", stdout);
    	#endif
	}
	
	void FAST_IO(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	}

	public:
	Driver(){
			READ_FROM_IO_FILE();
			FAST_IO();
	}

	void solveQuery(){
		Solver::Solve();
	}

	void solveQueries(){
		int numOfTestCases;
		cin>>numOfTestCases;
		for(int currentTestCase = 1;
					currentTestCase <=numOfTestCases; 
				  		++currentTestCase){
			Solver::Solve(currentTestCase);
		}
	}
};

signed main(){
	Driver obj;
	obj.solveQuery();
	// obj.solveQueries();
	return 0;
}






