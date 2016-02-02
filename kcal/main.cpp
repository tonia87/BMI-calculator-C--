#include<iostream>
#include<string.h>
#include <fstream>
#include"human.h"
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void PrintResultBMI(float);
char PromptSave();
char WelcomeMessage();
char ChooseGender();

struct humanUser{
	string name;
	string gender;
	int age;
	float bmr,bmi,height,weight;
};

int main(int argc, char** argv) {
	
	
const string quote1="The body mass index (BMI) or Quetelet index is a value derived from \r\nthe mass (weight) and height of an individual. The BMI is defined as the \r\nbody mass divided by the square of the body height, and is universally \r\nexpressed in units of kg/m2, resulting from mass in kilograms \r\nand height in metres.\r\n";
const string quote2="The BMI is an attempt to quantify the amount of tissue mass \r\n(muscle, fat, and bone) in an individual, and then categorize \r\nthat person as underweight, normal weight, overweight, or obese \r\nbased on that value. However, there is some debate about where \r\non the BMI scale the dividing lines between categories should be placed.\r\nCommonly accepted BMI ranges are underweight: under 18.5,\r\nnormal weight: 18.5 to 25, overweight: 25 to 30, obese: over 30.";
const string quote3="This means that you need the same amount of daily intake in kcal \r\nto maintain your weight.";

Man* current_m=new Man(0);
Woman* current_w=new Woman(0);
humanUser current;

char answerSave;
char gender;
float bmi;
ofstream myfile;
	
char a=WelcomeMessage();
	if(a=='N'){
		cout<<"Ok!Maybe at your leisure... Bye!!"<<endl;
	}
	else{
		 cout<<endl;
 		 answerSave=PromptSave();
 		  if(answerSave=='Y'){
 		 	myfile.open("Calories.txt");
 		 	if(myfile.is_open()){
 		 	
 		 	cout<<"Your file has been created! Awaiting info..."<<endl;
 		 	cout<<endl;
 		 }
		  }
		  else{
		  	cout<<"Ok! Let's just give you the overview..."<<endl;
		  	cout<<endl;
		  }
		  
		gender=ChooseGender();
	
		 if(gender=='M'){
	
 		 //Man* current=new Man();
 		
 		current_m=new Man();
 		current_m->CountBMR();
	  	current_m->BMI() ;
 		PrintResultBMI(current_m->getBmi());
	}
 	else{
		 //Woman* current=new Woman();
 	 	 current_w=new Woman();
		 current_w->CountBMR();
		 current_w->BMI() ;
		 PrintResultBMI(current_w->getBmi());
	}


if(gender=='M'){

current.name =current_m->getName() ;
current.gender="Male";
current.age=current_m->getAge();
current.height =current_m->getKgr();
current.weight=current_m->getKgr();
current.bmi=current_m->getBmi();
current.bmr=current_m->getBmr();
}
else{
current.name =current_w->getName() ;
current.gender="Female";
current.age=current_w->getAge();
current.height =current_w->getCm();
current.weight=current_w->getKgr();
current.bmi=current_w->getBmi();
current.bmr=current_w->getBmr();
}

if(answerSave=='Y'){
	myfile<<"Below is the information of your account: ";
	myfile<<"\r\n";
	myfile<<"\r\n";
	myfile<<"\r\n";
	myfile<<("Name: "+ current.name );
	myfile<<"\r\n";
	myfile<<"Gender: ";
	myfile<<current.gender;
	myfile<<"\r\n";
	myfile<<"Your age in years: ";
	myfile<<current.age;
	myfile<<"\r\n";
	myfile<<"Your height in cm: ";
	myfile<<current.height; 
	myfile<<"\r\n";
	myfile<<"Your weight in kgr: ";
	myfile<<current.weight ;
	myfile<<"\r\n";
	myfile<<"\r\n";
	myfile<<"\r\n";
	myfile<<("Your Basal Metabolic Rate values in kcal: " );
	myfile<<current.bmr;
 	myfile<<"\r\n";
 	myfile<<quote3;
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<("Your Body Mass Index is equal to: ");
 	myfile<<current.bmi;
 	myfile<<"\r\n";
 	myfile<<quote1;
 	myfile<<"\r\n";
 	myfile<<quote2;
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"\r\n";
 	myfile<<"Thank you for using my app!!!";
 	myfile.close();
}

}

system("pause");
	return 0;
}

