# tripcode (t.c)
## a 4chan tripcode generator

```bash
# how to compile
cc t.c -o t -lcrypt

# how to compile (gentoo mode)
cc t.c -static -lcrypt -o t -O3 -Ofast -march=native
```

```bash
# how to use
$ ./t tripcode
tripcode: 3GqYIJ3Obs
$ ./t "everything past the 7th char gets cut off"
everything past the 7th char gets cut off: 8.L5bN30V.
$ ./t everyth
everyth: zddyYv2Mi.
$ ./t multi-track drifting included!
multi-track: TNvysgQEcw
drifting: OLFPFYeULg
included!: Zklu3k.xso
```
