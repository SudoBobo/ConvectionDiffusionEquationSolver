#ifndef SOLVER_H
#define SOLVER_H

#include <SystemSolver.h>
#include <Conditions.h>
#include <FileWriter.h>
#include <State.h>
// #include <GNUPlotMaker.h>

class Solver
{
public:
	Solver();
	Solver (SystemSolver * systemSolver, Conditions & conditions, a, b, T);
protected:
	State m_origState;
	State m_newState;
	Conditions * m_conditions;

	FileWriter m_numericalFileWriter;
	FileWriter m_analyticalFileWriter;
	FileWriter m_errorFileWriter;

	//GNUPlotMaker m_GNUPlotMaker;
};

//#endif // SOLVER_H
