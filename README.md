
# About
Modification of wget based on v1.21.2.

In my daily work I have to use tools that downloads a lot of stuff. I found out that it's often downloading exactly the same files again and again. The tools uses wget so I decided to do modification that allows wget to support caching.

# How it works
File downloaded for first time will be copied to

`<home directory>/.cached_wget/<md5_of_url>/<file name>`

Each subsequent attempt to download file from the same url will copy it from cache instead of downloading again.

# How to build
```
$ git clone https://github.com/bleakdev/wget_cache.git
$ cd wget_cache
$ ./bootstrap
$ autoreconf -f -i
$ ./configure
$ make -j8
```
Prepared binary will be located under `src` directory.

# How to use
I do not recommend to install that modification as default version of wget. If you need use it as default, you can always add it to your PATH variable.

For example add in your .bashrc
```
...

export PATH=/home/user/wget_cache/src:$PATH
```
How to check if you already using the right version?
```
$ wget --version
GNU Wget [cache modification]  <- output you should get
```
# Disable caching
It is possible to disable local caching by setting flag `uselocalcache` in `/home/<user>/.wgetrc` file.

Disable:
```
uselocalcache = 0
```
Enable (enabled by default):
```
uselocalcache = 1
```
