# splay (sp.c)
## shitty sdl-based music player

```bash
# how to compile
cc sp.c -o ~/.local/bin/splay -lSDL2

# how to compile (gentoo mode)
cc sp.c -static -lSDL2 -o ~/.local/bin/splay -O3 -Ofast -march=native
```

```bash
# how to use
$ splay music.wav
^C # plays music until ctrl+c

$ source bash_func # or add to bashrc
$ cplay music.opus 
^C # if you use the bash function you can play any file that ffmpeg supports
```
