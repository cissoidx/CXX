# Use the latest official Ubuntu LTS as a base
FROM ubuntu:22.04

# Set environment variables to avoid user interaction during installs
ENV DEBIAN_FRONTEND=noninteractive

# Update and install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    clang \
    lldb \
    lcov \
    valgrind \
    vim \
    curl \
    wget \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /workspace

