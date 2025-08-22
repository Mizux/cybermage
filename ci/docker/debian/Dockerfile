# Create a virtual environment with all tools installed
# ref: https://hub.docker.com/_/debian
FROM debian:unstable AS env

# Install system build dependencies
ENV PATH=/usr/local/bin:$PATH
RUN apt update -q \
&& apt install -yq \
 git wget libssl-dev \
 build-essential cmake \
 qt6-base-dev libgl-dev \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

FROM env AS devel
WORKDIR /home/project
COPY . .

FROM devel AS build
RUN cmake --version
RUN cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build --target all -v
RUN cmake --build build --target install -v

FROM build AS test
RUN CTEST_OUTPUT_ON_FAILURE=1 cmake --build build --target test -v

# Test install rules
FROM env AS install_env
COPY --from=build /usr/local/ /usr/local/

FROM install_env AS install_devel
WORKDIR /home/sample
COPY ci/sample .

FROM install_devel AS install_build
RUN cmake -S. -Bbuild
RUN cmake --build build --target all -v

FROM install_build AS install_test
RUN CTEST_OUTPUT_ON_FAILURE=1 cmake --build build --target test -v

# Create a production image
FROM debian:unstable AS prod

RUN apt update -q \
&& apt install -yq libqt6gui6 libqt6widgets6 \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Create app directory
WORKDIR /home/app
COPY --from=build /usr/local/ .
