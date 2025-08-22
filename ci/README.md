# CI: Makefile/Docker testing

To test the build, there is a Makefile in [ci](.) folder using
docker containers to test on various distro.

## Usage

To get the help simply type:
```sh
make
```

note: you can also use from top directory
```sh
make --directory=ci
```

### Example

For example to test inside an `Alpine` container:
```sh
make alpine_test
```

# Dockerfile for CMake/C++/Qt Development Environment

Currently it build environment for one distribution:
* [Alpine Linux](https://alpinelinux.org/).

## Alpine Image

From [alpine:latest](https://hub.docker.com/r/alpine/)
* [cmake](https://pkgs.alpinelinux.org/package/edge/main/x86_64/cmake)
* [make](https://pkgs.alpinelinux.org/package/edge/main/x86_64/make)
* [gcc](https://pkgs.alpinelinux.org/package/edge/main/x86_64/gcc)
* [clang](https://pkgs.alpinelinux.org/package/edge/main/x86_64/clang)
* [doxygen](https://pkgs.alpinelinux.org/package/edge/main/x86_64/doxygen)
* [graphviz](https://pkgs.alpinelinux.org/package/edge/main/x86_64/graphviz)

## Docker layers

Dockerfile is splitted in several stages.

![docker](docs/docker.svg)

### Run arm64v8 image on amd64 machine

You can build and run `arm64v8` (i.e. `aarch64`) docker container on a `amd64` host (`x86_64`) by enabling qemu support:
```sh
docker run --pull always --rm --privileged multiarch/qemu-user-static --reset -p yes
```
ref: https://github.com/multiarch/qemu-user-static#getting-started

Then you should be able to run them, e.g.:
```sh
docker run --rm -it arm64v8/ubuntu
```
ref: https://github.com/docker-library/official-images#architectures-other-than-amd64

### Docker buildx

ref: https://docs.docker.com/buildx/working-with-buildx/

On you enable qemu support (see above), you can list available platform using:
```sh
docker buildx ls
```
Then you can build a docker image using one of the available platform
```sh
docker buildx build --platform linux/arm64 ...
```

## Custom CMake install

To control the version of CMake, instead of using the
[version provided by the distro package manager](https://repology.org/project/cmake/badges), you can:
* Install the prebuilt binaries (recommanded) 
* Build it from source (slower)
* Install it using the [pypi package cmake](https://pypi.org/project/cmake/) (need a python stack)

### Install prebuilt

The recommended and faster way is to use the prebuilt version:
```Dockerfile
# Install CMake 3.25.2
RUN wget "https://cmake.org/files/v3.25/cmake-3.25.2-linux-x86_64.sh" \
&& chmod a+x cmake-3.25.2-linux-x86_64.sh \
&& ./cmake-3.25.2-linux-x86_64.sh --prefix=/usr/local/ --skip-license \
&& rm cmake-3.25.2-linux-x86_64.sh
```

**warning**: Since [CMake 3.20](https://cmake.org/files/v3.20/) Kitware use a lowercase `linux` instead of `Linux` (e.g. [CMake 3.19](https://cmake.org/files/v3.19/)).

### Build from source

To build from source you can use the following snippet:
```Dockerfile
# Install CMake 3.25.2
RUN wget "https://cmake.org/files/v3.25/cmake-3.25.2.tar.gz" \
&& tar xzf cmake-3.25.2.tar.gz \
&& rm cmake-3.25.2.tar.gz \
&& cd cmake-3.25.2 \
&& ./bootstrap --prefix=/usr/local/ \
&& make \
&& make install \
&& cd .. \
&& rm -rf cmake-3.25.2
```

