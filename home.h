#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
//#include "human.h"
//#include "utility.h"
//#include "interface.h"
class home{
private:
	human *head;
	food *F;
	medicine *M;

	int money;
	int nmask;
	int tree;
	int PM25;

	int homestatus;
public:
	int day;

	home();
	~home();
	void inserth(human* &x){
		head->add_human(x);
		head=x;
	}
	void insertf(food* &y){
		F->add_food(y);
		F=y;
	}
	void insertm(medicine* &z){
		M->add_med(z);
		M=z;
	}

	int get_PM(){
		return PM25;
	}
	void mtree(){
		tree--;
		text_ani("Oh no! You forgot to water a tree? 1 tree is dead!"); cout<<endl;
	}
	int getree(){
		return tree;
	}

	void show_info();
	void showsupplies();
	void checkhome();
	void fix_hstatus(int,int);
	void nextday(int);
	void nextday2(int);

/////////////////////////////////////////////////

	void buy(int);
	int gotosp();
	void growtree();
	void water_tree();
	void fsup();
	void usefood(int,int);
	void usemed(int,int);

/////////////////////////////////////////////////

	void runout_energy();
	void invade();
	void broken_window();

	void sick1();
	void sick2();
	void sick3();
};
///////////////////////////////////////////////////////////////////

home::home(){
	head=NULL;
	F=NULL;
	M=NULL;

	money=500;
	nmask=5;
	tree=0;
	PM25=0;
	homestatus=0;
	day=1;
	cout<<"Create Home"<<endl;
}
home::~home(){
	int i;
	human *t1;
	for(i=0;i<4;i++){
		t1=head;
		head=head->movenext();
		delete t1;
	}

	food *t2;
	for(i=0;i<3;i++){
		t2=F;
		F=F->fnext();
		delete t2;
	}

	medicine *t3;
	for(i=0;i<3;i++){
		t3=M;
		M=M->mnext();
		delete t3;
	}
}


void home::show_info(){
     human* ts=head;
     int i;
     for(i=0;i<4;i++){
            ts->show();
	      ts = ts->movenext();    
     }
}
void home::showsupplies(){
	food *tf=F;
	medicine *tm=M;
	int i;
	cout<<"=-=-=-=-=-= FOOD =-=-=-=-=-="; cout<<endl;
	for(i=1;i<=3;i++){
					cout<<i<<") ";
            tf->fshow();
	      tf = tf->fnext();  
	  			
     }
	 cout<<endl;

	 cout<<"=-=-=-=-=-= MEDICINE =-=-=-=-=-="; cout<<endl;
	 for(i=1;i<=3;i++){
		cout<<i<<") ";
            tm->mshow();
	      tm = tm->mnext();    
	
     }
		 cout<<i<<") Protective mask : Amount => "<<nmask<<endl;
	 cout<<endl;
}

void home::checkhome(){
	cout<<endl;
	ftext_ani("======== DAY "); cout<<day; ftext_ani("========"); cout<<endl<<endl;
	bar(PM25);
	cout<<"Money : "<<money<<" $    "<<"Tree : "<<tree<<endl;
}

void home::fix_hstatus(int x,int y){
	human *t=head;
		for(int i=1;i<=4;i++){
				if(i == x){ t->fix_status(y); }
				t=t->movenext();	
				}
}


