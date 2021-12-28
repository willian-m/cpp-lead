# C++ Lead

I often found myself on the need of coding a progress bar in my C++ programs.
It is an easy job, but often it amounts to some 10-20 lines that just needs to
be typed and checked if it is working as intended. There are some packages that
does the job. For example, the very popular [boost](https://www.boost.org/)
library. There is also
[tqdm.cpp](https://github.com/tqdm/tqdm.cpp), which is a port to C++ of the very
popular python module [tqdm](https://github.com/tqdm/tqdm).

However, to use boost people (specially those who are starting learning) will
often find easier to download the entire library when it is not actually needed.
tqdm.cpp is in a pre-alpha stage last time I checked and I was not able to make
it work.

It was due to these issues I made (mainly for my own use) the
**C++ Lead** library: a header only library for generating progress
bars. It is inspired on tqdm, but it does not wraps around iterators to
automatically compute size and display the progress bar. Instead, you need to
create an object and ask it to increase the bar on each step.

## Why CPP Lead

Originally, the name was simply **Progress Bar**. But that was too generic. Thus,
I put `cpp` on front of it, since it is for C++ and it became
**CPP Progress Bar**, which was abreviated to **cpppb**. There were too many
p's on it. But it turns out that "Pb" is the periodic table element symbol to
lead. Thus, one can read "cpp pb" as *cpp lead*. I liked the word play and
decided to stick to it.

## Usage

The program below exemplifies the most basic usage:

```cpp
include "ProgressBar.hpp" // Do not forget to place the ProgressBar.hpp in your include path

int main(int argv, char** argc){
    int nsteps = 100;

    ProgressBar pb(nsteps); // Create progress bar object

    for(int istep=0; istep<nsteps; ++istep){
        //<Your loop code>
        pb.step(); //Increments the display bat
    }
}
```

You may also add a "prefix" message to the bar by means of the constructor
`ProgressBar(int nsteps, std::string prefix)`. If you update only after a
given number `n` of steps, you just use the `ProgressBar::step(int n)`. This is
useful if you have many iterations and wants to minimize the performance impact
of printing the progress bar.

See the `example` folder for an example of usage. Also, look at the `Makefile`
in the current folder as an example of how to compile a program with this
library.

To see the progress bar in action, just clone this repository, compile the
example with `make` and execute the `ProgressBarExample` file.

## License

This software is distributed under the MIT License. See the LICENSE file for
details.
