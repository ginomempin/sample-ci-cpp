# This Docker container configuration is only used if it is not possible
# to run this sample C++ app on your own environment. For example, you
# either don't have CMake, g++, lcov, etc. or you can't install them.

# Use the same docker image as the one specified in gitlab-ci.yml.
FROM 192.168.1.37:5000/cdpf-ubuntu-cpptests:16.04

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
