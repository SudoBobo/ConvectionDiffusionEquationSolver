#include "support/Solver.h"
#include <string>
#include <algorithm>

Solver::Solver(SystemMaker * systemMaker, SystemSolver * systemSolver,
			   Conditions * conditions)
	: m_systemMaker(systemMaker), m_systemSolver(systemSolver),
	  m_conditions(conditions)
{
	m_systemSolver->setSystemMaker(m_systemMaker);
	m_numericalFileWriter.setPrecision(6);

	std::vector <int> newGridSize = {(m_systemMaker->getK() *
					  int(m_conditions->getSpatialSteps())), 0, 0};

	m_numericalFileWriter.setGridSize(newGridSize);
	m_numericalFileWriter.setGeneralFileName("part0_");
	m_numericalFileWriter.setGeneralHeaderName("file");
	m_numericalFileWriter.setPath("home/bobo/newData/");

	m_numericalFileWriter.setSource(&m_valueVectorForFileWriter);

	//	FileWriter m_analyticalFileWriter;
	//	FileWriter m_errorFileWriter;
}


void Solver::solve(Limiter * limiter, Stream * stream,
				   InitialState * initialState)
{
m_systemMaker->setStream(stream);
m_systemSolver->setLimiter(limiter);

static std::string dataGeneralDirectoryName;
//static std::string GNUplotName;

dataGeneralDirectoryName.clear();
dataGeneralDirectoryName = m_systemMaker->getName() + " " + m_systemSolver->getName() + " " +
			   limiter->getName() + " " + stream->getName() + " " +
			   initialState->getName();

static std::string command;
command = "mkdir" + m_numericalFileWriter.getPath() + dataGeneralDirectoryName;
std::system(command.c_str());

m_numericalFileWriter.setDirectory(dataGeneralDirectoryName);

static int timeSteps;
timeSteps = m_conditions->getTimeSteps();

//? try it
m_origState = initialState->getState();
// ??
for (int t = 0; t <= timeSteps; t++)
	{
		//!!
		m_valueVectorForFileWriter = m_origState.makeValueVector(42);
		m_numericalFileWriter.write(t);

		if (std::count(initialState->getTimeMoments().begin(),
				  initialState->getTimeMoments().end(), t) == 1 )
		{
			//GNUplotName.clear();
			//GNUplotName = dataGeneralFileName + std::to_string(t);
			//Fine write in file
			//Draw the picture using system and stuff
		}
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
