#include "number.h"
#include "exp10to2.h"

void exp10ToExp2(struct Number *pn)
{
	if (pn->exp10 < 0);
	{
	    while (pn->exp10 < 0)
        {
            while (pn->mantissa <= (UINT64_MAX) / 2)
            {
                pn->mantissa = pn->mantissa * 2;
                pn->exp2--;
            }
            pn->mantissa = (pn->mantissa + 5)/10;
            pn->exp10++;
            while (pn->mantissa <= (UINT64_MAX) / 2)
            {
                pn->mantissa = pn->mantissa * 2;
                pn->exp2--;
            }
        }
	}
	if (pn->exp10 > 0)
    {
        while (pn->exp10 > 0)
        {
            while ((pn->mantissa <= (UINT64_MAX) / 10) && (pn->exp10 > 0))
            {
                pn->mantissa = pn->mantissa * 10;
                pn->exp10--;
            }
            /*pn->mantissa = (pn->mantissa + 5) / 2;
            pn->exp2++;
            while (pn->mantissa <= (UINT64_MAX) / 2)
            {
                pn->mantissa = pn->mantissa / 2;
                pn->exp2++;
            }*/
        }
    }
}
