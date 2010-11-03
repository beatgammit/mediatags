MediaTags
====

A collection of tools to output unabstracted tag information as JSON and (in the future) ProtoBuf formats.

id3tags
----

Usage:

    ./id3tags /path/to/my/.mp3

Building
====

    cd mediatags
    make

Dependencies
----

The [id3lib by Dirk Mahoney](http://id3lib.sourceforge.net/) (as opposed to the others of similar name)

  * `id3lib-3.8.3` - you know it's the right one because of the `3.8.3` and if the contents match
    * /usr/lib/libid3.a
    * /usr/lib/libid3.so
    * /usr/include/id3/tag.h
  * `zlib`

Mac OS X:

    # ??? this doesn't seem to install anything
    sudo port install id3lib

Ubuntu:

    # libid3-3.8.3-dev
    sudo apt-get install libid3-dev

OpenEmbedded:

    bitbake libid3
    # should produce packages in `${OE_HOME}/tmp/deploy/glibc/ipk/arm7a/` such as
    # id3lib_3.8.3-r2.6_armv7a.ipk
    # id3lib-static_3.8.3-r2.6_armv7a.ipk
    # id3lib-dev_3.8.3-r2.6_armv7a.ipk
    sudo opkg install id3lib-dev id3lib id3lib-static


Considerations
====

id3lib appeared to be the only library with documentation easily googleable documentation.

Some have said others are better. Well, tell us how to use them!

  * [`id3lib`](http://id3lib.sourceforge.net/) - has documentation
  * [`taglib`](http://developer.kde.org/~wheeler/taglib/api) - Good documentation, but unclear on how to get all tags
  * [`libid3`](http://freshmeat.net/projects/libid3/) - No documentation
  * [`libid3tag`](http://www.underbit.com/products/mad/) - No documentation
    * [mailing list quickstart](http://www.mars.org/pipermail/mad-dev/2002-January/000439.html)
