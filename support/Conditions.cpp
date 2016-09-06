#include "Conditions.h"

Conditions::Conditions(const double spatialStep, const double timeStep)
{
	m_spatialStep = spatialStep;
	m_timeStep = timeStep;
}

Conditions::Conditions(const Conditions * anotherConditions)
{
	m_spatialStep   = anotherConditions->getSpatialStep();
	m_timeStep = anotherConditions->getTimeStep();
}

double Conditions::getSpatialStep() const
{
	return m_spatialStep;
}

double Conditions::getTimeStep() const
{
	return m_timeStep;
}
