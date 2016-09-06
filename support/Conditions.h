#ifndef CONDITIONS_H
#define CONDITIONS_H

//checked

class Conditions
{
public:
	Conditions(const double spatialStep, const double timeStep);
	Conditions(const Conditions * anotherConditions);
	double getSpatialStep() const;
	double getTimeStep() const;

private:
	double m_spatialStep;
	double m_timeStep;
};

#endif // CONDITIONS_H
