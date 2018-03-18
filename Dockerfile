FROM alpine:latest

RUN apk update && \ 
    apk add python3 make && \
    pip3 install --upgrade pip && \
    pip3 install pytest pytest-html pytest-json && \
    mkdir -p $HOME/app

ADD Makefile $HOME/app/Makefile
ADD src $HOME/app/src

WORKDIR $HOME/app