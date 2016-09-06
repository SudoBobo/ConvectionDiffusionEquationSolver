#include "Solver.h"

Solver();
Solver (SystemSolver * systemSolver, Conditions & conditions, a, b, T)
{
	//тут хорошо бы менять лимитеры, потоки и начальные условия
	//создаём райтеры, ероры, осущетсвляем осуществялем обмен между ст
}

protected:
State m_origState;
State m_newState;
Conditions * m_conditions;

FileWriter m_numericalFileWriter;
FileWriter m_analyticalFileWriter;
FileWriter m_errorFileWriter;
{

}
