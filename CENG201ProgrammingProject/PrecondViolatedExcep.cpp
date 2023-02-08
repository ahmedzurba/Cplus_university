//21.12
#include "PrecondViolatedExcep.h"


PrecondViolatedExcep::PrecondViolatedExcep(const string& mass) :logic_error("Precondition Violated Exception" + mass)
{
}
	