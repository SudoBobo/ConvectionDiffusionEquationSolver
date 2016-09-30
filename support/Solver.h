#ifndef SOLVER_H
#define SOLVER_H

#include <systemSolvers/SystemSolver.h>
#include <support/Conditions.h>
#include <support/FileWriter.h>
#include <support/State.h>
#include <support/InitialState.h>

// #include <GNUPlotMaker.h>

class Solver
{
public:
	Solver (SystemMaker * systemMaker, SystemSolver * systemSolver,
			Conditions * conditions);
	void solve(Limiter * limiter, Stream * stream,
			   InitialState * initialState);
	void solveAll(std::vector<Limiter*> & limiters,
				  std::vector<Stream*>  & streams,
					  std::vector<InitialState*>  & initialStates);
protected:
	SystemMaker  * m_systemMaker;
	SystemSolver * m_systemSolver;
	Conditions   * m_conditions;

	State m_origState;
	State m_newState;
	std::vector <double> m_valueVectorForFileWriter;
	std::vector <double> m_valueVectorForAnalyticalFileWriter;

	FileWriter m_numericalFileWriter;
	FileWriter m_analyticalFileWriter;
	FileWriter m_errorFileWriter;
	//GNUPlotMaker m_GNUPlotMaker;
};

#endif // SOLVER_H
