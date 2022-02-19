#!/bin/bash

MALLOC_PYTHON_LIBRARY=./mallocless_python_hook/libmallocless_python_hook.so LD_LIBRARY_PATH=./mallocless_python_hook/ make
