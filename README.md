MediaTags
====

A collection of tools to output unabstracted tag information as JSON and (in the future) ProtoBuf formats.

id3tags
----

Usage:

    ./id3tags --file /path/to/my/.mp3

Building
====

    cd mediatags
    make

Dependencies
----

  * `id3lib-3.8.3`
  * `zlib`

Mac OS X:

    # ???
    sudo port install id3lib

Ubuntu:

    # libid3-3.8.3-dev
    sudo apt-get install libid3-dev

OpenEmbedded:

    bitbake libid3
    sudo opkg install id3lib-dev


Considerations
====

id3lib appeared to be the only library with documentation easily googleable documentation.

Some have said others are better. Well, tell us how to use them!

  * [`taglib`](http://developer.kde.org/~wheeler/taglib/api) - Unclear on how to get all tags
  * [`id3lib`](http://id3lib.sourceforge.net/)
  * [`libid3tag`](http://www.underbit.com/products/mad/) - No documentation
    * [mailing list quickstart](http://www.mars.org/pipermail/mad-dev/2002-January/000439.html)

  * [`libid3`](http://freshmeat.net/projects/libid3/) - No documentation
