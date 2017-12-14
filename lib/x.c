#include "x.h"
#if defined(ALT2)
#  include "alt2/x.h"
#elif defined(ALT1)
#  include "alt1/x.h"
#endif
int example_func()
{
#if defined(ALT2) || defined(ALT1)    
    return call_example_func();
#endif
}
