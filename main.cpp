#include <iostream>
#include <math.h>
using namespace std;

//Creating a structure for the points
struct Point{
	double x;
	double y;		
};    
	
int main()
{
	//Creating objects from the Point structure
	Point p1;
	Point p2;
	Point p3;
	Point p12;
	Point p13;
	Point p23;
	Point mid;
	
	//Taking user inputs for the 3 points
	cout<<" Enter the 3 points of the triangle, \n";
	cout<<" \tP1.x = ";
	cin>>p1.x;
	cout<<" \tP1.y = ";
	cin>>p1.y;
	cout<<" \tP2.x = ";
	cin>>p2.x;
	cout<<" \tP2.y = ";
	cin>>p2.y;
	cout<<" \tP3.x = ";
	cin>>p3.x;
	cout<<" \tP3.y = ";
	cin>>p3.y;
	
	//Calculating the mid point coordinates of the each line
	p12.x = (p1.x + p2.x)/2;
	p12.y = (p1.y + p2.y)/2;
	p13.x = (p1.x + p3.x)/2;
	p13.y = (p1.y + p3.y)/2;
	
	//Calculating the gradients of the triagle lines
	double p12_grad = (p1.y - p2.y)/(p1.x - p2.x);
	double p13_grad = (p1.y - p3.y)/(p1.x - p3.x);
	
	//Taking the gradient of the line perpendicular to it
	double p12_perp_grad = -1/p12_grad;
	double p13_perp_grad = -1/p13_grad;
	
	//Calculating the intercepts of those perpendicular lines
	double c12 = p12.y - p12.x*p12_perp_grad;
	double c13 = p13.y - p13.x*p13_perp_grad;
	
	//Calculating the coordinates of the midpoint
	mid.x = (c13-c12)/(p12_perp_grad-p13_perp_grad);
	mid.y = p12_perp_grad*mid.x + c12;
	
	//Calculating the radius
	double rad = sqrt(pow(mid.x,2)+pow(mid.y,2));
	
	cout<<"\n\n Center coordinates of the circle, ";
	cout<<"X = "<<mid.x<<", Y = "<<mid.y;
	cout<<"\n\n Radius of the circle = "<<rad;	
}
