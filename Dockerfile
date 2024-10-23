# See docs : https://mybinder.readthedocs.io/en/latest/tutorials/dockerfile.html
#FROM python:3.11.8-slim-bookworm
FROM ubuntu:24.04
    LABEL maintainer="William Oquendo <woquendo@gmail.com>"
#ARG CACHEBUST=0 # reset cache at this point, change to 1 to reset cache

# Install packages
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    python3 \
    python3-pip \
    python3-dev \
    python3-venv \
    libffi-dev \
    g++-14 \
    make \
    cmake \
    clang \
    libeigen3-dev \
    bat \
    emacs-nox \
    #vim \
    gnuplot-nox \
    nano \
    git \
    htop \
    curl \
    unzip \
    sudo \
    cpplint \
    #valgrind \
    gdb \
    libspdlog-dev \
    && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/bin/g++-14 /usr/bin/g++
RUN ln -s /usr/bin/gcc-14 /usr/bin/gcc
RUN ln -s /usr/bin/python3 /usr/bin/python
RUN ln -s /usr/bin/aarch64-linux-gnu-gcc-14 /usr/bin/aarch64-linux-gnu-gcc

# Install catch2
RUN git clone https://github.com/catchorg/Catch2.git
RUN cd Catch2 && \
    cmake -Bbuild -H. -DBUILD_TESTING=OFF && \
    sudo cmake --build build/ --target install --parallel $(nproc)

# Install fmt
RUN git clone https://github.com/fmtlib/fmt.git
RUN cd fmt && \
    cmake -Bbuild -H. -DBUILD_SHARED_LIBS=TRUE -DFMT_TEST=OFF && \
    sudo cmake --build build/ --target install --parallel $(nproc)

# Install starship to show git branch in prompt plus some other stuff
RUN curl -fsSL https://starship.rs/install.sh | sh -s -- -y

# Fix timezone
ENV TZ=America/Bogota
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Set the SHELL environment variable to /bin/bash
ENV SHELL=/bin/bash

# Remove the default user to free id 1000
RUN userdel -r ubuntu

# create user with a home directory
ARG NB_USER=jovyan
ARG NB_UID=1000
ENV USER ${NB_USER}
ENV HOME /home/${NB_USER}

RUN adduser --disabled-password \
    --gecos "Default user" \
    --shell /bin/bash \
    --uid ${NB_UID} \
    ${NB_USER}

USER ${NB_USER}
# move to home
WORKDIR ${HOME}

# Copy only the requirements file first
COPY requirements.txt .

# USING pip
# create venv, activate and run pip install
#RUN python3 -m venv ${HOME}/.venv
#RUN . ${HOME}/.venv/bin/activate && pip install -r requirements.txt


# Clone the source code repo
RUN git clone https://github.com/iluvatar1/ProgCPP-lectures-jupyter.git

# Switch back to root to install jupyter
WORKDIR ${HOME}
USER ${USER}

## Run matplotlib config to generate the font cache
#RUN . .venv/bin/activate && MPLBACKEND=Agg python3 -c "import matplotlib.pyplot"

# Setup starship
RUN echo 'eval "$(starship init bash)"' >> ${HOME}/.bashrc
# setup venv for user
RUN echo "source ~/.venv/bin/activate" >> ${HOME}/.bashrc


# USING uv
# Download and run the uv installer
RUN curl -Lsf https://astral.sh/uv/install.sh | sh
# Set the PATH to include both cargo bin and current directory
ENV PATH="/root/.cargo/bin:/usr/local/bin:$PATH"
RUN ${HOME}/.cargo/bin/uv venv --python 3.12 && ${HOME}/.cargo/bin/uv pip install -r requirements.txt
RUN echo 'source $HOME/.cargo/env' >> ${HOME}/.bashrc
RUN echo "source .venv/bin/activate" >> ${HOME}/.bashrc