void home::nextday(int x){
	cout<<endl;
	human *t=head;
		for(int i=1;i<=4;i++){
			   t->lowfood(10);
				t->Ppm_rate(1);
				t->fix_mask(0); 
				t=t->movenext();	
				}
	PM25 = PM25 + x ;
	day++;
}
void home::nextday2(int x){
	cout<<endl;
	human *t=head;
		for(int i=1;i<=4;i++){

				if(i=1) {t->lowfood(10);}
	      else {t->lowfood(10);}
				
			  t->Ppm_rate(1);
				t->fix_mask(0); 
				t=t->movenext();	
				}
	PM25 = PM25 - x ;
	day++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int home::gotosp(){
	
	int i,a;
	int k=0,checkperson;

	do{ a=0;
		try{
			ftext_ani("1) Kid   2) Doctor   3) Handyman    4) Police"); cout<<endl;
			cout<<"Who did you want to go supermarket : ";
			cin>>k;
			if(cin.fail()) throw "Enter number!";
			if( k < 1 || k > 4) throw "Enter number between 1-4";

				human *t=head;
				for(i=1;i<=4;i++){
					if(i == k){ checkperson = t->get_status(); }
					t = t->movenext();}
			if(checkperson != 0) throw "Cannot use this character!";
		}
		catch(const char* error){
			cout<<error<<endl;
		   cin.clear();
		   cin.ignore(10,'\n');
		   getch();
		   system("cls");
		   a=1;
	   		}
	   }while(a);

	human *t=head;
		for(i=1;i<=4;i++){
				if(i == k){ t->fix_status(2); }
				t=t->movenext();
			}
	cout<<endl;
	text_ani("This character go to the Supermarket."); cout<<endl;
	text_ani("You can't use this charater for 1 day!"); cout<<endl;
	return k;
}	

void home::buy(int k){
food *tf;
	medicine *tm;	
	int m=0,n=0,i,a;		
do{
	a=0;

	try{
	cout<<"Your money :"<<money<<endl;
	cout<<"====== What do you want to buy? ======="<<endl;
	ftext_ani("|| 1). Canned Food				50 Baht");cout<<endl;
	ftext_ani("|| 2). Bread							25 Baht");cout<<endl;
	ftext_ani("|| 3). Water							10 Baht");cout<<endl;
	ftext_ani("|| 4). Protective mask		30 Baht");cout<<endl;
	ftext_ani("|| 5). Nasal spray				20 Baht");cout<<endl;
	ftext_ani("|| 6). Eye drops					10 Baht");cout<<endl;
	ftext_ani("|| 7). Ointment					15 Baht");cout<<endl;
	ftext_ani("|| 0). END");cout<<endl;
	cout<<"======================================="<<endl;
	cout<<"===>> : ";
	cin>>m;
	if(cin.fail()) throw "!! It not number !!";
	if(m<0 || m>7) throw "!! Enter number between 0-7 !!";
	if(m!=0){cout<<"How many? => : ";
	cin>>n;
	if(cin.fail()) throw "!! It not number !!";}

	food *tf=F;
	medicine *tm=M;
	switch(m){
	case 1 :
			for(i=1;i<=3;i++){
				if(i == 1){ if(money - tf->Pfood(n) < 0 || money<0) {throw "no enough money!";}
										else money = money - tf->Pfood(n); }
				tf=tf->fnext();
			}
			break;
	case 2 : 
			for(i=1;i<=3;i++){
				if(i == 2){ if(money - tf->Pfood(n) < 0 || money<0) {throw "no enough money!";}
				  					else money = money - tf->Pfood(n); }
				tf=tf->fnext();
			}
			break;
	case 3 :
			for(i=1;i<=3;i++){
				if(i == 3){ if(money - tf->Pfood(n) < 0 || money<0) {throw "no enough money!";}
										else{money = money - tf->Pfood(n);}	 }
				tf=tf->fnext();
			}
			break;
	case 4 : if(money - (30*n) < 0 || money<0) {throw "no enough money!";}
			     else {money = money - (30*n);
			nmask = nmask + n;}
			break;
	case 5 : 
			for(i=1;i<=3;i++){
				if(i == 1){ if(money - tm->Pmed(n) < 0 || money<0) {throw "no enough money!";}
											else{money = money - tm->Pmed(n);} }
				tm=tm->mnext();
			}
			break;
	case 6 : 
			for(i=1;i<=3;i++){
				if(i == 2){ if(money - tm->Pmed(n) < 0 || money<0) {throw "no enough money!";}
										else {money = money - tm->Pmed(n);} }
				tm=tm->mnext();
			}
			break;
	case 7 : 
			for(i=1;i<=3;i++){
				if(i == 3){ if(money - tm->Pmed(n) < 0 || money<0) throw "no enough money!";
										else{ money = money - tm->Pmed(n); } }
				tm=tm->mnext();
			}
			break;
	defualt : break;
		}
	}
	catch(const char* error){
		cout<<error<<endl;
		   cin.clear();
		   cin.ignore(10,'\n');
		   getch();
		   system("cls");
		   a=1;
	   }
	cout<<"Your money :"<<money<<endl;
	getch();
	system("cls");
  }while(m!=0 || a!=0);

  human *t=head;
	int p = PM25/3;
		for(i=1;i<=4;i++){
				if(i == k){ t->lowfood(30);
							t->Ppm_rate(p);
							t->fix_status(0); }
				t=t->movenext();
			}

}

void home::growtree(){
	int k,a,checkperson,i;

	do{ a=0;
		try{
			ftext_ani("1) Kid   2) Doctor   3) Handyman    4) Police"); cout<<endl;
			cout<<"Who did you want to plant : ";
			cin>>k;
			if(cin.fail()) throw "Enter number!";
			if( k < 1 || k > 4) throw "Enter number between 1-4";

				human *t=head;
				for(i=1;i<=4;i++){
					if(i == k){ checkperson = t->get_status(); }
					t = t->movenext();}
			if(checkperson != 0) throw "Cannot use this character!";
			}
		catch(const char* error){
			cout<<error<<endl;
		   cin.clear();
		   cin.ignore(10,'\n');
		   getch();
		   system("cls");
		   a=1;
	   		}
	   }while(a);
	   
	human *t=head;
	int p = PM25/3;
		for(int i=1;i<=4;i++){
				if(i == k){ t->lowfood(20);
							t->Ppm_rate(p); }
				t=t->movenext();
			}
	tree = tree +1;
}

void home::usefood(int x,int y){
	food* tf=F;
	human* th=head;
	int h,i,n;

	for(int i=1;i<=3;i++){
				if(i == y){ h = tf->gethunger();
				n=tf->Mfood(1);
				 }
				tf=tf->fnext();
			}
if(n==1){
		for(i=1;i<=4;i++){
				if(i == x){ th->getfood(h); }
				th=th->movenext();
			}
}
}
void home::usemed(int x,int y){
	medicine* tm=M;
	human* th=head;
	int m,n,i;

	for(int i=1;i<=3;i++){
				if(i == y){ m = tm->getdose(); 
				n= tm->Mmed(1); }
				tm = tm->mnext();
			}
if(n==1){
		for(i=1;i<=3;i++){
				if(i == x){ th->Mpm_rate(m);
					n = th->get_disease(); }
				th=th->movenext();
			}
	if(n == y){ text_ani("THE DISEAES HAS BEEN CURE!"); 
				for(i=1;i<=3;i++){
				if(i == x){ th->fix_disease(0);}
				th=th->movenext();
			}
		}
}
}

void home::fsup(){
	int n,k,a,checkperson,i;
	do{ a=0;
		try{
			ftext_ani("1) Kid   2) Doctor   3) Handyman    4) Police"); cout<<endl;
			cout<<"Who did you want to use with : ";
			cin>>k;
			if(cin.fail()) throw "Enter number!";
			if( k < 1 || k > 4) throw "Enter number between 1-4";

				human *t=head;
				for(i=1;i<=4;i++){
					if(i == k){ checkperson = t->get_status(); }
					t = t->movenext();}
			if(checkperson != 0 || checkperson != 1) throw "Cannot use this character!";
			}
		catch(const char* error){
			cout<<error<<endl;
		   cin.clear();
		   cin.ignore(10,'\n');
		   getch();
		   system("cls");
		   a=1;
	   		}
	   }while(a);

		do{
			a=0;
			try{
				suppileinfo();
				cin>>n;
				if(cin.fail()) throw "!! It not number !!";
				if(n<0 || n>7) throw "!! Enter number between 0-7 !!";
				}
			catch(const char* error){
				cout<<error<<endl;
				   cin.clear();
				   cin.ignore(10,'\n');
				   getch();
				   system("cls");
				   a=1;
		   		}
		}while (a);

	food* tf;
	medicine* tm;
	human *t=head;
switch(n){
	case 1 : usefood(k,n); break;
	case 2 : usefood(k,n); break;
	case 3 : usefood(k,n); break;
	case 4 : {
						for(i=1;i<=4;i++){
							if(i == k){  t->fix_mask(1); }
							t = t->movenext();}
					 break;}
	case 5 : usemed(k,n); break;
	case 6 : usemed(k,n); break;
	case 7 : usemed(k,n); break;
  defualt : break;
}

}

void home::water_tree(){
	int k,a,checkperson,i;

	do{ a=0;
		try{
			ftext_ani("1) Kid   2) Doctor   3) Handyman    4) Police"); cout<<endl;
			cout<<"Who did you want to plant : ";
			cin>>k;
			if(cin.fail()) throw "Enter number!";
			if( k < 1 || k > 4) throw "Enter number between 1-4";

				human *t=head;
				for(i=1;i<=4;i++){
					if(i == k){ checkperson = t->get_status(); }
					t = t->movenext();}
			if(checkperson != 0) throw "Cannot use this character!";
			}
		catch(const char* error){
			cout<<error<<endl;
		   cin.clear();
		   cin.ignore(10,'\n');
		   getch();
		   system("cls");
		   a=1;
	   		}
	   }while(a);

	   human *t=head;
		int p = PM25/3;
		for(int i=1;i<=4;i++){
				if(i == k){ t->lowfood(10);
							t->Ppm_rate(p); }
				t=t->movenext();
			}
}

////////////////////////////////////////////////////////////////////////////////////////
void home::runout_energy(){
	   cout<<"======================= WARNING!!!!========================"<<endl;
	text_ani("     Your house is power outage problem! It's cause ");        cout<<endl;
	text_ani(" the air vaccume not working! Try to use handyman to check"); cout<<endl;
	text_ani("    the generator. If it broken you should repair it.");      cout<<endl;
	text_ani("       Otherwise, the PM2.5 can get in your house!");           cout<<endl;
	   cout<<"==========================================================="<<endl;

	homestatus = 1;
}

void home::invade(){
	   cout<<"======================= WARNING!!!!========================"<<endl;
	text_ani("   Someone is outside the door. It seems he want to get");    cout<<endl;
	text_ani("       in your house. Beware! maybe he is a burglar");       cout<<endl;
	text_ani("  Try to use police to talk to this man. If it dangerous");   cout<<endl;
	text_ani("use gun to threaten him. Otherwise, you may loss your food!");cout<<endl;
	   cout<<"==========================================================="<<endl;

	homestatus = 2;
}

void  home::broken_window(){
	   cout<<"======================= WARNING!!!!========================"<<endl;
	text_ani("    Oh no! Your window is broken. It dangerous if you"); cout<<endl;
	text_ani("        neglect it. PM2.5 can get in your house! "); cout<<endl;
	text_ani("   You should use handyman to fix the the broken window"); cout<<endl;
	   cout<<"==========================================================="<<endl;


	homestatus = 3;
}