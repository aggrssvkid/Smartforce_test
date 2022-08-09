FROM ubuntu

COPY . /Part2

WORKDIR /Part2

RUN apt update && apt install -y build-essential && make && make clean
