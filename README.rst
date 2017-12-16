|Travis| <- We expect this to fail

.. |Travis| image:: https://img.shields.io/travis/headupinclouds/cmake_xcode_object_lib/master.svg?style=flat-square&label=Linux%20OSX%20FAIL
   :target: https://travis-ci.org/headupinclouds/cmake_xcode_object_lib

Minimal example to reproduce CMake Xcode generator OBJECT library limitations constructed from Matthew Wheeler's CMake post.

See the failure build badge above for the Travis CI Xcode logs containing the problem.  The OS X Makefile jobs `libcxx` and the Linux (Ubuntu Trusty) `default` Makefile jobs run without issue.


See: http://cmake.3232098.n2.nabble.com/OBJECT-Libraries-with-Xcode-Generator-td7593197.html

Note that the OBJECT library won't work with both ``lib/x.c`` and ``lib/alt1/x.c`` or ``lib/alt2/x.c``
:: 

  cmake -H. -B_build1 -GXcode -DALT1=OFF -DALT2=OFF && cmake --build _build1

::

  Build all projects

  ** BUILD SUCCEEDED **


::

  cmake -H. -B_build2 -GXcode -DALT1=OFF -DALT2=ON && cmake --build _build2
  
:: 

  clang: error: no such file or directory: '/Users/scratch/cmake_xcode_object_lib/_build2/lib/example.build/Debug/example.build/Objects-normal/x86_64/x.o'

  ** BUILD FAILED **


.. image:: https://user-images.githubusercontent.com/554720/34009023-46098a04-e0d5-11e7-850f-e0ef11f9fced.jpg
   :target: https://travis-ci.org/headupinclouds/cmake_xcode_object_lib
