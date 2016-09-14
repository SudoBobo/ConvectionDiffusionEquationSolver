#include "support/Conditions.h"

Conditions::Conditions(const double spatialStep, const double timeStep)
{
	m_spatialStep = spatialStep;
	m_timeStep = timeStep;
}

Conditions::Conditions(const double spatialStep, const double timeStep,
					   const double spatialSteps, const double timeSteps,
		   const double a, const double b, const double T)
{
	m_spatialStep = spatialStep;
	m_timeStep = timeStep;
	m_spatialSteps = spatialSteps;
	m_timeSteps = timeSteps;
	m_a = a;
	m_b = b;
	m_T = T;

}

Conditions::Conditions(const Conditions * anotherConditions)
{
	m_spatialStep   = anotherConditions->getSpatialStep();
	m_timeStep = anotherConditions->getTimeStep();
	m_spatialSteps = anotherConditions->getSpatialSteps();
	m_timeSteps = anotherConditions->getTimeSteps();
	m_a = anotherConditions->getA();
	m_b = anotherConditions->getB();
	m_T = anotherConditions->getT();
}

double Conditions::getSpatialStep() const
{
	return m_spatialStep;
}

double Conditions::getTimeStep() const
{
	return m_timeStep;
}

double Conditions::getSpatialSteps() const
{
	return m_spatialSteps;
}

double Conditions::getTimeSteps() const
{
	return m_timeSteps;
}


double Conditions::getA() const
{
	return m_a;
}

double Conditions::getB() const
{
	return m_b;
}

double Conditions::getT() const
{
	return m_T;
}
