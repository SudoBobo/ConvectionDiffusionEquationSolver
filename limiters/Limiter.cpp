#include "limiters/Limiter.h"

Limiter::Limiter(Conditions * conditions, const int k)
{
 m_conditions = conditions;
 m_k = k;
}

