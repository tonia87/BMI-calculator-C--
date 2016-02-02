#include<iostream>
#include<string.h>
using namespace std;


class Human{
	protected:
	string name;
	
	float kgr,cm,years,bmi;
	public:
		Human(){
			cout<<"Ok, I'm gonna need some time learning"<<endl;
			cout<<"about you..."<<endl;
			cout<<endl;
			cout<<"Let's start! What is your name?"<<endl;
			cin>>this->name ;
			cout<<endl;
			cout<<"Pleased to meet you, "<<this->name<<" !"<<endl;
			cout<<endl;
			cout<<"How old are you?"<<endl;
			cin>>this->years;
			cout<<endl;
			cout<<"Cool.. Now I'm going to need your height in cm.. "<<endl;
			cin>>this->cm;
			cout<<endl;
			cout<<"..and your weight in kgr:"<<endl;
			cin>>this->kgr;
			cout<<endl;
			
		
		}
		Human(int a){
		}
		
		~Human(){
			cout<<this->name<<", your account has been deleted."<<endl;
			cout<<"See you again anytime!"<<endl;
		}
		public:
			virtual string getName(){
				return(this->name);
			}
		virtual void BMI(){
			cout<<"Your BODY MASS INDEX is equal to: ";
			this->bmi =this->kgr /this->cm/this->cm*10000;
			cout<<this->bmi;
			cout<<endl;
		}
		virtual float getBmi(){
			return(this->bmi);
		}
		virtual float getKgr(){
			return(this->kgr);
		}
		virtual float getCm(){
			return(this->cm);
		}
		virtual int getAge(){
			return(this->years );
		}
	
		
};


//////////////////////////////////////////////////////////////////////////////


class Man:public Human{
	private:
		string gender;
		float base,baseKgr,baseCm,baseYears;
		float bmr,bmi;
	public:
		//: B.M. = 66 + (13,7 x B) + (5 x Y) - (6,8 x H).
		Man():Human(){
			gender="Male";
			base=66;
			baseCm=5;
			baseKgr=13.7;
			baseYears=6.8;
		}
		Man(int a):Human(a){		}
	
			void CountBMR(){
			cout<<"Your Basal Metabolic Rate values ";
			this->bmr=base+baseKgr*kgr+baseCm*cm-baseYears*years;
			cout<<this->bmr<<" kcal.";
			cout<<endl;
			cout<<"This means that you need the same amount of daily intake in kcal\n";
			cout<<"to maintain your weight."<<endl;
			cout<<endl;
	}
	float getBmr(){
		return(this->bmr);
	}
};


//////////////////////////////////////////////////////////////////////////////


class Woman:public Human{
	private:
		string gender;
		float base,baseKgr,baseCm,baseYears;
		float bmr,bmi;
	public:
		//655+(9.6*kgr)+(1.8*cm)-(4.7*years);
		Woman():Human(){
			gender="Female";
			base=655;
			baseCm=1.8;
			baseYears=4.7;
		}
		Woman(int a):Human(a){		}
		
		void CountBMR(){
			cout<<"Your Basal Metabolic Rate values ";
			this->bmr=base+baseKgr*kgr+baseCm*cm-baseYears*years;
			cout<<this->bmr<<" kcal.";
			cout<<endl;
			cout<<"This means that you need the same amount of daily intake in kcal\n";
			cout<<"to maintain your weight."<<endl;
			cout<<endl;
		}
		float getBmr(){
		return(this->bmr);
	}
	};
	
