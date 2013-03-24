# About gauche-clipboard

This module provides an interface to clipboard using Windows API.

## Install the package

    $ git clone git://github.com/SaitoAtsushi/gauche-clipboard.git
    $ cd gauche-clipboard
    $ ./DIST gen
    $ ./configure
    $ make
    $ make -s check
    $ make install

## Example

    (use clipboard)
    (write-clipboard "文字列") ;; write "文字列" to clipboard.
    (read-clipboard) ;; => "文字列"
