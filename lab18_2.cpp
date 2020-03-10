#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2 ){
	double r1_x = R1->x + R1->w; //right position
	double r2_x = R2->x + R2->w;  //right position
	// Min of right position - Max of left position
	double a= min(r1_x,r2_x)-max(R1->x,R2->x); //Horizontal length

	double r1_y = R1->y - R1->h; //Bottom position
	double r2_y = R2->y - R2->h; //Bottom position
	//Min of top position - Max of bottom position
	double b = min(R1->y,R2->y) - max(r1_y,r2_y); // Vertical Length
	if(a<0 or b<0) return 0.0;
	return a*b;
}

int main(){
	double a,s,d,f;
	double g,h,j,k;
	cout << "Please input Rect 1 (x y w h): ";
	cin>>a>>s>>d>>f;
	cout << "Please input Rect 2 (x y w h): ";
	cin>>g>>h>>j>>k;
	Rect R1={a,s,d,f};
	Rect R2={g,h,j,k};
	cout << "Overlap area = "<<overlap(&R1,&R2);	
	return 0;
}
