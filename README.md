homeutils
=========

*homeutils* is a collection of command line tools and toys inspired by [Homestuck]().  

![]()

This little collection is a work in progress. For now it includes :

- homesay : a [cxxsay]() wrapper allowing you to draw your favourite characters in your terminal, with some text in a speech bubble, pretty much like [cowsay](),
- homethink : a wrapper for [cxxthink](), pretty much like *homesay* but with a though bubble instead
- homespeak : a tool allowing you to transform strings according to predefined "[typing quirks]()" along with the corresponding color (optional).

Features
--------

Usage
-----

### homesay

Homesay works exactly like [cxxsay]() but is shipped with a collection of characters (called cowfiles under the cowsay logic). Possible cowfiles provided with this release include the following: 

- default (karkat)
- karkat
- terezi
- vriska

### homespeak

Using `--help` will display the usage message as well as a list of all possible typing quirks.

    usage: homespeak [--color] [--bg] [--help] <identifier>

    --help      Display the usage message
    --color     Colors the text
    --bg        Adds a white background

The identifier allows you to select which quirk you want to apply on the text.

### Example

    homespeak AG --color "Hello world :)" | homesay -f vriska

![]()

Dependencies
------------

To work properly, *homesay* requires [cxxsay]() to be installed on your system.

Installing
----------

### Binaries

#### Mac OS X

`TODO`

#### Linux

`TODO`

### From source

Compiling *homespeak* requires a C++ compiler which can compile C++11 code along with *make*. You'll also need *make* to install everything.

Clone the repository:

    git clone https://github.com/Marneus68/homeutils.git

You can both build and install everything by running the following as root:

    make install

Uninstalling
------------

The various tools can all be uninstalled by running the following command as root:

    make uninstall

### License

This project and every file in it are under the lGPL v3.0. See the LICENSE file for more details.

Contributing
------------

If you want new characters to be added to *homesay* or *homespeak* I can be reached at [duane.bekaert@gmail.com](mailto:duane.bekaert@gmail.com). Don't hesitate to contact me if you find any bug or if you have other ideas for additional tools.

Every contribution is welcome, just submit a pull request and I'll review it.

License
-------

*homeutils* is under the lGPL v3 See [LICENSE](https://raw.githubusercontent.com/Marneus68/homeutils/master/LICENSE) for more details.

