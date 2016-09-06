#ifndef SOLVER_H
#define SOLVER_H

#include <systemSolvers/SystemSolver.h>
#include <support/Conditions.h>
#include <support/FileWriter.h>
#include <support/State.h>
// #include <GNUPlotMaker.h>

class Solver
{
public:
	Solver();
	Solver (SystemSolver * systemSolver, Conditions & conditions,
			const double a, const double b, const double T);
protected:
	State m_origState;
	State m_newState;
	Conditions * m_conditions;

	FileWriter m_numericalFileWriter;
	FileWriter m_analyticalFileWriter;
	FileWriter m_errorFileWriter;

	//GNUPlotMaker m_GNUPlotMaker;
};

#endif // SOLVER_H
