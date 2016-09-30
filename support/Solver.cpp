#include "support/Solver.h"
#include <string>
#include <algorithm>
#include <iostream>

Solver::Solver(SystemMaker * systemMaker, SystemSolver * systemSolver,
			   Conditions * conditions)
	: m_systemMaker(systemMaker), m_systemSolver(systemSolver),
	  m_conditions(conditions)
{
	m_systemSolver->setSystemMaker(m_systemMaker);

	std::vector <int> newGridSize = {((m_systemMaker->getK() + 1) *
					  int(m_conditions->getSpatialSteps())), 0, 0};

	m_numericalFileWriter.setPrecision(6);
	m_numericalFileWriter.setGridSize(newGridSize);
	m_numericalFileWriter.setGeneralFileName("part0_");
	m_numericalFileWriter.setGeneralHeaderName("file");
	m_numericalFileWriter.setPath("/home/bobo/newData/");

	m_numericalFileWriter.setSource(&m_valueVectorForFileWriter);


	 m_analyticalFileWriter.setPrecision(6);
	 m_analyticalFileWriter.setGridSize(newGridSize);
	 m_analyticalFileWriter.setGeneralFileName("part0_");
	 m_analyticalFileWriter.setGeneralHeaderName("file");
	 m_analyticalFileWriter.setPath("/home/bobo/newData/");

	 m_analyticalFileWriter.setSource(&m_valueVectorForAnalyticalFileWriter);



	//	FileWriter m_analyticalFileWriter;
	//	FileWriter m_errorFileWriter;
}


void Solver::solve(Limiter * limiter, Stream * stream,
				   InitialState * initialState)
{
m_systemMaker->setStream(stream);
m_systemSolver->setSystemMaker(m_systemMaker);
m_systemSolver->setLimiter(limiter);

static std::string dataGeneralDirectoryName;
//static std::string GNUplotName;

dataGeneralDirectoryName.clear();
dataGeneralDirectoryName = m_systemMaker->getName() + m_systemSolver->getName() +
			   limiter->getName() + stream->getName() +
			   initialState->getName();



static std::string command;
command = "mkdir " + m_numericalFileWriter.getPath() + dataGeneralDirectoryName;
std::system(command.c_str());

m_numericalFileWriter.setDirectory(dataGeneralDirectoryName);



std::string analyticalGeneralDirectoryName = dataGeneralDirectoryName +
											 "Analytical";

command = "mkdir " + m_analyticalFileWriter.getPath() +
		  analyticalGeneralDirectoryName;
std::system(command.c_str());

m_analyticalFileWriter.setDirectory(analyticalGeneralDirectoryName);



static int timeSteps;
timeSteps = m_conditions->getTimeSteps();

m_origState = initialState->getState();
m_newState  = initialState->getState();

if (m_systemMaker == nullptr)
{
	throw std::range_error("m_systemMaker == nullptr!");
}

if (m_systemSolver == nullptr)
{
	throw std::range_error("m_systemSolver == nullptr!");
}

if (m_systemMaker->getStream() == nullptr)
{
	throw std::range_error("m_stream == nullptr!");
}

if (m_systemSolver->getLimiter() == nullptr)
{
	throw std::range_error("m_limiter == nullptr!");
}

if (m_systemSolver->getSystemMaker()== nullptr)
{
	throw std::range_error("m_systemMaker == nullptr!");
}



for (int t = 0; t <= timeSteps; t++)
	{
		//!!
		m_valueVectorForFileWriter = m_origState.makeValueVector();
		m_valueVectorForAnalyticalFileWriter =
				initialState->makeAnalyticalValueVector(t);



		m_numericalFileWriter.write(t);
		m_analyticalFileWriter.write(t);

		if (std::count(initialState->getTimeMoments().begin(),
				  initialState->getTimeMoments().end(), t) == 1 )
		{
			//GNUplotName.clear();
			//GNUplotName = dataGeneralFileName + std::to_string(t);
			//Fine write in file
			//Draw the picture using system and stuff
		}
		m_systemSolver->calcNextState(m_origState, m_newState);
//		m_newState = m_origState * 0.99;
		m_origState = m_newState;
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

	// analytical solution
	// add extra directory
	// create temp states
	// calc solution
	// write there


}
