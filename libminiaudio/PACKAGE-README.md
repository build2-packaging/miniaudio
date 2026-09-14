# libminiaudio - Audio playback and capture C library

This is a `build2` package for the [`miniaudio`](https://github.com/mackron/miniaudio)
C library. It provides audio playback, capture, decoding, and mixing with no
dependencies other than the standard library.


## Usage

To start using `libminiaudio` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libminiaudio ^0.11.25
```

Then import the library in your `buildfile`:

```
import libs = libminiaudio%lib{miniaudio}
```


## Importable targets

This package provides the following importable targets:

```
lib{miniaudio}
```

The compiled miniaudio library. Public headers are included as
`<miniaudio/miniaudio.h>`.


## Configuration variables

This package has no configuration variables.
