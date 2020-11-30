#include <iostream>
class food{
private:
	std::string food_name;
	int price;
	int number;
	int hunger;

	food *next;
public:
	food(std::string x,int y ,int z){
		food_name = x;
		price = y;
		hunger = z;
		number = 0;
		next=NULL;
		//cout<<"Creat :"<<med_name<<endl;
	}
	~food(){
		//cout<<"Delete :"<<food_name<<endl;
	}

	int Pfood(int x){
		number = number + x;
		return price*x;
	}
    int Mfood(int x){
		if(number>0){ number = number - x;
		ftext_ani("Useing "); cout<<food_name; return 1;}
		else{ cout<<"NO "<<food_name<<" LEFT!!"<<endl; return 0;}
	}
	food* fnext(){
        return next;
    }
    void add_food(food* &x){
        x->next=this;
    }
	void fshow(){
		cout<<food_name<<" : Amount => "<<number<<endl;
	}
	int gethunger(){
		return hunger;
	}
	int getfnum(){
		return number;
	}
};

class medicine{
private:
	std::string med_name;
	int price;
	int number;
	int dose;

	medicine *next;
public:
	medicine(std::string x,int y,int z){
		med_name = x;
		price = y;
		dose = z;
		number = 0;
		next=NULL;
		//cout<<"Creat :"<<med_name<<endl;
	}
	~medicine(){
		//cout<<"Delete :"<<med_name<<endl;
	}

	int Pmed(int x){
		number = number + x;
		return price*x;
	}
	int Mmed(int x){
		if(number>0){ number = number - x;
		ftext_ani("Useing "); cout<<med_name; return 1;}
		else{ cout<<"NO "<<med_name<<" LEFT!!"<<endl; return 0; }
	}
	medicine* mnext(){
        return next;
    }
    void add_med(medicine* &x){
        x->next=this;
    }
	void mshow(){
		cout<<med_name<<" : Amount => "<<number<<endl;
	}
	int getdose(){
		return dose;
	}
	int getmnum(){
		return number;
	}
};