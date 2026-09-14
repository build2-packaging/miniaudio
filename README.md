# miniaudio - Audio playback and capture C library

This is a `build2` package repository for [`miniaudio`](https://github.com/mackron/miniaudio),
an audio playback and capture C library.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`miniaudio` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libminiaudio/PACKAGE-README.md) file.

The development setup for `miniaudio` uses the standard `bdep`-based workflow.
For example:

```
git clone .../miniaudio.git
cd miniaudio

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
