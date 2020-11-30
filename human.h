#include <iostream>
using namespace std;
class human{
protected: 
    std::string name;
    int energy;
    int pm_rate;
    int status;
    int disease;
    int mask;
    human* next;
public:
    human(std::string="0");
    ~human(){
        cout<<"Delete "<<name<<endl;
    }
    human* movenext();

    void add_human(human* &x){
        x->next=this;
    }

    virtual void show();

    void fix_mask(int x){
        mask = x;
        if(mask!=0){text_ani("This character use protective mask!");
    } } 
    int get_mask(){
        return mask;
    }

    void getfood(int);
    void lowfood(int);
    
    void Ppm_rate(int);
    void Mpm_rate(int);

    void fix_status(int);
    void fix_disease(int);

    int get_status(){
        if(status==1) return 1;
        if(status==2) return 2;
        if(status==3) return 3;
        if(status==4) return 4;
        else return 0;
    }
    int get_disease(){
        if(status==1) return 1;
        if(status==2) return 2;
        if(status==3) return 3;
        else return 0;
    }

   // virtual void repair(){cout<<"you dont have toolbox!!"<<endl;}
   // virtual void shoot(){cout<<"you dont have gun!!"<<endl;}
};

class handyman :public human{
private:
    int toolbox;
public:
    void repair();
    void show();
    handyman(string x):human(x){
    toolbox = 10;
    }
    ~handyman(){
        cout<<"Delete "<<name<<endl;
    }
};

class police :public human{
private:
    int gun;
public:
    void shoot();
    void show();
    police(string x):human(x){
    gun = 5;
}
    ~police(){
        cout<<"Delete "<<name<<endl;
    }
};

//////////////////////////////////////////////////////////////////
human* human::movenext(){
        return next;
    }

 human::human(string x){
    name=x;
    energy=100;
    pm_rate=0;
    status=0;
    disease=0;
    mask=0;
    next=NULL;
    cout<<"Create "<<x<<endl;
 }

 void human::show(){
    cout<<"======"<<name<<"======"<<endl;

    if(status!=3){
    cout<<"Healt : ";
    if(pm_rate<=40) {ftext_ani("Normal"); cout<<endl;}
    if(pm_rate>40&&pm_rate<=75) {ftext_ani("Danger!"); cout<<endl;}
    if(pm_rate>75&&pm_rate<=99) {ftext_ani("Very Danger!"); cout<<endl;}
    if(pm_rate==100) {status=3;}
    }
    
    cout<<"Status : ";
    if(status==0){ftext_ani("Normal"); cout<<endl;}
    if(status==1){ftext_ani("Sick!"); cout<<endl;}
    if(status==2){ftext_ani("Not at home!"); cout<<endl;}
    if(status==3){ftext_ani("Death!"); cout<<endl;}
    if(status==4){ftext_ani("Cannot use this Character!"); cout<<endl;}

    if(status!=3){
    if(energy>40){ftext_ani("=> Not Hungry"); cout<<endl; status=0;}
    if(energy>20&&energy<=40){ftext_ani("=> Hungry!"); cout<<endl; status=0;}
    if(energy<=20&&energy>0){ftext_ani("=> Very Hungry!!"); cout<<endl; status=0;}
    if(energy=0){status=4;}
    }
    cout<<"========================"<<endl;
 }
void human::getfood(int x){
    if(pm_rate + x <100){energy = energy + x;
                        cout<<name<<" +energy : "<<energy<<endl;}
    else {cout<<"Full of enerygy!"<<endl;}
}
void human::lowfood(int x){
    if(energy >= x) energy = energy - x;
    if(energy < x) {energy = 0;}
    cout<<name<<" energy : "<<energy<<endl;
}

void human::Ppm_rate(int x){
    if(mask!=1) { if(pm_rate + x <100) pm_rate = pm_rate + x;
                  else pm_rate =100;}
    else { cout<<name<<" using mask...."<<endl;}
}
void human::Mpm_rate(int x){
    pm_rate = pm_rate - x;
    text_ani("Maybr It could be help a little bit... "); cout<<endl;
}
void human::fix_status(int x){
    status = x;
}
void human::fix_disease(int x){
    disease = x;
} 

///////////////////////////////////////////////////////////////////

void handyman::show(){
    cout<<"======"<<name<<"======"<<endl;
    
    if(status!=3){
    cout<<"Healt : ";
    if(pm_rate<=40) {ftext_ani("Normal"); cout<<endl;}
    if(pm_rate>40&&pm_rate<=75) {ftext_ani("Danger!"); cout<<endl;}
    if(pm_rate>75&&pm_rate<=99) {ftext_ani("Very Danger!"); cout<<endl;}
    if(pm_rate==100) {status=3;}
    }
    
    cout<<"Status : ";
    if(status==0){ftext_ani("Normal"); cout<<endl;}
    if(status==1){ftext_ani("Sick!"); cout<<endl;}
    if(status==2){ftext_ani("Not at home!"); cout<<endl;}
    if(status==3){ftext_ani("Death!"); cout<<endl;}
    if(status==4){ftext_ani("Cannot use this Character!"); cout<<endl;}
    
    if(status!=3) cout<<"Toolbox :"<<toolbox<<endl;

    if(status!=3){
    if(energy>40){ftext_ani("=> Not Hungry"); cout<<endl; status=0;}
    if(energy>20&&energy<=40){ftext_ani("=> Hungry!"); cout<<endl; status=0;}
    if(energy<=20&&energy>0){ftext_ani("=> Very Hungry!!"); cout<<endl; status=0;}
    if(energy=0){status=4;}
    }
    cout<<"========================"<<endl;
 }

void handyman::repair(){
    if(toolbox>0){toolbox = toolbox -1;}
    else{cout<<"No enough toolbox!"<<endl;}
}

///////////////////////////////////////////////////////////////////
void police::show(){
    cout<<"======"<<name<<"======"<<endl;

    if(status!=3){
    cout<<"Healt : ";
    if(pm_rate<=40) {ftext_ani("Normal"); cout<<endl;}
    if(pm_rate>40&&pm_rate<=75) {ftext_ani("Danger!"); cout<<endl;}
    if(pm_rate>75&&pm_rate<=99) {ftext_ani("Very Danger!"); cout<<endl;}
    if(pm_rate==100) {status=3;}
    }
    
    cout<<"Status : ";
    if(status==0){ftext_ani("Normal"); cout<<endl;}
    if(status==1){ftext_ani("Sick!"); cout<<endl;}
    if(status==2){ftext_ani("Not at home!"); cout<<endl;}
    if(status==3){ftext_ani("Death!"); cout<<endl;}

    if(status!=3) cout<<"Gun : "<<gun<<endl;

    if(status!=3){
    if(energy>40){ftext_ani("=> Not Hungry"); cout<<endl; status=0;}
    if(energy>20&&energy<=40){ftext_ani("=> Hungry!"); cout<<endl; status=0;}
    if(energy<=20&&energy>0){ftext_ani("=> Very Hungry!!"); cout<<endl; status=0;}
    if(energy=0){status=4;}
    }
    cout<<"========================"<<endl;
 }

void police::shoot(){
    if(gun>0){gun = gun - 1;}
    else{cout<<"No more bullet!"<<endl;}
}
