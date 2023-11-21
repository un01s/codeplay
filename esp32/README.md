# esp32

## setup for esp32 and others

### for compilation of esp32

```
$ brew install cmake ninja dfu-util
$
$ cmake --version
cmake version 3.27.8
$
$ ninja --version
1.11.1
$
$ dfu-util --version
dfu-util 0.11
$
```

### Xcode command line tools

Then run ```xcode-select --install``` to install Xcode command line tools. It triggers a popup window. Just follow it to install.

### python version

```
$ python3 --version
Python 3.10.1
$
```

There is no python version2 available in the current system, Sonoma 14.1.1.

### esp-idf and esp-adf

```
$ git clone --recursive https://github.com/espressif/esp-adf
$ cd esp-adf
$ export ADF_PATH=$PWD
$
$ cd $ADF_PATH/esp-idf
$ ./install.sh
$ . ./export.sh
$
$ echo $ADF_PATH
$
# find a project
# configure the project
$
$ idf.py menuconfig
$ idf.py build
```


