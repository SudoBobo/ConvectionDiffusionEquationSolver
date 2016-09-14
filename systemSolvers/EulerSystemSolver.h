#ifndef EULERSYSTEMSOLVER_H
#define EULERSYSTEMSOLVER_H

#include "systemSolvers/SystemSolver.h"

class EulerSystemSolver: public SystemSolver
{
	public:
		EulerSystemSolver(Limiter * limiter, Conditions * conditions,
							   SystemMaker * systemMaker);
		EulerSystemSolver(Conditions * conditions);

		void calcNextState(const State & currentState, State & nextState) const;

	private: Polynomial uNew(const Polynomial & uPrev, const Polynomial & u,
							  const Polynomial & uNext) const;
		std::string getName() const;

};

#endif // EULERSYSTEMSOLVER_H
