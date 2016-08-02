Navio2Sharp -- This software is provided 'as-is' without any express or
implied warranty. Read the full license agreement in "license.txt".

Navio2Sharp was created by Zachariah Brown (zsbzsb) to provide an easy to use
object oriented wrapper around the Navio C++ drivers provided by Emlid. This
was done by writing a C API wrapper (CNavio2) around the Navio C++ drivers. The
CNavio2 API is then wrapped in an object oriented C# library (Navio2Sharp).

To compile run CMake in the CNavio2 directory and make sure to specify the
NAVIO2_ROOT_DIR variable (https://github.com/emlid/Navio2).

Dependencies
emlid/Navio2 (https://github.com/emlid/Navio2)
