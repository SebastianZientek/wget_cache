
# About
Modification of wget (v1.21.2) that supports caching.

# How it works
File downloaded for first time will be copied to

`<home directory>/.cached_wget/<md5_of_url>/<file name>`

Each subsequent attempt to download file from the same url will copy it from cache instead of downloading again.
