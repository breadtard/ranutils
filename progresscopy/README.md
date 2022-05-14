# progresscopy (pc.c)
## `cp` but outputs progress and doesnt have any flags

```bash
# how to compile
cc pc.c -o pc

# how to compile (gentoo mode)
cc pc.c -static -o pc -O3 -Ofast -march=native
```

```bash
# how to use
$ pc <src> <dst>

# examples
$pc ~/disks/storage/big_file.mp4 ./big_file.mp4
0%
1%
2%
3%
...
(91 lines ommited)
...
95%
96%
97%
98%
99%
100%
$
```
