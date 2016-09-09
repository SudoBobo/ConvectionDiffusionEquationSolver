#include "support/Solver.h"
#include <string>

Solver::Solver(SystemMaker * systemMaker, SystemSolver * systemSolver,
			   Conditions * conditions)
	: m_systemMaker(systemMaker), m_systemSolver(systemSolver),
	  m_conditions(conditions)
{
	m_systemSolver->setSystemMaker(m_systemMaker);
	// задание подходящих общих параметров fileWriter'ов
	// source = orig
	// precision
	// grid size
	// path

}


// Limiter * vs const Limiter
void Solver::solve(Limiter * limiter, Stream * stream,
				   InitialState * initialState)
{
m_systemMaker->setStream(stream);
m_systemSolver->setLimiter(limiter);


// создание подходящих имён
static std::string dataFileName;
static std::string GNUplotName;

dataFileName.clear();
dataFileName = m_systemMaker->name() + " " + m_systemSolver->name() + " " +
			   limiter->name() + " " + stream->name() + " " +
			   initialState->name();

static int timeSteps;
timeSteps = m_conditions->getTimeSteps();

//? try it
m_origState = initialState;
// ??
for (int t = 0; t <= timeSteps; t++)
	{
		m_numericalFileWriter.write(t);
		//
		// gnu write will be here
		// if time has come
		// GNUplotName += t
		// GNUplotMaker.draw()
		//
		m_systemSolver->calcNextState(m_origState, m_newState);
	}
}

void Solver::solveAll(std::vector<Limiter*> & limiters,
					 std::vector<Stream*>  & streams,
						 std::vector<InitialState*>  & initialStates)
{
	{
		for (int i = 0; i < limiters.size(); i++)
			{
				for (int j = 0; j < streams.size(); i++)
				{
					for (int k = 0; k < initialStates.size(); k++)
					{
						this->solve(limiters[i], streams[j], initialStates[k]);
					}
				}
			}
	}
}
