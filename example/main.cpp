///\author Willian M. Serenone
///\date 28ht december, 2021

/// The MIT License (MIT)
///\copyright 2021 (c) Willian Matioli Serenone
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

///\brief Example program for the implementation of the Progress bar

#include <unistd.h>
#include <iostream>

#include "ProgressBar.hpp"

int main(int argv, char** argc){
    int nsteps = 100;
    std::cout << "Simple progress bar example:" << std::endl;
    ProgressBar pb(nsteps);
    for(int istep=0;istep<nsteps;++istep){
        pb.step();
        usleep(100000);
    }

    std::cout << "Progress bar with prefix and updated each 5 steps:" << std::endl << std::endl;

    ProgressBar pb2(nsteps,"Test bar");
    for(int istep=0;istep<nsteps;++istep){
        if (istep%5 == 0) pb2.step(5);

        usleep(100000);
    }
}