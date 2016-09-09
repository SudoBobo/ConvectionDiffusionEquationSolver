#ifndef CONDITIONS_H
#define CONDITIONS_H

//checked

class Conditions
{
public:
	Conditions(const double spatialStep, const double timeStep);
	Conditions(const double spatialStep, const double timeStep,
			   const double spatialSteps, const double timeSteps,
			   const double a, const double b, const double T);
	Conditions(const Conditions * anotherConditions);
	double getSpatialStep() const;
	double getTimeStep() const;
	double getSpatialSteps() const;
	double getTimeSteps() const;
	double getA() const;
	double getB() const;
	double getT() const;

private:
	double m_spatialStep;
	double m_timeStep;
	double m_spatialSteps;
	double m_timeSteps;
	double m_a;
	double m_b;
	double m_T;
};

#endif // CONDITIONS_H
