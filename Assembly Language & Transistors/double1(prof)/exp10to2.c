#include "number.h"
#include "exp10to2.h"

void exp10ToExp2(struct Number *pn)
{
	if (pn->exp10 < 0);
	{
	    while (pn->exp10 > 0)
        {
            while (pn->mantissa < UINT64_MAX)
            {
                pn->mantissa = pn->mantissa * 2;
                pn->exp2--;
            }
            pn->mantissa = (pn->mantissa + 5)/10;
            pn->exp10++;
        }
	}
	if (pn->exp10 > 0)
    {
        while (pn->exp10 < 0)
        {
            while (pn->mantissa < UINT64_MAX)
            {
                pn->mantissa = pn->mantissa * 2;
                pn->exp2++;
            }
            pn->mantissa = (pn->mantissa + 5)/10;
            pn->exp10--;
        }
    }
}
