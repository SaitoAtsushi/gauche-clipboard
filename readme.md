# About gauche-clipboard

This module provides an interface to clipboard using Windows API.

## Install the package

    $ git clone git://github.com/SaitoAtsushi/gauche-clipboard.git
    $ cd gauche-clipboard
    $ ./configure
    $ make
    $ make check
    $ make install

## Example

    (use clipboard)
    (write-clipboard "文字列") ;; write "文字列" to clipboard.
    (read-clipboard) ;; => "文字列"

## License

Gauche-clipboard is BSD style license.

See also COPYING.
