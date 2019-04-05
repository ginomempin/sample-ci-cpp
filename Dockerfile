FROM ubuntu:16.04

LABEL NAME="sample-ci-cpp" \
      VERSION="16.04" \
      DESC="Ubuntu 16.04 with added packages to support CI tests." \
      PACKAGES="cmake,g++,git,lcov,pthread"

RUN apt-get update --yes && \
    apt-get install --yes g++=4:5.3.1-1ubuntu1 && \
    apt-get install --yes lcov=1.12-2 && \
    apt-get install --yes cmake=3.5.1-1ubuntu3 && \
    apt-get install --yes git=1:2.7.4-0ubuntu1.6 && \
    apt-get install --yes libpthread-stubs0-dev=0.3-4

# Set the working directory inside the Docker image
WORKDIR /sample-ci-cpp

# Copy everything
COPY . /sample-ci-cpp

# Build the app and tests
RUN rm -Rf build && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j8
