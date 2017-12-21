#ifndef Vecteur_hpp
#define Vecteur_hpp

#include<iostream>
#include<fstream>
#include<cmath>

class Vecteur{
	private:
		double x_;
		double y_;
	public:
		Vecteur(): x_(0.), y_(0.){};
		Vecteur(double x, double y): x_(x), y_(y){};
		~Vecteur(){};

		void print() const{std::cout<<x_<<" "<<y_<<" "<<getNorme()<<std::endl;}
		void add(double dx, double dy) { x_ += dx ; y_ += dy;}
		void addx(double dx) { x_ += dx;}
		void addy(double dy) { y_ += dy;}

		//Accessors:
		double getNorme() const {return sqrt( x_*x_ + y_ * y_);}
		double getNorme2() const {return  x_*x_ + y_ * y_;}

		double getx() const {return x_;}
		double gety() const {return y_;}
		//Mutators:
		void setx(double x) {x_ = x;}
		void sety(double y) {y_ = y;}
		void set(double x,double y){ x_=x; y_=y;}
		//Read from ifstream
		void load(std::ifstream& is);
		//Write in ofstream
		void write(std::ofstream& os) const;

		//Surcharge operator:
		//Scalar product:
		double operator * (Vecteur a){
			return (x_*a.x_ + y_*a.y_);
		}

		Vecteur operator + (Vecteur a){
			Vecteur p;
			p.x_ = x_ + a.x_;
			p.y_ = y_ + a.y_;
			return p;
		}

		Vecteur operator - (Vecteur a){
			Vecteur p;
			p.x_ = x_ - a.x_;
			p.y_ = y_ - a.y_;
			return p;
		}

		Vecteur operator * (double a){
			Vecteur p;
			p.x_ = a*x_ ;
			p.y_ = a*y_ ;
			return p;
		}

		Vecteur operator * (double a) const{
			Vecteur p;
			p.x_ = a*x_ ;
			p.y_ = a*y_ ;
			return p;
		}

		Vecteur operator * (int a) {
			Vecteur p;
			p.x_ = a*x_ ;
			p.y_ = a*y_ ;
			return p;
		}

		Vecteur operator / (double a){
			Vecteur p;
			p.x_ = x_ / a ;
			p.y_ = y_ / a ;
			return p;
		}
		Vecteur operator - () {
			Vecteur p;
			p.x_ = - x_;
			p.y_ = - y_;
			return p;
		}
};

#endif
