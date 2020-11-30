void text_ani(char const a[100]){
	int i; 
	for(i=0;a[i]!='\0';++i){
		Sleep(50);
		cout<<a[i];
	}
}
void ftext_ani(char const a[100]){
	int i; 
	for(i=0;a[i]!='\0';++i){
		Sleep(10);
		cout<<a[i];
	}
}

void bar(int x){// 10 
cout<<"======================"<<endl<<"|";
//cout<<"|####################|"
int k=x/5;
for(int i=1;i<=20;i++){
	if(k>=i){cout<<"#";}
	else {cout<<" ";}
}
cout<<"|"<<endl<<"======================"<<endl;
}

void Introduce(){
	cout<<endl<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	text_ani("=> ANNOUSEMENT FROM GOVERNMENT!!!");  cout<<endl;
	text_ani("FROM THE INCREASEMENT OF PM 2.5!!  WE PROCLAIM THAT IN 5 DAYS"); cout<<endl;
	text_ani("THE PM 2.5 RATE WILL INCREASE TO HIGH RATE. IT VERY DANGEROUUS "); cout<<endl;
	text_ani("TO LIVIVING OUTSIDE. IF THE SITUATION IS IN CRISIS "); cout<<endl;
	text_ani("WE DECIDE TO DECLARE ALL OF PUBLIC-SEVICE AND STROE WILL STOP SEVICE");	cout<<endl;
	text_ani("!!PEOPLE SHOULD STAY IN THE HOUSE AND PREPARE A SUPPLIES!!"); cout<<endl;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	getch();
}

void Introduce2(){
	   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	text_ani("          WE FORGOT TO TELL YOU SOMETHING! "); cout<<endl;
	text_ani("    WHEN YOU USE ANY CHARACTER TO DO SOME ACTIVITY"); cout<<endl;
	text_ani("  THEY WILL GET PM 2.5 . ALWAYS CHECK THEIR STATUS!"); cout<<endl;
	text_ani("      AND SHOULD PREPARE EACH TYPE OF MEDICINE  "); cout<<endl;
	   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	getch();
}

void Introduce3(){
	   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	text_ani("    SEMMS LIKE YOU SHOULD CHECK OUT YOU SUPPILES! "); cout<<endl;
	text_ani("  CHOOSE 4 TO CHECK YOUR SUPPLIES OR CHOOSE 5 IF YOU  "); cout<<endl;
	text_ani("   WANT TO USE SOMETHING SUCH AS WHEN PEOPLE HUNGRY  "); cout<<endl;
	text_ani("      GIVE THEM SOME FOOD! DO NOT LET THEM DIE!!  "); cout<<endl;
	   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	 getch();
}

void suppileinfo(){
	    cout<<"=-=-=-=-= What do you want to use? =-=-=-=-="<<endl;
	ftext_ani("|| 1). Canned Food	");cout<<endl;
	ftext_ani("|| 2). Bread		");cout<<endl;
	ftext_ani("|| 3). Water			");cout<<endl;
	ftext_ani("|| 4). Protective mask	");cout<<endl;
	ftext_ani("|| 5). Nasal spray		");cout<<endl;
	ftext_ani("|| 6). Eye drops		");cout<<endl;
	ftext_ani("|| 7). Ointment		");cout<<endl;
	ftext_ani("|| 0). END");cout<<endl;
	cout<<"======================================="<<endl;
	cout<<"===>> : ";
}

void Introduce4(){
	   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	text_ani("     IF YOU SENT SOMEONE TO DO ACTIVITY OUTSIDE "); cout<<endl;
	text_ani("    MUST WEAR PROTECTIVE MASK BEFORE GO OUTSIDE  "); cout<<endl;
	text_ani(" IF THE BAR OF PM2.5 RATE IS IN HIGH RATE ,YOU SHOULD  "); cout<<endl;
	text_ani("   KNOW THAT YOU WILL GET HIGH PM2.5 IN YOUR BODY!  "); cout<<endl;
	   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	 getch();
}

void Introduce5(){
	cout<<endl<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	text_ani("=> ANNOUSEMENT FROM GOVERNMENT!!!");  cout<<endl;
	text_ani("EMERGENCY STATEMENT!! THE RATE OF PM 2.5 IS IN VERY DANGEROUS!!"); cout<<endl;
	text_ani("ALL OF PUBLIC-SEVICE AND STROE WILL STOP SEVICE"); cout<<endl;
	text_ani("IF PEOPLE WANT TO GO OUTSIDE ,SHOULD WEAR PROTECTIVE MASK!! "); cout<<endl;
	text_ani("WE HOPE THE RATE OF PM 2.5 WILL DECREASE in QUICKLY");	cout<<endl;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	getch();
}

void Introduce6(){
	    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
cout<<endl;
	ftext_ani("                          => ACHEIVEMENT <=                              ");  cout<<endl;
 	ftext_ani("                SURVIE UNTILL THE PM2.5 RATE IS ZERO !!                  "); cout<<endl;
cout<<endl;
	    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	getch();
}

void Introduce7(){
	 	   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		text_ani("    YOU MUST WATER A TREE EVERY 5 DAY! UNLESS THE TREE WILL DIE");  cout<<endl;
		   cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	getch();
}