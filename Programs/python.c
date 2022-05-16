/* Minimal main program -- everything is loaded from the library */

#include "Python.h"
#include "pycore_pylifecycle.h"

#include "../mallocless_python_hook/mallocless_python_hook.h"

#ifdef MS_WINDOWS
int
wmain(int argc, wchar_t **argv)
{
    return Py_Main(argc, argv);
}
#else
int
main(int argc, char **argv)
{
    int ret = Py_BytesMain(argc, argv);
    zsim_magic_op_end_sim();
    return ret;
}
#endif
