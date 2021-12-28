///\author Willian M. Serenone
///\date 21st december, 2021

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


#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <iomanip> 

#include <string>


///\class ProgressBar
///\brief creates a progress bar
class ProgressBar
{
private:
    long niterations;
    long current_iteration;
    int terminal_width;
    int nblocks;
    int ndots;
    int percentage;
    std::string prefix;

    int get_terminal_width();
    void display();
    void update_variables();
public:
    ProgressBar(long niterations);
    ProgressBar(long niterations, std::string prefix_message);
    ~ProgressBar();

    void step();
    void step(int nsteps);

};

///\brief Constructor
///\param niterations The number of iterations
ProgressBar::ProgressBar(long niterations) : 
niterations(niterations),
current_iteration(0),
prefix("")
{
    terminal_width = get_terminal_width();
    update_variables();
    std::cout << std::endl;
}

///\brief Constructor
///\param niterations The number of iterations
///\param prefix_message A message to be displayed to the left of the progress bar
ProgressBar::ProgressBar(long niterations, std::string prefix_message) : 
niterations(niterations),
current_iteration(0),
prefix(prefix_message)
{
    terminal_width = get_terminal_width();
    update_variables();
    //std::cout << std::endl;
}


ProgressBar::~ProgressBar()
{
}

///\brief Gets the terminal width
///\return The terminal width
///Adapted from https://www.linuxquestions.org/questions/programming-9/get-width-height-of-a-terminal-window-in-c-810739/
int ProgressBar::get_terminal_width()
{
    int cols = 80;
    //int lines = 24;

    #ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    cols = ts.ts_cols;
    //lines = ts.ts_lines;
    #elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    cols = ts.ws_col;
    //lines = ts.ws_row;
    #endif /* TIOCGSIZE */

    return cols;
}

///\brief Display the progress bar in its current state
void ProgressBar::display(){

    std::cout <<"\r"<< prefix << " |";
    for(int i=0; i < nblocks; ++i) std:: cout << "\u2588";
    for(int i=0; i < ndots; ++i) std:: cout << ".";

    std::cout << "| "<<std::setw(3) << percentage <<"% ";
    std::cout << std::flush;

}

///\brief Update the variables used in the display step
void ProgressBar::update_variables(){

    int avaliable_space = terminal_width - prefix.size() - 9;
    percentage = (int) 100*((float) current_iteration/(float) niterations);

    nblocks = ((float) percentage/100.)*avaliable_space;
    ndots = avaliable_space-nblocks;

}


///\brief Increases the progress by one unit and updates the progress bar
void ProgressBar::step(){
    current_iteration++;
    update_variables();
    display();
}

///\brief Increases the progress by a desired number of steps and updates the progress bar
///\param nsteps //The number of steps 
void ProgressBar::step(int nsteps){
    current_iteration += nsteps;
    update_variables();
    display();
}

#endif