char ChooseGender(){

	char ch;
	 cout<<"PLease choose from the following to help me"<<endl;
	cout<<"initialize the right pattern for you..."<<endl;
	cout<<endl;
	cout<<"M.Male\nF.Female\n"<<endl;
	cout<<endl;
	cin>>ch;
	while(ch!='M'&& ch!='F'){
		cout<<"Please enter valid character..."<<endl;
		cin>>ch;
	}
	if(ch=='M'){
		cout<<"You have chosen the male pattern."<<endl;
	}
	else{
		cout<<"You have chosen the female pattern."<<endl;
	}
	cout<<endl;
	cout<<endl;
	return (ch);
}

char WelcomeMessage(){
	char ch;
	
	cout<<"***********************************"<<endl;
	cout<<"Welcome to my console application !"<<endl;
	cout<<"***********************************"<<endl;
	cout<<"Would you like to create a new account?"<<endl;
	cout<<endl;
	cout<<"Please enter:"<<endl;
	cout<<"Y. yes"<<endl;
	cout<<"N. no"<<endl;
	cout<<endl;
	cin>>ch;
	while(ch!='N'&& ch!='Y'){
		cout<<"Please enter valid character..."<<endl;
		cin>>ch;
	}
	cout<<endl;
	return (ch);
}

void PrintResultBMI(float a){
	cout<<endl;
	cout<<"The body mass index (BMI) or Quetelet index is a value derived from\n";
	 cout<<"the mass (weight) and height of an individual. The BMI is defined as the\n";
	 cout<<"body mass divided by the square of the body height, and is universally\n";
	 cout<<"expressed in units of kg/m2, resulting from mass in kilograms\n";
	 cout<<"and height in metres.\n";
	 
cout<<endl;
cout<<"The BMI may also be determined using a table or\n";
cout<<"chart which displays BMI as a function of mass and height\n";
cout<<"using contour lines or colors for different BMI categories,\n";
cout<<"and may use two different units of measurement.\n";
 cout<<endl; 

cout<<"The BMI is an attempt to quantify the amount of tissue mass\n";
cout<<"(muscle, fat, and bone) in an individual, and then categorize\n";
cout<<"that person as underweight, normal weight, overweight, or obese\n";
cout<<"based on that value. However, there is some debate about where\n";
cout<<"on the BMI scale the dividing lines between categories should be placed.\n";
cout<<"Commonly accepted BMI ranges are underweight: under 18.5,\n";
cout<<"normal weight: 18.5 to 25, overweight: 25 to 30, obese: over 30.";
cout<<endl;
cout<<endl;
	if(a<18.5){
		cout<<"It seems like you're underweight... Think about consulting a dietician for special advice\non how to gain some weight..."<<endl;
	}
	else if(a<=25){
		cout<<"Congrats! Your weight is normal!!"<<endl;
	}
	else if(a<30){
		cout<<"It seems like you're slightly overweight, some excercise would improve your \nhealth state."<<endl;
	}
	else{
		cout<<"You are overweight.. Think about consulting a diet expert for special advice\non how to get rid of some extra weight..."<<endl;
	}
}

char PromptSave(){

char a;
cout<<"Would you like me to save your account stats in a file?"<<endl;
 		 cout<<endl;
 		 
	cout<<"Please enter:"<<endl;
	cout<<"Y. yes"<<endl;
	cout<<"N. no"<<endl;
	cout<<endl;
	cin>>a;
	while(a!='N'&& a!='Y'){
		cout<<"Please enter valid character..."<<endl;
		cin>>a;
	}
	cout<<endl;
	return(a);
	
 		
}
