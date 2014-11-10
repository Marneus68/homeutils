# homeutils

*homeutils* is a collection of command line tools and toys inspired by Homestuck.  
This little collection is a work in progress. For now it includes :

- homesay : a cowsay wrapper allowing you to draw your favourite characters in your terminal
- homespeak : a tool allowing you to transform strings according to predefined "[typing quirks]()" along with the corresponding color (optional).

If you want new characters to be added to the *homesay* tool I can be reached at [duane.bekaert@gmail.com](mailto:duane.bekaert@gmail.com). Don't hesitate to contact me if you find any bug or if you have other ideas for additional tools.

Every contribution is welcome, just submit a pull request and I'll review it.

Please not that this project is in its early stages.

## Installation

After cloning the repository, you'll have to build *homspeak* bu running *make*. 

    git clone xxx
    make

Once this is done you can install all the tools at once by running the following command as root.

    make install

## Dependencies

Compiling *homespeak* requires a C++ compiler along with *make*. You'll also need *make* to install everything.

To work properly, *homesay* requires *cowsay* to be installed.

## Running

TODO

## Uninstalling

The various tools can all be uninstalled by running the following command as root.

    make uninstall


### License

This project and every file in it are under the lGPL v3.0. See the LICENSE file for more details.

