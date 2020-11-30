#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
#include "interface.h"
#include "human.h"
#include "utility.h"
#include "home.h"

using namespace std;

int main(){
	home my_house;
	human *t1;
	food *t2;
	medicine *t3;

	for(int i=0;i<4;i++) {
         if(i==3)   t1=new human("Kid");
         if(i==2)   t1=new human("Doctor");
		 if(i==1)   t1=new handyman("Handyman");
		 if(i==0)   t1=new police("Police");
                       my_house.inserth(t1);
   }

   for(int i=0;i<3;i++) {
         
         if(i==2)   t2=new food("Canned Food",50,70);
		 if(i==1)   t2=new food("Bread",25,30);
		 if(i==0)   t2=new food("Water",10,10);
                       my_house.insertf(t2);
   }

   for(int i=0;i<3;i++) {
         if(i==2)   t3=new medicine("Nasal Spray",50,10);
         if(i==1)   t3=new medicine("Oinment",20,0);
		 if(i==0)   t3=new medicine("Eye Drops",25,5);
                       my_house.insertm(t3);
   }

// Phase 1 Prepare for PM 2.5 (5 DAY)
 int j,checktree=0,a,k,checkbuy=0,checkbuy1,checkbuy2;

for(;my_house.day<=5;){ 

  if(my_house.day==1)Introduce();
  if(my_house.day==2)Introduce2();
  if(my_house.day==3)Introduce3();
  if(my_house.day==4)Introduce4();
  if(my_house.day==5)Introduce5();
   do{ // ลูป next day

	   do{ // ลูปซ้ำ exception
	   a=0;
	  	 try{
			my_house.checkhome();
   			cout<<endl<<"================= MENU ================"<<endl;
			ftext_ani("|| 1). Show House member information");cout<<endl;
	if(my_house.day!=5){
			if(checkbuy==0 && checkbuy2!=1){ftext_ani("|| 2). Go to Supermarket");cout<<endl;} //เสียพลังงาน 30
			if(checkbuy==1 && checkbuy2!=1){ftext_ani("|| 2). Buying something");cout<<endl;}
			if(checkbuy2==1){ftext_ani("|| 2). None");cout<<endl;}
	}else {ftext_ani("|| 2). None");cout<<endl;}

			if(checktree==0){ftext_ani("|| 3). Growing tree");cout<<endl;} //เสียพลังงาน 20
			if(checktree==1){ftext_ani("|| 3). None");cout<<endl;}

			if(my_house.day>=3){
			ftext_ani("|| 4). Check Supplies");cout<<endl;
			ftext_ani("|| 5). Use Suppiles");cout<<endl;}
			
			ftext_ani("||");cout<<endl;
			ftext_ani("|| 0). Next DAY");cout<<endl;
			cout<<"======================================="<<endl;
			cout<<"===>> : ";
			cin>>j;
			if(cin.fail()) throw "!! It not number !!";
			if(my_house.day<=2) if(j!=0 && j!=1 && j!=2 && j!=3 && j!= 9) throw "!! Enter number betweeb 0-3 !!";
			if(my_house.day>2) if(j!=0 && j!=1 && j!=2 && j!=3 && j!=4 && j!=5 && j!= 9) throw "!! Enter number betweeb 0-5 !!";
			 }
	 		  catch(const char* error){
				   cout<<error<<endl;
					cin.clear();
				   cin.ignore(10,'\n');
				   a=1;
				   getch();
				   system("cls");
	  	 		}
	   	//system("cls");
	   }while(a);
/////////////////////////////////////////////////////////////////////////////////////////
	if(j==1){
		my_house.show_info(); getch();}
if(my_house.day!=5){
	if(j==2){   if(checkbuy2==1){ftext_ani("!! Cannot use this menu. You already use it !!"); getch();}
				else{
					if(checkbuy==1){my_house.buy(k); 
					checkbuy2=1; getch();}
					if(checkbuy==0){k=my_house.gotosp();
			    	checkbuy2=1; checkbuy=1; checkbuy1=my_house.day+2; getch();}
				}
			}			
}else{ftext_ani("!! Cannot use this menu !!"); getch();}

	if(j==3){ if(checktree!=1){my_house.growtree(); getch(); checktree=1;}
			  else{ ftext_ani("!! 1 DAY CAN GROW 1 TREE !!"); cout<<endl; getch();}
   }

	if(j==4){
		my_house.showsupplies(); getch();
	}

	if(j==5){
		my_house.fsup(); getch();
	}

	if(j==0){
			my_house.nextday(20); getch();
			if(checkbuy1==my_house.day) {checkbuy=0; my_house.fix_hstatus(k,0);}
			checkbuy2=0;
			checktree=0;


			}

																			if(j==9) break;

	system("cls");
   }while(j!=0);
   																			if(j==9) break;
}
system("cls");
text_ani("END OF PHASE 1"); getch();



//////////////////////////////////////////////////////////////////////////////////////////
// Phase 2 Survive in PM 2.5 (?? day)

	do
	{
		int ptree,a,i,j,k,chectree=0,checktree1;

		if(my_house.day==6) {checktree1 = my_house.day + 5; Introduce6();}
		if(my_house.day==7) {Introduce7();}


		if(checktree1 == my_house.day) my_house.mtree();

		do{
		a=0;
	  	 try{
			my_house.checkhome();
   			cout<<endl<<"================= MENU ================"<<endl;
			ftext_ani("|| 1). Show House member information");cout<<endl;
			ftext_ani("|| 2). Check Supplies");cout<<endl;
			ftext_ani("|| 3). Use Suppiles");cout<<endl;
			
			if(checktree==0){ftext_ani("|| 4). Water the tree");cout<<endl;} //เสียพลังงาน 10
			if(checktree==1){ftext_ani("|| 4). None");cout<<endl;}



			ftext_ani("||");cout<<endl;
			ftext_ani("|| 0). Next DAY");cout<<endl;
			cout<<"======================================="<<endl;
			cout<<"===>> : ";
			cin>>k;
			if(cin.fail()) throw "!! It not number !!";
			if(j!=0 && j!=1 && j!=2 && j!=3 && j!=4 && j!= 9) throw "!! Enter number betweeb 0-4 !!";
		   }
		   catch(const char* error){
				   cout<<error<<endl;
					cin.clear();
				   cin.ignore(10,'\n');
				   a=1;
				   getch();
				   system("cls");
	  	 		}
		}while(a);

	if(k==1){ my_house.show_info(); getch();}

	if(k==2){ my_house.showsupplies(); getch();}

	if(k==3){ my_house.fsup(); getch();}

	if(k==4){ if(checktree!=1){my_house.growtree(); getch(); checktree=1;}
			  else{ ftext_ani("!! Cannot use this menu. You already use it !!"); cout<<endl; getch();}
			  checktree1 = my_house.day + 5;
			}

	if(k==0){ 
		int t = (2 * my_house.getree()) + 2;
		my_house.nextday2(t); getch();

		checktree=0;
	}



	} while (my_house.get_PM() > 0);
	

	return 0;
}