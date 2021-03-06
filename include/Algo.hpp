#ifndef Algo_hpp
#define Algo_hpp

#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>

class Cell;
class Sample;
class Interactions;
class Analyse;

class Algo{
	private:
		int ns_;
		double dt_;
		double t_;
		double tf_;
		bool init_t_;
		int tic_;
		//Numerotation files
		int ticw_;
		int tica_;
		//Frequency recording sample+network
		int nrecord_;
		//Frequency analyse during simulation
		int nana_;
		//Print to standard
		int nprint_;

		//Computed from Interactions/dt
		//Global parameters to print:
		//All writiin during computed during initcheck
		//calling checkSimulationParameters

		//Normal restitution coefficient
		double e_;
		//Max normal viscosity
		double gnmax_;
		double gtmax_;
		//Max time step
		double dtmax_;

		//Global damping
		bool damping_;
		//between 0 an 1
		double dampCoeff_;

		//File where initial setup is written:
		std::string fsetup_;

		//Plug:
		Interactions * Int_;
		Cell * cell_;
		Sample * spl_;
		Analyse * ana_;

	public:
		Algo();
		~Algo(){};
		//void verletalgo(Cell&,std::vector<Particle>&);
		void verletalgo2();
		void damping(const double);
		void init(std::ifstream&);
		bool initcheck();
		void run();
		void plug(Cell&,Sample&,Interactions&,Analyse&);
		void write();
		bool checkSimulationParameters();
		void computedtmax();

		//Auto compute max viscosities gn and gt
		void compute_gmax();
		bool checktimestep()const;

		bool checkNormalViscosity() const;
		//Write simu setup in filesetup_;
		void writesetup() const;
		void initTics();

		//Call any fonctions modifying driving/Boundary cond
		//to change at the run time
		void updateDriving();
		void imposeForceStatus()const;


		//Manage stop/reverse shearing
		void shearStatus()const;
};

#endif
