#ifndef CONDITIONS_H
#define CONDITIONS_H

//checked

class Conditions
{
public:
	Conditions(const double spatialStep, const double timeStep);
	Conditions(const double spatialStep, const double timeStep,
			   const double spatialSteps, const double timeSteps,
			   const double a, const double b, const double T,
			   const int k, const double courantNumber);
	Conditions(const Conditions * anotherConditions);
	double getSpatialStep() const;
	double getTimeStep() const;
	double getSpatialSteps() const;
	double getTimeSteps() const;
	double getA() const;
	double getB() const;
	double getT() const;
	int getK() const;
	double getCourantNumber () const;

private:
	double m_spatialStep;
	double m_timeStep;
	double m_spatialSteps;
	double m_timeSteps;
	double m_a;
	double m_b;
	double m_T;
	int m_k;
	double m_courantNumber;
};

#endif // CONDITIONS_H
