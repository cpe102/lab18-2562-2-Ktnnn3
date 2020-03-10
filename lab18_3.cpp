//Write your code here
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<cctype>
using namespace std;

string upper(string s){
    for(int i=0;i<s.size();i++){
           s[i] =  toupper(s[i]) ;
        }
        return s;
}


int main(){
    ifstream source;
    source.open("name_score.txt");
    string textline;
    vector<string> v_name,v_grade;
    char name[100];
    int a,b,c;
    
    while( getline(source,textline)){ //read each line of file
    	
    	sscanf(textline.c_str(),"%[^:]: %d %d %d",name,&a,&b,&c);
        v_name.push_back(name);
        int total = a+b+c;
        v_grade.push_back(total >= 80 ? "A" : total>=70 ? "B" : total >= 60 ? "C" : total >= 50 ? "D" : "F");
        cout<<name<<" "<<a<<" "<<b<<" "<<c<<" = "<<total<<endl;
	}
    string type,search;
  	while(1) {
          
  		cout<<"Please input your command : ";
        getline(cin,textline);
        int idx= textline.find_first_of(" ");
        int i=0;
       
      
        string s1=upper(textline.substr(0,idx));
        string s2=upper(textline.substr(idx+1,textline.size()));
        
        //string s2 = upper(textline,substr(..........)); //option ; a,b,c,...,sanji,...
        // if(s1=="NAME") {
            
        // }
        if (s1 == "GRADE") {
            for(int i=0;i<v_name.size();i++) {
                if (s2==v_grade[i]) cout << v_name[i]<<endl;
            }
            cout<<"-----------------------------------"<<endl;
        }
        else if (s1=="NAME") {
            for(int i=0;i<v_name.size();i++){
                string ss = v_name[i].substr(0,v_name[i].size());
                if (s2==upper(v_name[i]))  {
                    cout <<v_name[i]<<"'s grade = "<<v_grade[i]<<endl; 
                    break;
                    }
                else if (s2!=upper(v_name[i]) && i != v_name.size()-1);
                else cout<<"Cannot found."<<endl;
            }
            cout<<"-----------------------------------"<<endl;
        }
        else if (s1 == "EXIT") break;
        else cout<<"Invalind command."<<endl<<"-----------------------------------"<<endl;
   
  		
  		//type exit ; break
      
}
}